// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "GDKTestCase.h"

#include "GDKTestRunner.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

AGDKTestCase::AGDKTestCase()
	: bIsFinished(false)
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

bool AGDKTestCase::IsFinished() const
{
	return bIsFinished;
}

void AGDKTestCase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
