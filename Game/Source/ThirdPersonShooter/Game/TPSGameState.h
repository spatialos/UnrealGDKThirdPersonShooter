// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/GameStateBase.h"
#include "Teams/TPSTeams.h"
#include "Teams/TPSTeamScores.h"
#include "TPSGameState.generated.h"


DECLARE_DELEGATE_OneParam(FSGTeamScoresUpdatedDelegate, const TArray<FTeamScore>&);

UCLASS()
class THIRDPERSONSHOOTER_API ATPSGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:	
	ATPSGameState();

	// Adds a player to the game's score data with empty stats.
	void AddPlayer(ETPSTeam Team, const FString& Player);

	// Adds a death (and a corresponding kill, if necessary) to the game's score data.
	void AddDeath(const FString& KillerName, ETPSTeam KillerTeam, const FString& VictimName, ETPSTeam VictimTeam);

	// [client] Registers a listener for changes in the scoreboard.
	void RegisterScoreChangeListener(FSGTeamScoresUpdatedDelegate Callback);

protected:
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UFUNCTION()
	void OnRep_TeamScores();

	// Retrieves the FTeamScore value for a given team, or nullptr if the team is invalid (or the scores haven't been initialized yet).
	FTeamScore* GetScoreForTeam(ETPSTeam Team);

	// Actually adds the player.
	void AddPlayerInternal(ETPSTeam Team, const FString& Player);

	// List of teams' scores, including top player lists.
	UPROPERTY(ReplicatedUsing = OnRep_TeamScores)
	TArray<FTeamScore> TeamScores;

	// A map from player name to score, to make it easier to refer to players.
	TMap<FName, FPlayerScore*> PlayerScores;

	FSGTeamScoresUpdatedDelegate TeamScoresUpdatedCallback;

};
