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
	USGTeamScoreWidget(const FObjectInitializer& ObjectInitializer);

	void SetTeam(ESampleGameTeam NewTeam);
	void SetKills(int32 NewKills);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Team Score", meta = (AllowPrivateAccess = "true"))
	ESampleGameTeam Team;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Team Score", meta = (AllowPrivateAccess = "true"))
	int32 Kills;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TeamNameText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TeamKillsText;
	
};
