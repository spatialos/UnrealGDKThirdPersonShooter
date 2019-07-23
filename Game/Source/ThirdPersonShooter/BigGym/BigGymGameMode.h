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
	int32 PlayersSpawned;
	float PlayerCheckoutRadius;
	TArray<AActor*> SpawnPoints;
	TMap<int32, AActor*> PlayerIdToSpawnPointMap;
	virtual void InitGameState() override;
	bool ShouldUseCustomSpawning();
	void ParsePassedValues();
	void ClearExistingSpawnPoints();
	void GenerateSpawnPoints(int SpawnPointsNum);
};
