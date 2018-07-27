// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TPSPlayerScoreWidget.h"

#include "Components/TextBlock.h"


void UTPSPlayerScoreWidget::SetPlayerName(const FString& NewPlayerName)
{
	if (PlayerNameText)
	{
		PlayerNameText->SetText(FText::FromString(NewPlayerName));
	}
}

void UTPSPlayerScoreWidget::SetScores(const FPlayerScore& NewPlayerScore)
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
