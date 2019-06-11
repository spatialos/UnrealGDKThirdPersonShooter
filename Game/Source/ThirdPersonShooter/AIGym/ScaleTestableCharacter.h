// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"
#include "ScaleTestableCharacter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSpatialLatencyTest, Log, All);

UCLASS(config = Game, SpatialType)
class AScaleTestableCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AScaleTestableCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called for forwards/backward input
	void MoveForward(float Value);

	// Called for side to side input
	void MoveRight(float Value);

	// Automatically jump and record a time stamp for latency testing
	void StimulateJump();

	// Automatically shoot and record a time stamp for latency testing
	void StimulateShoot(); 

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// RPC for communicating fake shots to the server.
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerShoot();

	// RPC for notifying clients of fake shots.
	UFUNCTION(NetMulticast, Unreliable)
	void MulticastNotifyHit();

private:
	// Whether or not this is a fake client, to be determined by command line args
	bool bIsSimulatedPlayer = false;

	// Used for timing when the fake client will change the direction it is moving
	FTimerHandle TimerHandler;

	// Called to change the direction the character is running to the right
	void TurnRight();

	int DirectionIndex = 0;
	const FVector Directions[4] = { FVector(1, 0, 0), FVector(0, 1, 0), FVector(-1, 0, 0), FVector(0, -1, 0) };

	// Magnitude multiplier used on movement impulses
	float Speed = 0.5f;

	bool bHasHitGround = false;
};
