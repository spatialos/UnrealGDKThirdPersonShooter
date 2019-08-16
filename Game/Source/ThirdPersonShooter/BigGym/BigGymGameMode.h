// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BigGymGameMode.generated.h"

UCLASS(minimalapi, SpatialType=(Singleton, ServerOnly))
class ABigGymGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABigGymGameMode();

	//virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditDefaultsOnly, Category = "Spatial Networking")
	int32 MaxActorsToReplicate;

	// NOTE : This is an override of a BlueprintNativeEvent, not an RPC
	// Return the specific player start actor that should be used for the next spawn
	// This will either use a specified startactor, if it matches Player's team affiliation,
	// or calls ChoosePlayerStart to select a startactor matching Player's team affiliation.
	virtual AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName = TEXT("")) override;

private:
	bool bHasUpdatedMaxActorsToReplicate = false;

	// Custom density spawning parameters.
	bool bInitializedCustomSpawnParameters = false;
	// Total number of players that will connect. Used to determine number of clusters and spawn points to create.
	int32 TotalPlayers;
	// Number of players per cluster. Players only see other players in the same cluster.
	// Number of generated clusters is Ceil(TotalPlayers / PlayerDensity)
	int32 PlayerDensity;
	// NPCs will be spread out evenly over the created player clusters.
	int32 TotalNPCs;
	int32 NumPlayerClusters;
	int32 PlayersSpawned;
	float PlayerCheckoutRadius;
	TArray<AActor*> SpawnPoints;
	TSubclassOf<APawn> NPCPawnClass;
	TMap<int32, AActor*> PlayerIdToSpawnPointMap;
	bool ShouldUseCustomSpawning();
	void CheckInitCustomSpawning();
	void ParsePassedValues();
	void ClearExistingSpawnPoints();
	void SpawnNPCs(int NumNPCs);
	void SpawnNPC(FVector SpawnLocation);
	// Generates a grid of points centered at (0, 0), as square-like as possible. A row has a fixed y-value, and a column a fixed x-value.
	void GenerateGridSettings(int DistBetweenPoints, int NumPoints, int& NumRows, int& NumCols, int& MinRelativeX, int& MinRelativeY);
	void GenerateSpawnPointClusters(int NumClusters);
	void GenerateSpawnPoints(int CenterX, int CenterY, int SpawnPointsNum);
};
