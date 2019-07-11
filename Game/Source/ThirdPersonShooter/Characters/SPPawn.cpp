// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SPPawn.h"


// Sets default values
ASPPawn::ASPPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASPPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASPPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASPPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

