#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SampleGameLoginUI.generated.h"

UCLASS(BlueprintType, Blueprintable)
class SAMPLEGAME_API USampleGameLoginUI : public UUserWidget
{
	GENERATED_BODY()

/// Blueprint Control Bindings
public:
	/// Team Selection
	/// - Value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player_Team)
	uint8 TeamId;	// NOTE - uint8 can support up to 255 total teams.  For games with more teams, use int32 instead (uint32 isn't supported by UE4 Blueprints)
	/// - Accessors
	UFUNCTION(BlueprintPure, Category = Player_Team)
	uint8 GetTeamId() const { return TeamId; }
	UFUNCTION(BlueprintCallable, Category = Player_Team)
	void SetTeamId(const uint8& NewTeamId) { TeamId = NewTeamId; }

	/// Name Input
	/// - Value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player_Name)
	FText PlayerName;
	/// - Accessors
	UFUNCTION(BlueprintPure, Category = Player_Name)
	FText GetPlayerName() const { return PlayerName; }
	UFUNCTION(BlueprintCallable, Category = Player_Name)
	void SetPlayerName(const FText& NewName) { PlayerName = NewName; }

private:

/// UI Functionality
public:
	void SubmitWasRejected();
};
