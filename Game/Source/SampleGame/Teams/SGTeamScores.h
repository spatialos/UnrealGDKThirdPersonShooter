// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Teams/SampleGameTeams.h"

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
