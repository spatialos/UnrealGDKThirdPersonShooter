// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SimulatedTracingLoadComponent.h"

#include "Engine/Engine.h"
#include "GameFramework/Actor.h"
#include "Interop/SpatialWorkerFlags.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"
#include "Stats/Stats.h"

DECLARE_CYCLE_STAT(TEXT("Simulated Tracing Load Time"), STAT_SimulatedTracingLoadTime, STATGROUP_Game, );

// Sets default values for this component's properties
USimulatedTracingLoadComponent::USimulatedTracingLoadComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;
}


// Called when the game starts
void USimulatedTracingLoadComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void USimulatedTracingLoadComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	SCOPE_CYCLE_COUNTER(STAT_SimulatedTracingLoadTime);

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bUpdatePropertiesFromWorkerFlags)
	{
		FString FlagValue;
		TraceCount = USpatialWorkerFlags::GetWorkerFlag("ray_count", FlagValue) ? FCString::Atoi(*FlagValue) : TraceCount;
		TraceLength = USpatialWorkerFlags::GetWorkerFlag("ray_length", FlagValue) ? FCString::Atof(*FlagValue) : TraceLength;
		TickInterval = USpatialWorkerFlags::GetWorkerFlag("ray_tick_interval", FlagValue) ? FCString::Atof(*FlagValue) : TickInterval;
		TickIntervalRandomDeviation = USpatialWorkerFlags::GetWorkerFlag("ray_tick_rand_delta", FlagValue) ? FCString::Atof(*FlagValue) : TickIntervalRandomDeviation;
	}

	SimulateLineTrace(GetOwner()->GetActorForwardVector());
	SimulateLineTraceCircle();

	SetComponentTickInterval(TickInterval + FMath::RandRange(-TickIntervalRandomDeviation, TickIntervalRandomDeviation));
}

void USimulatedTracingLoadComponent::SimulateLineTraceCircle()
{
	float Angle = FMath::DegreesToRadians(360 / TraceCount);

	for (int k = 0; k < TraceCount; k++)
	{

		FVector TraceDirection = FVector{ FMath::Cos(k * Angle), FMath::Sin(k * Angle), 0 };
		SimulateLineTrace(TraceDirection);
	}
}

void USimulatedTracingLoadComponent::SimulateLineTrace(const FVector& TraceDirection)
{
	FHitResult Hit;
	FVector Start = GetOwner()->GetActorLocation();
	FVector End = GetOwner()->GetActorLocation() + TraceDirection * TraceLength;


	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility))
	{
		DrawDebugLine(GetWorld(), Hit.TraceStart, Hit.ImpactPoint, FColor::Blue);
		DrawDebugPoint(GetWorld(), Hit.ImpactPoint, 50, FColor::Red);
	}
}

void USimulatedTracingLoadComponent::Initialize()
{
	SetComponentTickEnabled(true);
}

