// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TPSTeamScoreWidget.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Engine/Texture2D.h"
#include "Teams/TPSTeams.h"


void UTPSTeamScoreWidget::SetTeam(ETPSTeam NewTeam)
{
	if (TeamNameText)
	{
		TeamNameText->SetText(FText::FromString(TPSTeamName(NewTeam)));
	}

	if (TeamLogo && TeamLogos.Contains(NewTeam))
	{
		TeamLogo->SetBrushFromTexture(TeamLogos[NewTeam]);
	}
}

void UTPSTeamScoreWidget::SetKills(int32 NewKills)
{
	if (TeamKillsText)
	{
		TeamKillsText->SetText(FText::AsNumber(NewKills));
	}
}
