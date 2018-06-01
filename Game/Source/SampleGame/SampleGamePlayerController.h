// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SampleGamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLEGAME_API ASampleGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASampleGamePlayerController();

	// Updates the health UI with a new value.
	void UpdateHealthUI(int32 NewHealth, int32 MaxHealth);

	// Overrides AController::SetPawn, which should be called on the client and server whenever the controller
	// possesses (or unpossesses) a pawn.
	virtual void SetPawn(APawn* InPawn) override;

private:
	// UI class to draw in-game.
	UPROPERTY(EditAnywhere, Category = "SampleGameUI")
	TSubclassOf<class USampleGameUI> UITemplate;

	// The current game UI.
	UPROPERTY(Transient)
	class USampleGameUI* SampleGameUI;

};
