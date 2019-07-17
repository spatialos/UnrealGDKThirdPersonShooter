// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "AIGymGameMode.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Classes/Engine/StaticMesh.h"
#include "Engine/World.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Rendering/PositionVertexBuffer.h"
#include "ScaleTestableCharacter.h"
#include "SpatialWorkerFlags.h"
#include "UObject/ConstructorHelpers.h"

AAIGymGameMode::AAIGymGameMode()
{
	static ConstructorHelpers::FObjectFinder<UBlueprint> NPCBPClass(TEXT("Blueprint'/Game/AIGym/AIGymNPC'"));
	
	if (NPCBPClass.Object) {
		NPCPawnClass = (UClass*)NPCBPClass.Object->GeneratedClass;
	}

	PlayersSpawned = 0;

	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<AActor> PlayerActorBPClass(TEXT("/Game/AIGym/AIGymCharacter_BP"));
	if (PlayerActorBPClass.Class != NULL)
	{
		PlayerCheckoutRadius = PlayerActorBPClass.Class.GetDefaultObject()->CheckoutRadius;
		DefaultPawnClass = PlayerActorBPClass.Class;
	}

	// Seamless Travel is not currently supported in SpatialOS [UNR-897]
	bUseSeamlessTravel = false;
}

void AAIGymGameMode::InitGameState()
{
	if (ShouldUseCustomSpawning())
	{
		ParsePassedValues();
		ClearExistingSpawnPoints();
		GenerateSpawnPoints(Clusters);
		SpawnNPCs();
	}
}

bool AAIGymGameMode::ShouldUseCustomSpawning()
{
	FString WorkerValue;
	USpatialWorkerFlags::GetWorkerFlag(TEXT("override_spawning"), WorkerValue);
	return (WorkerValue.Equals(TEXT("true"), ESearchCase::IgnoreCase) || FParse::Param(FCommandLine::Get(), TEXT("OverrideSpawning")));
}

void AAIGymGameMode::SpawnNPCs()
{
	if (Clusters > SpawnPoints.Num())
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't spawn NPCs - the number of clusters (%d) is higher than the existing spawn points (%d)."), Clusters, SpawnPoints.Num());
		return;
	}

	for (int32 i = 0; i < Clusters; i++)
	{
		AActor* SpawnPoint = SpawnPoints[i];

		FVector SpawnLocation = SpawnPoint->GetActorLocation();
		for (int32 j = 0; j < NPCsToPlayerRatio; j++)
		{
			SpawnNPC(SpawnLocation);
		}
	}
}

void AAIGymGameMode::SpawnNPC(FVector SpawnLocation)
{
	UWorld* const World = GetWorld();
	
	UE_LOG(LogTemp, Log, TEXT("Spawning a NPC at %s."), *SpawnLocation.ToString());

	if (World && NPCPawnClass != NULL) {
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		APawn* NPC = World->SpawnActor<APawn>(NPCPawnClass.GetDefaultObject()->GetClass(), SpawnLocation, FRotator::ZeroRotator, SpawnParams);
	}
}

void AAIGymGameMode::ParsePassedValues()
{
	if (FParse::Param(FCommandLine::Get(), TEXT("OverrideSpawning")))
	{
		if (FParse::Param(FCommandLine::Get(), TEXT("PlayerDensity=")))
		{
			FParse::Value(FCommandLine::Get(), TEXT("PlayerDensity="), PlayerDensity);
		}

		if (FParse::Param(FCommandLine::Get(), TEXT("TotalPlayers=")))
		{
			FParse::Value(FCommandLine::Get(), TEXT("TotalPlayers="), TotalPlayers);
		}

		if (FParse::Param(FCommandLine::Get(), TEXT("NPCsToPlayerRatio=")))
		{
			FParse::Value(FCommandLine::Get(), TEXT("NPCsToPlayerRatio="), NPCsToPlayerRatio);
		}
	}
	else
	{
		FString PlayerDensityString, TotalPlayersString, NPCsToPlayersRatioString;
		if (USpatialWorkerFlags::GetWorkerFlag(TEXT("player_density"), PlayerDensityString))
		{
			PlayerDensity = FCString::Atoi(*PlayerDensityString);
		}

		if (USpatialWorkerFlags::GetWorkerFlag(TEXT("total_players"), TotalPlayersString))
		{
			TotalPlayers = FCString::Atoi(*TotalPlayersString);
		}

		if (USpatialWorkerFlags::GetWorkerFlag(TEXT("npcs_to_players_ratio"), NPCsToPlayersRatioString))
		{
			NPCsToPlayerRatio = FCString::Atoi(*NPCsToPlayersRatioString);
		}
	}

	if (PlayerDensity != 0)
	{
		Clusters = TotalPlayers / PlayerDensity;
	}
}

void AAIGymGameMode::ClearExistingSpawnPoints()
{
	TArray<AActor*> ExistingSpawnPoints;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), ExistingSpawnPoints);

	for (AActor* SpawnPoint : ExistingSpawnPoints)
	{
		SpawnPoint->Destroy();
	}
}

void AAIGymGameMode::GenerateSpawnPoints(int SpawnPointsNum)
{
	// NOTE: Should check what the entity checkout radius is and make sure it's actually complyinng with the density
	int Z = 105;

	AStaticMeshActor* Floor = GetFloor();
	if (Floor == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't find the 'Floor' to measure the bounds of the world."));
		return;
	}

	if (SpawnPointsNum < 1)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't spawn requested %d spawn points - the spawn points number should be positive"), SpawnPointsNum);
		return;
	}
	
	FBox FloorBoundingBox = Floor->GetComponentsBoundingBox();
	
	// Multiply the actual bounds by 0.9 to accommodate the SpatialOS world and players not going outside of bounds
	int EdgeLength = FMath::Abs(FloorBoundingBox.Min.X - FloorBoundingBox.Max.X) * 0.9;

	int SpacingBetweenClusters = FMath::CeilToInt(EdgeLength / FGenericPlatformMath::Sqrt(SpawnPointsNum));

	// Provides a ratio between Spatial world units and Unreal world units
	int SpatialToUnrealWorldUnitRatio = 100;
	int MarginBetweenClusters = 150;
	int MinimumSpacingBetweenClusters = PlayerCheckoutRadius * 2 + MarginBetweenClusters * SpatialToUnrealWorldUnitRatio;

	if (SpacingBetweenClusters < MinimumSpacingBetweenClusters)
	{
		UE_LOG(LogTemp, Error, 
			TEXT("The platers' checkout radius of one cluster can overlap with players' from another cluster - reduce density or the entity checkout radius. Current configuration:\nWorld edge length (in SpatialOS units): %d\nPlayer checkout radius (in SpatialOS units): %f\nPadding between clusters: %d\nDesired number of clusters: %d\nOptimal number of clusters: %d"),
			EdgeLength / SpatialToUnrealWorldUnitRatio, PlayerCheckoutRadius / SpatialToUnrealWorldUnitRatio, MarginBetweenClusters, SpawnPointsNum, FMath::Square(EdgeLength / MinimumSpacingBetweenClusters));
		return;
	}

	for (int32 x = - (EdgeLength / 2); x < (EdgeLength / 2); x += SpacingBetweenClusters)
	{
		for (int32 y = -(EdgeLength / 2); y < (EdgeLength / 2); y += SpacingBetweenClusters)
		{
			// NOTE: Might have to provide SpawnCollisionHandlingOverride in case simulated players stack on top of each other and as a result can't spawn
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.Owner = this;
			SpawnInfo.Instigator = NULL;
			SpawnInfo.bDeferConstruction = false;

			FVector SpawnLocation = FVector(x, y, Z);
			if (GetWorld() != NULL)
			{
				UE_LOG(LogTemp, Log, TEXT("Creating a new PlayerStart at location %s."), *SpawnLocation.ToString());
				SpawnPoints.Add(GetWorld()->SpawnActor<APlayerStart>(APlayerStart::StaticClass(), SpawnLocation, FRotator::ZeroRotator, SpawnInfo));
			}

			// Avoid creating more spawn locations than needed due to ceiling of sqrt
			if (SpawnPoints.Num() >= SpawnPointsNum)
			{
				break;
			}
		}
	}
}

AStaticMeshActor* AAIGymGameMode::GetFloor()
{
	TArray<AActor*> StaticMeshes;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStaticMeshActor::StaticClass(), StaticMeshes);

	for (AActor* StaticMesh : StaticMeshes)
	{
		if (StaticMesh->GetName().Equals("Floor"))
		{
			return Cast<AStaticMeshActor>(StaticMesh);
		}
	}

	return NULL;
}

AActor* AAIGymGameMode::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
{
	if (!ShouldUseCustomSpawning() || SpawnPoints.Num() == 0)
	{
		return Super::FindPlayerStart_Implementation(Player, IncomingName);
	}

	int32 PlayerUniqueID = Player->GetUniqueID();

	UWorld* World = GetWorld();
	
	if (PlayerIdToSpawnPointMap.Contains(PlayerUniqueID))
	{
		return PlayerIdToSpawnPointMap[PlayerUniqueID];
	}

	AActor* ChosenSpawnPoint = SpawnPoints[PlayersSpawned % SpawnPoints.Num()];
	PlayerIdToSpawnPointMap.Add(PlayerUniqueID, ChosenSpawnPoint);

	UE_LOG(LogTemp, Log, TEXT("Spawning player %d at %s."), PlayerUniqueID, *ChosenSpawnPoint->GetActorLocation().ToString());

	PlayersSpawned++;

	return ChosenSpawnPoint;
}
