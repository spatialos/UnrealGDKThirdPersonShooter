// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestsuiteCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TestsuiteGameStateBase.h"
#include "SpatialNetDriver.h"

#include "UnrealNetwork.h"

//////////////////////////////////////////////////////////////////////////
// ATestSuiteCharacter

ATestSuiteCharacter::ATestSuiteCharacter()
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
}

void ATestSuiteCharacter::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (World && GetNetMode() == NM_DedicatedServer)
	{
		TestRunner = World->SpawnActor<AGDKTestRunner>();
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void ATestSuiteCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATestSuiteCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATestSuiteCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ATestSuiteCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ATestSuiteCharacter::LookUpAtRate);
	PlayerInputComponent->BindAction("DebugCmd", IE_Pressed, this, &ATestSuiteCharacter::DebugCmd);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ATestSuiteCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ATestSuiteCharacter::TouchStopped);
}

void ATestSuiteCharacter::Server_StartTestRunner_Implementation()
{
	check(TestRunner);
	TestRunner->Server_RunTests();
}

bool ATestSuiteCharacter::Server_StartTestRunner_Validate()
{
	return true;
}

void ATestSuiteCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void ATestSuiteCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void ATestSuiteCharacter::DebugCmd()
{
	UE_LOG(LogTemp, Warning, TEXT("%s: DebugCmd"), GetNetMode() == NM_Client ? TEXT("Client") : TEXT("Server"));

	if (bTestRunnerReplicated)
	{
		if (!TestRunner->IsRunning())
		{
			Server_StartTestRunner();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Test runner is already running!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Test runner not ready yet!"));
	}
}

void ATestSuiteCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ATestSuiteCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ATestSuiteCharacter::MoveForward(float Value)
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

void ATestSuiteCharacter::MoveRight(float Value)
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

void ATestSuiteCharacter::OnRep_TestRunner()
{
	check(TestRunner);
	bTestRunnerReplicated = true;
}

void ATestSuiteCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(ATestSuiteCharacter, TestRunner, COND_InitialOnly);
}
