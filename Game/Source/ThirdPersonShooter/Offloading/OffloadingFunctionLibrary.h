// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OffloadingFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API UOffloadingFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void DisableNavMesh(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable)
	static int GetNumBotsFromCommandLine(const FString& Arg);
};
