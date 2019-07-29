// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"
#include "AIGymNPC.generated.h"

UCLASS()
class THIRDPERSONSHOOTER_API AAIGymNPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIGymNPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Used for timing when the fake client will change the direction it is moving
	FTimerHandle TimerHandler;

	// Called to change the direction the character is running to the right
	void TurnRight();

	int DirectionIndex = 0;
	const FVector Directions[4] = { FVector(1, 0, 0), FVector(0, 1, 0), FVector(-1, 0, 0), FVector(0, -1, 0) };

	// Magnitude multiplier used on movement impulses
	float Speed = 0.5f;
};
