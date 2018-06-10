// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ESampleGameTeam : uint8
{
	Team_Red		UMETA(DisplayName = "Red Team"),
	Team_Green		UMETA(DisplayName = "Green Team"),
	Team_Blue		UMETA(DisplayName = "Blue Team"),
	Team_Yellow		UMETA(DisplayName = "Yellow Team"),
	Team_Purple		UMETA(DisplayName = "Purple Team"),
	Team_Black		UMETA(DisplayName = "Black Team"),
	Team_White		UMETA(DisplayName = "White Team"),
};
