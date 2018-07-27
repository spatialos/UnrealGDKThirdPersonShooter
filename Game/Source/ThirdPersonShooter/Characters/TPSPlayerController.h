// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Teams/TPSTeams.h"
#include "TPSPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API ATPSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATPSPlayerController();

	virtual void EndPlay(const EEndPlayReason::Type Reason) override;

	// Updates the health UI with a new value.
	void UpdateHealthUI(int32 NewHealth, int32 MaxHealth);

	// Overrides AController::SetPawn, which should be called on the client and server whenever the controller
	// possesses (or unpossesses) a pawn.
	virtual void SetPawn(APawn* InPawn) override;

	// [server] Tells the controller that it's time for the player to die, and sets up conditions for respawn.
	// @param Killer  The player who killed me. Can be null if it wasn't a player who dealt the damage that killed me.
	void KillCharacter(const class ATPSCharacter* Killer);

	// [client] Sets whether the player UI should be visible.
	void SetPlayerUIVisible(bool bIsVisible);

	// [client] Sets whether the scoreboard should be visible.
	void SetScoreboardIsVisible(bool bIsVisible);

	// [client] Sets whether the cursor is in "UI mode", meaning it is visible and can be moved around the screen,
	// instead of locked, invisible, and used for aiming.
	void SetUIMode(bool bIsUIMode, bool bAllowMovement = false);

	// [client] Sets whether we should ignore action input. For this to work properly, the character
	// must check the result of IgnoreActionInput before applying any action inputs.
	void SetIgnoreActionInput(bool bIgnoreInput) { bIgnoreActionInput = bIgnoreInput; }

	// [client] If true, action input should be ignored. This should be called from the character, or any other object
	// which handles user input.
	bool IgnoreActionInput() const { return bIgnoreActionInput; }

	// [client] Sets the player-choice data (name, team, etc) and requests to spawn player pawn and join play.
	// Will populate "NewPlayerName" with a default value if empty.
	void TryJoinGame(const FString& NewPlayerName, const ETPSTeam NewPlayerTeam);

protected:
	virtual void SetupInputComponent() override;

private:
	// Sets the player-choice data (name, team, etc) and requests to spawn player pawn and join play
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerTryJoinGame(const FString& NewPlayerName, const ETPSTeam NewPlayerTeam);

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

	// [client] Shows the scoreboard UI.
	void ShowScoreboard();

	// [client] Hides the scoreboard UI.
	void HideScoreboard();

	// Gets a default player name based upon the worker's ID.
	// Generates a GUID if we're not running on a SpatialOS worker.
	FString GetDefaultPlayerName();

	// If true, action input should be ignored.
	// Default value is false.
	bool bIgnoreActionInput;

	// UI class to draw in-game.
	UPROPERTY(EditAnywhere, Category = "SampleGameUI")
	TSubclassOf<class UTPSUI> UITemplate;

	// The current game UI.
	UPROPERTY(Transient)
	class UTPSUI* SampleGameUI;

	// Scoreboard UI class to use in-game.
	UPROPERTY(EditAnywhere, Category = "SampleGameUI")
	TSubclassOf<class UTPSScoreboard> ScoreboardTemplate;

	// The current scoreboard UI widget instance.
	UPROPERTY(Transient)
	class UTPSScoreboard* Scoreboard;

	// Login UI class template to load at player join.
	UPROPERTY(EditDefaultsOnly, Category = "SampleGameUI")
	TSubclassOf<class UTPSLoginUI> LoginUIWidgetTemplate;

	// The instance of the Login UI class to allow player choice interaction.
	UPROPERTY(Transient)
	class UTPSLoginUI* SampleGameLoginUI;

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

// HACK for login state (Unreal issue, not GDK issue)
//=================================================//
public:
	virtual void Tick(float DeltaSeconds) override;
private:
	bool bHasShownLoginHud = false;
	bool bHasSubmittedLoginOptions = false;
//=================================================//
};
