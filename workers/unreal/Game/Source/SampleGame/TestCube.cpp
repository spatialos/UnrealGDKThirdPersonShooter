// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestCube.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "SampleGameLogging.h"
#include "UnrealNetwork.h"


// Sets default values
ATestCube::ATestCube()
{
	PrimaryActorTick.bCanEverTick = false;

	bReplicates = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SetRootComponent(BoxComponent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(GetRootComponent());

	bColor1 = true;
	MaterialInstanceDynamic = nullptr;
	Color1 = FLinearColor::Blue;
	Color2 = FLinearColor::Yellow;
}

float ATestCube::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	UE_LOG(LogSampleGame, Log, TEXT("%s took %f damage from %s via %s"), *this->GetName(), DamageAmount, *EventInstigator->GetName(), *DamageCauser->GetName());
	return DamageAmount;
}

void ATestCube::Interact(ACharacter* Interactor)
{
	if (HasAuthority())
	{
		ToggleColor();
	}
	else
	{
		ServerInteract();
	}
}

// Called when the game starts or when spawned
void ATestCube::BeginPlay()
{
	Super::BeginPlay();
	if (GetNetMode() != NM_DedicatedServer)
	{
		MaterialInstanceDynamic = MeshComponent->CreateAndSetMaterialInstanceDynamic(0);
	}
	OnRep_Color1();
}

void ATestCube::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATestCube, bColor1);
}

bool ATestCube::ServerInteract_Validate()
{
	return true;
}

void ATestCube::ServerInteract_Implementation()
{
	ToggleColor();
}

void ATestCube::ToggleColor()
{
	bColor1 = !bColor1;
}

void ATestCube::OnRep_Color1()
{
	if (GetNetMode() != NM_DedicatedServer)
	{
		MaterialInstanceDynamic->SetVectorParameterValue(FName("BaseColor"), bColor1 ? Color1 : Color2);
	}
}

