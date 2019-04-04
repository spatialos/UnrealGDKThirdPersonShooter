// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
#pragma optimize("", off)

#include "BigGymCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SpatialNetDriver.h"

#include "SpatialPackageMapClient.h"
#include "Engine/PackageMapClient.h"

#include "Companion.h"
#include "BigGymInteractable.h"
#include "Interactions/InteractionManager.h"

#include "UnrealNetwork.h"

//////////////////////////////////////////////////////////////////////////
// ABigGymCharacter

ABigGymCharacter::ABigGymCharacter()
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

	InteractionManager = CreateDefaultSubobject<UInteractionManager>(TEXT("InteractionManager"));

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void ABigGymCharacter::BeginPlay()
{
	Super::BeginPlay();

	if ((GetNetDriver() == nullptr || !GetNetDriver()->IsA(USpatialNetDriver::StaticClass())) && HasAuthority())
	{
		OnAuthorityGained();
	}
}

void ABigGymCharacter::OnAuthorityGained()
{
	Super::OnAuthorityGained();

	if (Companion == nullptr && Role == ROLE_Authority)
	{
		if (CompanionTemplate != nullptr)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			FVector SpawnLocation = GetActorLocation();
			Companion = GetWorld()->SpawnActor<AActor>(CompanionTemplate, FTransform(FRotator::ZeroRotator, SpawnLocation), SpawnParams);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("CompanionTemplate empty for character %s"), *this->GetPathName());
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void ABigGymCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABigGymCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABigGymCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ABigGymCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ABigGymCharacter::LookUpAtRate);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ABigGymCharacter::Interact);
	PlayerInputComponent->BindAction("DestroyHitActor", IE_Pressed, this, &ABigGymCharacter::DestroyHitActor);
	PlayerInputComponent->BindAction("QueryHitActor", IE_Pressed, this, &ABigGymCharacter::QueryHitActor);
	PlayerInputComponent->BindAction("SpawnDebugActor", IE_Pressed, this, &ABigGymCharacter::SpawnDebugActor);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ABigGymCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ABigGymCharacter::TouchStopped);
}

void ABigGymCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABigGymCharacter, Companion);
}

void ABigGymCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void ABigGymCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void ABigGymCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABigGymCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ABigGymCharacter::MoveForward(float Value)
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

void ABigGymCharacter::MoveRight(float Value)
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

bool ABigGymCharacter::ServerInteract_Validate(AActor* Target)
{
	return true;
}

void ABigGymCharacter::ServerInteract_Implementation(AActor* Target)
{
	if (Target->GetClass()->ImplementsInterface(UBigGymInteractable::StaticClass()))
	{
		IBigGymInteractable::Execute_Interact(Target);
	}
}

void ABigGymCharacter::Interact()
{
	if (InteractionManager->IsMenuOpen())
	{
		InteractionManager->CloseMenu();
		return;
	}

	AActor* HitActor = LineTrace();
	if (HitActor && HitActor->GetClass()->ImplementsInterface(UBigGymInteractable::StaticClass()))
	{
		ServerInteract(HitActor);
	}
	else if (InteractionManager->IsActorInteractable(HitActor))
	{
		InteractionManager->OpenMenu(HitActor);
	}

	/*
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
	FString ContentRelativeDir(TEXT("/Game/Maps/StreamingGym"));
	AssetRegistry.AddPath(ContentRelativeDir);
	AssetRegistry.ScanPathsSynchronous({ ContentRelativeDir });

	UObjectLibrary* Library = UObjectLibrary::CreateLibrary(UObject::StaticClass(), false, false);
	Library->LoadAssetDataFromPath(ContentRelativeDir);
	*/

//	if (AssetToLoad.IsEmpty())
//	{
//		AssetToLoad = TEXT("/Game/Maps/StreamingGym/StreamingGym.StreamingGym");
//	}
//	UObject* FoundObject = StaticLoadObject(AActor::StaticClass(), nullptr, *AssetToLoad);
//	if (AActor* FoundActor = Cast<AActor>(FoundObject))
//	{
//		FActorSpawnParameters SpawnParams;
//		SpawnParams.Template = FoundActor;
//		FTransform SpawnTransform = FTransform::Identity;
//		AActor* NewActor = GetWorld()->SpawnActor(FoundActor->GetClass(), &SpawnTransform, SpawnParams);
//		UE_LOG(LogTemp, Log, TEXT("Created new actor %s"), *NewActor->GetName());
//	}

//	if (PackageToLoad.IsEmpty())
//	{
//		PackageToLoad = TEXT("/Game/Maps/StreamingGym/StreamingGym");
//	}

//	UPackage* MapPackage = LoadPackage(nullptr, *PackageToLoad, LOAD_None);
//	if (MapPackage)
//	{
//		//MapPackage->
//	}
}

void ABigGymCharacter::SpawnDebugActor()
{
	ServerSpawnDebugActor();
}

void ABigGymCharacter::ServerSpawnDebugActor_Implementation()
{
	if (SpawnActorTemplate == nullptr)
	{
		return;
	}

	FActorSpawnParameters SpawnParams;

	FRotator CameraRotation = GetFollowCamera()->GetComponentRotation();
	FVector SpawnPosition = GetActorLocation() + CameraRotation.RotateVector(SpawnActorOffset);

	GetWorld()->SpawnActor<AActor>(SpawnActorTemplate, SpawnPosition, FRotator::ZeroRotator, SpawnParams);
}

bool ABigGymCharacter::ServerSpawnDebugActor_Validate()
{
	return true;
}

void ABigGymCharacter::ServerDestroyHitActor_Implementation(AActor* HitActor)
{
	if (HitActor && HitActor->HasAuthority() && !HitActor->IsPendingKill())
	{
		const FString ObjectBaseName = FString::Printf(TEXT("DESTROYED_%s"), *HitActor->GetName());

		// We can only rename objects if we're not garbage collecting. We shouldn't be in GC at this point though.
		if (!IsGarbageCollecting())
		{
			HitActor->Rename(*MakeUniqueObjectName(HitActor->GetOuter(), HitActor->GetClass(), *ObjectBaseName).ToString());
			UE_LOG(LogTemp, Log, TEXT("Renamed actor to %s"), *HitActor->GetName());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to rename destroyed actor %s because we're garbage collecting. It might still be addressable by name."),
				*HitActor->GetFullName());
		}

		HitActor->Destroy();
		UE_LOG(LogTemp, Log, TEXT("Destroying actor %s"), *HitActor->GetName());
	}
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
}

bool ABigGymCharacter::ServerDestroyHitActor_Validate(AActor* HitActor)
{
	return true;
}

void ABigGymCharacter::DestroyHitActor()
{
	if (AActor* HitActor = LineTrace())
	{
		ServerDestroyHitActor(HitActor);
	}
}

void ABigGymCharacter::ServerQueryHitActor_Implementation(AActor* HitActor)
{
	QueryActor(HitActor);
}

bool ABigGymCharacter::ServerQueryHitActor_Validate(AActor* HitActor)
{
	return true;
}

void ABigGymCharacter::QueryHitActor()
{
	check(!HasAuthority());

	if (AActor* HitActor = LineTrace())
	{
		ServerQueryHitActor(HitActor);
		QueryActor(HitActor);
	}
}

void ABigGymCharacter::QueryActor(AActor* Actor)
{
	if (Actor == nullptr) return;

	FString Output = FString::Printf(TEXT("HitActor (%s): %s"), HasAuthority() ? TEXT("Server") : TEXT("Client"), *Actor->GetFullName());
	if (USpatialNetDriver* SpatialNetDriver = Cast<USpatialNetDriver>(GetNetDriver()))
	{
		if (Worker_EntityId EntityId = SpatialNetDriver->PackageMap->GetEntityIdFromObject(Actor))
		{
			Output.Append(FString::Printf(TEXT("\n EntityId: %lld"), EntityId));
		}
	}
	Output.Append(FString::Printf(TEXT("\n Role: %d\n Remote Role: %d"), Actor->Role.GetValue(), Actor->RemoteRole.GetValue()));
	UE_LOG(LogTemp, Log, TEXT("%s"), *Output);
}

AActor* ABigGymCharacter::LineTrace() const
{
	FCollisionQueryParams TraceParams(FName(TEXT("SP_Trace")), true, this);
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = false;

	FHitResult HitResult(ForceInit);

	FVector TraceDirection = GetFollowCamera()->GetForwardVector();
	FVector StartPosition = GetFollowCamera()->GetComponentLocation() + (TraceDirection * 30.0f);
	const float kTraceLength = 5000.0f;
	FVector EndPosition = StartPosition + (TraceDirection * kTraceLength);

	bool bDidHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartPosition, EndPosition, ECC_WorldDynamic, TraceParams);
	if (bDidHit && HitResult.Actor != nullptr)
	{
		return HitResult.Actor.Get();
	}
	return nullptr;
}

bool ABigGymCharacter::TestMulticast_Validate()
{
	return true;
}

void ABigGymCharacter::TestMulticast_Implementation()
{
}


bool ABigGymCharacter::TestRPC_Validate()
{
	return true;
}

void ABigGymCharacter::TestRPC_Implementation()
{

}

#pragma optimize("", on)
