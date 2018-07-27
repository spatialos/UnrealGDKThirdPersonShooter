#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Teams/TPSTeams.h"
#include "TPSLoginUI.generated.h"

class ATPSPlayerController;

UCLASS(BlueprintType, Blueprintable)
class THIRDPERSONSHOOTER_API UTPSLoginUI : public UUserWidget
{
	GENERATED_BODY()

// -= Blueprint Control Bindings =-
public:
	UTPSLoginUI(const FObjectInitializer& ObjectInitializer);

	// Team Selection
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player_Team)
	ETPSTeam TeamId;

	// Name Input
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player_Name)
	FText PlayerName;

	// Join Game
	UFUNCTION(BlueprintPure, Category = "Widgets")
	bool IsJoinGameButtonEnabled() const { return (!PlayerName.IsEmptyOrWhitespace()); }

	UFUNCTION(BlueprintCallable, Category = "Widgets")
	void OnJoinGameButtonClicked() const;

	UFUNCTION(BlueprintPure, Category = "Debug")
	bool IsAutoJoinReady() const { return (PlayerController != nullptr); }

// -= Class Functionality =-
private:
	ATPSPlayerController* PlayerController;

public:
	// Informs the UI Widget which PlayerController instance is controlling it.  Must be called and given a valid PlayerController before 'OnJoinGameButtonClicked' can be invoked.
	void SetOwnerPlayerController(ATPSPlayerController* NewPlayerContoller) { PlayerController = NewPlayerContoller; }

	// This method will be called from PlayerController if the join request sent by 'OnJoinGameButtonClicked' to 'PlayerController' fails server-side.
	void JoinGameWasRejected();
};
