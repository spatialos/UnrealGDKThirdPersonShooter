// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "Weapon.h"

#include "Characters/TPSCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "UnrealNetwork.h"


AWeapon::AWeapon()
	: CurrentState(EWeaponState::Idle)
	, OwningCharacter(nullptr)
{
	PrimaryActorTick.bCanEverTick = false;
	
	bReplicates = true;
	bReplicateMovement = true;

	LocationComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(LocationComponent);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	Mesh->SetupAttachment(RootComponent);
}

class ATPSCharacter* AWeapon::GetOwningCharacter() const
{
	return OwningCharacter;
}

void AWeapon::SetOwningCharacter(ATPSCharacter* NewCharacter)
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
