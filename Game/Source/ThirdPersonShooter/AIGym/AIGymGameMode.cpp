// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "AIGymGameMode.h"
#include "UObject/ConstructorHelpers.h"

#include "Engine/World.h"
#include "GameFramework/PlayerStart.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Classes/Engine/StaticMesh.h"
#include "Public/Rendering/PositionVertexBuffer.h"
#include "Kismet/GameplayStatics.h"

AAIGymGameMode::AAIGymGameMode()
{
	if (ShouldUseCustomSpawning())
	{
		ParsePassedValues();
		ClearExistingSpawnPoints();
		GenerateSpawnPoints(Clusters);
		SpawnBots();
	}

	PlayersSpawned = 0;

	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/AIGym/AIGymCharacter_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// Seamless Travel is not currently supported in SpatialOS [UNR-897]
	bUseSeamlessTravel = false;
}

bool AAIGymGameMode::ShouldUseCustomSpawning()
{
	//TODO: Check if a worker flag or something is passed through the command line
	return true;
}

void AAIGymGameMode::SpawnBots()
{
	if (Clusters > SpawnPoints.Num())
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't spawn bots - the number of clusters (%d) is higher than the existing spawn points (%d)."), Clusters, SpawnPoints.Num());
		return;
	}

	for (int32 i = 0; i < Clusters; i++)
	{
		AActor* SpawnPoint = SpawnPoints[i];

		FVector SpawnLocation = SpawnPoint->GetActorLocation();
		for (int32 j = 0; j < BotsToPlayerRatio; j++)
		{
			SpawnBot(SpawnLocation);
		}
	}
}

void AAIGymGameMode::SpawnBot(FVector SpawnLocation)
{
	// TODO: Spawn a bot at the target location
	UE_LOG(LogTemp, Warning, TEXT("Spawning a bot at %s."), *SpawnLocation.ToString());
}

void AAIGymGameMode::ParsePassedValues()
{
	// TODO: Parse the numbers from either a worker flag or something for Unreal Native
	Density = 1;
	TotalPlayers = 4;
	BotsToPlayerRatio = 2;

	Clusters = TotalPlayers / Density;
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
	int EdgeLength = 5000;
	int Z = 105;

	int SpacingBetweenClusters = FMath::CeilToInt(EdgeLength / FGenericPlatformMath::Sqrt(SpawnPointsNum));

	if (SpacingBetweenClusters > 300)
	{
		UE_LOG(LogTemp, Error, TEXT("The checkout radius is bigger than the spacing between clusters - reduce density or the entity checkout radius."));
	}

	for (int32 x = - (EdgeLength / 2); x < (EdgeLength / 2); x += SpacingBetweenClusters)
	{
		for (int32 y = -(EdgeLength / 2); y < (EdgeLength / 2); y += SpacingBetweenClusters)
		{
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.Owner = this;
			SpawnInfo.Instigator = NULL;
			SpawnInfo.bDeferConstruction = false;

			FVector SpawnLocation = FVector(x, y, Z);
			if (GetWorld() != NULL)
			{
				UE_LOG(LogTemp, Warning, TEXT("Creating a new PlayerStart at location %s."), *SpawnLocation.ToString());
				SpawnPoints.Add(GetWorld()->SpawnActor<APlayerStart>(APlayerStart::StaticClass(), SpawnLocation, FRotator::ZeroRotator, SpawnInfo));
			}

			// Avoid creating more spawn locations than needed due to ceiling of sqrt
			if (SpawnPoints.Num() >= SpawnPointsNum)
			{
				break;
			}
		}
	}

	AStaticMeshActor* Floor = GetFloor();
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
	if (!ShouldUseCustomSpawning())
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

	UE_LOG(LogTemp, Warning, TEXT("Spawning player %d at %s."), PlayerUniqueID, *ChosenSpawnPoint->GetActorLocation().ToString());

	PlayersSpawned++;

	return ChosenSpawnPoint;
}
