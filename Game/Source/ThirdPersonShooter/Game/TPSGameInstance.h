// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "SpatialGameInstance.h"
#include "TPSGameInstance.generated.h"

UCLASS()
class THIRDPERSONSHOOTER_API UTPSGameInstance : public USpatialGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	bool Tick(float DeltaSeconds);

private:
	FTickerDelegate TickDelegate;
	FDelegateHandle TickDelegateHandle;

	float AverageFPS = 1.0;
	float SecondsSinceFPSLog = 0.0;
};
