// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "AISpawner.h"
#include "EngineUtils.h"
#include "GameFramework/PlayerStart.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Interop/SpatialWorkerFlags.h"
#include "Engine/Engine.h"
#include "NavigationSystem.h"

// Sets default values
AAISpawner::AAISpawner()
{
	// This actor only ticks in the authoritative server
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	// An entity is needed so that the correct server gains authority
	bReplicates = true;

	bSpawningEnabled = false;

	NumSpawned = 0;
	SecondsSinceLastSpawn = 0.f;
	SecondsSinceLastUpdateParameters = 0.f;
}

// Called when the game starts or when spawned
void AAISpawner::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("AISpawner BeginPlay"));
	Super::BeginPlay();

	NumSpawned = 0;
	SecondsSinceLastSpawn = 0.f;
	SecondsSinceLastUpdateParameters = 0.f;
}

void AAISpawner::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AAISpawner, HasCompletedSpawning);
}

void AAISpawner::OnAuthorityGained()
{
	SpawnInitial();
	SetActorTickEnabled(true);

	// force parameters update so that spawning starts with correct data
	if (UpdateParametersIntervalSeconds > 0)
	{
		UpdateParameters();
	}

	PrintParameters();

	Super::OnAuthorityGained();
}

void AAISpawner::SpawnInitial()
{
	UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());

	for (TActorIterator<APlayerStart> Itr(GetWorld()); Itr; ++Itr)
	{
		FNavLocation SpawnPointOnNavMesh;
		if (NavSys->GetRandomPointInNavigableRadius(Itr->GetActorLocation(), 1000.f, SpawnPointOnNavMesh))
		{
			SpawnPointOnNavMesh.Location.Z += 35;
			SpawnPoints.Add(SpawnPointOnNavMesh.Location);
		}
	}

	bCanSpawn = SpawnPoints.Num() > 0;
	bSpawningEnabled = true;

	UE_LOG(LogTemp, Warning, TEXT("AISpawner initialised using %d points"), SpawnPoints.Num());
}

void AAISpawner::PrintParameters()
{
	UE_LOG(LogTemp, Warning, TEXT("AISpawner parameters:"));
	UE_LOG(LogTemp, Warning, TEXT("  bSpawningEnabled = %s"), bSpawningEnabled ? TEXT("true") : TEXT("false"));
	UE_LOG(LogTemp, Warning, TEXT("  MinSecondsBetweenSpawns = %f"), MinSecondsBetweenSpawns);
	UE_LOG(LogTemp, Warning, TEXT("  NumAIToSpawn = %d"), NumAIToSpawn);
}

void AAISpawner::UpdateParameters()
{
	SecondsSinceLastUpdateParameters = 0;

	FString FlagValue;

	USpatialWorkerFlags::GetWorkerFlag("ai_spawning_enabled", FlagValue);
	bSpawningEnabled = FlagValue.ToBool();

	USpatialWorkerFlags::GetWorkerFlag("ai_min_seconds_between_spawns", FlagValue);
	MinSecondsBetweenSpawns = FCString::Atof(*FlagValue);

	USpatialWorkerFlags::GetWorkerFlag("ai_num_to_spawn", FlagValue);
	NumAIToSpawn = FCString::Atoi(*FlagValue);
}

void AAISpawner::SpawnActor()
{
	SecondsSinceLastSpawn = 0;

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	int SpawnPointIndex = FMath::RandRange(0, SpawnPoints.Num() - 1);

	APawn* SpawnedActor = GetWorld()->SpawnActor<APawn>(AICharacterTemplate, SpawnPoints[SpawnPointIndex], FRotator::ZeroRotator, SpawnParams);
	if (!SpawnedActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("AISpawner: Failed to spawn actor. NumSpawned will not be incremented so this will be retried"));
		return;
	}

	AICharacterHandles.Push(SpawnedActor);

	NumSpawned++;
}

void AAISpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SecondsSinceLastSpawn += DeltaTime;
	SecondsSinceLastUpdateParameters += DeltaTime;

	if (UpdateParametersIntervalSeconds > 0 && SecondsSinceLastUpdateParameters > UpdateParametersIntervalSeconds)
	{
		UpdateParameters();
	}

	if (NumSpawned == NumAIToSpawn)
	{
		HasCompletedSpawning = true;
		StartStat();
		return;
	}

	// batch clean up
	while (NumSpawned > NumAIToSpawn && AICharacterHandles.Num() > 0)
	{
		if (APawn* ActorToRemove = AICharacterHandles.Pop())
		{
			GetWorld()->DestroyActor(ActorToRemove);
			NumSpawned--;
		}
	}
	
	// interval based spawning
	if (bCanSpawn && bSpawningEnabled && NumSpawned < NumAIToSpawn && SecondsSinceLastSpawn >= MinSecondsBetweenSpawns)
	{
		SpawnActor();
	}
}

void AAISpawner::StartStat()
{
	if (bStatStarted)
	{
		return;
	}

	bStatStarted = true;

	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		FString FlagValue;
		USpatialWorkerFlags::GetWorkerFlag("stat_duration", FlagValue);
		float StatDuration = FCString::Atof(*FlagValue);

		UE_LOG(LogTemp, Warning, TEXT("AISpawner: Requested stat duration: %f"), StatDuration);
		if (StatDuration > 0.f)
		{
			float WorldSeconds = UGameplayStatics::GetRealTimeSeconds(World); // the time it took to spawn all AI
			float ScenarioLifetime = 600; // this is configured in the scenario JSON
			float SafetyBufferSeconds = 60; // need to make sure stat file is saved before deployment stops
			float TimeLeft = ScenarioLifetime - WorldSeconds - SafetyBufferSeconds;
			if (TimeLeft < StatDuration)
			{
				StatDuration = TimeLeft;
				UE_LOG(LogTemp, Warning, TEXT("AISpawner: stat duration override to %f"), StatDuration);
			}

			UE_LOG(LogTemp, Warning, TEXT("Executing startfile at %f"), WorldSeconds);
			GEngine->Exec(World, TEXT("Stat StartFile"));

			World->GetTimerManager().SetTimer(StatTimer, this, &AAISpawner::StopStat, StatDuration, false);
		}
	}
}

void AAISpawner::StopStat()
{
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Executing stopfile"));
		GEngine->Exec(World, TEXT("Stat StopFile"));
	}
}

void AAISpawner::OnRep_HasCompletedSpawning()
{
	if (HasCompletedSpawning)
	{
		StartStat();
	}
}

