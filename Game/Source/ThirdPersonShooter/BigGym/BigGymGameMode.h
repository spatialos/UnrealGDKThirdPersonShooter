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

	// Custom spawning - density controls
	int32 TotalPlayers;
	int32 PlayerDensity;
	int32 PlayersSpawned;
	float PlayerCheckoutRadius;
	TArray<AActor*> SpawnPoints;
	TMap<int32, AActor*> PlayerIdToSpawnPointMap;
	virtual void InitGameState() override;
	bool ShouldUseCustomSpawning();
	void ParsePassedValues();
	void ClearExistingSpawnPoints();
	// Generates a grid of points centered at (0, 0), as square-like as possible. A row has a fixed y-value, and a column a fixed x-value.
	void GenerateGridSettings(int DistBetweenPoints, int NumPoints, int& NumRows, int& NumCols, int& MinRelativeX, int& MinRelativeY);
	void GenerateSpawnPointClusters(int NumClusters, TArray<AActor*>& SpawnPoints);
	void GenerateSpawnPoints(int CenterX, int CenterY, int SpawnPointsNum, TArray<AActor*>& SpawnPoints);
};
