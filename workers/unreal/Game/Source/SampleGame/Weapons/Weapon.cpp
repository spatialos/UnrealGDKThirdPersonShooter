// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "Weapon.h"

#include "Engine/World.h"
#include "SampleGameCharacter.h"
#include "UnrealNetwork.h"


AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
	
	bReplicates = true;
	bReplicateMovement = true;

	LocationComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(LocationComponent);

	CurrentState = EWeaponState::Idle;
	OwningCharacter = nullptr;
}

class ASampleGameCharacter* AWeapon::GetOwningCharacter() const
{
	return OwningCharacter;
}

void AWeapon::SetOwningCharacter(ASampleGameCharacter* NewCharacter)
{
	OwningCharacter = NewCharacter;
}

void AWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWeapon, OwningCharacter);
}

EWeaponState AWeapon::GetWeaponState() const
{
	return CurrentState;
}

void AWeapon::SetWeaponState(EWeaponState NewState)
{
	CurrentState = NewState;
}
