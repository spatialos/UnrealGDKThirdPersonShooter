// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "Characters/TPSCharacterMovementComponent.h"

#include "Characters/TPSCharacter.h"
#include "GameFramework/Character.h"

// Use the first custom movement flag slot in the character for sprinting.
static const FSavedMove_Character::CompressedFlags FLAG_WantsToSprint = FSavedMove_TPSMovement::FLAG_Custom_0;

UTPSCharacterMovementComponent::UTPSCharacterMovementComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SprintSpeedMultiplier(1.5f)
	, SprintAccelerationMultiplier(1.5f)
	, SprintDirectionTolerance(0.7f)
	, bShouldOrientToControlRotation(false)
{}

void UTPSCharacterMovementComponent::UpdateFromCompressedFlags(uint8 Flags)
{
	Super::UpdateFromCompressedFlags(Flags);

	// Extract saved state from Flags and apply it to our local variables.
	bWantsToSprint = (Flags & FLAG_WantsToSprint) != 0;
}

class FNetworkPredictionData_Client* UTPSCharacterMovementComponent::GetPredictionData_Client() const
{
	check(PawnOwner != nullptr);
	check(PawnOwner->Role < ROLE_Authority);

	if (!ClientPredictionData)
	{
		UTPSCharacterMovementComponent* MutableThis = const_cast<UTPSCharacterMovementComponent*>(this);

		MutableThis->ClientPredictionData = new FNetworkPredictionData_Client_TPSMovement(*this);
		MutableThis->ClientPredictionData->MaxSmoothNetUpdateDist = NetworkMaxSmoothUpdateDistance;
		MutableThis->ClientPredictionData->NoSmoothNetUpdateDist = NetworkNoSmoothUpdateDistance;
	}

	return ClientPredictionData;
}

void UTPSCharacterMovementComponent::PhysicsRotation(float DeltaTime)
{
	FVector LookForward = PawnOwner->GetActorForwardVector();
	if (ATPSCharacter* Character = Cast<ATPSCharacter>(PawnOwner))
	{
		if (AController* Controller = Character->GetController())
		{
			// Ideally our LookForward vector is the camera's forward vector.
			LookForward = Controller->GetControlRotation().Vector();
		}
	}

	if (Acceleration.SizeSquared() < KINDA_SMALL_NUMBER)
	{
		float ForwardDotLook = FVector::DotProduct(PawnOwner->GetActorForwardVector(), LookForward);
		if (ForwardDotLook < -KINDA_SMALL_NUMBER)
		{
			// If we're standing still and looking more than 90 degrees from the character's forward yaw, pull the character back
			// towards the control rotation.
			bShouldOrientToControlRotation = true;
		}
		else if (ForwardDotLook > 0.9f)
		{
			// If we've just about reached the control rotation, stop pulling.
			bShouldOrientToControlRotation = false;
		}
	}
	else
	{
		// If we've started moving, stop interpolating towards the control rotation.
		bShouldOrientToControlRotation = false;
	}

	Super::PhysicsRotation(DeltaTime);
}

FRotator UTPSCharacterMovementComponent::ComputeOrientToMovementRotation(const FRotator& CurrentRotation, float DeltaTime, FRotator& DeltaRotation) const
{
	FVector LookForward = PawnOwner->GetActorForwardVector();
	if (ATPSCharacter* Character = Cast<ATPSCharacter>(PawnOwner))
	{
		if (AController* Controller = Character->GetController())
		{
			// Ideally our LookForward vector is the camera's forward vector.
			LookForward = Controller->GetControlRotation().Vector();
		}
	}

	if (Acceleration.SizeSquared() < KINDA_SMALL_NUMBER)
	{
		if (bShouldOrientToControlRotation)
		{
			// If we've over-rotated, push the character's rotation back towards the camera rotation.
			return LookForward.GetSafeNormal().Rotation();
		}
		// Don't rotate if there's no acceleration.
		return CurrentRotation;
	}

	// If acceleration is more than 90 degrees (plus a pretty big fudge factor) in either direction of the
	// forward vector (usually the camera direction) then invert the character's forward direction to make
	// it look like it's running backward.
	// Note that this is a tiny bit buggy when the character is running full right and turning the camera to the right,
	// but for now it's a decent solution.
	if (FVector::DotProduct(Acceleration, LookForward) < -0.2)
	{
		return Acceleration.GetSafeNormal().Rotation() + FRotator(0, -180, 0);
	}

	// This is what UCharacterMovementComponent::ComputeOrientToMovementRotation does in the default case.
	return Acceleration.GetSafeNormal().Rotation();
}

void UTPSCharacterMovementComponent::SetWantsToSprint(bool bSprinting)
{
	bWantsToSprint = bSprinting;
}

bool UTPSCharacterMovementComponent::IsSprinting() const
{
	return static_cast<bool>(bWantsToSprint) && IsMovingForward();
}

float UTPSCharacterMovementComponent::GetMaxSpeed() const
{
	float MaxSpeed = Super::GetMaxSpeed();
	if (IsSprinting())
	{
		MaxSpeed *= SprintSpeedMultiplier;
	}
	return MaxSpeed;
}

float UTPSCharacterMovementComponent::GetMaxAcceleration() const
{
	float MaxAcceleration = Super::GetMaxAcceleration();
	if (IsSprinting())
	{
		MaxAcceleration *= SprintAccelerationMultiplier;
	}
	return MaxAcceleration;
}

bool UTPSCharacterMovementComponent::IsMovingForward() const
{
	if (PawnOwner == nullptr)
	{
		return false;
	}

	FVector MoveDirection = Velocity.GetSafeNormal();
	FVector Forward = PawnOwner->GetActorForwardVector();
	if (ATPSCharacter* Character = Cast<ATPSCharacter>(PawnOwner))
	{
		if (AController* PlayerController = Character->GetController())
		{
			// Check move direction against control rotation.
			Forward = PlayerController->GetControlRotation().Vector();
		}
	}

	// Ignore the Z axis for comparison.
	Forward.Z = 0.0f;
	MoveDirection.Z = 0.0f;
	Forward.Normalize();
	MoveDirection.Normalize();

	float VelocityDot = FVector::DotProduct(Forward, MoveDirection);

	return VelocityDot > SprintDirectionTolerance;
}

void FSavedMove_TPSMovement::Clear()
{
	Super::Clear();
	bSavedWantsToSprint = false;
}

uint8 FSavedMove_TPSMovement::GetCompressedFlags() const
{
	uint8 Result = Super::GetCompressedFlags();
	if (bSavedWantsToSprint)
	{
		Result |= FLAG_WantsToSprint;
	}
	return Result;
}

bool FSavedMove_TPSMovement::CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InPawn, float MaxDelta) const
{
	if (bSavedWantsToSprint != ((FSavedMove_TPSMovement*)&NewMove)->bSavedWantsToSprint)
	{
		return false;
	}
	return Super::CanCombineWith(NewMove, InPawn, MaxDelta);
}

void FSavedMove_TPSMovement::SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, class FNetworkPredictionData_Client_Character& ClientData)
{
	Super::SetMoveFor(Character, InDeltaTime, NewAccel, ClientData);

	UTPSCharacterMovementComponent* CharacterMovement = Cast<UTPSCharacterMovementComponent>(Character->GetCharacterMovement());
	if (CharacterMovement)
	{
		bSavedWantsToSprint = CharacterMovement->bWantsToSprint;
	}
}

FNetworkPredictionData_Client_TPSMovement::FNetworkPredictionData_Client_TPSMovement(const UCharacterMovementComponent& ClientMovement)
	: Super(ClientMovement)
{ }

FSavedMovePtr FNetworkPredictionData_Client_TPSMovement::AllocateNewMove()
{
	return FSavedMovePtr(new FSavedMove_TPSMovement());
}

