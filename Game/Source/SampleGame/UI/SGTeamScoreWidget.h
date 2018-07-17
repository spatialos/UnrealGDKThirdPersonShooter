// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Teams/SampleGameTeams.h"
#include "SGTeamScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLEGAME_API USGTeamScoreWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	USGTeamScoreWidget();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Team Score")
	ESampleGameTeam Team;
	
};
