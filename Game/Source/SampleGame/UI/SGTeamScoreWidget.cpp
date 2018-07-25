// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SGTeamScoreWidget.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Engine/Texture2D.h"
#include "Teams/SampleGameTeams.h"


void USGTeamScoreWidget::SetTeam(ESampleGameTeam NewTeam)
{
	if (TeamNameText)
	{
		TeamNameText->SetText(FText::FromString(SampleGameTeamName(NewTeam)));
	}

	if (TeamLogo && TeamLogos.Contains(NewTeam))
	{
		TeamLogo->SetBrushFromTexture(TeamLogos[NewTeam]);
	}
}

void USGTeamScoreWidget::SetKills(int32 NewKills)
{
	if (TeamKillsText)
	{
		TeamKillsText->SetText(FText::AsNumber(NewKills));
	}
}
