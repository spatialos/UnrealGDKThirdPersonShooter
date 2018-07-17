// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGameScoreboard.h"

#include "Components/PanelWidget.h"
#include "Teams/SGTeamScores.h"
#include "UI/SGTeamPlayersScoreWidget.h"
#include "UI/SGTeamScoreWidget.h"

void USampleGameScoreboard::UpdateTeamScores(const TArray<FTeamScore>& TeamScores)
{
	for (const FTeamScore& TeamScore : TeamScores)
	{
		if (!TeamScoreWidgets.Contains(TeamScore.Team))
		{
			// TODO: validate all necessary pointers used below

			USGTeamScoreWidget* NewWidget = CreateWidget<USGTeamScoreWidget>(GetOwningPlayer(), TeamScoreWidgetTemplate);
			NewWidget->SetTeam(TeamScore.Team);
			TeamScoreWidgets.Emplace(TeamScore.Team, NewWidget);
			TeamScoresContainerWidget->AddChild(NewWidget);
		}

		USGTeamScoreWidget* TeamWidget = TeamScoreWidgets[TeamScore.Team];
		TeamWidget->SetKills(TeamScore.TeamKills);

		if (!PlayersScoreWidgets.Contains(TeamScore.Team))
		{
			// TODO: validate all necessary pointers used below

			USGTeamPlayersScoreWidget* NewWidget = CreateWidget<USGTeamPlayersScoreWidget>(GetOwningPlayer(), PlayersScoreWidgetTemplate);
			NewWidget->SetTeam(TeamScore.Team);
			PlayersScoreWidgets.Emplace(TeamScore.Team, NewWidget);
			PlayerScoresContainerWidget->AddChild(NewWidget);
		}

		USGTeamPlayersScoreWidget* TeamPlayersWidget = PlayersScoreWidgets[TeamScore.Team];
		TeamPlayersWidget->SetPlayerScores(TeamScore.TopPlayers);
	}

	// TODO: sort the team score widgets by score in the UI
}
