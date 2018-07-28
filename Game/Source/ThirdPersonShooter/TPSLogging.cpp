// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TPSLogging.h"

#include "CoreMinimal.h"
#include "Engine/NetDriver.h"
#include "EntityRegistry.h"
#include "GameFramework/Actor.h"
#include "SpatialNetDriver.h"


DEFINE_LOG_CATEGORY(LogTPS);

FString TPSLogging::LogPrefix(AActor* Actor)
{
	FString WorkerId("UNKNOWN");
	int32 EntityId = -1;
	if (USpatialNetDriver* SpatialNetDriver = Cast<USpatialNetDriver>(Actor->GetNetDriver()))
	{
		WorkerId = SpatialNetDriver->GetSpatialOS()->GetWorkerId();
		EntityId = SpatialNetDriver->GetEntityRegistry()->GetEntityIdFromActor(Actor).ToSpatialEntityId();
	}
	else
	{
		// No SpatialOS net driver, so just return the actor's name.
		return Actor->GetName();
	}

	if (EntityId == 0)
	{
		return FString::Printf(TEXT("%s %s (non-spatial actor)"), *WorkerId, *Actor->GetName());
	}

	return FString::Printf(TEXT("%s %s (%d)"), *WorkerId, *Actor->GetName(), EntityId);
}
