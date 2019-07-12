// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "Engine/StaticMeshActor.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AIGymGameMode.generated.h"

UCLASS(minimalapi, SpatialType = (Singleton, ServerOnly))
class AAIGymGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAIGymGameMode();

	//virtual void Tick(float DeltaSeconds) override;

	int32 MaxActorsToReplicate;
	int32 BruhMax;

private:
	int32 Clusters;
	int32 Density;
	int32 TotalPlayers;
	int32 BotsToPlayerRatio;
	int32 PlayersSpawned;

	TArray<AActor*> SpawnPoints;
	TMap<int32, AActor*> PlayerIdToSpawnPointMap;

	bool bHasUpdatedMaxActorsToReplicate = false;

	bool ShouldUseCustomSpawning();

	void SpawnBots();

	void SpawnBot(FVector SpawnLocation);

	void ParsePassedValues();

	void ClearExistingSpawnPoints();

	void GenerateSpawnPoints(int SpawnPointsNum);

	virtual AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName) override;

	AStaticMeshActor* GetFloor();
};
