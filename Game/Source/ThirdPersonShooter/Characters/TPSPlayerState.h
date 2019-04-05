// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Teams/TPSTeams.h"
#include "TPSPlayerState.generated.h"

DECLARE_STATS_GROUP(TEXT("SpatialPing"), STATGROUP_SpatialNetPing, STATCAT_Advanced);
DECLARE_DWORD_ACCUMULATOR_STAT_EXTERN(TEXT("Ping"), STAT_SpatialPing, STATGROUP_SpatialNetPing, );

// Delegate to allow Character class to register a listener to the OnRep_SelectedTeam event
DECLARE_DELEGATE(CharacterListenerDelegate);

UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API ATPSPlayerState : public APlayerState
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Replicated)
	ETPSTeam SelectedTeam;

	// Delegate to allow Character class to register a listener to the OnRep_SelectedTeam event
	CharacterListenerDelegate CharacterListenerSelectedTeam;
	
public:
	ATPSPlayerState();

	void SetSelectedTeam(const ETPSTeam& NewSelectedTeam) { SelectedTeam = NewSelectedTeam; }
	const ETPSTeam GetSelectedTeam() const { return SelectedTeam; }

	void Tick(float DeltaSeconds) override;
};
