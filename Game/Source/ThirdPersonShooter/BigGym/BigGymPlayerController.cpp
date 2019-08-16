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
