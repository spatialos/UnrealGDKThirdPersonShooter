// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SGTeamScoreWidget.h"

#include "Components/TextBlock.h"
#include "Teams/SampleGameTeams.h"


USGTeamScoreWidget::USGTeamScoreWidget(const FObjectInitializer& ObjectInitializer)
	: UUserWidget(ObjectInitializer)
	, Team(ESampleGameTeam::Team_None)
	, Kills(0)
{
}

void USGTeamScoreWidget::SetTeam(ESampleGameTeam NewTeam)
{
	Team = NewTeam;
	if (TeamNameText)
	{
		TeamNameText->SetText(FText::FromString(SampleGameTeamName(GetWorld(), Team)));
	}
}

void USGTeamScoreWidget::SetKills(int32 NewKills)
{
	Kills = NewKills;
	if (TeamKillsText)
	{
		TeamKillsText->SetText(FText::AsNumber(Kills));
	}
}
