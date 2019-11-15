// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "GDKTestCase.h"

#include "GDKTestRunner.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

AGDKTestCase::AGDKTestCase()
	: bReadyToSendServerRPCs(false),
	bIsFinished(false)
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	bAlwaysRelevant = true;
}

void AGDKTestCase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (GetNetMode() == NM_Client && bReadyToSendServerRPCs && HasNetOwner())
	{
		bReadyToSendServerRPCs = false;
		SendServerRPCs();
	}
}

bool AGDKTestCase::IsFinished() const
{
	return bIsFinished;
}

void AGDKTestCase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void AGDKTestCase::SetupNewGDKRunner()
{
	check(GetNetMode() == NM_DedicatedServer);
	if (CurrentRunnerIndex < Runners.Num())
	{
		SetOwner(Runners[CurrentRunnerIndex]);
	}
}

void AGDKTestCase::InitializeGDKTestRunnersForThisTestCase(TArray<AGDKTestRunner*> InRunners)
{
	check(GetNetMode() == NM_DedicatedServer);
	Runners = InRunners;
	CurrentRunnerIndex = 0;
	SetupNewGDKRunner();
}
