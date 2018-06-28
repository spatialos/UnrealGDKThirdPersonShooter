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

	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;
	virtual AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName = TEXT("")) override;
};