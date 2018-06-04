// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SGCharacterMovementComponent.h"

#include "GameFramework//Character.h"


USGCharacterMovementComponent::USGCharacterMovementComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SprintSpeedMultiplier(1.5f)
	, SprintAccelerationMultiplier(1.5f)
	, SprintDirectionTolerance(0.7f)
{}

void USGCharacterMovementComponent::UpdateFromCompressedFlags(uint8 Flags)
{
	Super::UpdateFromCompressedFlags(Flags);

	// Extract saved state from Flags and apply it to our local variables.
	bWantsToSprint = (Flags & FSavedMove_SGMovement::FLAG_Custom_0) != 0;
}

class FNetworkPredictionData_Client* USGCharacterMovementComponent::GetPredictionData_Client() const
{
	check(PawnOwner != nullptr);
	check(PawnOwner->Role < ROLE_Authority);

	if (!ClientPredictionData)
	{
		USGCharacterMovementComponent* MutableThis = const_cast<USGCharacterMovementComponent*>(this);

		MutableThis->ClientPredictionData = new FNetworkPredictionData_Client_SGMovement(*this);
		MutableThis->ClientPredictionData->MaxSmoothNetUpdateDist = 92.0f;
		MutableThis->ClientPredictionData->NoSmoothNetUpdateDist = 140.0f;
	}

	return ClientPredictionData;
}

void USGCharacterMovementComponent::SetSprinting(bool bSprinting)
{
	bWantsToSprint = bSprinting;
}

bool USGCharacterMovementComponent::GetSprinting()
{
	return static_cast<bool>(bWantsToSprint);
}

float USGCharacterMovementComponent::GetMaxSpeed() const
{
	float MaxSpeed = Super::GetMaxSpeed();
	if (bWantsToSprint && IsMovingForward())
	{
		MaxSpeed *= SprintSpeedMultiplier;
	}
	return MaxSpeed;
}

float USGCharacterMovementComponent::GetMaxAcceleration() const
{
	float MaxAcceleration = Super::GetMaxAcceleration();
	if (bWantsToSprint && IsMovingForward())
	{
		MaxAcceleration *= SprintAccelerationMultiplier;
	}
	return MaxAcceleration;
}

bool USGCharacterMovementComponent::IsMovingForward() const
{
	if (!PawnOwner)
	{
		return false;
	}

	FVector Forward = PawnOwner->GetActorForwardVector();
	FVector MoveDirection = Velocity.GetSafeNormal();

	// Ignore the Z axis for comparison.
	Forward.Z = 0.0f;
	MoveDirection.Z = 0.0f;

	float VelocityDot = FVector::DotProduct(Forward, MoveDirection);
	return VelocityDot > SprintDirectionTolerance;
}

void FSavedMove_SGMovement::Clear()
{
	Super::Clear();
	bSavedWantsToSprint = false;
}

uint8 FSavedMove_SGMovement::GetCompressedFlags() const
{
	uint8 Result = Super::GetCompressedFlags();
	if (bSavedWantsToSprint)
	{
		Result |= FLAG_Custom_0;
	}
	return Result;
}

bool FSavedMove_SGMovement::CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InPawn, float MaxDelta) const
{
	if (bSavedWantsToSprint != ((FSavedMove_SGMovement*)&NewMove)->bSavedWantsToSprint)
	{
		return false;
	}
	return Super::CanCombineWith(NewMove, InPawn, MaxDelta);
}

void FSavedMove_SGMovement::SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, class FNetworkPredictionData_Client_Character& ClientData)
{
	Super::SetMoveFor(Character, InDeltaTime, NewAccel, ClientData);

	USGCharacterMovementComponent* CharacterMovement = Cast<USGCharacterMovementComponent>(Character->GetCharacterMovement());
	if (CharacterMovement)
	{
		bSavedWantsToSprint = CharacterMovement->bWantsToSprint;
	}
}

void FSavedMove_SGMovement::PrepMoveFor(class ACharacter* Character)
{
	Super::PrepMoveFor(Character);

	USGCharacterMovementComponent* CharacterMovement = Cast<USGCharacterMovementComponent>(Character->GetCharacterMovement());
	if (CharacterMovement)
	{

	}
}

FNetworkPredictionData_Client_SGMovement::FNetworkPredictionData_Client_SGMovement(const UCharacterMovementComponent& ClientMovement)
	: Super(ClientMovement)
{ }

FSavedMovePtr FNetworkPredictionData_Client_SGMovement::AllocateNewMove()
{
	return FSavedMovePtr(new FSavedMove_SGMovement());
}

