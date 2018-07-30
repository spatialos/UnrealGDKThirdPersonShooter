// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Teams/TPSTeams.h"
#include "Teams/TPSTeamScores.h"
#include "TPSTeamPlayersScoreWidget.generated.h"


UCLASS()
class THIRDPERSONSHOOTER_API UTPSTeamPlayersScoreWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetTeam(ETPSTeam NewTeam);
	void SetPlayerScores(const TArray<FPlayerScore>& PlayerScores);
	
private:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TeamNameText;

	UPROPERTY(EditDefaultsOnly, Category = "Score")
	TSubclassOf<class UTPSPlayerScoreWidget> PlayerScoreWidgetTemplate;

	UPROPERTY(VisibleAnywhere, Category = "Score")
	TMap<FName, class UTPSPlayerScoreWidget*> PlayerScoreWidgets;

	UPROPERTY(meta = (BindWidget))
	class UPanelWidget* PlayerScoresContainer;
	
};
