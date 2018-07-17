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

	void AddKill(ESampleGameTeam Team, const FString& Killer);

	void RegisterScoreChangeListener(FSGTeamScoresUpdatedDelegate Callback);

	const TArray<FTeamScore>& GetTeamScores() { return TeamScores; }

protected:
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UFUNCTION()
	void OnRep_TeamScores();

	FTeamScore* GetScoreForTeam(ESampleGameTeam Team);

	UPROPERTY(ReplicatedUsing = OnRep_TeamScores)
	TArray<FTeamScore> TeamScores;

	FSGTeamScoresUpdatedDelegate TeamScoresUpdatedCallback;

};
