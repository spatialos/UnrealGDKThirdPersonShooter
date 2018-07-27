// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface for interactable objects.
 */
class THIRDPERSONSHOOTER_API IInteractable
{
	GENERATED_BODY()

public:
	// Interface function for interacting with objects. Implement in Blueprints or C++ to handle the interaction.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interactable")
	void Interact(AActor* OriginatingActor);
	
};
