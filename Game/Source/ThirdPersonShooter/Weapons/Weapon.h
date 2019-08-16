// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Teams/TPSTeams.h"
#include "Weapon.generated.h"


enum class EWeaponState : uint8
{
	Idle,
	Firing
};

UCLASS(Abstract)
class THIRDPERSONSHOOTER_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();

	// [client] Starts firing the weapon.
	virtual void StartFire() PURE_VIRTUAL(AWeapon::StartFire,);

	// [client] Stops firing the weapon.
	virtual void StopFire() PURE_VIRTUAL(AWeapon::StopFire,);

	class ATPSCharacter* GetOwningCharacter() const;
	void SetOwningCharacter(class ATPSCharacter* NewCharacter);

	// Indicates which team this Gun is associated with
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_Team)
	ETPSTeam Team;

	// Change the color of this gun to match their owners team
	UFUNCTION()
	void UpdateTeamColor();

	// [server] Sets the Weapon's Team value.
	void SetTeam(ETPSTeam NewTeam);

	// Returns the current value of Team.
	ETPSTeam GetTeam() const;

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	EWeaponState GetWeaponState() const;
	void SetWeaponState(EWeaponState NewState);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Team Appearance")
	UMaterialInstance* NoneTeamMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Team Appearance")
	UMaterialInstance* RedTeamMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Team Appearance")
	UMaterialInstance* BlueTeamMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Team Appearance")
	UMaterialInstance* YellowTeamMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Team Appearance")
	UMaterialInstance* PurpleTeamMaterial;
	
private:
	EWeaponState CurrentState;

	// Set up a root component so this actor can have a position in the world.
	class USceneComponent* LocationComponent;

	// Character that currently owns this weapon.
	UPROPERTY(Replicated)
	class ATPSCharacter* OwningCharacter;

	// Weapon mesh.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons", meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* Mesh;

	UFUNCTION()
	void OnRep_Team();
	
};
