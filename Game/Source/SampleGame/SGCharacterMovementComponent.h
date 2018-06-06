// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SGCharacterMovementComponent.generated.h"

UCLASS()
class SAMPLEGAME_API USGCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	friend class FSavedMove_SGMovement;

	USGCharacterMovementComponent(const FObjectInitializer& ObjectInitializer);

	virtual void UpdateFromCompressedFlags(uint8 Flags) override;

	virtual class FNetworkPredictionData_Client* GetPredictionData_Client() const override;

	// Returns true if the character is trying to sprint.
	void SetWantsToSprint(bool bSprinting);

	// Returns true if the character is actually sprinting.
	UFUNCTION(BlueprintPure, Category = "Sprint")
	bool IsSprinting() const;

	// Returns the max speed of the character, modified if sprinting.
	virtual float GetMaxSpeed() const override;

	// Returns the max acceleration of the character, modified if sprinting.
	virtual float GetMaxAcceleration() const override;

	// True if movement direction is within SprintDirectionTolerance of the look direction.
	bool IsMovingForward() const;

private:
	uint8 bWantsToSprint : 1;

	// Multiply max speed by this factor when sprinting.
	UPROPERTY(EditAnywhere, Category = "Sprint")
	float SprintSpeedMultiplier;

	// Multiply acceleration by this factor when sprinting.
	UPROPERTY(EditAnywhere, Category = "Sprint")
	float SprintAccelerationMultiplier;

	// Tolerance between forward and move direction within which the character can sprint.
	// Represents the minimum magnitude of the dot product between the vectors.
	UPROPERTY(EditAnywhere, Category = "Sprint")
	float SprintDirectionTolerance;
};

class FSavedMove_SGMovement : public FSavedMove_Character
{
public:
	typedef FSavedMove_Character Super;

	virtual void Clear() override;

	virtual uint8 GetCompressedFlags() const override;

	virtual bool CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InPawn, float MaxDelta) const override;

	virtual void SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, class FNetworkPredictionData_Client_Character& ClientData) override;

private:
	uint8 bSavedWantsToSprint : 1;
};

class FNetworkPredictionData_Client_SGMovement : public FNetworkPredictionData_Client_Character
{
public:
	FNetworkPredictionData_Client_SGMovement(const UCharacterMovementComponent& ClientMovement);

	typedef FNetworkPredictionData_Client_Character Super;

	virtual FSavedMovePtr AllocateNewMove() override;
};
