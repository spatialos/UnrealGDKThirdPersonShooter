// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SGCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLEGAME_API USGCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	friend class FSavedMove_SGMovement;

	USGCharacterMovementComponent(const FObjectInitializer& ObjectInitializer);

	virtual void UpdateFromCompressedFlags(uint8 Flags) override;

	virtual class FNetworkPredictionData_Client* GetPredictionData_Client() const override;

	void SetSprinting(bool bSprinting);

	UFUNCTION(BlueprintPure, Category = "Sprint")
	bool GetSprinting();

	virtual float GetMaxSpeed() const override;

	virtual float GetMaxAcceleration() const override;

	bool IsMovingForward() const;

	uint8 bWantsToSprint : 1;

private:
	UPROPERTY(EditAnywhere, Category = "Sprint")
	float SprintSpeedMultiplier;

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

	virtual void PrepMoveFor(class ACharacter* Character) override;

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
