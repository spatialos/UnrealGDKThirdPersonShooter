// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SimulatedNavMovementComponent.h"
#include "SimulatedPlayerPawn.h"
#include "TPSLogging.h"


// Sets default values for this component's properties
USimulatedNavMovementComponent::USimulatedNavMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void USimulatedNavMovementComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void USimulatedNavMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Initialise controlled player if not done already.
	if (ControlledPlayer == nullptr)
	{
		ASimulatedPlayerPawn* owner = Cast<ASimulatedPlayerPawn>(GetOwner());
		if (owner == nullptr) {
			UE_LOG(LogTPS, Warning, TEXT("Cannot get ControlledPlayer from owner, owner is not a SimulatedPlayerPawn"));
			return;
		}

		auto ControlledPlayerInOwner = owner->ControlledPlayer;
		if (ControlledPlayerInOwner == nullptr)
		{
			UE_LOG(LogTPS, Warning, TEXT("Cannot set ControlledPlayer, ControlledPlayer in owner is null"));
			return;
		}

		ControlledPlayer = ControlledPlayerInOwner;
	}
}

void USimulatedNavMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	if (ControlledPlayer != nullptr)
	{
		// Redirect move request to ControlledPlayer
		ControlledPlayer->AddMovementInput(MoveVelocity, 1.0f, bForceMaxSpeed);
	}
}

void USimulatedNavMovementComponent::RequestPathMove(const FVector& MoveInput)
{
	if (ControlledPlayer != nullptr)
	{
		// Redirect move request to ControlledPlayer
		ControlledPlayer->AddMovementInput(MoveInput);
	}
}
