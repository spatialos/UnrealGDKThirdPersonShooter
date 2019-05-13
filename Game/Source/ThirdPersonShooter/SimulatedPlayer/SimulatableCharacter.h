// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SimulatableCharacter.generated.h"

UCLASS(config = Game, SpatialType)
class ASimulatableCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASimulatableCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Whether or not this is player is simulated, as determined by SimulatedPlayer.h. 
	// This can be forced to be true by setting bForceSimulatedCharacter to true.
	UFUNCTION(BlueprintCallable)
	bool IsSimulatedCharacter();

	// Can be set to true to force this character to behave as a simulated character,
	// overriding whether this client is actually a simulated player or not.
	// Useful for debugging purposes, but should be turned off when building the actual
	// client worker.
	UPROPERTY(EditDefaultsOnly)
	bool bForceSimulatedCharacter;
};
