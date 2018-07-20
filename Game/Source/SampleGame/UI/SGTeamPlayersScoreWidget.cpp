// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SGTeamPlayersScoreWidget.h"

#include "Components/PanelWidget.h"
#include "Components/TextBlock.h"
#include "Teams/SampleGameTeams.h"
#include "Teams/SGTeamScores.h"
#include "UI/SGPlayerScoreWidget.h"


void USGTeamPlayersScoreWidget::SetTeam(ESampleGameTeam NewTeam)
{
	if (TeamNameText)
	{
		TeamNameText->SetText(FText::FromString(SampleGameTeamName(NewTeam)));
	}
}

void USGTeamPlayersScoreWidget::SetPlayerScores(const TArray<FPlayerScore>& PlayerScores)
{
	// Clear the container so we can re-add player scores in sorted order.
	PlayerScoresContainer->ClearChildren();

	for (const FPlayerScore& PlayerScore : PlayerScores)
	{
		FName PlayerName(*PlayerScore.PlayerName);
		if (!PlayerScoreWidgets.Contains(PlayerName))
		{
			check(PlayerScoreWidgetTemplate);

			USGPlayerScoreWidget* NewWidget = CreateWidget<USGPlayerScoreWidget>(GetOwningPlayer(), PlayerScoreWidgetTemplate);
			NewWidget->SetPlayerName(PlayerScore.PlayerName);
			PlayerScoreWidgets.Emplace(PlayerName, NewWidget);
		}

		USGPlayerScoreWidget* PlayerScoreWidget = PlayerScoreWidgets[PlayerName];
		PlayerScoreWidget->SetScores(PlayerScore);
		PlayerScoresContainer->AddChild(PlayerScoreWidget);
	}
}
