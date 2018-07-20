// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Teams/SampleGameTeams.h"
#include "SampleGameGameMode.generated.h"

UCLASS(minimalapi)
class ASampleGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASampleGameGameMode();

	// NOTE : This is an override of a BlueprintNativeEvent, not an RPC
	// Return the 'best' player start for this player to spawn from
	// This implementation first attempts to find a spot associated with Player team
	// Default implementation looks for a random unoccupied spot
	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

	// NOTE : This is an override of a BlueprintNativeEvent, not an RPC
	// Return the specific player start actor that should be used for the next spawn
	// This will either use a specified startactor, if it matches Player's team affiliation,
	// or calls ChoosePlayerStart to select a startactor matching Player's team affiliation.
	virtual AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName = TEXT("")) override;

	// TODO: mark this as a W2W RPC
	void NotifyPlayerKilled(FString PlayerName, ESampleGameTeam PlayerTeam, FString KillerName, ESampleGameTeam KillerTeam);

	// TODO: remove this
	class ASGGameState* GetCustomGameState()
	{
		return CustomGameState;
	}

protected:
	virtual void BeginPlay() override;

private:
	// TODO: remove this
	class ASGGameState* CustomGameState;
};