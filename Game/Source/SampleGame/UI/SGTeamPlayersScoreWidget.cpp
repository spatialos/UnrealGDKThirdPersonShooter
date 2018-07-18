// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SGTeamPlayersScoreWidget.h"

#include "Components/PanelWidget.h"
#include "Components/TextBlock.h"
#include "Teams/SampleGameTeams.h"
#include "Teams/SGTeamScores.h"
#include "UI/SGPlayerScoreWidget.h"


USGTeamPlayersScoreWidget::USGTeamPlayersScoreWidget(const FObjectInitializer& ObjectInitializer)
	: UUserWidget(ObjectInitializer)
	, Team(ESampleGameTeam::Team_None)
{
}

void USGTeamPlayersScoreWidget::SetTeam(ESampleGameTeam NewTeam)
{
	Team = NewTeam;
	if (TeamNameText)
	{
		TeamNameText->SetText(FText::FromString(SampleGameTeamName(Team)));
	}
}

void USGTeamPlayersScoreWidget::SetPlayerScores(const TArray<FPlayerScore>& PlayerScores)
{
	for (const FPlayerScore& PlayerScore : PlayerScores)
	{
		FName PlayerName(*PlayerScore.PlayerName);
		if (!PlayerScoreWidgets.Contains(PlayerName))
		{
			// TODO: validate all things below

			USGPlayerScoreWidget* NewWidget = CreateWidget<USGPlayerScoreWidget>(GetOwningPlayer(), PlayerScoreWidgetTemplate);
			NewWidget->SetPlayerName(PlayerScore.PlayerName);
			PlayerScoreWidgets.Emplace(PlayerName, NewWidget);
			PlayerScoresContainer->AddChild(NewWidget);
		}

		USGPlayerScoreWidget* PlayerScoreWidget = PlayerScoreWidgets[PlayerName];
		PlayerScoreWidget->SetScores(PlayerScore);
	}

	// TODO: sort players by kills
}
