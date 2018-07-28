// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"

// NOTE - uint8 can support up to 255 total teams.  For games with more teams, use int32 instead (uint32 isn't supported by UE4 Blueprints)
UENUM(BlueprintType)
enum class ETPSTeam : uint8
{
	Team_None				UMETA(DisplayName = "UNSELECTED"),
	Team_Red				UMETA(DisplayName = "Red Team"),
	Team_Green				UMETA(DisplayName = "Green Team"),
	Team_Blue				UMETA(DisplayName = "Blue Team"),
	Team_Yellow				UMETA(DisplayName = "Yellow Team"),
	Team_Purple				UMETA(DisplayName = "Purple Team"),
	Team_Black				UMETA(DisplayName = "Black Team"),
	Team_White				UMETA(DisplayName = "White Team"),
	Team_MIN = Team_Red		UMETA(DisplayName = "Team MIN"),
	Team_MAX = Team_White	UMETA(DisplayName = "Team MAX"),
};

// Returns the display name for a given team.
FString TPSTeamName(ETPSTeam Team);
