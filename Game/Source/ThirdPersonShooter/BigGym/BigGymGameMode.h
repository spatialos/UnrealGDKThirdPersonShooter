// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BigGymGameMode.generated.h"

UCLASS(minimalapi, SpatialType=(Singleton, ServerOnly))
class ABigGymGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABigGymGameMode();

	//virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditDefaultsOnly, Category = "Spatial Networking")
	int32 MaxActorsToReplicate;

private:
	bool bHasUpdatedMaxActorsToReplicate = false;
};
