// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGameGameMode.h"

#include "SampleGameLogging.h"
#include "UObject/ConstructorHelpers.h"
#include "UI/SampleGameHUD.h"

ASampleGameGameMode::ASampleGameGameMode()
{
	//set default pawn class to our Blueprinted character
	const TCHAR* DefaultPawnBPPath = TEXT("/Game/EntityBlueprints/SampleGameCharacter_BP");
	const ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(DefaultPawnBPPath);
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	else
	{
		UE_LOG(LogSampleGame, Error, TEXT("[SampleGameGameMode]: Couldn't find default Pawn blueprint class: %s"), DefaultPawnBPPath);
	}

	HUDClass = ASampleGameHUD::StaticClass();

	const TCHAR* DefaultPlayerControllerBPPath = TEXT("/Game/ThirdPersonCPP/Blueprints/SampleGamePlayerController_BP");
	const ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(DefaultPlayerControllerBPPath);
	if (PlayerControllerBPClass.Class != nullptr)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
	else
	{
		UE_LOG(LogSampleGame, Error, TEXT("[SampleGameGameMode]: Couldn't find default PlayerController blueprint class: %s"), DefaultPlayerControllerBPPath);
	}
}
