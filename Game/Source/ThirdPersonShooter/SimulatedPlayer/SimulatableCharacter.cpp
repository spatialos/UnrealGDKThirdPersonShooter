// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SimulatableCharacter.h"
#include "c_worker.h"
#include "EngineClasses/SpatialGameInstance.h"
#include "Engine/World.h"
#include "Misc/Parse.h"
#include "SimulatedPlayer.h"
#include "SpatialWorkerConnection.h"
#include "Stats/Stats2.h"
#include "TPSLogging.h"

// Sets default values
ASimulatableCharacter::ASimulatableCharacter(
    const FObjectInitializer& ObjectInitializer) : ACharacter(ObjectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance
	// if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASimulatableCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (IsSimulatedCharacter())
	{
		UE_LOG(LogTPS, Log, TEXT("Starting a simulated player"));
	}
}

// Called every frame
void ASimulatableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ASimulatableCharacter::IsSimulatedCharacter()
{
	return bForceSimulatedCharacter || USimulatedPlayer::IsSimulatedPlayer();
}
