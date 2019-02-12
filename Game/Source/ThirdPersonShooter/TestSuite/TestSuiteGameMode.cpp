// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestsuiteGameMode.h"
#include "TestsuitePlayerController.h"
#include "TestsuiteGameStateBase.h"
#include "TestsuitePlayerState.h"
#include "UObject/ConstructorHelpers.h"

ATestSuiteGameMode::ATestSuiteGameMode()
{
	// Set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TestSuite/Characters/TestSuiteCharacter_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = ATestSuitePlayerController::StaticClass();
	GameStateClass = ATestSuiteGameStateBase::StaticClass();
	PlayerStateClass = ATestSuitePlayerState::StaticClass();

	// Seamless Travel is not currently supported in SpatialOS [UNR-897]
	bUseSeamlessTravel = false;
}
