// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NavigationSystem.h"

#include "SimulatedFindPathLoadComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class USimulatedFindPathLoadComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USimulatedFindPathLoadComponent();

	void SimulateFindPath(float MinDistance);

	UFUNCTION(BlueprintCallable)
	void Initialize();

	UPROPERTY(EditAnywhere)
	bool bUpdatePropertiesFromWorkerFlags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinDistanceToSimulate = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TickInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TickIntervalRandomDeviation;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	TArray<AActor*> CachedPathGoals;
	bool CanSimulateFindPath;
	UNavigationSystemV1* NavSys;
};
