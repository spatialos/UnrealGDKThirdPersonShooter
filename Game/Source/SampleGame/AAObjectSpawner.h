
// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnedObject.h"
#include "AAObjectSpawner.generated.h"

UCLASS()
class SAMPLEGAME_API AAObjectSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAObjectSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float generateX(float deltaSeconds);
	float generateY(float deltaSeconds);

	float timeAlive;

	// spawn information
	FTransform oldSpawnLocation;

	// spawn location
	FVector location;

	FRotator rotation;

	// holds the blueprints
	UPROPERTY(EditAnywhere, Category = "Spawning object")
	TSubclassOf<AActor> spawningObject;

private:
	float generateNumInBound(float lowerBound, float upperBound);
	void spawnObject(int DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
