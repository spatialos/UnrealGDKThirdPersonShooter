// Copyright (c) Improbable Worlds Ltd, All Rights Reserved


#include "AIGymNPC.h"

// Sets default values
AAIGymNPC::AAIGymNPC()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIGymNPC::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandler, this, &AAIGymNPC::TurnRight, 1.0f, true, 0.0f);
}

// Called every frame
void AAIGymNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddMovementInput(Directions[DirectionIndex] * Speed);
}

void AAIGymNPC::TurnRight()
{
	DirectionIndex++;
	if (DirectionIndex >= 4)
	{
		DirectionIndex = 0;
	}
}
