// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGameGameMode.h"
#include "UObject/ConstructorHelpers.h"

ASampleGameGameMode::ASampleGameGameMode()
{
	//set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/EntityBlueprints/SampleGameCharacter_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
