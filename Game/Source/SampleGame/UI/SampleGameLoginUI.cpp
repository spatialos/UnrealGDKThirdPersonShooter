
#include "SampleGameLoginUI.h"

#include "Characters/SampleGamePlayerController.h"
#include "SpatialNetDriver.h"


USampleGameLoginUI::USampleGameLoginUI(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), PlayerController(nullptr)
{
}

void USampleGameLoginUI::OnJoinGameButtonClicked() const
{
	check(PlayerController != nullptr)

	// Inform PlayerController, update PlayerState, etc
	PlayerController->TryJoinGame(PlayerName.ToString(), TeamId);
}

void USampleGameLoginUI::JoinGameWasRejected()
{
	// TODO: jamescrowder - Write validation failure code here.  Indicate which field(s) were the reason for rejection.
}
