// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGameScoreboard.h"

#include "Teams/SGTeamScores.h"
#include "UI/SGTeamScoreWidget.h"

void USampleGameScoreboard::UpdateTeamScores(const TArray<FTeamScore>& TeamScores)
{
	for (const FTeamScore& TeamScore : TeamScores)
	{
		if (!TeamScoreWidgets.Contains(TeamScore.Team))
		{
			// TODO: add new widget
			// TOOD: add newly created widget to container
		}

		USGTeamScoreWidget* TeamWidget = TeamScoreWidgets[TeamScore.Team];
		// TODO: set score of the team
	}

	// TODO: sort the team score widgets by score in the UI
}
