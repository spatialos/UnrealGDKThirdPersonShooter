// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Teams/SampleGameTeams.h"
#include "Teams/SGTeamScores.h"
#include "SampleGameScoreboard.generated.h"

UCLASS()
class SAMPLEGAME_API USampleGameScoreboard : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void UpdateTeamScores(const TArray<FTeamScore>& TeamScores);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Team Score")
	TSubclassOf<class USGTeamScoreWidget> TeamScoreWidgetTemplate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Team Score")
	TMap<ESampleGameTeam, class USGTeamScoreWidget*> TeamScoreWidgets;

	UPROPERTY(EditDefaultsOnly, Category = "TeamScore")
	UPanelWidget* TeamScoresContainerWidget;

};
