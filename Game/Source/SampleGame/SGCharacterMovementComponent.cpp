// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SGCharacterMovementComponent.h"

#include "GameFramework/Character.h"
#include "SampleGameCharacter.h"

// Use the first custom movement flag slot in the character for sprinting.
static const FSavedMove_Character::CompressedFlags FLAG_WantsToSprint = FSavedMove_SGMovement::FLAG_Custom_0;

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
	bWantsToSprint = (Flags & FLAG_WantsToSprint) != 0;
}

class FNetworkPredictionData_Client* USGCharacterMovementComponent::GetPredictionData_Client() const
{
	check(PawnOwner != nullptr);
	check(PawnOwner->Role < ROLE_Authority);

	if (!ClientPredictionData)
	{
		USGCharacterMovementComponent* MutableThis = const_cast<USGCharacterMovementComponent*>(this);

		MutableThis->ClientPredictionData = new FNetworkPredictionData_Client_SGMovement(*this);
		MutableThis->ClientPredictionData->MaxSmoothNetUpdateDist = NetworkMaxSmoothUpdateDistance;
		MutableThis->ClientPredictionData->NoSmoothNetUpdateDist = NetworkNoSmoothUpdateDistance;
	}

	return ClientPredictionData;
}

void USGCharacterMovementComponent::SetWantsToSprint(bool bSprinting)
{
	bWantsToSprint = bSprinting;
}

bool USGCharacterMovementComponent::IsSprinting() const
{
	return static_cast<bool>(bWantsToSprint) && IsMovingForward();
}

float USGCharacterMovementComponent::GetMaxSpeed() const
{
	float MaxSpeed = Super::GetMaxSpeed();
	if (IsSprinting())
	{
		MaxSpeed *= SprintSpeedMultiplier;
	}
	return MaxSpeed;
}

float USGCharacterMovementComponent::GetMaxAcceleration() const
{
	float MaxAcceleration = Super::GetMaxAcceleration();
	if (IsSprinting())
	{
		MaxAcceleration *= SprintAccelerationMultiplier;
	}
	return MaxAcceleration;
}

bool USGCharacterMovementComponent::IsMovingForward() const
{
	if (PawnOwner == nullptr)
	{
		return false;
	}

	FVector MoveDirection = Velocity.GetSafeNormal();
	FVector Forward = PawnOwner->GetActorForwardVector();
	if (ASampleGameCharacter* Character = Cast<ASampleGameCharacter>(PawnOwner))
	{
		// Check move direction against control rotation.
		Forward = Character->GetController()->GetControlRotation().Vector();
	}

	// Ignore the Z axis for comparison.
	Forward.Z = 0.0f;
	MoveDirection.Z = 0.0f;
	Forward.Normalize();
	MoveDirection.Normalize();

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
		Result |= FLAG_WantsToSprint;
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

FNetworkPredictionData_Client_SGMovement::FNetworkPredictionData_Client_SGMovement(const UCharacterMovementComponent& ClientMovement)
	: Super(ClientMovement)
{ }

FSavedMovePtr FNetworkPredictionData_Client_SGMovement::AllocateNewMove()
{
	return FSavedMovePtr(new FSavedMove_SGMovement());
}

