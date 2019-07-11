// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SPMovementComponent.h"
#include "SPPawn.h"


DEFINE_LOG_CATEGORY_STATIC(LogSimPlayer, Log, All);

// Called every frame
void USPMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Initialise controlled player if not done already.
	if (ControlledPlayer == nullptr)
	{
		ASPPawn* owner = Cast<ASPPawn>(GetOwner());
		if (owner == nullptr) {
			UE_LOG(LogSimPlayer, Warning, TEXT("Cannot get ControlledPlayer from owner, owner is not a SimulatedPlayerPawn"));
			return;
		}

		auto ControlledPlayerInOwner = owner->ControlledPlayer;
		if (ControlledPlayerInOwner == nullptr)
		{
			UE_LOG(LogSimPlayer, Warning, TEXT("Cannot set ControlledPlayer, ControlledPlayer in owner is null"));
			return;
		}

		ControlledPlayer = ControlledPlayerInOwner;
	}
}

void USPMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	if (ControlledPlayer != nullptr)
	{
		// Redirect move request to ControlledPlayer
		ControlledPlayer->AddMovementInput(MoveVelocity, 1.0f, bForceMaxSpeed);
	}
}

void USPMovementComponent::RequestPathMove(const FVector& MoveInput)
{
	if (ControlledPlayer != nullptr)
	{
		// Redirect move request to ControlledPlayer
		ControlledPlayer->AddMovementInput(MoveInput);
	}
}
