// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractMenuBase.generated.h"


UCLASS()
class UInteractMenuBase : public UUserWidget
{
	GENERATED_BODY()

public:
	void Init(class UInteractionManager* InInteractionManager);

	UFUNCTION(BlueprintPure, Category = "Interactions")
	class UInteractionManager* GetInteractionManager() const;
	
private:
	class UInteractionManager* InteractionManager;
	
};
