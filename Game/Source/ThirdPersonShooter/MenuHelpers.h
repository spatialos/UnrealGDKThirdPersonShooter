// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "MenuHelpers.generated.h"

UCLASS()
class UMenuHelpers : public UObject
{
public:
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void ConnectViaLoginFlow(UObject* WorldContextObject, ULocalPlayer* Player);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void ConnectViaReceptionist(UObject* WorldContextObject, ULocalPlayer* Player);
};
