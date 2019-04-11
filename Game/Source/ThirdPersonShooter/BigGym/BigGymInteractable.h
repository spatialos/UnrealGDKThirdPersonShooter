// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BigGymInteractable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBigGymInteractable : public UInterface
{
	GENERATED_BODY()
};

class THIRDPERSONSHOOTER_API IBigGymInteractable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
	void Interact();
	
};
