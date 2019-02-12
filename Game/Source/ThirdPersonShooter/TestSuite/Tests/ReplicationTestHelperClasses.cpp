// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "ReplicationTestHelperClasses.h"
#include "UnrealNetwork.h"

ATestActor::ATestActor()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

void ATestActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestActor, ActorName, COND_None);
}
