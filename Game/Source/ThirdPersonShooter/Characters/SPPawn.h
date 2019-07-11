// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SPPawn.generated.h"

UCLASS()
class THIRDPERSONSHOOTER_API ASPPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASPPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// The character this pawn controls. Pawn must be attached to this player.
	UPROPERTY(BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	ACharacter* ControlledPlayer;
	
};
