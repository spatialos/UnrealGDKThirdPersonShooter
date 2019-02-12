// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestFNameReplication.generated.h"

UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API ATestFNameReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestFNameReplication() 
		: ValidationName(TEXT("Rosebud"))
	{ 
		TestName = TEXT("FName types"); 
	}

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(const FName& RepFName);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void Server_StartTestImpl() override;
	
	virtual void Server_TearDownImpl() override;

	virtual void ValidateClientReplicationImpl() override;

	virtual void SendTestResponseRPCImpl() override;

private:

	UPROPERTY(Replicated)
	FName TestFName;

	FName ValidationName;
};
