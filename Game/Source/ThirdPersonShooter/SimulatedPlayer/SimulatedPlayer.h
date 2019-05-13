// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SimulatedPlayer.generated.h"


UCLASS()
class THIRDPERSONSHOOTER_API USimulatedPlayer : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Get whether this is a simulated client. */
	UFUNCTION(BlueprintPure, Category = "SimulatedPlayer")
	static bool IsSimulatedPlayer();
};
