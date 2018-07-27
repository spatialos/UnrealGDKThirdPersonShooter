// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TPSHUD.h"

#include "Engine/Canvas.h"


ATPSHUD::ATPSHUD()
	: CrosshairWidth(2.0f)
	, CrosshairHeight(2.0f)
	, bDrawCrosshair(true)
{}

void ATPSHUD::DrawHUD()
{
	Super::DrawHUD();
	if (Canvas == nullptr)
	{
		return;
	}

	if (bDrawCrosshair)
	{
		DrawCrosshair();
	}
}

void ATPSHUD::DrawCrosshair()
{
	float CenterX = Canvas->ClipX / 2.0f;
	float CenterY = Canvas->ClipY / 2.0f;
	DrawRect(FLinearColor::White, CenterX, CenterY, CrosshairWidth, CrosshairHeight);
}
