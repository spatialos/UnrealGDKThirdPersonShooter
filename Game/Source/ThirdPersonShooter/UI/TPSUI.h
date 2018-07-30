// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TPSUI.generated.h"


UCLASS()
class THIRDPERSONSHOOTER_API UTPSUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Updates the UI's health value.
	void UpdateHealth(int32 NewHealth, int32 MaxHealth);

protected:
	// Blueprint event called whenever the current health value is updated.
	UFUNCTION(BlueprintImplementableEvent, Category = "TPS UI")
	void UpdateHealthBar();

	// Current UI health value, between 0 and 1.
	UPROPERTY(BlueprintReadOnly)
	float CurrentHealth = 0.0f;
	
};
