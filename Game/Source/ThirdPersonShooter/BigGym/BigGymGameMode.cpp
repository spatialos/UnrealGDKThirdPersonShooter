// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "BigGymGameMode.h"
#include "UObject/ConstructorHelpers.h"

#include "BigGymLogging.h"
#include "EngineClasses/SpatialNetConnection.h"
#include "EngineClasses/SpatialNetDriver.h"
#include "Engine/World.h"
#include "Interop/Connection/SpatialWorkerConnection.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "SpatialStatics.h"

ABigGymGameMode::ABigGymGameMode()
{
	PrimaryActorTick.bCanEverTick = true;

	//set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/BigGym/EntityBlueprints/BigGymCharacter_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
		PlayerCheckoutRadius = FGenericPlatformMath::Sqrt(PlayerPawnBPClass.Class.GetDefaultObject()->NetCullDistanceSquared);
	}

	static ConstructorHelpers::FClassFinder<APawn> NPCBPClass(TEXT("/Game/AIGym/AIGymNPC_BP"));
	if (NPCBPClass.Class != NULL) {
		NPCPawnClass = NPCBPClass.Class;
	}

	TotalPlayers = 0;
	TotalNPCs = 0;
	NumPlayerClusters = 0;
	PlayersSpawned = 0;

	// Seamless Travel is not currently supported in SpatialOS [UNR-897]
	bUseSeamlessTravel = false;
}

void ABigGymGameMode::CheckInitCustomSpawning()
{
	if (bInitializedCustomSpawnParameters)
	{
		return;
	}

	if (ShouldUseCustomSpawning())
	{
		UE_LOG(LogBigGym, Log, TEXT("Enabling custom density spawning."));
		ParsePassedValues();
		ClearExistingSpawnPoints();

		SpawnPoints.Reset();
		GenerateSpawnPointClusters(NumPlayerClusters);

		if (SpawnPoints.Num() != TotalPlayers) {
			UE_LOG(LogBigGym, Error, TEXT("Error creating spawnpoints, number of created spawn points (%d) does not equal total players (%d)"), SpawnPoints.Num(), TotalPlayers);
		}

		SpawnNPCs(TotalNPCs);
	}
	else
	{
		UE_LOG(LogBigGym, Log, TEXT("Custom density spawning disabled."));
	}

	bInitializedCustomSpawnParameters = true;
}

bool ABigGymGameMode::ShouldUseCustomSpawning()
{
	FString WorkerValue;
	USpatialStatics::GetWorkerFlag(this, TEXT("override_spawning"), WorkerValue);
	return (WorkerValue.Equals(TEXT("true"), ESearchCase::IgnoreCase) || FParse::Param(FCommandLine::Get(), TEXT("OverrideSpawning")));
}

void ABigGymGameMode::ParsePassedValues()
{
	if (FParse::Param(FCommandLine::Get(), TEXT("OverrideSpawning")))
	{
		UE_LOG(LogBigGym, Log, TEXT("Found OverrideSpawning in command line args, worker flags for custom spawning will be ignored."));
		FParse::Value(FCommandLine::Get(), TEXT("TotalPlayers="), TotalPlayers);

		// Set default value of PlayerDensity equal to TotalPlayers. Will be overwritten if PlayerDensity option is specified.
		PlayerDensity = TotalPlayers;

		FParse::Value(FCommandLine::Get(), TEXT("PlayerDensity="), PlayerDensity);

		FParse::Value(FCommandLine::Get(), TEXT("TotalNPCs="), TotalNPCs);
	}
	else
	{
		UE_LOG(LogBigGym, Log, TEXT("Using worker flags to load custom spawning parameters."));
		FString TotalPlayersString, PlayerDensityString, TotalNPCsString;
		if (USpatialStatics::GetWorkerFlag(this, TEXT("total_players"), TotalPlayersString))
		{
			TotalPlayers = FCString::Atoi(*TotalPlayersString);
		}

		// Set default value of PlayerDensity equal to TotalPlayers. Will be overwritten if PlayerDensity option is specified.
		PlayerDensity = TotalPlayers;

		if (USpatialStatics::GetWorkerFlag(this, TEXT("player_density"), PlayerDensityString))
		{
			PlayerDensity = FCString::Atoi(*PlayerDensityString);
		}

		if (USpatialStatics::GetWorkerFlag(this, TEXT("total_npcs"), TotalNPCsString))
		{
			TotalNPCs = FCString::Atoi(*TotalNPCsString);
		}
	}

	NumPlayerClusters = FMath::CeilToInt(TotalPlayers / (float)PlayerDensity);
}

void ABigGymGameMode::ClearExistingSpawnPoints()
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), SpawnPoints);
	for (AActor* SpawnPoint : SpawnPoints)
	{
		SpawnPoint->Destroy();
	}
}

void ABigGymGameMode::GenerateGridSettings(int DistBetweenPoints, int NumPoints, int& NumRows, int& NumCols, int& MinRelativeX, int& MinRelativeY)
{
	if (NumPoints <= 0)
	{
		UE_LOG(LogBigGym, Warning, TEXT("Generating grid settings with non-postive number of points (%d)"), NumPoints);
		NumRows = 0;
		NumCols = 0;
		MinRelativeX = 0;
		MinRelativeY = 0;
		return;
	}

	NumRows = FMath::RoundToInt(FMath::Sqrt(NumPoints));
	NumCols = FMath::CeilToInt(NumPoints / (float)NumRows);
	const int GridWidth = (NumCols - 1) * DistBetweenPoints;
	const int GridHeight = (NumRows - 1) * DistBetweenPoints;
	MinRelativeX = FMath::RoundToInt(-GridWidth / 2.0);
	MinRelativeY = FMath::RoundToInt(-GridHeight / 2.0);
}

void ABigGymGameMode::GenerateSpawnPointClusters(int NumClusters)
{
	const int DistBetweenClusterCenters = 40000; // 400 meters, in Unreal units.
	int NumRows, NumCols, MinRelativeX, MinRelativeY;
	GenerateGridSettings(DistBetweenClusterCenters, NumClusters, NumRows, NumCols, MinRelativeX, MinRelativeY);

	UE_LOG(LogBigGym, Log, TEXT("Creating player cluster grid of %d rows by %d columns"), NumRows, NumCols);
	for (int i = 0; i < NumClusters; i++)
	{
		const int Row = i % NumRows;
		const int Col = i / NumRows;

		const int ClusterCenterX = MinRelativeX + Col * DistBetweenClusterCenters;
		const int ClusterCenterY = MinRelativeY + Row * DistBetweenClusterCenters;

		GenerateSpawnPoints(ClusterCenterX, ClusterCenterY, PlayerDensity);
	}
}

void ABigGymGameMode::GenerateSpawnPoints(int CenterX, int CenterY, int SpawnPointsNum)
{
	// Spawn in the air above terrain obstacles (Unreal units).
	const int Z = 305;

	const int DistBetweenSpawnPoints = 300; // In Unreal units.
	int NumRows, NumCols, MinRelativeX, MinRelativeY;
	GenerateGridSettings(DistBetweenSpawnPoints, SpawnPointsNum, NumRows, NumCols, MinRelativeX, MinRelativeY);

	UWorld* World = GetWorld();
	if (World == nullptr)
	{
		UE_LOG(LogBigGym, Error, TEXT("Cannot spawn spawnpoints, world is null"));
		return;
	}

	const int WalkRadius = 200; // In Unreal units. More than actual radius, just to be sure.
	const int MaxXDistance = (NumCols - 1) * DistBetweenSpawnPoints + 2 * WalkRadius;
	const int MaxYDistance = (NumRows - 1) * DistBetweenSpawnPoints + 2 * WalkRadius;
	const int MaxDistanceBetweenPlayers = FMath::Sqrt(FMath::Square(MaxXDistance) + FMath::Square(MaxYDistance));
	if (MaxDistanceBetweenPlayers >= PlayerCheckoutRadius)
	{
		UE_LOG(LogBigGym, Error, TEXT("Maximum distance between players is larger than checkout radius. Cannot ensure players will always see each other."));
	}

	for (int i = 0; i < SpawnPointsNum; i++)
	{
		const int Row = i % NumRows;
		const int Col = i / NumRows;

		const int X = CenterX + MinRelativeX + Col * DistBetweenSpawnPoints;
		const int Y = CenterY + MinRelativeY + Row * DistBetweenSpawnPoints;

		FActorSpawnParameters SpawnInfo{};
		SpawnInfo.Owner = this;
		SpawnInfo.Instigator = NULL;
		SpawnInfo.bDeferConstruction = false;
		SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		const FVector SpawnLocation = FVector(X, Y, Z);
		UE_LOG(LogBigGym, Log, TEXT("Creating a new PlayerStart at location %s."), *SpawnLocation.ToString());
		SpawnPoints.Add(World->SpawnActor<APlayerStart>(APlayerStart::StaticClass(), SpawnLocation, FRotator::ZeroRotator, SpawnInfo));
	}
}

void ABigGymGameMode::SpawnNPCs(int NumNPCs)
{
	for (int32 i = 0; i < NumNPCs; i++)
	{
		int32 Cluster = i % NumPlayerClusters;
		int32 SpawnPointIndex = Cluster * PlayerDensity;
		AActor* SpawnPoint = SpawnPoints[SpawnPointIndex];
		SpawnNPC(SpawnPoint->GetActorLocation());
	}
}

void ABigGymGameMode::SpawnNPC(FVector SpawnLocation)
{
	UWorld* const World = GetWorld();
	if (World == nullptr)
	{
		UE_LOG(LogBigGym, Error, TEXT("Error spawning NPC, World is null"));
		return;
	}

	if (NPCPawnClass == nullptr)
	{
		UE_LOG(LogBigGym, Error, TEXT("Error spawning NPC, NPCPawnClass is not set."));
		return;
	}

	UE_LOG(LogBigGym, Log, TEXT("Spawning NPC at %s"), *SpawnLocation.ToString());
	FActorSpawnParameters SpawnInfo{};
	//SpawnInfo.Owner = this;
	//SpawnInfo.Instigator = NULL;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	World->SpawnActor<APawn>(NPCPawnClass->GetDefaultObject()->GetClass(), SpawnLocation, FRotator::ZeroRotator, SpawnInfo);
}

AActor* ABigGymGameMode::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
{
	CheckInitCustomSpawning();

	if (!ShouldUseCustomSpawning() || SpawnPoints.Num() == 0)
	{
		return Super::FindPlayerStart_Implementation(Player, IncomingName);
	}

	// Use custom spawning with density controls
	const int32 PlayerUniqueID = Player->GetUniqueID();
	if (PlayerIdToSpawnPointMap.Contains(PlayerUniqueID))
	{
		return PlayerIdToSpawnPointMap[PlayerUniqueID];
	}

	AActor* ChosenSpawnPoint = SpawnPoints[PlayersSpawned % SpawnPoints.Num()];
	PlayerIdToSpawnPointMap.Add(PlayerUniqueID, ChosenSpawnPoint);

	UE_LOG(LogBigGym, Log, TEXT("Spawning player %d at %s."), PlayerUniqueID, *ChosenSpawnPoint->GetActorLocation().ToString());

	PlayersSpawned++;

	return ChosenSpawnPoint;
}
