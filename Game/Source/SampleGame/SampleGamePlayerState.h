// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Teams/SampleGameTeams.h"
#include "SampleGamePlayerState.generated.h"


// Delegate to allow Character class to register a listener to the OnRep_SelectedTeam event
DECLARE_DELEGATE(CharacterListenerDelegate);

UCLASS()
class SAMPLEGAME_API ASampleGamePlayerState : public APlayerState
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Replicated)
	ESampleGameTeam SelectedTeam;

	// Delegate to allow Character class to register a listener to the OnRep_SelectedTeam event
	CharacterListenerDelegate CharacterListenerSelectedTeam;
	
public:
	void SetSelectedTeam(const ESampleGameTeam& NewSelectedTeam) { SelectedTeam = NewSelectedTeam; }
	const ESampleGameTeam GetSelectedTeam() const { return SelectedTeam; }
};
