// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Teams/TPSTeams.h"
#include "TPSTeamScoreWidget.generated.h"


UCLASS()
class THIRDPERSONSHOOTER_API UTPSTeamScoreWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetTeam(ETPSTeam NewTeam);
	void SetKills(int32 NewKills);

private:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TeamNameText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TeamKillsText;

	UPROPERTY(meta = (BindWidget))
	class UImage* TeamLogo;

	UPROPERTY(EditDefaultsOnly, Category = "Teams")
	TMap<ETPSTeam, class UTexture2D*> TeamLogos;
	
};
