// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SpawnedObject.h"


// Sets default values
ASpawnedObject::ASpawnedObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetReplicates(true);
}

// Called when the game starts or when spawned
void ASpawnedObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnedObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

