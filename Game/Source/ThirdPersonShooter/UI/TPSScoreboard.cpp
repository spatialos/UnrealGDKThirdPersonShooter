// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TPSScoreboard.h"

#include "Components/PanelWidget.h"
#include "Teams/TPSTeamScores.h"
#include "UI/TPSTeamPlayersScoreWidget.h"
#include "UI/TPSTeamScoreWidget.h"

void UTPSScoreboard::UpdateTeamScores(const TArray<FTeamScore>& TeamScores)
{
	// Clear children so we can re-add them in sorted order.
	TeamScoresContainerWidget->ClearChildren();
	PlayerScoresContainerWidget->ClearChildren();

	for (const FTeamScore& TeamScore : TeamScores)
	{
		if (TeamScore.Team == ETPSTeam::Team_None || TeamScore.Team > ETPSTeam::Team_Purple)
		{
			// Skip invalid teams.
			continue;
		}

		if (!TeamScoreWidgets.Contains(TeamScore.Team))
		{
			check(TeamScoreWidgetTemplate);

			UTPSTeamScoreWidget* NewWidget = CreateWidget<UTPSTeamScoreWidget>(GetOwningPlayer(), TeamScoreWidgetTemplate);
			NewWidget->SetTeam(TeamScore.Team);
			TeamScoreWidgets.Emplace(TeamScore.Team, NewWidget);
		}

		UTPSTeamScoreWidget* TeamWidget = TeamScoreWidgets[TeamScore.Team];
		TeamWidget->SetKills(TeamScore.TeamKills);
		TeamScoresContainerWidget->AddChild(TeamWidget);

		if (!PlayersScoreWidgets.Contains(TeamScore.Team))
		{
			check(PlayersScoreWidgetTemplate);

			UTPSTeamPlayersScoreWidget* NewWidget = CreateWidget<UTPSTeamPlayersScoreWidget>(GetOwningPlayer(), PlayersScoreWidgetTemplate);
			NewWidget->SetTeam(TeamScore.Team);
			PlayersScoreWidgets.Emplace(TeamScore.Team, NewWidget);
		}

		UTPSTeamPlayersScoreWidget* TeamPlayersWidget = PlayersScoreWidgets[TeamScore.Team];
		TeamPlayersWidget->SetPlayerScores(TeamScore.TopPlayers);
		PlayerScoresContainerWidget->AddChild(TeamPlayersWidget);
	}
}
