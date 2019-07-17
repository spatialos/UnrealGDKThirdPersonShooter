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

private:
	int32 Clusters;
	int32 PlayerDensity;
	int32 TotalPlayers;
	int32 NPCsToPlayerRatio;
	int32 PlayersSpawned;

	float PlayerCheckoutRadius;

	TArray<AActor*> SpawnPoints;
	
	TSubclassOf<APawn> NPCPawnClass;

	TMap<int32, AActor*> PlayerIdToSpawnPointMap;

	bool bHasUpdatedMaxActorsToReplicate = false;

	virtual void InitGameState() override;

	bool ShouldUseCustomSpawning();

	void SpawnNPCs();

	void SpawnNPC(FVector SpawnLocation);

	void ParsePassedValues();

	void ClearExistingSpawnPoints();

	void GenerateSpawnPoints(int SpawnPointsNum);

	virtual AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName) override;

	AStaticMeshActor* GetFloor();
};
