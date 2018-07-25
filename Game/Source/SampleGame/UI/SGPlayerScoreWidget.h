// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Teams/SGTeamScores.h"
#include "SGPlayerScoreWidget.generated.h"


UCLASS()
class SAMPLEGAME_API USGPlayerScoreWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetPlayerName(const FString& NewPlayerName);
	void SetScores(const FPlayerScore& NewPlayerScore);

private:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PlayerNameText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PlayerDeathsText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PlayerKillsText;
	
};
