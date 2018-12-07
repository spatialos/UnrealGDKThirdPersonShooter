// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"

// NOTE - uint8 can support up to 255 total teams.  For games with more teams, use int32 instead (uint32 isn't supported by UE4 Blueprints)
UENUM(BlueprintType)
enum class ETPSTeam : uint8
{
	Team_None				UMETA(DisplayName = "UNSELECTED"),
	Team_Red				UMETA(DisplayName = "Red Team"),
	Team_Blue				UMETA(DisplayName = "Blue Team"),
	Team_Yellow				UMETA(DisplayName = "Yellow Team"),
	Team_Purple				UMETA(DisplayName = "Purple Team"),
	Team_Overflow			UMETA(DisplayName = "OVERFLOW"),
};

// Returns the display name for a given team.
FString TPSTeamName(ETPSTeam Team);
