// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SGPlayerScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLEGAME_API USGPlayerScoreWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetPlayerName(const FString& NewPlayerName);
	void SetKills(int32 NewKills);
	
private:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PlayerNameText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PlayerKillsText;
	
};
