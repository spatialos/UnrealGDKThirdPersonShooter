// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/GameFramework/NavMovementComponent.h"
#include "SimulatedNavMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THIRDPERSONSHOOTER_API USimulatedNavMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USimulatedNavMovementComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ACharacter* ControlledPlayer;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Override to send these movement requests to the controlled player
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	virtual void RequestPathMove(const FVector& MoveInput) override;

};
