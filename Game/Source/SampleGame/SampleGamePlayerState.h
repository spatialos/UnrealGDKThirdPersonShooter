// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SampleGameTeams.h"
#include "SampleGamePlayerState.generated.h"


// Delegate to allow Character class to register a listener to the OnRep_SelectedTeam event
DECLARE_DELEGATE(CharacterListenerDelegate);

UCLASS()
class SAMPLEGAME_API ASampleGamePlayerState : public APlayerState
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, ReplicatedUsing = OnRep_SelectedTeam)
	ESampleGameTeam SelectedTeam;

	// Delegate to allow Character class to register a listener to the OnRep_SelectedTeam event
	CharacterListenerDelegate CharacterListenerSelectedTeam;
	
public:
	void SetSelectedTeamFromEnum(const ESampleGameTeam& NewSelectedTeam) { SelectedTeam = NewSelectedTeam; }
	void SetSelectedTeamFromByte(const uint8& NewSelectedTeam) { SelectedTeam = (ESampleGameTeam)NewSelectedTeam; }
	const ESampleGameTeam GetSelectedTeamAsEnum() const { return SelectedTeam; }
	const uint8 GetSelectedTeamAsByte() const { return (uint8)SelectedTeam; }

	UFUNCTION()
	void OnRep_SelectedTeam();

	void RegisterCharacterListenerForSelectedTeam(class ASampleGameCharacter* CharacterInstance);
	void UnregisterCharacterListenerForSelectedTeam();
};
