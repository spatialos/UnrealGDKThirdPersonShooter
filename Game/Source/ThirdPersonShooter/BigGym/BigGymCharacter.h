// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BigGymCharacter.generated.h"

UCLASS(config=Game, SpatialType)
class ABigGymCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UInteractionManager* InteractionManager;

public:
	ABigGymCharacter();

	virtual void BeginPlay() override;

	virtual void OnAuthorityGained() override;

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

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerInteract(AActor* Target);

	void Interact();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSpawnDebugActor();
	void SpawnDebugActor();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDestroyHitActor(AActor* HitActor);
	void DestroyHitActor();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerQueryHitActor(AActor* HitActor);
	void QueryHitActor();
	void QueryActor(AActor* Actor);

	AActor* LineTrace() const;

	UFUNCTION(Server, Reliable, WithValidation)
	void TestRPC();

	UFUNCTION(NetMulticast, Unreliable, WithValidation)
	void TestMulticast();

	UPROPERTY(EditDefaultsOnly, Category = "Testing")
	TSubclassOf<AActor> SpawnActorTemplate;
	UPROPERTY(EditDefaultsOnly, Category = "Testing")
	FVector SpawnActorOffset;

	UPROPERTY(EditDefaultsOnly, Category = "Testing")
	FString PackageToLoad;
	UPROPERTY(EditDefaultsOnly, Category = "Testing")
	FString AssetToLoad;

	UPROPERTY(EditDefaultsOnly, Category = "Testing")
	TSubclassOf<class ACompanion> CompanionTemplate;

	UPROPERTY(Replicated)
	AActor* Companion;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

