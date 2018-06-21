// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGamePlayerController.h"

#include "SampleGamePlayerState.h"
#include "SampleGameCharacter.h"
#include "SampleGameLogging.h"
#include "UI/SampleGameHUD.h"
#include "UI/SampleGameLoginUI.h"
#include "UI/SampleGameUI.h"

#include "SpatialNetDriver.h"


ASampleGamePlayerController::ASampleGamePlayerController()
	: SampleGameUI(nullptr)
	, RespawnCharacterDelay(5.0f)
	, DeleteCharacterDelay(15.0f)
	, PawnToDelete(nullptr)
{
	// Don't automatically switch the camera view when the pawn changes, to avoid weird camera jumps when a character dies.
	bAutoManageActiveCameraTarget = false;
}

void ASampleGamePlayerController::EndPlay(const EEndPlayReason::Type Reason)
{
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void ASampleGamePlayerController::UpdateHealthUI(int32 NewHealth, int32 MaxHealth)
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

void ASampleGamePlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (GetNetMode() == NM_Client && bHasSubmittedLoginOptions)
	{
		SetPlayerUIVisible(InPawn != nullptr);

		ASampleGameCharacter* Character = Cast<ASampleGameCharacter>(InPawn);
		if (Character != nullptr)
		{
			UpdateHealthUI(Character->GetCurrentHealth(), Character->GetMaxHealth());

			// Make the new pawn's camera this controller's camera.
			SetViewTarget(InPawn);
		}
	}
}

void ASampleGamePlayerController::KillCharacter()
{
	check(GetNetMode() == NM_DedicatedServer);

	if (!HasAuthority())
	{
		return;
	}

	InternalKillCharacter(DeleteCharacterDelay);

	GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &ASampleGamePlayerController::RespawnCharacter, RespawnCharacterDelay);
}

void ASampleGamePlayerController::InternalKillCharacter(float DeleteCharacterDelayOverride)
{
	check(GetNetMode() == NM_DedicatedServer);

	if (!HasAuthority())
	{
		return;
	}

	PawnToDelete = GetPawn();
	UnPossess();

	// TODO: timers won't persist across worker boundary migrations, and neither will PawnToDelete
	GetWorldTimerManager().SetTimer(DeleteCharacterTimerHandle, this, &ASampleGamePlayerController::DeleteCharacter, DeleteCharacterDelayOverride);
}

void ASampleGamePlayerController::SetPlayerUIVisible(bool bIsVisible)
{
	check(GetNetMode() == NM_Client);

	ASampleGameHUD* HUD = Cast<ASampleGameHUD>(GetHUD());
	if (HUD != nullptr)
	{
		HUD->SetDrawCrosshair(bIsVisible);
	}

	if (bIsVisible)
	{
		if (SampleGameUI == nullptr)
		{
			check(UITemplate != nullptr);
			SampleGameUI = CreateWidget<USampleGameUI>(this, UITemplate);
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

void ASampleGamePlayerController::SetLoginUIVisible(bool bIsVisible)
{
	/// Lazy instantiate the Login UI
	if (SampleGameLoginUI == nullptr)
	{
		check(LoginUIWidgetTemplate != nullptr);
		SampleGameLoginUI = CreateWidget<USampleGameLoginUI>(this, LoginUIWidgetTemplate);
		
		/// Early out - Error case
		if (SampleGameLoginUI == nullptr)
		{
			// TODO jamcrow - Put some sort of check here or macro to deal with cases where networking has been switched to something other than SpatialOS?
			USpatialNetDriver* SpatialNetDriver = Cast<USpatialNetDriver>(GetNetDriver());
			UE_LOG(LogSampleGame, Error, TEXT("Failed to create Login UI for controller %s on worker %s"),
				*this->GetName(),
				SpatialNetDriver != nullptr ? *SpatialNetDriver->GetSpatialOS()->GetWorkerId() : TEXT("Invalid SpatialNetDriver"));

			return;
		}
	}

	/// Early out - If our visibility state is already set to the requested value, do nothing
	if (SampleGameLoginUI->IsVisible() == bIsVisible)
	{
		return;
	}

	if (bIsVisible)
	{
		/// Show the Login UI
		SampleGameLoginUI->AddToViewport();
		/// You tell that UI Widget who's boss...
		SampleGameLoginUI->SetOwnerPlayerController(this);
		/// Set Mouse Cursor to SHOW, and only interact with the UI
		bShowMouseCursor = true;
		SetIgnoreLookInput(true);
		SetIgnoreMoveInput(true);
	}
	else
	{
		/// Hide the Login UI
		SampleGameLoginUI->RemoveFromViewport();
		/// Hide the Mouse Cursor, restore Look and Move control
		bShowMouseCursor = false;
		SetIgnoreLookInput(false);
		SetIgnoreMoveInput(false);
	}
}

void ASampleGamePlayerController::ServerTryJoinGame_Implementation(const FString& NewPlayerName, const ESampleGameTeam NewPlayerTeam)
{
	check(GetNetMode() == NM_DedicatedServer);
	check(!bHasSubmittedLoginOptions);
	check(PlayerState != nullptr);
	check(PlayerState->IsA(ASampleGamePlayerState::StaticClass()));

	bool bJoinWasSuccessful = true;

	// TODO jamcrow - Validate the join request

	/// Inform Client as to whether or not join was accepted
	ClientJoinResults(bJoinWasSuccessful);
	
	if (bJoinWasSuccessful)
	{
		bHasSubmittedLoginOptions = true;

		/// Set the player-selected values
		PlayerState->SetPlayerName(NewPlayerName);
		((ASampleGamePlayerState*)PlayerState)->SetSelectedTeamFromEnum(NewPlayerTeam);

		// TODO jamcrow - Other team stuff?  Other player choices?

		/// Spawn the Pawn
		RespawnCharacter();
	}

}

bool ASampleGamePlayerController::ServerTryJoinGame_Validate(const FString& NewPlayerName, const ESampleGameTeam NewPlayerTeam)
{
	return true;
}

void ASampleGamePlayerController::ClientJoinResults_Implementation(const bool bJoinSucceeded)
{
	check(GetNetMode() == NM_Client);
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
}

bool ASampleGamePlayerController::ClientJoinResults_Validate(const bool bJoinSucceeded)
{
	return true;
}

void ASampleGamePlayerController::RespawnCharacter()
{
	check(GetNetMode() == NM_DedicatedServer);
	AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();
	if (GameMode != nullptr)
	{
		APawn* NewPawn = GameMode->SpawnDefaultPawnFor(this, StartSpot.Get());
		Possess(NewPawn);
	}
}

void ASampleGamePlayerController::DeleteCharacter()
{
	check(GetNetMode() == NM_DedicatedServer);
	if (PawnToDelete != nullptr)
	{
		// TODO: what if the character is on a different worker?
		GetWorld()->DestroyActor(PawnToDelete);
		PawnToDelete = nullptr;
	}
}

void ASampleGamePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	/// HACK because sometimes (often?) Tick() runs (WAY) before BeginPlay(), or even before all the assigned-in-Blueprint variables have populated...
	if (LoginUIWidgetTemplate != nullptr)
	{
		if (GetNetMode() == NM_Client && Role == ROLE_AutonomousProxy && !bHasShownLoginHud)
		{
			bHasShownLoginHud = true;
			/// PLAYER LOGIN UI
			SetLoginUIVisible(true);
		}
	}
}
