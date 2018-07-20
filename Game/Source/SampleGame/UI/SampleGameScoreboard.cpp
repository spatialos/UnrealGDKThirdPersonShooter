// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGameScoreboard.h"

#include "Components/PanelWidget.h"
#include "Teams/SGTeamScores.h"
#include "UI/SGTeamPlayersScoreWidget.h"
#include "UI/SGTeamScoreWidget.h"

void USampleGameScoreboard::UpdateTeamScores(const TArray<FTeamScore>& TeamScores)
{
	// Clear children so we can re-add them in sorted order.
	TeamScoresContainerWidget->ClearChildren();
	PlayerScoresContainerWidget->ClearChildren();

	for (const FTeamScore& TeamScore : TeamScores)
	{
		if (TeamScore.Team == ESampleGameTeam::Team_None || TeamScore.Team >= ESampleGameTeam::Team_MAX)
		{
			// Skip invalid teams.
			continue;
		}

		if (!TeamScoreWidgets.Contains(TeamScore.Team))
		{
			check(TeamScoreWidgetTemplate);

			USGTeamScoreWidget* NewWidget = CreateWidget<USGTeamScoreWidget>(GetOwningPlayer(), TeamScoreWidgetTemplate);
			NewWidget->SetTeam(TeamScore.Team);
			TeamScoreWidgets.Emplace(TeamScore.Team, NewWidget);
		}

		USGTeamScoreWidget* TeamWidget = TeamScoreWidgets[TeamScore.Team];
		TeamWidget->SetKills(TeamScore.TeamKills);
		TeamScoresContainerWidget->AddChild(TeamWidget);

		if (!PlayersScoreWidgets.Contains(TeamScore.Team))
		{
			check(PlayersScoreWidgetTemplate);

			USGTeamPlayersScoreWidget* NewWidget = CreateWidget<USGTeamPlayersScoreWidget>(GetOwningPlayer(), PlayersScoreWidgetTemplate);
			NewWidget->SetTeam(TeamScore.Team);
			PlayersScoreWidgets.Emplace(TeamScore.Team, NewWidget);
		}

		USGTeamPlayersScoreWidget* TeamPlayersWidget = PlayersScoreWidgets[TeamScore.Team];
		TeamPlayersWidget->SetPlayerScores(TeamScore.TopPlayers);
		PlayerScoresContainerWidget->AddChild(TeamPlayersWidget);
	}
}
