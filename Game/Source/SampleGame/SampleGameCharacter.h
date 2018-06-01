// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EntityRegistry.h"
#include "GameFramework/Character.h"
#include "SampleGameCharacter.generated.h"

UCLASS(config=Game)
class ASampleGameCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	ASampleGameCharacter();

	virtual void BeginPlay() override;

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

public:
	// Returns a position from which to start a line trace.
	// Use this so your line trace doesn't collide with the player character.
	FVector GetLineTraceStart() const;

	// Returns the direction in which to perform a line trace so it lines up with the center of the crosshair.
	FVector GetLineTraceDirection() const;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	FORCEINLINE float GetCurrentHealth() const
	{
		return CurrentHealth;
	}

	FORCEINLINE float GetMaxHealth() const
	{
		return MaxHealth;
	}

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	// [client] Checks if the crosshair is pointing at an interactable object, and if so, calls Interact() on it.
	void Interact();

	// [client] Tells the server to spawn a test cube.
	void SpawnCube();

	// [server] Spawns a starter weapon and attaches it to the character.
	void SpawnStarterWeapon();

	// [client] Triggers the equipped weapon to start firing.
	void StartFire();

	// [client] Triggers the equipped weapon to stop firing.
	void StopFire();

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

	UPROPERTY(VisibleAnywhere, Replicated)
	class AWeapon* EquippedWeapon;

	// Weapon to spawn the player with initially.
	UPROPERTY(EditDefaultsOnly, Category = "Weapons")
	TSubclassOf<AWeapon> StarterWeaponTemplate;

	// Cube to spawn when the player presses "SpawnCube".
	UPROPERTY(EditDefaultsOnly, Category = "SampleGameDebugging")
	TSubclassOf<AActor> TestCubeTemplate;

	// Maximum distance at which the player can interact with objects.
	UPROPERTY(EditDefaultsOnly, Category = "Interaction", meta = (ClampMin = "0.0"))
	float InteractDistance;

	// Max health this character can have.
	UPROPERTY(EditDefaultsOnly, Category = "Health", meta = (ClampMin = "1"))
	int32 MaxHealth;

	// Current health of the character, can be at most MaxHealth.
	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_CurrentHealth, Category = "Health")
	int32 CurrentHealth;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

