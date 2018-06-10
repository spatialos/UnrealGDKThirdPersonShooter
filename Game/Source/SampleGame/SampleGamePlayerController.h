// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SampleGameTeams.h"
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

	virtual void EndPlay(const EEndPlayReason::Type Reason) override;

	// Updates the health UI with a new value.
	void UpdateHealthUI(int32 NewHealth, int32 MaxHealth);

	// Overrides AController::SetPawn, which should be called on the client and server whenever the controller
	// possesses (or unpossesses) a pawn.
	virtual void SetPawn(APawn* InPawn) override;

	// [server] Tells the controller that it's time for the player to die.
	void KillCharacter();

	// [client] Sets whether the player UI should be visible.
	void SetPlayerUIVisible(bool bIsVisible);

	// Sets the player-choice data (name, team, etc) and requests to spawn player pawn and join play
	UFUNCTION(Server, Reliable, WitHValidation)
	void ServerTryJoinGame(const FString& NewPlayerName, const ESampleGameTeam NewPlayerTeam);

private:
	// [server] Causes the character to respawn.
	void RespawnCharacter();

	// [server] Deletes the character.
	void DeleteCharacter();

	// UI class to draw in-game.
	UPROPERTY(EditAnywhere, Category = "SampleGameUI")
	TSubclassOf<class USampleGameUI> UITemplate;

	// The current game UI.
	UPROPERTY(Transient)
	class USampleGameUI* SampleGameUI;

	// Character respawn delay, in seconds.
	UPROPERTY(EditDefaultsOnly, Category = "Respawn")
	float RespawnCharacterDelay;

	// Time for which to keep the character's body around before deleting it.
	UPROPERTY(EditDefaultsOnly, Category = "Respawn")
	float DeleteCharacterDelay;

	// Pawn to be deleted when the DeletePawn timer expires.
	class APawn* PawnToDelete;

	FTimerHandle RespawnTimerHandle;
	FTimerHandle DeleteCharacterTimerHandle;

};
