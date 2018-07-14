// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Teams/SampleGameTeams.h"
#include "SGGameState.generated.h"

USTRUCT()
struct FPlayerScore {
	GENERATED_BODY()

	UPROPERTY()
	FString PlayerName;

	UPROPERTY()
	int32 Kills;
};

USTRUCT()
struct FTeamScore {
	GENERATED_BODY()

	UPROPERTY()
	ESampleGameTeam Team;

	UPROPERTY()
	int32 TeamKills;

	UPROPERTY()
	TArray<FPlayerScore> TopPlayers;
};


// TODO: make this a subclass of GameState once its replication is properly handled by the Unreal GDK
UCLASS()
class SAMPLEGAME_API ASGGameState : public AActor
{
	GENERATED_BODY()
	
public:	
	ASGGameState();

	void AddKill(ESampleGameTeam Team, FString Killer);

protected:
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UFUNCTION()
	void OnRep_TeamScores();

	FTeamScore* GetScoreForTeam(ESampleGameTeam Team);

	UPROPERTY(ReplicatedUsing = OnRep_TeamScores)
	TArray<FTeamScore> TeamScores;

};
