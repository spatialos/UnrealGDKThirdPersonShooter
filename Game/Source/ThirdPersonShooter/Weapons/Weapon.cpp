// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "Weapon.h"

#include "Characters/TPSCharacter.h"
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
	DOREPLIFETIME(AWeapon, Team);
}

EWeaponState AWeapon::GetWeaponState() const
{
	return CurrentState;
}

void AWeapon::SetWeaponState(EWeaponState NewState)
{
	CurrentState = NewState;
}

void AWeapon::OnRep_Team()
{
	if (GetNetMode() == NM_DedicatedServer)
	{
		return;
	}

	UpdateTeamColor();
}

void AWeapon::SetTeam(ETPSTeam NewTeam)
{
	Team = NewTeam;
}

ETPSTeam AWeapon::GetTeam() const
{
	return Team;
}

void AWeapon::UpdateTeamColor()
{
	check(NoneTeamMaterial != nullptr);
	check(RedTeamMaterial != nullptr);
	check(BlueTeamMaterial != nullptr);
	check(PurpleTeamMaterial != nullptr);
	check(YellowTeamMaterial != nullptr);
	check(Mesh != nullptr);

	switch (Team)
	{
	case ETPSTeam::Team_Red:
		Mesh->SetMaterial(0, RedTeamMaterial);
		Mesh->SetMaterial(1, RedTeamMaterial);
		break;
	case ETPSTeam::Team_Blue:
		Mesh->SetMaterial(0, BlueTeamMaterial);
		Mesh->SetMaterial(1, BlueTeamMaterial);
		break;
	case ETPSTeam::Team_Purple:
		Mesh->SetMaterial(0, PurpleTeamMaterial);
		Mesh->SetMaterial(1, PurpleTeamMaterial);
		break;
	case ETPSTeam::Team_Yellow:
		Mesh->SetMaterial(0, YellowTeamMaterial);
		Mesh->SetMaterial(1, YellowTeamMaterial);
		break;
	default:
		// If team value has not yet replicated, use the temporary colors
		Mesh->SetMaterial(0, NoneTeamMaterial);
		Mesh->SetMaterial(1, NoneTeamMaterial);
		break;
	}
}
