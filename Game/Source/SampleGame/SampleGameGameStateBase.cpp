// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGameGameStateBase.h"

void ASampleGameGameStateBase::FakeServerHasBegunPlay()
{
	if (!GetWorld()) 
	{
		return;
	}
	Role = ROLE_SimulatedProxy;
	
	bReplicatedHasBegunPlay = true;
	OnRep_ReplicatedHasBegunPlay();
}
