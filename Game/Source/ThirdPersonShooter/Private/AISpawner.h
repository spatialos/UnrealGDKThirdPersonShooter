// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "AISpawner.generated.h"

UCLASS(SpatialType = (Singleton, ServerOnly))
class AAISpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAISpawner();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnAuthorityGained() override;

	void SpawnInitial();
	void UpdateParameters();
	void SpawnActor();

	UPROPERTY(EditInstanceOnly)
	int NumAIToSpawn;

	UPROPERTY(EditInstanceOnly)
	float MinSecondsBetweenSpawns = 2.0f;

	UPROPERTY(EditInstanceOnly)
	// When set to 0 doesn't update parameters
	float UpdateParametersIntervalSeconds = 0.f;

	UPROPERTY(EditInstanceOnly)
	TSubclassOf<ACharacter> AICharacterTemplate;

	bool bCanSpawn;
	bool bSpawningEnabled;
private:
	TArray<FTransform> SpawnPoints;
	TArray<ACharacter*> AICharacterHandles;

	int NumSpawned = 0;
	float SecondsSinceLastSpawn = 0.f;
	float SecondsSinceLastUpdateParameters = 0.f;
};
