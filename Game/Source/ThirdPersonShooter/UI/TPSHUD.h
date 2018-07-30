// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TPSHUD.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API ATPSHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	ATPSHUD();

	virtual void DrawHUD() override;

	FORCEINLINE void SetDrawCrosshair(bool bDoDraw)
	{
		bDrawCrosshair = bDoDraw;
	}

	UPROPERTY(EditAnywhere)
	float CrosshairWidth;
	
	UPROPERTY(EditAnywhere)
	float CrosshairHeight;
	
private:
	// Draws a crosshair on the center of the screen.
	void DrawCrosshair();

	bool bDrawCrosshair;
	
};
