// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EntityRegistry.h"
#include "GameFramework/Character.h"
#include "TestCube.h"
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

	UPROPERTY(VisibleAnywhere, Replicated)
	class AWeapon* EquippedWeapon;

	// Weapon to spawn the player with initially.
	UPROPERTY(EditAnywhere, Category = "SampleGame")
	TSubclassOf<AWeapon> StarterWeaponTemplate;

	// Cube to spawn when the player presses "SpawnCube".
	UPROPERTY(EditAnywhere, Category = "SampleGame")
	TSubclassOf<ATestCube> TestCubeTemplate;

	// Maximum distance at which the player can interact with objects.
	UPROPERTY(EditAnywhere, Category = "SampleGame")
	float InteractDistance;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

