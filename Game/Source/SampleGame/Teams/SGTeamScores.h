// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Teams/SampleGameTeams.h"
#include "SGTeamScores.generated.h"

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

inline bool operator<(const FPlayerScore& lhs, const FPlayerScore& rhs)
{
	return lhs.Kills < rhs.Kills;
}

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

inline bool operator<(const FTeamScore& lhs, const FTeamScore& rhs)
{
	return lhs.TeamKills < rhs.TeamKills;
}
