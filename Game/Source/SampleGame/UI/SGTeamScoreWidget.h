// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Teams/SampleGameTeams.h"
#include "SGTeamScoreWidget.generated.h"


UCLASS()
class SAMPLEGAME_API USGTeamScoreWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetTeam(ESampleGameTeam NewTeam);
	void SetKills(int32 NewKills);

private:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TeamNameText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TeamKillsText;

	UPROPERTY(meta = (BindWidget))
	class UImage* TeamLogo;

	UPROPERTY(EditDefaultsOnly, Category = "Teams")
	TMap<ESampleGameTeam, class UTexture2D*> TeamLogos;
	
};
