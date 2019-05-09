// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "AISpawner.generated.h"

UCLASS(SpatialType = (Singleton, ServerOnly), WorkerAssociation = "UnrealWorker")
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

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void SpawnInitial();
	void UpdateParameters();
	void SpawnActor();
	void PrintParameters();

	UPROPERTY(EditInstanceOnly)
	int NumAIToSpawn;

	UPROPERTY(EditInstanceOnly)
	float MinSecondsBetweenSpawns = 2.0f;

	UPROPERTY(EditInstanceOnly)
	// When set to 0 doesn't update parameters
	float UpdateParametersIntervalSeconds = 0.f;

	UPROPERTY(EditInstanceOnly)
	TSubclassOf<APawn> AICharacterTemplate;

	bool bCanSpawn;
	bool bSpawningEnabled;
private:
	TArray<FVector> SpawnPoints;
	TArray<APawn*> AICharacterHandles;

	UPROPERTY(ReplicatedUsing = OnRep_HasCompletedSpawning)
	bool HasCompletedSpawning;

	UFUNCTION()
	void OnRep_HasCompletedSpawning();

	int NumSpawned = 0;
	float SecondsSinceLastSpawn = 0.f;
	float SecondsSinceLastUpdateParameters = 0.f;

	bool bStatStarted;
	void StartStat();
	void StopStat();
	FTimerHandle StatTimer;
};
