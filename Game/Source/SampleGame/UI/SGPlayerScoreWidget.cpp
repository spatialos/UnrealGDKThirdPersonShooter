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

void USGPlayerScoreWidget::SetKills(int32 NewKills)
{
	if (PlayerKillsText)
	{
		PlayerKillsText->SetText(FText::AsNumber(NewKills));
	}
}
