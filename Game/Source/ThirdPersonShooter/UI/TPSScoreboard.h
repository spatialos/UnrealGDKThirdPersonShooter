// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Teams/TPSTeams.h"
#include "Teams/TPSTeamScores.h"
#include "TPSScoreboard.generated.h"


UCLASS()
class THIRDPERSONSHOOTER_API UTPSScoreboard : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void UpdateTeamScores(const TArray<FTeamScore>& TeamScores);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Team Score")
	TSubclassOf<class UTPSTeamScoreWidget> TeamScoreWidgetTemplate;

	UPROPERTY(VisibleAnywhere, Category = "Team Score")
	TMap<ETPSTeam, class UTPSTeamScoreWidget*> TeamScoreWidgets;

	UPROPERTY(meta = (BindWidget))
	class UPanelWidget* TeamScoresContainerWidget;

	UPROPERTY(EditDefaultsOnly, Category = "Team Score")
	TSubclassOf<class UTPSTeamPlayersScoreWidget> PlayersScoreWidgetTemplate;

	UPROPERTY(VisibleAnywhere, Category = "Team Score")
	TMap<ETPSTeam, class UTPSTeamPlayersScoreWidget*> PlayersScoreWidgets;

	UPROPERTY(meta = (BindWidget))
	class UPanelWidget* PlayerScoresContainerWidget;
};
