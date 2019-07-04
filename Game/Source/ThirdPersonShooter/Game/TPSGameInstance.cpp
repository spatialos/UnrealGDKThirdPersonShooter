// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "Game/TPSGameInstance.h"
#include "EngineUtils.h"

void UTPSGameInstance::Init() 
{
	Super::Init();

	TickDelegate = FTickerDelegate::CreateUObject(this, &UTPSGameInstance::Tick);
	TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(TickDelegate);
}

bool UTPSGameInstance::Tick(float DeltaSeconds)
{
	float alpha = 0.8;
	float thisFPS = 1.0f / DeltaSeconds;
	AverageFPS = (alpha * AverageFPS) + ((1.0 - alpha) * thisFPS);

	SecondsSinceFPSLog += DeltaSeconds;

	if (SecondsSinceFPSLog > 1.0) {
		SecondsSinceFPSLog = 0.0f;

		UE_LOG(LogOnline, Display, TEXT("FramesPerSecond is %f"), AverageFPS);
	}
}