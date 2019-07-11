// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "Game/TPSGameMode.h"

#include "Characters/TPSPlayerController.h"
#include "Characters/TPSPlayerState.h"
#include "EngineUtils.h"
#include "Game/TPSGameState.h"
#include "TPSLogging.h"
#include "Teams/TPSTeamPlayerStart.h"
#include "UObject/ConstructorHelpers.h"
#include "UI/TPSHUD.h"

ATPSGameMode::ATPSGameMode()
{
	//set default pawn class to our Blueprinted character
	//const TCHAR* DefaultPawnBPPath = TEXT("/Game/EntityBlueprints/TPSCharacter_BP");
	//const ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(DefaultPawnBPPath);
	//if (PlayerPawnBPClass.Class != nullptr)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
	//else
	//{
	//	UE_LOG(LogTPS, Error, TEXT("[TPSGameMode]: Couldn't find default Pawn blueprint class: %s"), DefaultPawnBPPath);
	//}

	//HUDClass = ATPSHUD::StaticClass();

	//const TCHAR* DefaultPlayerControllerBPPath = TEXT("/Game/Characters/TPSPlayerController_BP");
	//const ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(DefaultPlayerControllerBPPath);
	//if (PlayerControllerBPClass.Class != nullptr)
	//{
	//	PlayerControllerClass = PlayerControllerBPClass.Class;
	//}
	//else
	//{
	//	UE_LOG(LogTPS, Error, TEXT("[TPSGameMode]: Couldn't find default PlayerController blueprint class: %s"), DefaultPlayerControllerBPPath);
	//}

	//PlayerStateClass = ATPSPlayerState::StaticClass();
	//GameStateClass = ATPSGameState::StaticClass();

	//// Start in Spectator Mode - The PlayerController will spawn the Characters after login, instead of on connect
	//bStartPlayersAsSpectators = true;
	//
	//// Seamless Travel is not currently supported in SpatialOS [UNR-897]
	//bUseSeamlessTravel = false;
}

//AActor* ATPSGameMode::ChoosePlayerStart_Implementation(AController* Player)
//{
//	// If for some reason we aren't using an ATPSPlayerController, use default ChoosePlayerStart behavior
//	ATPSPlayerController* TPSPlayerController = Cast<ATPSPlayerController>(Player);
//	if (TPSPlayerController != nullptr)
//	{
//		ETPSTeam SelectedTeam = ETPSTeam::Team_None;
//		if (ATPSPlayerState* TPSPlayerState = Cast<ATPSPlayerState>(TPSPlayerController->PlayerState))
//		{
//			SelectedTeam = TPSPlayerState->GetSelectedTeam();
//		}
//		
//		TArray<ATPSTeamPlayerStart*> UnoccupiedStartPoints;
//		TArray<ATPSTeamPlayerStart*> OccupiedStartPoints;
//
//		APawn* PawnToFit = nullptr;
//		if (UClass* PawnClass = GetDefaultPawnClassForController(Player))
//		{
//			PawnToFit = PawnClass->GetDefaultObject<APawn>();
//		}
//
//		for (TActorIterator<ATPSTeamPlayerStart> It(GetWorld()); It; ++It)
//		{
//			ATPSTeamPlayerStart* PlayerStart = *It;
//
//			if (PlayerStart->TeamToSpawn == SelectedTeam)
//			{
//				const FVector ActorLocation = PlayerStart->GetActorLocation();
//				const FRotator ActorRotation = PlayerStart->GetActorRotation();
//				if (!GetWorld()->EncroachingBlockingGeometry(PawnToFit, ActorLocation, ActorRotation))
//				{
//					UnoccupiedStartPoints.Add(PlayerStart);
//				}
//				else
//				{
//					OccupiedStartPoints.Add(PlayerStart);
//				}
//			}
//		}
//
//		if (UnoccupiedStartPoints.Num() > 0)
//		{
//			return UnoccupiedStartPoints[FMath::RandRange(0, UnoccupiedStartPoints.Num() - 1)];
//		}
//		else if (OccupiedStartPoints.Num() > 0)
//		{
//			return OccupiedStartPoints[FMath::RandRange(0, OccupiedStartPoints.Num() - 1)];
//		}
//	}
//
//	// Default behavior, if no team-appropriate starts found otherwise
//	return Super::ChoosePlayerStart_Implementation(Player);
//}

bool IsPlayerStartAMatchForTeam(const ATPSTeamPlayerStart* PlayerStart, const ETPSTeam& SelectedTeam)
{
	return (PlayerStart != nullptr && PlayerStart->TeamToSpawn == SelectedTeam);
}

//AActor* ATPSGameMode::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
//{
//	return Super::FindPlayerStart_Implementation(Player, IncomingName);
//
//	// If for some reason we aren't using an ATPSPlayerController, use default FindPlayerStart behavior
//	/*ATPSPlayerController* TPSPlayerController = Cast<ATPSPlayerController>(Player);
//	if (TPSPlayerController != nullptr)
//	{
//		ETPSTeam SelectedTeam = ETPSTeam::Team_None;
//		ATPSPlayerState* TPSPlayerState = Cast<ATPSPlayerState>(TPSPlayerController->PlayerState);
//		if (TPSPlayerState != nullptr)
//		{
//			SelectedTeam = TPSPlayerState->GetSelectedTeam();
//		}
//	
//		UWorld* World = GetWorld();
//	
//		// Check if we have specified a PlayerStart by name
//		if (!IncomingName.IsEmpty())
//		{
//			const FName IncomingPlayerStartTag = FName(*IncomingName);
//			for (TActorIterator<ATPSTeamPlayerStart> It(World); It; ++It)
//			{
//				// Check that its team value (if any) matches current SelectedTeam
//				ATPSTeamPlayerStart* Start = *It;
//				if (Start
//					&& Start->PlayerStartTag == IncomingPlayerStartTag
//					&& Start->TeamToSpawn == SelectedTeam)
//				{
//					// If so, just use that one and return
//					return Start;
//				}
//			}
//		}
//
//		// Ignore pre-selected PlayerStarts per Character/PlayerController.  Instead, spawn by Team.
//		// Pick a PlayerStart based on SelectedTeam, or default behavior if not able to select by team
//		AActor* BestStart = ChoosePlayerStart(Player);
//		if (BestStart != nullptr)
//		{
//			return BestStart;
//		}
//	}
//
//	// Default behavior, if no starts found otherwise
//	return Super::FindPlayerStart_Implementation(Player, IncomingName);*/
//}

void ATPSGameMode::NotifyPlayerJoined(const FString& PlayerName, ETPSTeam PlayerTeam)
{
	if (ATPSGameState* GS = Cast<ATPSGameState>(GameState))
	{
		GS->AddPlayer(PlayerTeam, PlayerName);
	}
	else
	{
		UE_LOG(LogTPS, Error, TEXT("%s: failed to add player to scoreboard because GameState didn't exist"),
			*TPSLogging::LogPrefix(this));
	}
}

void ATPSGameMode::NotifyPlayerKilled(const FString& PlayerName, ETPSTeam PlayerTeam, const FString& KillerName, ETPSTeam KillerTeam)
{
	if (ATPSGameState* GS = Cast<ATPSGameState>(GameState))
	{
		GS->AddDeath(KillerName, KillerTeam, PlayerName, PlayerTeam);
	}
	else
	{
		UE_LOG(LogTPS, Error, TEXT("%s: failed to register kill because GameState didn't exist"),
			*TPSLogging::LogPrefix(this));
	}
}
