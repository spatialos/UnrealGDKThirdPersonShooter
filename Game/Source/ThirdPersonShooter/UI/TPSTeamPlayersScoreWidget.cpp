// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TPSTeamPlayersScoreWidget.h"

#include "Components/PanelWidget.h"
#include "Components/TextBlock.h"
#include "Teams/TPSTeams.h"
#include "Teams/TPSTeamScores.h"
#include "UI/TPSPlayerScoreWidget.h"


void UTPSTeamPlayersScoreWidget::SetTeam(ETPSTeam NewTeam)
{
	if (TeamNameText)
	{
		TeamNameText->SetText(FText::FromString(TPSTeamName(NewTeam)));
	}
}

void UTPSTeamPlayersScoreWidget::SetPlayerScores(const TArray<FPlayerScore>& PlayerScores)
{
	// Clear the container so we can re-add player scores in sorted order.
	PlayerScoresContainer->ClearChildren();

	for (const FPlayerScore& PlayerScore : PlayerScores)
	{
		FName PlayerName(*PlayerScore.PlayerName);
		if (!PlayerScoreWidgets.Contains(PlayerName))
		{
			check(PlayerScoreWidgetTemplate);

			UTPSPlayerScoreWidget* NewWidget = CreateWidget<UTPSPlayerScoreWidget>(GetOwningPlayer(), PlayerScoreWidgetTemplate);
			NewWidget->SetPlayerName(PlayerScore.PlayerName);
			PlayerScoreWidgets.Emplace(PlayerName, NewWidget);
		}

		UTPSPlayerScoreWidget* PlayerScoreWidget = PlayerScoreWidgets[PlayerName];
		PlayerScoreWidget->SetScores(PlayerScore);
		PlayerScoresContainer->AddChild(PlayerScoreWidget);
	}
}
