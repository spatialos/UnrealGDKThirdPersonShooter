// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"


enum class EWeaponState : uint8
{
	Idle,
	Firing
};

UCLASS(Abstract)
class SAMPLEGAME_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();

	// [client] Starts firing the weapon.
	virtual void StartFire() PURE_VIRTUAL(AWeapon::StartFire,);

	// [client] Stops firing the weapon.
	virtual void StopFire() PURE_VIRTUAL(AWeapon::StopFire,);

	class ASampleGameCharacter* GetOwningCharacter() const;
	void SetOwningCharacter(class ASampleGameCharacter* NewCharacter);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	EWeaponState GetWeaponState() const;
	void SetWeaponState(EWeaponState NewState);
	
private:
	EWeaponState CurrentState;

	// Set up a root component so this actor can have a position in the world.
	class USceneComponent* LocationComponent;

	// Character that currently owns this weapon.
	UPROPERTY(Replicated)
	class ASampleGameCharacter* OwningCharacter;

	// Weapon mesh.
	UPROPERTY(VisibleAnywhere, Category = "Weapons", meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* Mesh;
	
};
