// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SampleGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLEGAME_API ASampleGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	ASampleGameHUD();

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
