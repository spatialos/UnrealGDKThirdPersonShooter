// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Teams/SampleGameTeams.h"
#include "Teams/SGTeamScores.h"
#include "SGGameState.generated.h"


DECLARE_DELEGATE_OneParam(FSGTeamScoresUpdatedDelegate, const TArray<FTeamScore>&);

// TODO: make this a subclass of GameState once its replication is properly handled by the Unreal GDK
UCLASS()
class SAMPLEGAME_API ASGGameState : public AActor
{
	GENERATED_BODY()
	
public:	
	ASGGameState();

	// TODO: this needs to be a reliable worker-to-worker RPC
	// Adds a player to the game's score data with empty stats.
	void AddPlayer(ESampleGameTeam Team, const FString& Player);

	// TODO: this needs to be a reliable worker-to-worker RPC
	void AddKill(ESampleGameTeam KillerTeam, const FString& Killer, const FString& Victim);

	// [client] Registers a listener for changes in the scoreboard.
	void RegisterScoreChangeListener(FSGTeamScoresUpdatedDelegate Callback);

protected:
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UFUNCTION()
	void OnRep_TeamScores();

	FTeamScore* GetScoreForTeam(ESampleGameTeam Team);

	// Actually adds the player.
	void AddPlayerImpl(ESampleGameTeam Team, const FString& Player);

	UPROPERTY(ReplicatedUsing = OnRep_TeamScores)
	TArray<FTeamScore> TeamScores;

	// A map from player name to score, to make it easier to refer to players.
	TMap<FName, FPlayerScore*> PlayerScores;

	FSGTeamScoresUpdatedDelegate TeamScoresUpdatedCallback;

};