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
#include "SpatialWorkerFlags.h"

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

	PlayersSpawned = 0;

	// Seamless Travel is not currently supported in SpatialOS [UNR-897]
	bUseSeamlessTravel = false;
}

void ABigGymGameMode::InitGameState()
{
	Super::InitGameState();

	if (ShouldUseCustomSpawning())
	{
		ParsePassedValues();
		ClearExistingSpawnPoints();
		GenerateSpawnPoints(TotalPlayers);
	}
}

bool ABigGymGameMode::ShouldUseCustomSpawning()
{
	FString WorkerValue;
	USpatialWorkerFlags::GetWorkerFlag(TEXT("override_spawning"), WorkerValue);
	return (WorkerValue.Equals(TEXT("true"), ESearchCase::IgnoreCase) || FParse::Param(FCommandLine::Get(), TEXT("OverrideSpawning")));
}

void ABigGymGameMode::ParsePassedValues()
{
	if (FParse::Param(FCommandLine::Get(), TEXT("OverrideSpawning")))
	{
		UE_LOG(LogBigGym, Log, TEXT("Found OverrideSpawning in command line args, worker flags for custom spawning will be ignored."));
		if (FParse::Param(FCommandLine::Get(), TEXT("TotalPlayers=")))
		{
			FParse::Value(FCommandLine::Get(), TEXT("TotalPlayers="), TotalPlayers);
		}
	}
	else
	{
		FString TotalPlayersString;

		if (USpatialWorkerFlags::GetWorkerFlag(TEXT("total_players"), TotalPlayersString))
		{
			TotalPlayers = FCString::Atoi(*TotalPlayersString);
		}
	}
}

void ABigGymGameMode::ClearExistingSpawnPoints()
{
	TArray<AActor*> ExistingSpawnPoints;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), ExistingSpawnPoints);

	for (AActor* SpawnPoint : ExistingSpawnPoints)
	{
		SpawnPoint->Destroy();
	}
}

void ABigGymGameMode::GenerateSpawnPoints(int SpawnPointsNum)
{
	// Spawn in the air above terrain obstacles.
	const int Z = 305;

	if (SpawnPointsNum < 1)
	{
		UE_LOG(LogBigGym, Error, TEXT("Can't spawn requested %d spawn points - the spawn points number should be at least 1"), SpawnPointsNum);
		return;
	}

	const int NumRows = FMath::CeilToInt(FGenericPlatformMath::Sqrt(SpawnPointsNum));
	const int NumCols = FMath::CeilToInt(SpawnPointsNum / (float)NumRows);

	const int DistBetweenSpawnPoints = 300; // In Unreal units.

	const int MinX = FMath::RoundToInt(-(NumCols / 2.0) * DistBetweenSpawnPoints);
	const int MinY = FMath::RoundToInt(-(NumRows / 2.0) * DistBetweenSpawnPoints);

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

		const int X = MinX + Col * DistBetweenSpawnPoints;
		const int Y = MinY + Row * DistBetweenSpawnPoints;

		FActorSpawnParameters SpawnInfo;
		SpawnInfo.Owner = this;
		SpawnInfo.Instigator = NULL;
		SpawnInfo.bDeferConstruction = false;

		const FVector SpawnLocation = FVector(X, Y, Z);
		UE_LOG(LogBigGym, Log, TEXT("Creating a new PlayerStart at location %s."), *SpawnLocation.ToString());
		SpawnPoints.Add(World->SpawnActor<APlayerStart>(APlayerStart::StaticClass(), SpawnLocation, FRotator::ZeroRotator, SpawnInfo));
	}
}

AActor* ABigGymGameMode::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
{
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
