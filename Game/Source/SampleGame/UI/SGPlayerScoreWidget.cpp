// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SGPlayerScoreWidget.h"

#include "Components/TextBlock.h"


void USGPlayerScoreWidget::SetPlayerName(const FString& NewPlayerName)
{
	if (PlayerNameText)
	{
		PlayerNameText->SetText(FText::FromString(NewPlayerName));
	}
}

void USGPlayerScoreWidget::SetScores(const FPlayerScore& NewPlayerScore)
{
	if (PlayerDeathsText)
	{
		PlayerDeathsText->SetText(FText::AsNumber(NewPlayerScore.Deaths));
	}
	if (PlayerKillsText)
	{
		PlayerKillsText->SetText(FText::AsNumber(NewPlayerScore.Kills));
	}
}
