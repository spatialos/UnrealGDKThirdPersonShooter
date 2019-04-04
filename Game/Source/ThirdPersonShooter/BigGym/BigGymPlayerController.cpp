// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "BigGymPlayerController.h"
#include "SpatialNetDriver.h"

bool ABigGymPlayerController::TestRPC_Validate()
{
	return true;
}

void ABigGymPlayerController::TestRPC_Implementation()
{

}

bool ABigGymPlayerController::TestMulticast_Validate()
{
	return true;
}

void ABigGymPlayerController::TestMulticast_Implementation()
{
}

void ABigGymPlayerController::DoClientTravel(FString URLString)
{
	ClientTravel(URLString, ETravelType::TRAVEL_Absolute, false);
}

void ABigGymPlayerController::InitPlayerState()
{
	//// TODO: this is a workaround until we can query a replicated UObject*'s UnrealObjRef - UNR-407
	//UWorld* World = GetWorld();
	//check(World);
	//USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(World->GetNetDriver());
	//if (NetDriver)
	//{
	//	const Worker_EntityId EntityId = NetDriver->PackageMap->GetEntityIdFromObject(this);
	//	UE_LOG(LogTemp, Log, TEXT("PC:InitPlayerState called with entity id %lld"), EntityId);
	//	if (EntityId != 0)
	//	{
	//		// EntityId is not 0, which means that this PC has already been initialized.
	//		return;
	//	}
	//}

	Super::InitPlayerState();
}
