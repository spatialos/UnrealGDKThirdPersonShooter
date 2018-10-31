// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "Characters/TPSCharacter.h"

#include "Camera/CameraComponent.h"
#include "Characters/TPSPlayerController.h"
#include "Characters/TPSPlayerState.h"
#include "Characters/TPSCharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Game/TPSGameState.h"
#include "Interactable.h"
#include "Kismet/GameplayStatics.h"
#include "TPSLogging.h"
#include "SpatialNetDriver.h"
#include "UnrealNetwork.h"
#include "Weapons/InstantWeapon.h"


static const FName kRightGunSocketName("GunSocket_r");

ATPSCharacter::ATPSCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UTPSCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	EquippedWeapon = nullptr;
	InteractDistance = 500.0f;
	MaxHealth = 100;
	CurrentHealth = MaxHealth;
	bIsRagdoll = false;
	AimYaw = 0.0f;
	AimPitch = 0.0f;
	LocalAimUpdateThreshold = 0.01f;
	RemoteAimUpdateThreshold = 2.0f;
}

void ATPSCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Only spawn a new starter weapon if we're authoritative and don't already have one.
	if (HasAuthority())
	{
		// Short delay as a workaround for actor references potentially not being resolved when this actor gets checked out.
		FTimerHandle TimerHandle;
		FTimerDelegate TimerDelegate;
		TimerDelegate.BindLambda([this]() {
			UE_LOG(LogTPS, Log, TEXT("%s EquippedWeapon: %s"), *this->GetName(), EquippedWeapon == nullptr ? TEXT("nullptr") : *EquippedWeapon->GetName());
			if (GetEquippedWeapon() == nullptr)
			{
				SpawnStarterWeapon();
			}
		});
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, 0.2f, false);

		CurrentHealth = MaxHealth;
	}
}

void ATPSCharacter::Tick(float DeltaSeconds)
{
	if (Role == ROLE_Authority)
	{
		UpdateAimRotation(RemoteAimUpdateThreshold);
	}
	else if (Role == ROLE_AutonomousProxy)
	{
		UpdateAimRotation(LocalAimUpdateThreshold);
	}

	Super::Tick(DeltaSeconds);
}

void ATPSCharacter::UpdateTeamColor()
{
	check(NoneTeamMaterial != nullptr);
	check(RedTeamMaterial != nullptr);
	check(GreenTeamMaterial != nullptr);
	check(BlueTeamMaterial != nullptr);
	check(PurpleTeamMaterial != nullptr);
	check(YellowTeamMaterial != nullptr);
	check(BlackTeamMaterial != nullptr);
	check(WhiteTeamMaterial != nullptr);

	USkeletalMeshComponent* CharacterMesh = GetMesh();

	switch (Team)
	{
	case ETPSTeam::Team_Red:
		CharacterMesh->SetMaterial(0, RedTeamMaterial);
		break;
	case ETPSTeam::Team_Green:
		CharacterMesh->SetMaterial(0, GreenTeamMaterial);
		break;
	case ETPSTeam::Team_Blue:
		CharacterMesh->SetMaterial(0, BlueTeamMaterial);
		break;
	case ETPSTeam::Team_Purple:
		CharacterMesh->SetMaterial(0, PurpleTeamMaterial);
		break;
	case ETPSTeam::Team_Yellow:
		CharacterMesh->SetMaterial(0, YellowTeamMaterial);
		break;
	case ETPSTeam::Team_Black:
		CharacterMesh->SetMaterial(0, BlackTeamMaterial);
		break;
	case ETPSTeam::Team_White:
		CharacterMesh->SetMaterial(0, WhiteTeamMaterial);
		break;
	case ETPSTeam::Team_None:
	default:
		// If team value has not yet replicated, use the temporary colors
		CharacterMesh->SetMaterial(0, NoneTeamMaterial);
		break;
	}
}

void ATPSCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATPSCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ATPSCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ATPSCharacter::LookUpAtRate);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ATPSCharacter::StartSprinting);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ATPSCharacter::StopSprinting);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ATPSCharacter::Interact);
	PlayerInputComponent->BindAction("SpawnCube", IE_Pressed, this, &ATPSCharacter::SpawnCube);
	PlayerInputComponent->BindAction("DebugResetCharacter", IE_Pressed, this, &ATPSCharacter::DebugResetCharacter);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ATPSCharacter::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &ATPSCharacter::StopFire);
}

void ATPSCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATPSCharacter, EquippedWeapon);
	DOREPLIFETIME(ATPSCharacter, bIsRagdoll);
	DOREPLIFETIME(ATPSCharacter, Team);

	// Skip the owner here because we're updating the values locally on the owning client.
	DOREPLIFETIME_CONDITION(ATPSCharacter, AimYaw, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(ATPSCharacter, AimPitch, COND_SkipOwner);
}

bool ATPSCharacter::IgnoreActionInput() const
{
	check(GetNetMode() != NM_DedicatedServer);

	if (ATPSPlayerController* PC = Cast<ATPSPlayerController>(GetController()))
	{
		return PC->IgnoreActionInput();
	}
	return false;
}

void ATPSCharacter::Interact()
{
	check(GetNetMode() == NM_Client);

	if (IgnoreActionInput())
	{
		return;
	}

	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("TPS_Trace")), true, this);
	TraceParams.bTraceComplex = true;
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = false;

	FHitResult HitResult(ForceInit);
	FVector TraceStart = GetFollowCamera()->GetComponentLocation();
	FVector TraceEnd = TraceStart + GetFollowCamera()->GetForwardVector() * InteractDistance;

	bool bDidHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		TraceStart,
		TraceEnd,
		ECC_Visibility,
		TraceParams);

	if (!bDidHit)
	{
		return;
	}

	// Do the interface check this way so it catches both C++ and Blueprint implementations (cast will only catch C++).
	if (HitResult.GetActor()->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
	{
		IInteractable::Execute_Interact(HitResult.GetActor(), this);
	}
}

void ATPSCharacter::SpawnCube()
{
	if (IgnoreActionInput())
	{
		return;
	}

	ServerSpawnCube();
}

void ATPSCharacter::SpawnStarterWeapon()
{
	if (!HasAuthority())
	{
		return;
	}

	if (StarterWeaponTemplate == nullptr)
	{
		UE_LOG(LogTPS, Warning, TEXT("No starter weapon defined."));
		return;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	AWeapon* StartWeapon = GetWorld()->SpawnActor<AWeapon>(StarterWeaponTemplate, GetActorTransform(), SpawnParams);
	StartWeapon->SetOwningCharacter(this);
	StartWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, kRightGunSocketName);

	UE_LOG(LogTPS, Log, TEXT("Set weapon for character %s to %s"), *this->GetName(), *StartWeapon->GetName());
	EquippedWeapon = StartWeapon;
}

void ATPSCharacter::StartFire()
{
	check(GetNetMode() != NM_DedicatedServer);

	if (IgnoreActionInput())
	{
		return;
	}

	AWeapon* Weapon = GetEquippedWeapon();
	if (Weapon != nullptr)
	{
		// Don't allow sprinting and shooting at the same time.
		StopSprinting();

		Weapon->StartFire();
	}
}

void ATPSCharacter::StopFire()
{
	check(GetNetMode() != NM_DedicatedServer);

	if (IgnoreActionInput())
	{
		return;
	}

	AWeapon* Weapon = GetEquippedWeapon();
	if (Weapon != nullptr)
	{
		Weapon->StopFire();
	}
}

void ATPSCharacter::Die(const ATPSCharacter* Killer)
{
	if (GetNetMode() == NM_DedicatedServer && HasAuthority())
	{
		ATPSPlayerController* PC = Cast<ATPSPlayerController>(GetController());
		if (PC)
		{
			PC->KillCharacter(Killer);
		}

		// Destroy weapon actor if there is one.
		if (EquippedWeapon != nullptr && !EquippedWeapon->IsPendingKill())
		{
			GetWorld()->DestroyActor(EquippedWeapon);
		}

		bIsRagdoll = true;
		OnRep_IsRagdoll();
	}
}

void ATPSCharacter::StartRagdoll()
{
	// Disable capsule collision and disable movement.
	UCapsuleComponent* CapsuleComponent = GetCapsuleComponent();
	if (CapsuleComponent == nullptr)
	{
		UE_LOG(LogTPS, Error, TEXT("Invalid capsule component on character %s"), *this->GetName());
		return;
	}
	CapsuleComponent->SetSimulatePhysics(false);
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetCharacterMovement()->DisableMovement();

	// Enable mesh collision and physics.
	USkeletalMeshComponent* MeshComponent = GetMesh();
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	MeshComponent->SetCollisionProfileName(FName(TEXT("Ragdoll")));
	MeshComponent->SetSimulatePhysics(true);

	// Gather list of child components of the capsule.
	TArray<USceneComponent*> ComponentsToMove;
	int NumChildren = CapsuleComponent->GetNumChildrenComponents();
	for (int i = 0; i < NumChildren; ++i)
	{
		USceneComponent* Component = CapsuleComponent->GetChildComponent(i);
		if (Component != nullptr && Component != MeshComponent)
		{
			ComponentsToMove.Add(Component);
		}
	}

	SetRootComponent(MeshComponent);

	// Move the capsule's former child components over to the mesh.
	for (USceneComponent* Component : ComponentsToMove)
	{
		Component->AttachToComponent(MeshComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	}

	// Fix up the camera to a "death view".
	if (GetNetMode() == NM_Client)
	{
		USpringArmComponent* CameraBoom = GetCameraBoom();

		// Enable lag on the spring arm to smooth movement, counters sporadic movement of the ragdoll.
		CameraBoom->bEnableCameraLag = true;
		CameraBoom->bEnableCameraRotationLag = true;
		// Change the camera boom so it's looking down on the ragdoll from slightly further away.
		CameraBoom->bUsePawnControlRotation = false;
		CameraBoom->bInheritPitch = false;
		CameraBoom->bInheritRoll = false;
		CameraBoom->bInheritYaw = false;
		CameraBoom->SocketOffset = FVector::ZeroVector;  // Zero out the over-the-shoulder offset.
		CameraBoom->TargetOffset = FVector(0, 0, 50);  // Offset slightly up so the camera target doesn't collide with the floor.
		CameraBoom->SetRelativeLocation(FVector(0, 0, 97));  // Places it at the character mesh's root bone.
		CameraBoom->SetRelativeRotation(FRotator(300, 0, 0));  // Look down on the character.
		CameraBoom->TargetArmLength = 500;  // Extend the arm length slightly.
	}
}

void ATPSCharacter::UpdateAimRotation(float AngleUpdateThreshold)
{
	FRotator AimDelta = GetControlRotation() - GetActorRotation();
	AimDelta.Normalize();
	float NewAimYaw = FMath::ClampAngle(AimDelta.Yaw, -90.0f, 90.0f);
	float NewAimPitch = FMath::ClampAngle(AimDelta.Pitch, -90.0f, 90.0f);

	if (FMath::Abs(NewAimYaw - AimYaw) > AngleUpdateThreshold)
	{
		AimYaw = FMath::ClampAngle(AimDelta.Yaw, -90.0f, 90.0f);
	}
	if (FMath::Abs(NewAimPitch - AimPitch) > AngleUpdateThreshold)
	{
		AimPitch = FMath::ClampAngle(AimDelta.Pitch, -90.0f, 90.0f);
	}
}

float ATPSCharacter::GetAimYaw()
{
	return AimYaw;
}

float ATPSCharacter::GetAimPitch()
{
	return AimPitch;
}

bool ATPSCharacter::CanFire()
{
	return EquippedWeapon && !IsSprinting();
}

AWeapon* ATPSCharacter::GetEquippedWeapon() const
{
	return EquippedWeapon;
}

bool ATPSCharacter::ServerSpawnCube_Validate()
{
	return true;
}

void ATPSCharacter::ServerSpawnCube_Implementation()
{
	if (TestCubeTemplate == nullptr)
	{
		return;
	}

	FVector CameraCenter = GetFollowCamera()->GetComponentLocation();
	FVector SpawnLocation = CameraCenter + GetFollowCamera()->GetForwardVector() * InteractDistance;
	FTransform SpawnTranform(FRotator::ZeroRotator, SpawnLocation);

	GetWorld()->SpawnActor<AActor>(TestCubeTemplate, SpawnTranform);
}

bool ATPSCharacter::DebugResetCharacter_Validate()
{
	return true;
}

void ATPSCharacter::DebugResetCharacter_Implementation()
{
	CurrentHealth = MaxHealth;
}

void ATPSCharacter::OnRep_IsRagdoll()
{
	if (bIsRagdoll)
	{
		StartRagdoll();
	}
}

void ATPSCharacter::OnRep_Team()
{
	if (GetNetMode() == NM_DedicatedServer)
	{
		return;
	}

	UpdateTeamColor();
}

FVector ATPSCharacter::GetLineTraceStart() const
{
	return GetFollowCamera()->GetComponentLocation();
}

FVector ATPSCharacter::GetLineTraceDirection() const
{
	return GetFollowCamera()->GetForwardVector();
}

FString ATPSCharacter::GetPlayerName() const
{
	if (ATPSPlayerState* PS = Cast<ATPSPlayerState>(PlayerState))
	{
		return PS->GetPlayerName();
	}
	return FString("UNKNOWN");
}

float ATPSCharacter::TakeDamage(float Damage, const FDamageEvent& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (!HasAuthority())
	{
		return 0.0f;
	}

	const ATPSCharacter* Killer = nullptr;

	// Ignore friendly fire
	const AInstantWeapon* DamageSourceWeapon = Cast<AInstantWeapon>(DamageCauser);
	if (DamageSourceWeapon != nullptr)
	{
		const ATPSCharacter* DamageDealer = Cast<ATPSCharacter>(DamageSourceWeapon->GetWeilder());
		if (DamageDealer != nullptr)
		{
			if (Team != ETPSTeam::Team_None    // "Team_None" is not actually a team, and "teamless" should be able to damage one another
				&& DamageDealer->GetTeam() == Team)
			{
				return 0.0f;
			}
			Killer = DamageDealer;
		}
	}

	int32 DamageDealt = FMath::Min(static_cast<int32>(Damage), CurrentHealth);
	CurrentHealth -= DamageDealt;

	if (CurrentHealth <= 0)
	{
		Die(Killer);
	}

	return Damage;
}

bool ATPSCharacter::IsSprinting()
{
	UTPSCharacterMovementComponent* Movement = Cast<UTPSCharacterMovementComponent>(GetCharacterMovement());
	if (Movement == nullptr)
	{
		return false;
	}

	if (Role >= ROLE_AutonomousProxy)
	{
		// If we're authoritative or the owning client, we know definitively whether we're sprinting.
		return Movement->IsSprinting();
	}

	// For all other client types, we need to guess based on speed.
	// Add a tolerance factor to the max jog speed and use that as a sprint threshold.
	float SquaredSprintThreshold = Movement->MaxWalkSpeed + 10.0f;
	SquaredSprintThreshold *= SquaredSprintThreshold;

	// We only care about speed in the X-Y plane.
	return GetVelocity().SizeSquared2D() > SquaredSprintThreshold;
}

void ATPSCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ATPSCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ATPSCharacter::StartSprinting()
{
	if (UTPSCharacterMovementComponent* MovementComponent = Cast<UTPSCharacterMovementComponent>(GetCharacterMovement()))
	{
		MovementComponent->SetWantsToSprint(true);
	}
}

void ATPSCharacter::StopSprinting()
{
	if (UTPSCharacterMovementComponent* MovementComponent = Cast<UTPSCharacterMovementComponent>(GetCharacterMovement()))
	{
		MovementComponent->SetWantsToSprint(false);
	}
}

void ATPSCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ATPSCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void ATPSCharacter::SetTeam(ETPSTeam NewTeam)
{
	if (!HasAuthority())
	{
		return;
	}

	Team = NewTeam;
	OnRep_Team();
}

ETPSTeam ATPSCharacter::GetTeam() const
{
	return Team;
}
