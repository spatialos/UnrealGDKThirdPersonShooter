// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "Characters/SampleGamePlayerState.h"

#include "Characters/SampleGameCharacter.h"
#include "Net/UnrealNetwork.h"
#include "SpatialNetDriver.h"


void ASampleGamePlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASampleGamePlayerState, SelectedTeam);
}
