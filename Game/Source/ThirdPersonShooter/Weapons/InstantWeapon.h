// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Weapon.h"
#include "InstantWeapon.generated.h"


// Tag for weapon line trace visualization.
const FName kTraceTag("TPSTrace");

USTRUCT()
struct FInstantHitInfo
{
	GENERATED_USTRUCT_BODY()

	// Location of the hit in world space.
	UPROPERTY()
	FVector Location;

	// Actor that was hit, or nullptr if nothing was hit.
	UPROPERTY()
	AActor* HitActor;

	FInstantHitInfo() :
		Location(FVector{ 0,0,0 }),
		HitActor(nullptr)
	{}
};


/**
 * AInstantWeapon implements hitscan shooting for a single-shot, burst-fire, or full-auto weapon.
 * Hit detection is entirely client-side, with loose server validation.
 * Shot timing and rate-limiting is entirely client-side, with no server validation.
 */
UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API AInstantWeapon : public AWeapon
{
	GENERATED_BODY()
	
public:
	AInstantWeapon();

	virtual void StartFire() override;

	virtual void StopFire() override;

	// RPC for telling the server that we fired and hit something.
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDidHit(const FInstantHitInfo& HitInfo);
	bool ServerDidHit_Validate(const FInstantHitInfo& HitInfo);
	void ServerDidHit_Implementation(const FInstantHitInfo& HitInfo);

	// RPC for telling the server that we fired and did not hit anything.
	UFUNCTION(Server, Unreliable, WithValidation)
	void ServerDidMiss(const FInstantHitInfo& HitInfo);
	bool ServerDidMiss_Validate(const FInstantHitInfo& HitInfo);
	void ServerDidMiss_Implementation(const FInstantHitInfo& HitInfo);

	const AActor* GetWeilder() const { return GetAttachmentReplication().AttachParent; }

protected:
	virtual void BeginPlay() override;

	// [client] Runs a line trace and triggers the server RPC for hits.
	virtual void DoFire();

private:
	// [client] Performs a line trace and populates OutHitInfo based on the results.
	// Returns true if it hits anything, false otherwise.
	bool DoLineTrace(FInstantHitInfo& OutHitInfo);

	// [server] Notifies clients of a hit.
	void NotifyClientsOfHit(const FInstantHitInfo& HitInfo);

	// [client] Spawns the hit FX in the world.
	void SpawnHitFX(const FInstantHitInfo& HitInfo);

	// [server] Validates the hit. Returns true if it's valid, false otherwise.
	bool ValidateHit(const FInstantHitInfo& HitInfo);

	// [server] Actually deals damage to the actor we hit.
	void DealDamage(const FInstantHitInfo& HitInfo);

	// [client] Clears the NextShotTimer if it's running.
	void ClearTimerIfRunning();

	// [client] Actually stops the weapon firing.
	void StopFiring();

	// Notifies all clients that a shot hit something. Used for visualizing shots on the client.
	UFUNCTION(NetMulticast, Unreliable)
	void MulticastNotifyHit(FInstantHitInfo HitInfo);

	// Returns true if the weapon is a burst-fire weapon.
	FORCEINLINE bool IsBurstFire()
	{
		return BurstCount > 1;
	}

	// Returns true if the weapon is fully-automatic.
	FORCEINLINE bool IsFullyAutomatic()
	{
		return BurstCount < 1;
	}

	// Minimum time between bursts (or shots, if in single-shot or automatic mode), in seconds.
	// 0 = as fast as you can pull the trigger
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float BurstInterval;

	// Number of shots in a single burst.
	// 0  = full-auto
	// 1  = single-shot
	// >1 = burst fire
	UPROPERTY(EditAnywhere, Category = "Weapons")
	int32 BurstCount;

	// Interval between individual shots within a burst, in seconds.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float BurstShotInterval;

	// Time (in seconds since start of level) since the last burst fire. Used for limiting fire rate.
	float LastBurstTime;

	// Number of shots remaining in the current burst.
	int32 BurstShotsRemaining;

	// Maximum range of the weapon's hitscan.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float MaxRange;

	// Base damage done to others by a single shot.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float ShotBaseDamage;

	// Tolerance, in world units, to add to the bounding box of an actor when validating hits.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	float HitValidationTolerance;

	// Type of damage to send to hit actors.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	TSubclassOf<UDamageType> DamageTypeClass;

	// Template for the particle system to spawn in the world on hits.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	class UParticleSystem* HitFXTemplate;

	// Tolerance, in seconds, after which we will no longer visualize a shot notification.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	FTimespan ShotVisualizationDelayTolerance;

	// If true, draws debug line traces for hitscan shots.
	UPROPERTY(EditAnywhere, Category = "Weapons")
	bool bDrawDebugLineTrace;

	// Timer that handles firing the next shot.
	FTimerHandle NextShotTimer;

	// Delegate for running the next shot method.
	FTimerDelegate NextShotTimerDelegate;
};
