// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "ScaleTestableCharacter.h"
#include "c_worker.h"
#include "Misc/Parse.h"
#include "PlatformTime.h"
#include "Stats/Stats2.h"
#include "SpatialNetDriver.h"
#include "SpatialWorkerConnection.h"

// Sets default values
AScaleTestableCharacter::AScaleTestableCharacter(
    const FObjectInitializer& ObjectInitializer) : ACharacter(ObjectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance
	// if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AScaleTestableCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (FParse::Param(FCommandLine::Get(), TEXT("simulatedplayer")))
	{
		bIsSimulatedPlayer = true;
	}

	GetWorldTimerManager().SetTimer(TimerHandler, this, &AScaleTestableCharacter::TurnRight, 1.0f,
									true, 0.0f);
}

// Called every frame
void AScaleTestableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsSimulatedPlayer)
    {
		AddMovementInput(Directions[DirectionIndex] * Speed);
	}
}

void AScaleTestableCharacter::TurnRight()
{
	DirectionIndex++;
	if (DirectionIndex >= 4)
	{
		DirectionIndex = 0;
	}
}
