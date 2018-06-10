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

/// -= Blueprint Control Bindings =-
public:
	/// Team Selection
	/// - Value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player_Team)
	ESampleGameTeam TeamId;	// NOTE - uint8 can support up to 255 total teams.  For games with more teams, use int32 instead (uint32 isn't supported by UE4 Blueprints)
	/// - Accessors
	UFUNCTION(BlueprintPure, Category = Player_Team)
	ESampleGameTeam GetTeamId() const { return TeamId; }
	UFUNCTION(BlueprintCallable, Category = Player_Team)
	void SetTeamId(const ESampleGameTeam& NewTeamId) { TeamId = NewTeamId; }

	/// Name Input
	/// - Value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player_Name)
	FText PlayerName;
	/// - Accessors
	UFUNCTION(BlueprintPure, Category = Player_Name)
	FText GetPlayerName() const { return PlayerName; }
	UFUNCTION(BlueprintCallable, Category = Player_Name)
	void SetPlayerName(const FText& NewName) { PlayerName = NewName; }

	/// Join Game
	UFUNCTION(BlueprintPure, Category = "Widgets")
	bool IsJoinGameButtonEnabled() const { return (!PlayerName.IsEmptyOrWhitespace()); }
	UFUNCTION(BlueprintCallable, Category = "Widgets")
	void OnJoinGameButtonClicked() const;

/// -= Class Functionality =-
private:
	ASampleGamePlayerController* PlayerController = nullptr;

public:
	void SetMyPlayerController(ASampleGamePlayerController* NewPlayerContoller) { PlayerController = NewPlayerContoller; }
	void JoinGameWasRejected();
};
