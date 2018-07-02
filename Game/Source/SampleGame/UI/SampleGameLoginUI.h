#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Teams/SampleGameTeams.h"
#include "SampleGameLoginUI.generated.h"

class ASampleGamePlayerController;

UCLASS(BlueprintType, Blueprintable)
class SAMPLEGAME_API USampleGameLoginUI : public UUserWidget
{
	GENERATED_BODY()

// -= Blueprint Control Bindings =-
public:
	USampleGameLoginUI(const FObjectInitializer& ObjectInitializer);

	// Team Selection
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player_Team)
	ESampleGameTeam TeamId;

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
	ASampleGamePlayerController* PlayerController;

public:
	// Informs the UI Widget which PlayerController instance is controlling it.  Must be called and given a valid PlayerController before 'OnJoinGameButtonClicked' can be invoked.
	void SetOwnerPlayerController(ASampleGamePlayerController* NewPlayerContoller) { PlayerController = NewPlayerContoller; }

	// This method will be called from PlayerController if the join request sent by 'OnJoinGameButtonClicked' to 'PlayerController' fails server-side.
	void JoinGameWasRejected();
};
