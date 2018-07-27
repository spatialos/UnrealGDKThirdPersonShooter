// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "Characters/TPSPlayerState.h"

#include "Characters/TPSCharacter.h"
#include "Net/UnrealNetwork.h"
#include "SpatialNetDriver.h"


void ATPSPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATPSPlayerState, SelectedTeam);
}
