
#include "TPSLoginUI.h"

#include "Characters/TPSPlayerController.h"
#include "SpatialNetDriver.h"


UTPSLoginUI::UTPSLoginUI(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), PlayerController(nullptr)
{
}

void UTPSLoginUI::OnJoinGameButtonClicked() const
{
	check(PlayerController != nullptr)

	// Inform PlayerController, update PlayerState, etc
	PlayerController->TryJoinGame(PlayerName.ToString(), TeamId);
}

void UTPSLoginUI::JoinGameWasRejected()
{
	// TODO: jamescrowder - Write validation failure code here.  Indicate which field(s) were the reason for rejection.
}
