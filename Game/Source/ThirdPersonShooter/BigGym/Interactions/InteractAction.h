// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InteractAction.generated.h"


UCLASS()
class AInteractAction : public AActor
{
	GENERATED_BODY()
	
public:
	AInteractAction();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interactions")
	void DoAction(AActor* Target);
	
};
