#pragma once

#include "CoreMinimal.h"
#include "Engine/NetDriver.h"
#include "EntityRegistry.h"
#include "GameFramework/Actor.h"
#include "SpatialNetDriver.h"

class SGDebug {
public:
	static FString LogPrefix(AActor* Actor, UNetDriver* NetDriver)
	{
		FString WorkerId("UNKNOWN");
		int32 EntityId = -1;
		if (USpatialNetDriver* SpatialNetDriver = Cast<USpatialNetDriver>(NetDriver))
		{
			WorkerId = SpatialNetDriver->GetSpatialOS()->GetWorkerId();
			EntityId = SpatialNetDriver->GetEntityRegistry()->GetEntityIdFromActor(Actor).ToSpatialEntityId();
		}

		return FString::Printf(TEXT("%s (%d)"), *WorkerId, EntityId);
	}
};
