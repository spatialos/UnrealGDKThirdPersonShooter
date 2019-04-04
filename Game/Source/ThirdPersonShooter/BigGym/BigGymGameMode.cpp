// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "BigGymGameMode.h"
#include "UObject/ConstructorHelpers.h"

#include "EngineClasses/SpatialNetConnection.h"
#include "EngineClasses/SpatialNetDriver.h"
#include "Engine/World.h"
#include "Interop/Connection/SpatialWorkerConnection.h"

ABigGymGameMode::ABigGymGameMode()
{
	PrimaryActorTick.bCanEverTick = true;

	//set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/BigGym/EntityBlueprints/BigGymCharacter_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
	// Seamless Travel is not currently supported in SpatialOS [UNR-897]
	bUseSeamlessTravel = false;
}

//void ABigGymGameMode::Tick(float DeltaSeconds)
//{
//	if (GetNetMode() == NM_DedicatedServer && !bHasUpdatedMaxActorsToReplicate)
//	{
//		if (USpatialNetDriver* SND = Cast<USpatialNetDriver>(GetWorld()->GetNetDriver()))
//		{
//			if (SND->Connection && SND->Connection->IsConnected())
//			{
//				if (USpatialNetConnection* SNC = SND->GetSpatialOSNetConnection())
//				{
//					SNC->SetMaxActorsToReplicatePerFrame(MaxActorsToReplicate);
//					bHasUpdatedMaxActorsToReplicate = true;
//				}
//			}
//		}
//	}
//}

