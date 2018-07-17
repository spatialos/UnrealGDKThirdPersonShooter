// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "AAObjectSpawner.h"


// Sets default values
AAObjectSpawner::AAObjectSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	timeAlive = 0.f;

	// set vector and rotator to 0
	rotation.ZeroRotator;
	location.X = 0.f;
	location.Y = 0.f;
	location.Z = 300.f;
}

// Called when the game starts or when spawned
void AAObjectSpawner::BeginPlay()
{
	Super::BeginPlay();

	// debug message to make sure we exist
	
}

// Called every frame
void AAObjectSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	timeAlive++;

	if ((timeAlive > 10.f) && (this->HasAuthority()))
	{
        spawnObject(DeltaTime);

		FString str = FString::SanitizeFloat(timeAlive);

    
		timeAlive = 0.f;
	}
}

float AAObjectSpawner::generateNumInBound(float lowerBound, float upperBound)
{
	return FMath::RandRange(lowerBound, upperBound);
}


void AAObjectSpawner::spawnObject(int DeltaTime)
{
    FActorSpawnParameters spawnParams;

    spawnParams.Owner = this;
    spawnParams.Instigator = Instigator;

	location.X = generateX(DeltaTime);
    location.Y = generateY(DeltaTime);

	AActor *object = GetWorld()->SpawnActor<AActor>(spawningObject, location, rotation, spawnParams);
	object->SetReplicates(true);

}

float AAObjectSpawner::generateX(float deltaSeconds)
{
	return AAObjectSpawner::generateNumInBound(0, 16000) + deltaSeconds;

}


float AAObjectSpawner::generateY(float deltaSeconds)
{
	return AAObjectSpawner::generateNumInBound(0, 16000) + deltaSeconds;
}
