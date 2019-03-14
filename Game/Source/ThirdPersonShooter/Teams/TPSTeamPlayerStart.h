// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "Teams/TPSTeams.h"
#include "TPSTeamPlayerStart.generated.h"

UCLASS()
class ATPSTeamPlayerStart : public APlayerStart
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category = "Team")
	ETPSTeam TeamToSpawn;
};
