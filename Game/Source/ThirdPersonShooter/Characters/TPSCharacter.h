// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EntityRegistry.h"
#include "GameFramework/Character.h"
#include "Teams/TPSTeams.h"
#include "TPSCharacter.generated.h"

UCLASS(SpatialType, config = Game)
class ATPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATPSCharacter(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	void StartSprinting();

	void StopSprinting();

public:
	// Returns a position from which to start a line trace.
	// Use this so your line trace doesn't collide with the player character.
	FVector GetLineTraceStart() const;

	// Returns the direction in which to perform a line trace so it lines up with the center of the crosshair.
	FVector GetLineTraceDirection() const;

	// Returns the player's name, as specified on login.
	FString GetPlayerName() const;

	float TakeDamage(float Damage, const struct FDamageEvent& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(CrossServer, Reliable)
	void TakeGunDamageCrossServer(float Damage, const struct FDamageEvent& DamageEvent, AController* EventInstigator, AActor* DamageCauser);

	FORCEINLINE float GetCurrentHealth() const
	{
		return CurrentHealth;
	}

	FORCEINLINE float GetMaxHealth() const
	{
		return MaxHealth;
	}

	// [server + client] Returns true if the character is currently sprinting.
	UFUNCTION(BlueprintPure, Category = "Movement")
	bool IsSprinting();

	UFUNCTION(BlueprintPure, Category = "Aim")
	float GetAimYaw();

	UFUNCTION(BlueprintPure, Category = "Aim")
	float GetAimPitch();

	// [server + client] Returns true if the character is able to shoot at the given moment.
	bool CanFire();

	// [client] Triggers the equipped weapon to start firing.
	void StartFire();

	// [client] Triggers the equipped weapon to stop firing.
	void StopFire();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	// [client] If true, the character should ignore all action inputs.
	bool IgnoreActionInput() const;

	// [client] Checks if the crosshair is pointing at an interactable object, and if so, calls Interact() on it.
	void Interact();

	// [client] Tells the server to spawn a test cube.
	void SpawnCube();

	// [server] Spawns a starter weapon and attaches it to the character.
	void SpawnStarterWeapon();

	// [server] Tells this player that it's time to die.
	// @param Killer  The player who killed me. Can be null if it wasn't a player who dealt the damage that killed me.
	void Die(const class ATPSCharacter* Killer);

	// [client + server] Puts the player in ragdoll mode.
	void StartRagdoll();

	// [owning client + server] Updates the aim variables to be sync-ed out to clients, or updates the values locally
	// if we're executing on the owning client.
	// Will only update the angles if they differ from the current stored value by more than AngleUpdateThreshold.
	void UpdateAimRotation(float AngleUpdateThreshold);

	// Returns the currently equipped weapon, or nullptr if there isn't one.
	class AWeapon* GetEquippedWeapon() const;

	// RPC to tell the server to spawn a test cube.
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSpawnCube();

	// Debug RPC to tell the server to reset all of the characters stats (weapons, health, etc.)
	UFUNCTION(Server, Reliable, WithValidation)
	void DebugResetCharacter();

	UFUNCTION()
	void OnRep_CurrentHealth();

	UFUNCTION()
	void OnRep_IsRagdoll();

	UFUNCTION()
	void OnRep_Team();

	UPROPERTY(VisibleAnywhere, Replicated)
	class AWeapon* EquippedWeapon;

	// Weapon to spawn the player with initially.
	UPROPERTY(EditDefaultsOnly, Category = "Weapons")
	TSubclassOf<AWeapon> StarterWeaponTemplate;

	// Cube to spawn when the player presses "SpawnCube".
	UPROPERTY(EditDefaultsOnly, Category = "Test Cube")
	TSubclassOf<AActor> TestCubeTemplate;

	// Maximum distance at which the player can interact with objects.
	UPROPERTY(EditDefaultsOnly, Category = "Interaction", meta = (ClampMin = "0.0"))
	float InteractDistance;

	// Max health this character can have.
	UPROPERTY(EditDefaultsOnly, Category = "Health", meta = (ClampMin = "1"))
	int32 MaxHealth;

	// Current health of the character, can be at most MaxHealth.
	UPROPERTY(ReplicatedUsing = OnRep_CurrentHealth)
	int32 CurrentHealth;

	// If true, the character is currently ragdoll-ing.
	UPROPERTY(ReplicatedUsing = OnRep_IsRagdoll)
	bool bIsRagdoll;

	// Used for telling clients where the player should appear to be looking.
	UPROPERTY(VisibleAnywhere, Replicated, Category = "Aim")
	float AimYaw;

	// Used for telling clients where the player should appear to be looking.
	UPROPERTY(VisibleAnywhere, Replicated, Category = "Aim")
	float AimPitch;

	// If the aim offset angles change more than this threshold, update our local aim offset values (only applies on the owning client).
	// Value is in degrees.
	UPROPERTY(EditDefaultsOnly, Category = "Aim")
	float LocalAimUpdateThreshold;

	// If the aim offset angles change more than this threshold, update our replicated aim offset values.
	// Value is in degrees.
	UPROPERTY(EditDefaultsOnly, Category = "Aim")
	float RemoteAimUpdateThreshold;

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	// Indicates which team this Character is associated with
	UPROPERTY(ReplicatedUsing = OnRep_Team)
	ETPSTeam Team;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Team Appearance")
	UMaterialInstance* NoneTeamMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Team Appearance")
	UMaterialInstance* RedTeamMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Team Appearance")
	UMaterialInstance* GreenTeamMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Team Appearance")
	UMaterialInstance* BlueTeamMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Team Appearance")
	UMaterialInstance* YellowTeamMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Team Appearance")
	UMaterialInstance* PurpleTeamMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Team Appearance")
	UMaterialInstance* BlackTeamMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Team Appearance")
	UMaterialInstance* WhiteTeamMaterial;

public:
	// Change the color of this character to match their chosen team
	UFUNCTION()
	void UpdateTeamColor();

	// [server] Sets the Character's Team value.
	void SetTeam(ETPSTeam NewTeam);

	// Returns the current value of Team.
	ETPSTeam GetTeam() const;
};

