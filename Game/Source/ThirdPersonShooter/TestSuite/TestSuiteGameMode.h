// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestSuiteGameMode.generated.h"

UCLASS(minimalapi, SpatialType=(Singleton, ServerOnly))
class ATestSuiteGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATestSuiteGameMode();
};
