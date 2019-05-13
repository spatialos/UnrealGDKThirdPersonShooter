// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SimulatedPlayerAIController.h"
#include "TPSLogging.h"

void ASimulatedPlayerAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTPS, Log, TEXT("BeginPlay AIController"));
}
