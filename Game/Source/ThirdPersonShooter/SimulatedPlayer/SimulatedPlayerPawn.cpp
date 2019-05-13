// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SimulatedPlayerPawn.h"
#include "TPSLogging.h"


// Sets default values
ASimulatedPlayerPawn::ASimulatedPlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASimulatedPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTPS, Log, TEXT("BeginPlay SimulatedPlayerPawn"));
}

// Called every frame
void ASimulatedPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
