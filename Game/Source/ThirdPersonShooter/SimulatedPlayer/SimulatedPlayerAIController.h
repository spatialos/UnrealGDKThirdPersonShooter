// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SimulatedPlayerAIController.generated.h"


UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API ASimulatedPlayerAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

};
