// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EntityRegistry.h"
#include "GameFramework/PlayerStart.h"
#include "Teams/SampleGameTeams.h"
#include "SampleGameTeamPlayerStart.generated.h"

UCLASS()
class ASampleGameTeamPlayerStart : public APlayerStart
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category = "Team")
	ESampleGameTeam TeamToSpawn;
};
