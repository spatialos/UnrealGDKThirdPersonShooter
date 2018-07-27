// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "Characters/TPSPlayerController.h"

#include "Characters/TPSPlayerState.h"
#include "Characters/TPSCharacter.h"
#include "Game/TPSGameMode.h"
#include "Game/TPSGameState.h"
#include "TPSLogging.h"
#include "UI/TPSHUD.h"
#include "UI/TPSLoginUI.h"
#include "UI/TPSScoreboard.h"
#include "UI/TPSUI.h"
#include "UnrealNetwork.h"

#include "SpatialNetDriver.h"


ATPSPlayerController::ATPSPlayerController()
	: bIgnoreActionInput(false)
	, SampleGameUI(nullptr)
	, Scoreboard(nullptr)
	, SampleGameLoginUI(nullptr)
	, RespawnCharacterDelay(5.0f)
	, DeleteCharacterDelay(15.0f)
	, PawnToDelete(nullptr)
{
	// Don't automatically switch the camera view when the pawn changes, to avoid weird camera jumps when a character dies.
	bAutoManageActiveCameraTarget = false;
}

void ATPSPlayerController::EndPlay(const EEndPlayReason::Type Reason)
{
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void ATPSPlayerController::UpdateHealthUI(int32 NewHealth, int32 MaxHealth)
{
	if (SampleGameUI != nullptr)
	{
		SampleGameUI->UpdateHealth(NewHealth, MaxHealth);
	}
	else
	{
		UE_LOG(LogSampleGame, Log, TEXT("Couldn't find SampleGameUI for controller: %s"), *this->GetName());
	}
}

void ATPSPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (GetNetMode() == NM_Client && bHasSubmittedLoginOptions)
	{
		SetPlayerUIVisible(InPawn != nullptr);

		ATPSCharacter* Character = Cast<ATPSCharacter>(InPawn);
		if (Character != nullptr)
		{
			UpdateHealthUI(Character->GetCurrentHealth(), Character->GetMaxHealth());

			// Make the new pawn's camera this controller's camera.
			SetViewTarget(InPawn);
		}
	}
}

void ATPSPlayerController::KillCharacter(const ATPSCharacter* Killer)
{
	check(GetNetMode() == NM_DedicatedServer);

	if (!HasAuthority())
	{
		return;
	}

	FString KillerName;
	ETPSTeam KillerTeam = ETPSTeam::Team_None;
	if (Killer)
	{
		KillerName = Killer->GetPlayerName();
		KillerTeam = Killer->GetTeam();
	}

	ETPSTeam MyTeam = ETPSTeam::Team_None;
	if (ATPSCharacter* Me = Cast<ATPSCharacter>(GetCharacter()))
	{
		MyTeam = Me->GetTeam();
	}

	if (ATPSGameMode* GM = Cast<ATPSGameMode>(GetWorld()->GetAuthGameMode()))
	{
		if (ATPSPlayerState* PS = Cast<ATPSPlayerState>(PlayerState))
		{
			GM->NotifyPlayerKilled(PS->GetPlayerName(), MyTeam, KillerName, KillerTeam);
		}
	}

	PawnToDelete = GetPawn();
	UnPossess();

	// TODO: timers won't persist across worker boundary migrations, and neither will PawnToDelete
	GetWorldTimerManager().SetTimer(DeleteCharacterTimerHandle, this, &ATPSPlayerController::DeleteCharacter, DeleteCharacterDelay);
	GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &ATPSPlayerController::RespawnCharacter, RespawnCharacterDelay);
}

void ATPSPlayerController::SetPlayerUIVisible(bool bIsVisible)
{
	check(GetNetMode() == NM_Client);

	ATPSHUD* HUD = Cast<ATPSHUD>(GetHUD());
	if (HUD != nullptr)
	{
		HUD->SetDrawCrosshair(bIsVisible);
	}

	if (bIsVisible)
	{
		if (SampleGameUI == nullptr)
		{
			check(UITemplate != nullptr);
			SampleGameUI = CreateWidget<UTPSUI>(this, UITemplate);
			if (SampleGameUI == nullptr)
			{
				USpatialNetDriver* SpatialNetDriver = Cast<USpatialNetDriver>(GetNetDriver());
				UE_LOG(LogSampleGame, Error, TEXT("Failed to create UI for controller %s on worker %s"),
					*this->GetName(),
					SpatialNetDriver != nullptr ? *SpatialNetDriver->GetSpatialOS()->GetWorkerId() : TEXT("Invalid SpatialNetDriver"));
				return;
			}
		}

		if (!SampleGameUI->IsVisible())
		{
			SampleGameUI->AddToViewport();
		}
	}
	else
	{
		if (SampleGameUI != nullptr && SampleGameUI->IsVisible())
		{
			SampleGameUI->RemoveFromViewport();
		}
	}
}

void ATPSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("ShowScoreboard", IE_Pressed, this, &ATPSPlayerController::ShowScoreboard);
	InputComponent->BindAction("ShowScoreboard", IE_Released, this, &ATPSPlayerController::HideScoreboard);
}

void ATPSPlayerController::SetLoginUIVisible(bool bIsVisible)
{
	// Lazy instantiate the Login UI
	if (SampleGameLoginUI == nullptr)
	{
		check(LoginUIWidgetTemplate != nullptr);
		SampleGameLoginUI = CreateWidget<UTPSLoginUI>(this, LoginUIWidgetTemplate);
		
		// Early out - Error case
		if (SampleGameLoginUI == nullptr)
		{
			USpatialNetDriver* SpatialNetDriver = Cast<USpatialNetDriver>(GetNetDriver());
			UE_LOG(LogSampleGame, Error, TEXT("Failed to create Login UI for controller %s on worker %s"),
				*this->GetName(),
				SpatialNetDriver != nullptr ? *SpatialNetDriver->GetSpatialOS()->GetWorkerId() : TEXT("Invalid SpatialNetDriver"));

			return;
		}
	}

	// Early out - If our visibility state is already set to the requested value, do nothing
	if (SampleGameLoginUI->IsVisible() == bIsVisible)
	{
		return;
	}

	if (bIsVisible)
	{
		// Show the Login UI
		SampleGameLoginUI->AddToViewport();
		// The UI Widget needs to know who its owner is, so it knows who to respond to when user submits final selections
		SampleGameLoginUI->SetOwnerPlayerController(this);
		// Set Mouse Cursor to SHOW, and only interact with the UI
		SetUIMode(true);
	}
	else
	{
		// Hide the Login UI
		SampleGameLoginUI->RemoveFromViewport();
		// Hide the Mouse Cursor, restore Look and Move control
		SetUIMode(false);
	}
}

void ATPSPlayerController::InitScoreboard()
{
	check(GetNetMode() != NM_DedicatedServer);

	if (Scoreboard)
	{
		return;
	}

	check(ScoreboardTemplate != nullptr);
	Scoreboard = CreateWidget<UTPSScoreboard>(this, ScoreboardTemplate);

	if (Scoreboard == nullptr)
	{
		UE_LOG(LogSampleGame, Error, TEXT("%s: failed to create scoreboard widget"), *TPSLogging::LogPrefix(this));
		return;
	}

	if (ATPSGameState* GS = GetWorld()->GetGameState<ATPSGameState>())
	{
		// Register a listener between the GameState's score list and the scoreboard's update function.
		FSGTeamScoresUpdatedDelegate UpdateScoreboardCallback;
		UpdateScoreboardCallback.BindUObject(Scoreboard, &UTPSScoreboard::UpdateTeamScores);
		GS->RegisterScoreChangeListener(UpdateScoreboardCallback);
	}
	else
	{
		UE_LOG(LogSampleGame, Error, TEXT("%s: failed to initialize scoreboard because GameState didn't exist"),
			*TPSLogging::LogPrefix(this));
	}
}

void ATPSPlayerController::ShowScoreboard()
{
	check(GetNetMode() != NM_DedicatedServer);

	// Make sure we stop firing when the user pulls up the scoreboard.
	if (ATPSCharacter* SGCharacter = Cast<ATPSCharacter>(GetCharacter()))
	{
		SGCharacter->StopFire();
	}

	SetScoreboardIsVisible(true);
}

void ATPSPlayerController::HideScoreboard()
{
	check(GetNetMode() != NM_DedicatedServer);
	SetScoreboardIsVisible(false);
}

FString ATPSPlayerController::GetDefaultPlayerName()
{
	if (USpatialNetDriver* SpatialNetDriver = Cast<USpatialNetDriver>(GetNetDriver()))
	{
		return SpatialNetDriver->GetSpatialOS()->GetWorkerId();
	}
	return "Player" + FGuid::NewGuid().ToString();
}

void ATPSPlayerController::SetScoreboardIsVisible(bool bIsVisible)
{
	if (Scoreboard == nullptr || Scoreboard->IsInViewport() == bIsVisible)
	{
		return;
	}

	if (bIsVisible)
	{
		Scoreboard->AddToViewport();
		SetUIMode(true, true);
	}
	else
	{
		Scoreboard->RemoveFromViewport();
		SetUIMode(false, true);
	}
}

void ATPSPlayerController::SetUIMode(bool bIsUIMode, bool bAllowMovement)
{
	bShowMouseCursor = bIsUIMode;
	SetIgnoreLookInput(bIsUIMode);
	SetIgnoreMoveInput(bIsUIMode && !bAllowMovement);
	SetIgnoreActionInput(bIsUIMode);
	if (bIsUIMode)
	{
		SetInputMode(FInputModeGameAndUI());
	}
	else
	{
		SetInputMode(FInputModeGameOnly());
	}
}

void ATPSPlayerController::TryJoinGame(const FString& NewPlayerName, const ETPSTeam NewPlayerTeam)
{
	check(GetNetMode() != NM_DedicatedServer);
	ServerTryJoinGame(
		NewPlayerName.IsEmpty() ? GetDefaultPlayerName() : NewPlayerName,
		NewPlayerTeam);
}

void ATPSPlayerController::ServerTryJoinGame_Implementation(const FString& NewPlayerName, const ETPSTeam NewPlayerTeam)
{
	bool bJoinWasSuccessful = true;

	// Validate player name
	if (NewPlayerName.IsEmpty())
	{
		bJoinWasSuccessful = false;

		UE_LOG(LogSampleGame, Error, TEXT("%s PlayerController: Player attempted to join with empty name."), *this->GetName());
	}

	// Validate PlayerState
	if (PlayerState == nullptr
		|| !PlayerState->IsA(ATPSPlayerState::StaticClass()))
	{
		bJoinWasSuccessful = false;

		UE_LOG(LogSampleGame, Error, TEXT("%s PlayerController: Invalid PlayerState pointer (%s)"), *this->GetName(), PlayerState == nullptr ? TEXT("nullptr") : *PlayerState->GetName());
	}

	// Validate the join request
	if (bHasSubmittedLoginOptions)
	{
		bJoinWasSuccessful = false;

		UE_LOG(LogSampleGame, Error, TEXT("%s PlayerController: Already submitted Join request.  Client attempting to join session multiple times."), *this->GetName());
	}

	// Inform Client as to whether or not join was accepted
	ClientJoinResults(bJoinWasSuccessful);
	
	if (bJoinWasSuccessful)
	{
		bHasSubmittedLoginOptions = true;

		// Set the player-selected values
		PlayerState->SetPlayerName(NewPlayerName);
		Cast<ATPSPlayerState>(PlayerState)->SetSelectedTeam(NewPlayerTeam);

		// Recalculate our PlayerStart using the new SelectedTeam information
		AActor* const NewStartSpot = GetWorld()->GetAuthGameMode()->ChoosePlayerStart(this);
		if (NewStartSpot != nullptr)
		{
			// Set the player controller / camera in this new location
			FRotator InitialControllerRot = NewStartSpot->GetActorRotation();
			InitialControllerRot.Roll = 0.f;
			SetInitialLocationAndRotation(NewStartSpot->GetActorLocation(), InitialControllerRot);
			StartSpot = NewStartSpot;
		}

		// Spawn the Pawn
		RespawnCharacter();

		// Add the player to the game's scoreboard.
		if (ATPSGameMode* GM = GetWorld()->GetAuthGameMode<ATPSGameMode>())
		{
			GM->NotifyPlayerJoined(NewPlayerName, NewPlayerTeam);
		}
		else
		{
			UE_LOG(LogSampleGame, Error, TEXT("%s: failed to add player because GameMode didn't exist"),
				*TPSLogging::LogPrefix(this));
		}
	}

}

bool ATPSPlayerController::ServerTryJoinGame_Validate(const FString& NewPlayerName, const ETPSTeam NewPlayerTeam)
{
	return true;
}

void ATPSPlayerController::ClientJoinResults_Implementation(const bool bJoinSucceeded)
{
	check(SampleGameLoginUI != nullptr);

	if (bJoinSucceeded)
	{
		bHasSubmittedLoginOptions = true;
		SetLoginUIVisible(false);
	}
	else
	{
		SampleGameLoginUI->JoinGameWasRejected();
	}

	InitScoreboard();
}

void ATPSPlayerController::RespawnCharacter()
{
	check(GetNetMode() == NM_DedicatedServer);
	AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();
	if (GameMode != nullptr)
	{
		APawn* NewPawn = GameMode->SpawnDefaultPawnFor(this, StartSpot.Get());
		Possess(NewPawn);

		ATPSCharacter* NewCharacter = Cast<ATPSCharacter>(NewPawn);
		if (NewCharacter != nullptr)
		{
			ATPSPlayerState* SGPlayerState = Cast<ATPSPlayerState>(PlayerState);
			NewCharacter->SetTeam(SGPlayerState != nullptr ? SGPlayerState->GetSelectedTeam() : ETPSTeam::Team_None);
		}
	}
}

void ATPSPlayerController::DeleteCharacter()
{
	check(GetNetMode() == NM_DedicatedServer);
	if (PawnToDelete != nullptr)
	{
		// TODO: what if the character is on a different worker?
		GetWorld()->DestroyActor(PawnToDelete);
		PawnToDelete = nullptr;
	}
}

void ATPSPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// HACK because sometimes (often?) Tick() runs (WAY) before BeginPlay(), or even before all the assigned-in-Blueprint variables have populated...
	// This appears to be an Unreal issue, not a GDK issue, as I ran into this in Vanilla Shooter as well.
	if (LoginUIWidgetTemplate != nullptr
		&& GetNetMode() == NM_Client
		&& Role == ROLE_AutonomousProxy
		&& !bHasShownLoginHud)
	{
		bHasShownLoginHud = true;
		SetLoginUIVisible(true);
	}
}
