// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/GameStateBase.h"
#include "Teams/SampleGameTeams.h"
#include "Teams/SGTeamScores.h"
#include "SGGameState.generated.h"


DECLARE_DELEGATE_OneParam(FSGTeamScoresUpdatedDelegate, const TArray<FTeamScore>&);

UCLASS()
class SAMPLEGAME_API ASGGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:	
	ASGGameState();

	void FakeServerHasBegunPlay();

	// TODO: this needs to be a reliable worker-to-worker RPC
	// Adds a player to the game's score data with empty stats.
	void AddPlayer(ESampleGameTeam Team, const FString& Player);

	// TODO: this needs to be a reliable worker-to-worker RPC
	// Adds a kill to the game's score data.
	void AddKill(ESampleGameTeam KillerTeam, const FString& Killer, ESampleGameTeam VictimTeam, FString& Victim);

	// [client] Registers a listener for changes in the scoreboard.
	void RegisterScoreChangeListener(FSGTeamScoresUpdatedDelegate Callback);

protected:
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UFUNCTION()
	void OnRep_TeamScores();

	// Retrieves the FTeamScore value for a given team, or nullptr if the team is invalid (or the scores haven't been initialized yet).
	FTeamScore* GetScoreForTeam(ESampleGameTeam Team);

	// Actually adds the player.
	void AddPlayerImpl(ESampleGameTeam Team, const FString& Player);

	// List of teams' scores, including top player lists.
	UPROPERTY(ReplicatedUsing = OnRep_TeamScores)
	TArray<FTeamScore> TeamScores;

	// A map from player name to score, to make it easier to refer to players.
	TMap<FName, FPlayerScore*> PlayerScores;

	FSGTeamScoresUpdatedDelegate TeamScoresUpdatedCallback;

};
