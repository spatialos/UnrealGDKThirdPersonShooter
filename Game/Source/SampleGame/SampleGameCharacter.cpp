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
#include "SpatialNetDriver.h"
#include "UnrealNetwork.h"
#include "Weapons/Weapon.h"


//////////////////////////////////////////////////////////////////////////
// ASampleGameCharacter

ASampleGameCharacter::ASampleGameCharacter()
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

	// Only replicate health to the owning client.
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, CurrentHealth, COND_AutonomousOnly);
}

void ASampleGameCharacter::Interact()
{
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
	int32 DamageDealt = FMath::Min(static_cast<int32>(Damage), CurrentHealth);
	CurrentHealth -= DamageDealt;
	return DamageDealt;
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
