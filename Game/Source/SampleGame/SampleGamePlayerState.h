// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SampleGameTeams.h"
#include "SampleGamePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLEGAME_API ASampleGamePlayerState : public APlayerState
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Replicated)
	uint8 SelectedTeam;

	// TODO jamcrow - Add more team or player details here (ref to instantiated "team" object common across all team members?)

public:
	void SetSelectedTeamFromEnum(const ESampleGameTeam& NewSelectedTeam) { SelectedTeam = (uint8)NewSelectedTeam; }
	void SetSelectedTeamFromByte(const uint8& NewSelectedTeam) { SelectedTeam = NewSelectedTeam; }
	const ESampleGameTeam GetSelectedTeamAsEnum() const { return (ESampleGameTeam)SelectedTeam; }
	const uint8 GetSelectedTeamAsByte() const { return SelectedTeam; }

	// TODO jamcrow - Add more team or player details here (ref to instantiated "team" object common across all team members?)
};
