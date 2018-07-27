// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Teams/TPSTeamScores.h"
#include "TPSPlayerScoreWidget.generated.h"


UCLASS()
class THIRDPERSONSHOOTER_API UTPSPlayerScoreWidget : public UUserWidget
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
