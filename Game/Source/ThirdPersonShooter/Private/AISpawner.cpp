// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "AISpawner.h"
#include "EngineUtils.h"
#include "GameFramework/PlayerStart.h"


// Sets default values
AAISpawner::AAISpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called when the game starts or when spawned
void AAISpawner::BeginPlay()
{
	Super::BeginPlay();
	// Set this to prevent ticks from spawning before SpawnInitial is called
	NumSpawned = NumAIToSpawn;
}

void AAISpawner::OnAuthorityGained()
{
	SpawnInitial();
}

void AAISpawner::SpawnInitial()
{
	for (TActorIterator<APlayerStart> Itr(GetWorld()); Itr; ++Itr)
	{
		SpawnPoints.Add(Itr->GetActorTransform());
	}

	NumSpawned = 0;
}

// Called every frame
void AAISpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (NumSpawned >= NumAIToSpawn)
	{
		return;
	}

	SecondsSinceLastSpawn += DeltaTime;
	if (SecondsSinceLastSpawn < MinSecondsBetweenSpawns)
	{
		return;
	}

	FActorSpawnParameters SpawnParams;
	int spawnPointIndex = FMath::RandRange(0, SpawnPoints.Num() - 1);

	GetWorld()->SpawnActor<ACharacter>(AICharacterTemplate, SpawnPoints[spawnPointIndex], SpawnParams);

	SecondsSinceLastSpawn = 0;
	NumSpawned++;
}

