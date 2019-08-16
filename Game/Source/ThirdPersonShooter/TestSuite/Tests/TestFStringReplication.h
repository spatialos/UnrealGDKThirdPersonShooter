// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestFStringReplication.generated.h"

UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API ATestFStringReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestFStringReplication() 
		: TestFString(TEXT(""))
		, ComparisonValue(TEXT("Here's Johnny!"))
	{ 
		TestName = TEXT("FString types"); 
	}

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(const FString& RepFString);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void Server_StartTestImpl() override;

	virtual void Server_TearDownImpl() override;

	virtual void ValidateClientReplicationImpl() override;

	virtual void SendTestResponseRPCImpl() override;

private:

	UPROPERTY(Replicated)
	FString TestFString;

	const FString ComparisonValue;
};
