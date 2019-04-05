// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BigGymPlayerController.generated.h"

/**
 * 
 */
UCLASS(SpatialType)
class ABigGymPlayerController : public APlayerController
{
	GENERATED_BODY()

	UFUNCTION(Server, Reliable, WithValidation)
	void TestRPC();

	UFUNCTION(NetMulticast, Unreliable, WithValidation)
	void TestMulticast();

	UFUNCTION(BlueprintCallable)
	void DoClientTravel(FString URLString);
};
