// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SampleGameTeams.h"
#include "SampleGamePlayerState.generated.h"


/// Delegate to allow Character class to register a listener to the OnRep_SelectedTeam event
DECLARE_DELEGATE(CharacterListenerDelegate);

/**
 * 
 */
UCLASS()
class SAMPLEGAME_API ASampleGamePlayerState : public APlayerState
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, ReplicatedUsing = OnRep_SelectedTeam)
	uint8 SelectedTeam;

	/// Delegate to allow Character class to register a listener to the OnRep_SelectedTeam event
	CharacterListenerDelegate CharacterListenerSelectedTeam;

	// TODO jamcrow - Add more team or player details here (ref to instantiated "team" object common across all team members?)

public:
	void SetSelectedTeamFromEnum(const ESampleGameTeam& NewSelectedTeam) { SelectedTeam = (uint8)NewSelectedTeam; }
	void SetSelectedTeamFromByte(const uint8& NewSelectedTeam) { SelectedTeam = NewSelectedTeam; }
	const ESampleGameTeam GetSelectedTeamAsEnum() const { return (ESampleGameTeam)SelectedTeam; }
	const uint8 GetSelectedTeamAsByte() const { return SelectedTeam; }

	UFUNCTION()
	void OnRep_SelectedTeam();

	void RegisterCharacterListenerForSelectedTeam(class ASampleGameCharacter* CharacterInstance);
	void UnregisterCharacterListenerForSelectedTeam();

	// TODO jamcrow - Add more team or player details here (ref to instantiated "team" object common across all team members?)
};
