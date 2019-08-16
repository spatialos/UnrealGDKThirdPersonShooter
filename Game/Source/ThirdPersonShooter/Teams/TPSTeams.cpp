// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TPSTeams.h"


static const TCHAR* kTeamNames[]{
	TEXT("No Team"),
	TEXT("Red Team"),
	TEXT("Blue Team"),
	TEXT("Yellow Team"),
	TEXT("Purple Team"),
	TEXT("Overflow Team"),
};

FString TPSTeamName(ETPSTeam Team)
{
	if (Team > ETPSTeam::Team_Purple)
	{
		return TEXT("UNKNOWN TEAM");
	}
	return kTeamNames[static_cast<uint8>(Team)];
}
