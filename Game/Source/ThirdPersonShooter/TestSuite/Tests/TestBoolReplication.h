// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestBoolReplication.generated.h"

UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API ATestBoolReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestBoolReplication() 
		: TestBool(false)
	{ 
		TestName = TEXT("Bool types"); 
	}

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(bool RepBool);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void Server_StartTestImpl() override;

	virtual void Server_TearDownImpl() override;

	virtual void ValidateClientReplicationImpl() override;

	virtual void SendTestResponseRPCImpl() override;

private:

	UPROPERTY(Replicated)
	bool TestBool;
};
