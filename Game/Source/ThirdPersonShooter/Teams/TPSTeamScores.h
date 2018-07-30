// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Teams/TPSTeams.h"
#include "TPSTeamScores.generated.h"

USTRUCT()
struct FPlayerScore {
	GENERATED_BODY()

	UPROPERTY()
	FString PlayerName;

	UPROPERTY()
	int32 Kills;

	UPROPERTY()
	int32 Deaths;
};

USTRUCT()
struct FTeamScore {
	GENERATED_BODY()

	UPROPERTY()
	ETPSTeam Team;

	UPROPERTY()
	int32 TeamKills;

	UPROPERTY()
	TArray<FPlayerScore> TopPlayers;
};
