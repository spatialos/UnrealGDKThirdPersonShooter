// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SampleGameGameMode.generated.h"

UCLASS(minimalapi)
class ASampleGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASampleGameGameMode();

	// These are overrides of BlueprintNativeEvents, not RPCs
	///  /**
	///  * Return the 'best' player start for this player to spawn from
	///  * This implementation first attempts to find a spot associated with Player team
	///  * Default implementation looks for a random unoccupied spot
	///  *
	///  * @param Player is the controller for whom we are choosing a playerstart
	///  * @returns AActor chosen as player start (usually an ASampleGameTeamPlayerStart)
	///  */
	///  UFUNCTION(BlueprintNativeEvent, Category = Game)
	///  AActor* ChoosePlayerStart(AController* Player);
	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

	///  /**
	///  * Return the specific player start actor that should be used for the next spawn
	///  * This will either use a specified startactor, if it matches Player's team affiliation,
	///  * or calls ChoosePlayerStart to select a startactor matching Player's team affiliation.
	///  *
	///  * @param Player The AController for whom we are choosing a Player Start
	///  * @param IncomingName Specifies the tag of a Player Start to use
	///  * @returns Actor chosen as player start (usually an ASampleGameTeamPlayerStart)
	///  */
	///  UFUNCTION(BlueprintNativeEvent, Category = Game)
	///  AActor* FindPlayerStart(AController* Player, const FString& IncomingName = TEXT(""));
	virtual AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName = TEXT("")) override;
};