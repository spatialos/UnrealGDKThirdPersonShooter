// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SimulatedFindPathLoadComponent.h"

#include "AIController.h"
#include "EngineUtils.h"
#include "Interop/SpatialWorkerFlags.h"
#include "GameFramework/PlayerStart.h"
#include "NavigationSystem.h"
#include "Navigation/PathFollowingComponent.h"


// Sets default values for this component's properties
USimulatedFindPathLoadComponent::USimulatedFindPathLoadComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;

	// ...
}


// Called when the game starts
void USimulatedFindPathLoadComponent::BeginPlay()
{
	Super::BeginPlay();
}

namespace
{
	UPathFollowingComponent* InitNavigationControl(AController& Controller)
	{
		AAIController* AsAIController = Cast<AAIController>(&Controller);
		UPathFollowingComponent* PathFollowingComp = nullptr;

		if (AsAIController)
		{
			PathFollowingComp = AsAIController->GetPathFollowingComponent();
		}
		else
		{
			PathFollowingComp = Controller.FindComponentByClass<UPathFollowingComponent>();
			if (PathFollowingComp == nullptr)
			{
				PathFollowingComp = NewObject<UPathFollowingComponent>(&Controller);
				PathFollowingComp->RegisterComponentWithWorld(Controller.GetWorld());
				PathFollowingComp->Initialize();
			}
		}

		return PathFollowingComp;
	}
}

// Called every frame
void USimulatedFindPathLoadComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bUpdatePropertiesFromWorkerFlags)
	{
		FString FlagValue;

		MinDistanceToSimulate = USpatialWorkerFlags::GetWorkerFlag("pf_min_distance", FlagValue) ? FCString::Atof(*FlagValue) : MinDistanceToSimulate;
		TickInterval = USpatialWorkerFlags::GetWorkerFlag("pf_tick_interval", FlagValue) ? FCString::Atof(*FlagValue) : TickInterval;
		TickIntervalRandomDeviation = USpatialWorkerFlags::GetWorkerFlag("pf_tick_rand_delta", FlagValue) ? FCString::Atof(*FlagValue) : TickIntervalRandomDeviation;
	}

	SimulateFindPath(MinDistanceToSimulate);

	SetComponentTickInterval(TickInterval + FMath::RandRange(-TickIntervalRandomDeviation, TickIntervalRandomDeviation));
}

void USimulatedFindPathLoadComponent::SimulateFindPath(float MinDistance)
{
	if (!CanSimulateFindPath)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tried to simulate pathfinding but coudln't do it for this actor"));
		return;
	}

	APawn* Owner = Cast<APawn>(GetOwner());
	AController* Controller = Owner->Controller;

	const ANavigationData* NavData = NavSys->GetNavDataForProps(Controller->GetNavAgentPropertiesRef());
	if (NavData)
	{
		FVector Location = Owner->GetActorLocation();
		float DistanceTotal = 0.f;
		uint32 Iterations = 0;

		while (MinDistance > DistanceTotal)
		{
			int GoalIndex = FMath::RandRange(0, CachedPathGoals.Num() - 1);
			AActor* Goal = CachedPathGoals[GoalIndex];
			FPathFindingQuery Query(Controller, *NavData, Controller->GetNavAgentLocation(), Goal->GetActorLocation());
			FPathFindingResult Result = NavSys->FindPathSync(Query);
			DistanceTotal += FVector::Distance(Location, Goal->GetActorLocation());
			Iterations++;
		}
	}
}

void USimulatedFindPathLoadComponent::Initialize()
{
	APawn* Owner = Cast<APawn>(GetOwner());
	AController* Controller = Owner->Controller;

	NavSys = Controller ? FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld()) : nullptr;

	if (NavSys == nullptr || Controller == nullptr || Controller->GetPawn() == nullptr)
	{
		CanSimulateFindPath = false;
		return;
	}

	UPathFollowingComponent* PFollowComp = InitNavigationControl(*Controller);

	if (PFollowComp == nullptr)
	{
		CanSimulateFindPath = false;
		return;
	}

	if (!PFollowComp->IsPathFollowingAllowed())
	{
		CanSimulateFindPath = false;
		return;
	}

	for (TActorIterator<APlayerStart> Itr(GetWorld()); Itr; ++Itr)
	{
		CachedPathGoals.Add(*Itr);
	}

	if (CachedPathGoals.Num() == 0)
	{
		CanSimulateFindPath = false;
		return;
	}

	SetComponentTickEnabled(true);
	CanSimulateFindPath = true;
}
