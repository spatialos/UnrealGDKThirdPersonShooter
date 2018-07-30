// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TPSTeams.h"


static const TCHAR* kTeamNames[]{
	TEXT("No Team"),
	TEXT("Red Team"),
	TEXT("Green Team"),
	TEXT("Blue Team"),
	TEXT("Yellow Team"),
	TEXT("Purple Team"),
	TEXT("Black Team"),
	TEXT("White Team"),
};

FString TPSTeamName(ETPSTeam Team)
{
	if (Team > ETPSTeam::Team_MAX)
	{
		return "UNKNOWN TEAM";
	}
	return FString::Printf(kTeamNames[static_cast<uint8>(Team)]);
}
