
#include "SampleGameLoginUI.h"

#include "SpatialNetDriver.h"
#include "SampleGamePlayerController.h"


USampleGameLoginUI::USampleGameLoginUI(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), PlayerController(nullptr)
{
}

void USampleGameLoginUI::OnJoinGameButtonClicked() const
{
	check(PlayerController != nullptr)

	// Inform PlayerController, update PlayerState, etc
	PlayerController->ServerTryJoinGame(PlayerName.ToString(), TeamId);
}

void USampleGameLoginUI::SetAutomaticName()
{
	if (USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(GetOwningPlayer()->GetNetDriver()))
	{
		PlayerName = FText::FromString(NetDriver->GetSpatialOS()->GetWorkerId());
	}
	else
	{
		PlayerName = FText::FromString("Player" + FGuid::NewGuid().ToString());
	}
}

void USampleGameLoginUI::JoinGameWasRejected()
{
	// TODO: jamescrowder - Write validation failure code here.  Indicate which field(s) were the reason for rejection.
}
