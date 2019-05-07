// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SimulatedTracingLoadComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class USimulatedTracingLoadComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USimulatedTracingLoadComponent();
	
	UFUNCTION(BlueprintCallable)
	void Initialize();

	void SimulateLineTrace(const FVector& Direction);
	void SimulateLineTraceCircle();

	UPROPERTY(EditAnywhere)
	bool bUpdatePropertiesFromWorkerFlags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TraceCount = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TraceLength = 10000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TickInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TickIntervalRandomDeviation;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void UpdatePropertiesFromWorkerFlags();

	static bool bHasPrintedPropertiesForClass;
	void PrintProperties();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
