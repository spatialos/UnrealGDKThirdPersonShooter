
#include "SampleGameLoginUI.h"
#include "SampleGamePlayerController.h"

void USampleGameLoginUI::OnJoinGameButtonClicked() const
{
	check(PlayerController != nullptr)

	/// Update PlayerController, PlayerState, etc
	PlayerController->ServerTryJoinGame(PlayerName.ToString(), TeamId);
}

void USampleGameLoginUI::JoinGameWasRejected()
{
	// TODO jamcrow - Write validation failure code here.  Indicate which field(s) were the reason for rejection.
}
