// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGameCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Interactable.h"
#include "Kismet/GameplayStatics.h"
#include "SampleGameGameStateBase.h"
#include "SampleGameLogging.h"
#include "SampleGamePlayerController.h"
#include "SampleGamePlayerState.h"
#include "SGCharacterMovementComponent.h"
#include "SpatialNetDriver.h"
#include "UnrealNetwork.h"
#include "Weapons/Weapon.h"


//////////////////////////////////////////////////////////////////////////
// ASampleGameCharacter

ASampleGameCharacter::ASampleGameCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<USGCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Hack to ensure that the game state is created and set to tick on a client as we don't replicate it
	UWorld* World = GetWorld();
	if (World && World->GetGameState() == nullptr)
	{
		AGameStateBase* GameState = World->SpawnActor<AGameStateBase>(ASampleGameGameStateBase::StaticClass());
		World->SetGameState(GameState);
		Cast<ASampleGameGameStateBase>(GameState)->FakeServerHasBegunPlay();
	}

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
	CurrentHealth = 0;
	bIsRagdoll = false;
}

void ASampleGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Only spawn a new starter weapon if we're authoritative and don't already have one.
	if (HasAuthority())
	{
		// Short delay as a workaround for actor references potentially not being resolved when this actor gets checked out.
		FTimerHandle TimerHandle;
		FTimerDelegate TimerDelegate;
		TimerDelegate.BindLambda([this]() {
			UE_LOG(LogSampleGame, Log, TEXT("%s EquippedWeapon: %s"), *this->GetName(), EquippedWeapon == nullptr ? TEXT("nullptr") : *EquippedWeapon->GetName());
			if (GetEquippedWeapon() == nullptr)
			{
				SpawnStarterWeapon();
			}
		});
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, 0.2f, false);

		CurrentHealth = MaxHealth;
	}
}

void ASampleGameCharacter::EndPlay(const EEndPlayReason::Type Reason)
{
	Super::EndPlay(Reason);

	if (HasAuthority())
	{
		// Destroy weapon actor.
		if (EquippedWeapon != nullptr && !EquippedWeapon->IsPendingKill())
		{
			GetWorld()->DestroyActor(EquippedWeapon);
		}
	}
}

void ASampleGameCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	/// Update colors only on Clients
	if (GetNetMode() == NM_Client)
	{
		if (PlayerState != nullptr && PlayerState->IsA(ASampleGamePlayerState::StaticClass()))
		{
			ASampleGamePlayerState* SampleGamePlayerState = (ASampleGamePlayerState*)PlayerState;

			/// Register for updates to our selected team appearance from our PlayerState (switch teams mid-match? Powerup that fools everyone into thinking you're on their team?  Etc?)
			SampleGamePlayerState->RegisterCharacterListenerForSelectedTeam(this);

			/// Attempt to set the team using whatever value is current in PlayerState (will check for ESampleGameTeam::Team_None and ignore)
			SetTeamColor();
		}
	}
}

void ASampleGameCharacter::SetTeamColor()
{
	/// Hack - Remove the following 'check' lines once materials are switched to dynamic instances
	check(NoneTeamMaterial != nullptr);
	check(RedTeamMaterial != nullptr);
	check(GreenTeamMaterial != nullptr);
	check(BlueTeamMaterial != nullptr);
	check(PurpleTeamMaterial != nullptr);
	check(YellowTeamMaterial != nullptr);
	check(BlackTeamMaterial != nullptr);
	check(WhiteTeamMaterial != nullptr);

	// TODO jamcrow - Switch static material sets to dynamic instances instead
	if (PlayerState != nullptr && PlayerState->IsA(ASampleGamePlayerState::StaticClass()))
	{
		USkeletalMeshComponent* CharacterMesh = GetMesh();

		ASampleGamePlayerState* SampleGamePlayerState = (ASampleGamePlayerState*)PlayerState;				
		switch (SampleGamePlayerState->GetSelectedTeamAsEnum())
		{
		case ESampleGameTeam::Team_Red:
			CharacterMesh->SetMaterial(0, RedTeamMaterial);
			break;
		case ESampleGameTeam::Team_Green:
			CharacterMesh->SetMaterial(0, GreenTeamMaterial);
			break;
		case ESampleGameTeam::Team_Blue:
			CharacterMesh->SetMaterial(0, BlueTeamMaterial);
			break;
		case ESampleGameTeam::Team_Purple:
			CharacterMesh->SetMaterial(0, PurpleTeamMaterial);
			break;
		case ESampleGameTeam::Team_Yellow:
			CharacterMesh->SetMaterial(0, YellowTeamMaterial);
			break;
		case ESampleGameTeam::Team_Black:
			CharacterMesh->SetMaterial(0, BlackTeamMaterial);
			break;
		case ESampleGameTeam::Team_White:
			CharacterMesh->SetMaterial(0, WhiteTeamMaterial);
			break;			
		case ESampleGameTeam::Team_None:
			/// If team value has not yet replicated, use the temporary colors
			CharacterMesh->SetMaterial(0, NoneTeamMaterial);
			break;
		default:
			break;
		}
	}
}

void ASampleGameCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASampleGameCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASampleGameCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ASampleGameCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ASampleGameCharacter::LookUpAtRate);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ASampleGameCharacter::StartSprinting);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ASampleGameCharacter::StopSprinting);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ASampleGameCharacter::Interact);
	PlayerInputComponent->BindAction("SpawnCube", IE_Pressed, this, &ASampleGameCharacter::SpawnCube);
	PlayerInputComponent->BindAction("DebugResetCharacter", IE_Pressed, this, &ASampleGameCharacter::DebugResetCharacter);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ASampleGameCharacter::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &ASampleGameCharacter::StopFire);
}

void ASampleGameCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASampleGameCharacter, EquippedWeapon);
	DOREPLIFETIME(ASampleGameCharacter, bIsRagdoll);

	// Only replicate health to the owning client.
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, CurrentHealth, COND_AutonomousOnly);
}

void ASampleGameCharacter::Interact()
{
	check(GetNetMode() == NM_Client);

	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("SampleGame_Trace")), true, this);
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

	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan,
			FString::Printf(TEXT("Interact with actor: %s"), *HitResult.GetActor()->GetName()));
	}

	// Do the interface check this way so it catches both C++ and Blueprint implementations (cast will only catch C++).
	if (HitResult.GetActor()->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
	{
		IInteractable::Execute_Interact(HitResult.GetActor(), this);
	}
}

void ASampleGameCharacter::SpawnCube()
{
	ServerSpawnCube();
}

void ASampleGameCharacter::SpawnStarterWeapon()
{
	if (!HasAuthority())
	{
		return;
	}

	if (StarterWeaponTemplate == nullptr)
	{
		UE_LOG(LogSampleGame, Warning, TEXT("No starter weapon defined."));
		return;
	}

	AWeapon* StartWeapon = GetWorld()->SpawnActor<AWeapon>(StarterWeaponTemplate, GetActorTransform());
	StartWeapon->SetOwningCharacter(this);
	StartWeapon->AttachToActor(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	UE_LOG(LogSampleGame, Log, TEXT("Set weapon for character %s to %s"), *this->GetName(), *StartWeapon->GetName());
	EquippedWeapon = StartWeapon;
}

void ASampleGameCharacter::StartFire()
{
	AWeapon* Weapon = GetEquippedWeapon();
	if (Weapon != nullptr)
	{
		Weapon->StartFire();
	}
}

void ASampleGameCharacter::StopFire()
{
	AWeapon* Weapon = GetEquippedWeapon();
	if (Weapon != nullptr)
	{
		Weapon->StopFire();
	}
}

void ASampleGameCharacter::Die()
{
	if (GetNetMode() == NM_DedicatedServer && HasAuthority())
	{
		ASampleGamePlayerController* PC = Cast<ASampleGamePlayerController>(GetController());
		if (PC)
		{
			PC->KillCharacter();
		}

		bIsRagdoll = true;
		OnRep_IsRagdoll();
	}
}

void ASampleGameCharacter::StartRagdoll()
{
	// Disable capsule collision and disable movement.
	UCapsuleComponent* CapsuleComponent = GetCapsuleComponent();
	if (CapsuleComponent == nullptr)
	{
		UE_LOG(LogSampleGame, Error, TEXT("Invalid capsule component on character %s"), *this->GetName());
		return;
	}
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

AWeapon* ASampleGameCharacter::GetEquippedWeapon() const
{
	return EquippedWeapon;
}

bool ASampleGameCharacter::ServerSpawnCube_Validate()
{
	return true;
}

void ASampleGameCharacter::ServerSpawnCube_Implementation()
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

bool ASampleGameCharacter::DebugResetCharacter_Validate()
{
	return true;
}

void ASampleGameCharacter::DebugResetCharacter_Implementation()
{
	CurrentHealth = MaxHealth;
}

void ASampleGameCharacter::OnRep_CurrentHealth()
{
	if (GetNetMode() != NM_DedicatedServer)
	{
		ASampleGamePlayerController* PC = Cast<ASampleGamePlayerController>(GetController());
		if (PC)
		{
			PC->UpdateHealthUI(CurrentHealth, MaxHealth);
		}
		else
		{
			UE_LOG(LogSampleGame, Warning, TEXT("Couldn't find a player controller for character: %s"), *this->GetName());
		}
	}
}

void ASampleGameCharacter::OnRep_IsRagdoll()
{
	if (bIsRagdoll)
	{
		StartRagdoll();
	}
}

FVector ASampleGameCharacter::GetLineTraceStart() const
{
	return GetFollowCamera()->GetComponentLocation();
}

FVector ASampleGameCharacter::GetLineTraceDirection() const
{
	return GetFollowCamera()->GetForwardVector();
}

float ASampleGameCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (!HasAuthority())
	{
		return 0;
	}

	int32 DamageDealt = FMath::Min(static_cast<int32>(Damage), CurrentHealth);
	CurrentHealth -= DamageDealt;

	if (CurrentHealth <= 0)
	{
		Die();
	}

	return DamageDealt;
}

bool ASampleGameCharacter::IsSprinting()
{
	USGCharacterMovementComponent* Movement = Cast<USGCharacterMovementComponent>(GetCharacterMovement());
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

void ASampleGameCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ASampleGameCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ASampleGameCharacter::StartSprinting()
{
	if (USGCharacterMovementComponent* MovementComponent = Cast<USGCharacterMovementComponent>(GetCharacterMovement()))
	{
		MovementComponent->SetWantsToSprint(true);
	}
}

void ASampleGameCharacter::StopSprinting()
{
	if (USGCharacterMovementComponent* MovementComponent = Cast<USGCharacterMovementComponent>(GetCharacterMovement()))
	{
		MovementComponent->SetWantsToSprint(false);
	}
}

void ASampleGameCharacter::MoveForward(float Value)
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

void ASampleGameCharacter::MoveRight(float Value)
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
