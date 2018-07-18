// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Teams/SampleGameTeams.h"
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

	// [server] Tells the controller that it's time for the player to die, and sets up conditions for respawn.
	// @param Killer  The player who killed me. Can be null if it wasn't a player who dealt the damage that killed me.
	void KillCharacter(const class ASampleGameCharacter* Killer);

	// [client] Sets whether the player UI should be visible.
	void SetPlayerUIVisible(bool bIsVisible);

	// [client] Sets whether the scoreboard should be visible.
	void SetScoreboardIsVisible(bool bIsVisible);

	// [client] Sets whether the cursor is in "UI mode", meaning it is visible and can be moved around the screen,
	// instead of locked, invisible, and used for aiming.
	void SetCursorUIMode(bool bIsUIMode);

	// Sets the player-choice data (name, team, etc) and requests to spawn player pawn and join play
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerTryJoinGame(const FString& NewPlayerName, const ESampleGameTeam NewPlayerTeam);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> & OutLifetimeProps) const;

private:
	// [client] Informs the invoking client whether the join request suceeded or failed
	UFUNCTION(Client, Reliable)
	void ClientJoinResults(const bool bJoinSucceeded);

	// [server] Causes the character to respawn.
	void RespawnCharacter();

	// [server] Deletes the character.
	void DeleteCharacter();

	// [client] Sets whether or not the login UI should be visible.
	void SetLoginUIVisible(bool bIsVisible);

	// [client] Initializes the scoreboard UI.
	void InitScoreboard();

	// UI class to draw in-game.
	UPROPERTY(EditAnywhere, Category = "SampleGameUI")
	TSubclassOf<class USampleGameUI> UITemplate;

	// The current game UI.
	UPROPERTY(Transient)
	class USampleGameUI* SampleGameUI;

	// Scoreboard UI class to use in-game.
	UPROPERTY(EditAnywhere, Category = "SampleGameUI")
	TSubclassOf<class USampleGameScoreboard> ScoreboardTemplate;

	// The current scoreboard UI widget instance.
	UPROPERTY(Transient)
	class USampleGameScoreboard* Scoreboard;

	// Login UI class template to load at player join.
	UPROPERTY(EditDefaultsOnly, Category = "SampleGameUI")
	TSubclassOf<class USampleGameLoginUI> LoginUIWidgetTemplate;

	// The instance of the Login UI class to allow player choice interaction.
	UPROPERTY(Transient)
	class USampleGameLoginUI* SampleGameLoginUI;

	// Character respawn delay, in seconds.
	UPROPERTY(EditDefaultsOnly, Category = "Respawn")
	float RespawnCharacterDelay;

	// Time for which to keep the character's body around before deleting it.
	UPROPERTY(EditDefaultsOnly, Category = "Respawn")
	float DeleteCharacterDelay;

	// TODO: remove this
	UPROPERTY(Replicated)
	class ASGGameState* CustomGameState;

	// Pawn to be deleted when the DeletePawn timer expires.
	class APawn* PawnToDelete;

	FTimerHandle RespawnTimerHandle;
	FTimerHandle DeleteCharacterTimerHandle;

// HACK for login state (Unreal issue, not GDK issue)
//=================================================//
public:
	virtual void Tick(float DeltaSeconds) override;
private:
	bool bHasShownLoginHud = false;
	bool bHasSubmittedLoginOptions = false;
//=================================================//
};
