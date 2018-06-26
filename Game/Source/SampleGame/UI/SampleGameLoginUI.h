#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SampleGameTeams.h"
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
	ESampleGameTeam TeamId;	// NOTE - uint8 can support up to 255 total teams.  For games with more teams, use int32 instead (uint32 isn't supported by UE4 Blueprints)

	// Name Input
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player_Name)
	FText PlayerName;

	// Join Game
	UFUNCTION(BlueprintPure, Category = "Widgets")
	bool IsJoinGameButtonEnabled() const { return (!PlayerName.IsEmptyOrWhitespace()); }

	UFUNCTION(BlueprintCallable, Category = "Widgets")
	void OnJoinGameButtonClicked() const;

// -= Class Functionality =-
private:
	ASampleGamePlayerController* PlayerController;

public:
	void SetOwnerPlayerController(ASampleGamePlayerController* NewPlayerContoller) { PlayerController = NewPlayerContoller; }

	void JoinGameWasRejected();
};
