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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Team Score", meta = (AllowPrivateAccess = "true"))
	TMap<ESampleGameTeam, class USGTeamScoreWidget*> TeamScoreWidgets;

	UPROPERTY(VisibleAnywhere, Category = "TeamScore", meta = (BindWidget))
	class UPanelWidget* TeamScoresContainerWidget;
};
