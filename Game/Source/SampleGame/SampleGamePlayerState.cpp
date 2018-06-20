// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGamePlayerState.h"

#include "SampleGameCharacter.h"

#include "Net/UnrealNetwork.h"
#include "SpatialNetDriver.h"


void ASampleGamePlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASampleGamePlayerState, SelectedTeam);
}

void ASampleGamePlayerState::OnRep_SelectedTeam()
{
	if (CharacterListenerSelectedTeam.IsBound())
	{
		/// Notify the Character via Delegate, if bound, that SelectedTeam has been updated.
		CharacterListenerSelectedTeam.Execute();
	}
}

void ASampleGamePlayerState::RegisterCharacterListenerForSelectedTeam(ASampleGameCharacter* CharacterInstance)
{
	check(!CharacterListenerSelectedTeam.IsBound());

	CharacterListenerSelectedTeam.BindUFunction(CharacterInstance, "SetTeamColor");
}

void ASampleGamePlayerState::UnregisterCharacterListenerForSelectedTeam()
{
	if (CharacterListenerSelectedTeam.IsBound())
	{
		CharacterListenerSelectedTeam.Unbind();
	}
}
