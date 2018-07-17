#include "SampleGameLogging.h"

#include "CoreMinimal.h"
#include "Engine/NetDriver.h"
#include "EntityRegistry.h"
#include "GameFramework/Actor.h"
#include "SpatialNetDriver.h"


DEFINE_LOG_CATEGORY(LogSampleGame);

FString SampleGameLogging::LogPrefix(AActor* Actor, UNetDriver* NetDriver)
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
