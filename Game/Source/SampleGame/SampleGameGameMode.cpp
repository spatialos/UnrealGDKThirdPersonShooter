// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGameGameMode.h"

#include "EngineUtils.h"
#include "SampleGameLogging.h"
#include "SampleGamePlayerController.h"
#include "SampleGamePlayerState.h"
#include "SGGameState.h"
#include "Teams/SampleGameTeamPlayerStart.h"
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

	// Use our custom PlayerState child for additional game-specific player data
	PlayerStateClass = ASampleGamePlayerState::StaticClass();

	// Start in Spectator Mode - The PlayerController will spawn the Characters after login, instead of on connect
	bStartPlayersAsSpectators = true;
}

AActor* ASampleGameGameMode::ChoosePlayerStart_Implementation(AController* Player)
{
	// If for some reason we aren't using a SampleGame PlayerController, use default ChoosePlayerStart behavior
	ASampleGamePlayerController* SGPlayerController = Cast<ASampleGamePlayerController>(Player);
	if (SGPlayerController != nullptr)
	{
		ESampleGameTeam SelectedTeam = ESampleGameTeam::Team_None;
		if (ASampleGamePlayerState* SGPlayerState = Cast<ASampleGamePlayerState>(SGPlayerController->PlayerState))
		{
			SelectedTeam = SGPlayerState->GetSelectedTeam();
		}
		
		TArray<ASampleGameTeamPlayerStart*> UnoccupiedStartPoints;
		TArray<ASampleGameTeamPlayerStart*> OccupiedStartPoints;

		APawn* PawnToFit = nullptr;
		if (UClass* PawnClass = GetDefaultPawnClassForController(Player))
		{
			PawnToFit = PawnClass->GetDefaultObject<APawn>();
		}

		for (TActorIterator<ASampleGameTeamPlayerStart> It(GetWorld()); It; ++It)
		{
			ASampleGameTeamPlayerStart* PlayerStart = *It;

			if (PlayerStart->TeamToSpawn == SelectedTeam)
			{
				const FVector ActorLocation = PlayerStart->GetActorLocation();
				const FRotator ActorRotation = PlayerStart->GetActorRotation();
				if (!GetWorld()->EncroachingBlockingGeometry(PawnToFit, ActorLocation, ActorRotation))
				{
					UnoccupiedStartPoints.Add(PlayerStart);
				}
				else
				{
					OccupiedStartPoints.Add(PlayerStart);
				}
			}
		}

		if (UnoccupiedStartPoints.Num() > 0)
		{
			return UnoccupiedStartPoints[FMath::RandRange(0, UnoccupiedStartPoints.Num() - 1)];
		}
		else if (OccupiedStartPoints.Num() > 0)
		{
			return OccupiedStartPoints[FMath::RandRange(0, OccupiedStartPoints.Num() - 1)];
		}
	}

	// Default behavior, if no team-appropriate starts found otherwise
	return Super::ChoosePlayerStart_Implementation(Player);
}

bool IsPlayerStartAMatchForTeam(const ASampleGameTeamPlayerStart* PlayerStart, const ESampleGameTeam& SelectedTeam)
{
	return (PlayerStart != nullptr && PlayerStart->TeamToSpawn == SelectedTeam);
}

AActor* ASampleGameGameMode::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
{
	// If for some reason we aren't using a SampleGame PlayerController, use default FindPlayerStart behavior
	ASampleGamePlayerController* SGPlayerController = Cast<ASampleGamePlayerController>(Player);
	if (SGPlayerController != nullptr)
	{
		ESampleGameTeam SelectedTeam = ESampleGameTeam::Team_None;
		ASampleGamePlayerState* SGPlayerState = Cast<ASampleGamePlayerState>(SGPlayerController->PlayerState);
		if (SGPlayerState != nullptr)
		{
			SelectedTeam = SGPlayerState->GetSelectedTeam();
		}
	
		UWorld* World = GetWorld();
	
		// Check if we have specified a PlayerStart by name
		if (!IncomingName.IsEmpty())
		{
			const FName IncomingPlayerStartTag = FName(*IncomingName);
			for (TActorIterator<ASampleGameTeamPlayerStart> It(World); It; ++It)
			{
				// Check that its team value (if any) matches current SelectedTeam
				ASampleGameTeamPlayerStart* Start = *It;
				if (Start
					&& Start->PlayerStartTag == IncomingPlayerStartTag
					&& Start->TeamToSpawn == SelectedTeam)
				{
					// If so, just use that one and return
					return Start;
				}
			}
		}

		// Ignore pre-selected PlayerStarts per Character/PlayerController.  Instead, spawn by Team.
		// Pick a PlayerStart based on SelectedTeam, or default behavior if not able to select by team
		AActor* BestStart = ChoosePlayerStart(Player);
		if (BestStart != nullptr)
		{
			return BestStart;
		}
	}

	// Default behavior, if no starts found otherwise
	return Super::FindPlayerStart_Implementation(Player, IncomingName);
}

void ASampleGameGameMode::NotifyPlayerKilled(FString PlayerName, FString KillerName, ESampleGameTeam KillerTeam)
{
	if (CustomGameState)
	{
		CustomGameState->AddKill(KillerTeam, KillerName, PlayerName);
	}
}

void ASampleGameGameMode::BeginPlay()
{
	if (HasAuthority())
	{
		CustomGameState = GetWorld()->SpawnActor<ASGGameState>(FVector::ZeroVector, FRotator::ZeroRotator);
	}
}
