// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Teams/SampleGameTeams.h"
#include "Teams/SGTeamScores.h"
#include "SGTeamPlayersScoreWidget.generated.h"


UCLASS()
class SAMPLEGAME_API USGTeamPlayersScoreWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetTeam(ESampleGameTeam NewTeam);
	void SetPlayerScores(const TArray<FPlayerScore>& PlayerScores);
	
private:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TeamNameText;

	UPROPERTY(EditDefaultsOnly, Category = "Score")
	TSubclassOf<class USGPlayerScoreWidget> PlayerScoreWidgetTemplate;

	UPROPERTY(VisibleAnywhere, Category = "Score")
	TMap<FName, class USGPlayerScoreWidget*> PlayerScoreWidgets;

	UPROPERTY(meta = (BindWidget))
	class UPanelWidget* PlayerScoresContainer;
	
};
