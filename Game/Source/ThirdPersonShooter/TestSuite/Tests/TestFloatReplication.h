// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestFloatReplication.generated.h"

UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API ATestFloatReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestFloatReplication() 
		: FloatComparisonValue(25.0f)
		, DoubleComparisonValue(50.0)
	{ 
		TestName = TEXT("Float types"); 
	}

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(float RepFloat, double RepDouble);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void Server_StartTestImpl() override;

	virtual void Server_TearDownImpl() override;

	virtual void ValidateClientReplicationImpl() override;

	virtual void SendTestResponseRPCImpl() override;

private:

	UPROPERTY(Replicated)
	float TestFloat;

	UPROPERTY(Replicated)
	double TestDouble;

	float FloatComparisonValue;
	double DoubleComparisonValue;
};
