// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGamePlayerController.h"

#include "SampleGameCharacter.h"
#include "SampleGameLogging.h"
#include "UI/SampleGameUI.h"

#include "SpatialNetDriver.h"


ASampleGamePlayerController::ASampleGamePlayerController()
	: SampleGameUI(nullptr)
{}

void ASampleGamePlayerController::UpdateHealthUI(int32 NewHealth, int32 MaxHealth)
{
	if (SampleGameUI != nullptr)
	{
		SampleGameUI->UpdateHealth(NewHealth, MaxHealth);
	}
	else
	{
		UE_LOG(LogSampleGame, Log, TEXT("Couldn't find SampleGameUI for controller: %s"), *this->GetName());
	}
}

void ASampleGamePlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (GetNetMode() == NM_DedicatedServer)
	{
		return;
	}

	if (InPawn == nullptr)
	{
		if (SampleGameUI != nullptr && SampleGameUI->IsVisible())
		{
			SampleGameUI->RemoveFromViewport();
		}
	}
	else
	{
		if (SampleGameUI == nullptr)
		{
			check(UITemplate != nullptr);
			SampleGameUI = CreateWidget<USampleGameUI>(this, UITemplate);
			if (SampleGameUI == nullptr)
			{
				USpatialNetDriver* SpatialNetDriver = Cast<USpatialNetDriver>(GetNetDriver());
				UE_LOG(LogSampleGame, Error, TEXT("Failed to create UI for controller %s on worker %s"),
					*this->GetName(),
					SpatialNetDriver != nullptr ? *SpatialNetDriver->GetSpatialOS()->GetWorkerId() : TEXT("Invalid SpatialNetDriver"));
				return;
			}
		}

		if (!SampleGameUI->IsVisible())
		{
			SampleGameUI->AddToViewport();
		}

		ASampleGameCharacter* Character = Cast<ASampleGameCharacter>(InPawn);
		if (Character != nullptr)
		{
			UpdateHealthUI(Character->GetCurrentHealth(), Character->GetMaxHealth());
		}
	}
}
