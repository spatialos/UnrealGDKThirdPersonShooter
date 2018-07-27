// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TPSUI.h"


void UTPSUI::UpdateHealth(int32 NewHealth, int32 MaxHealth)
{
	if (MaxHealth > 0)
	{
		CurrentHealth = static_cast<float>(NewHealth) / static_cast<float>(MaxHealth);
	}
	else
	{
		CurrentHealth = 0.0f;
	}
	UpdateHealthBar();
}
