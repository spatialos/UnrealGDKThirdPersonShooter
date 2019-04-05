// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "Characters/TPSPlayerState.h"

#include "Characters/TPSCharacter.h"
#include "Net/UnrealNetwork.h"
#include "SpatialNetDriver.h"

DEFINE_STAT(STAT_SpatialPing);

ATPSPlayerState::ATPSPlayerState()
{
	if (GetNetMode() == NM_Client)
	{
		PrimaryActorTick.bCanEverTick = true;
	}
}

void ATPSPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATPSPlayerState, SelectedTeam);
}

void ATPSPlayerState::Tick(float DeltaSeconds)
{
	//UE_LOG(LogTemp, Log, TEXT("CLIENT PING IS %i"), Ping);
	SET_DWORD_STAT(STAT_SpatialPing, Ping * 4);
}
