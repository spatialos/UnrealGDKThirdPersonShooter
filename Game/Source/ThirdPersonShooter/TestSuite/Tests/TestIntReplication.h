// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestIntReplication.generated.h"

UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API ATestIntReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestIntReplication() { TestName = TEXT("Int types"); }

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(int8 Rep8Int, int16 Rep16Int, int32 Rep32Int, int64 Rep64Int, uint8 Rep8UInt, uint16 Rep16UInt, uint32 Rep32UInt, uint64 Rep64UInt);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void Server_StartTestImpl() override;

	virtual void Server_TearDownImpl() override;

	virtual void ValidateClientReplicationImpl() override;

	virtual void SendTestResponseRPCImpl() override;

private:

	UPROPERTY(Replicated)
	int8 Test8Int;

	UPROPERTY(Replicated)
	int16 Test16Int;

	UPROPERTY(Replicated)
	int32 Test32Int;

	UPROPERTY(Replicated)
	int64 Test64Int;

	UPROPERTY(Replicated)
	uint8 Test8UInt;

	UPROPERTY(Replicated)
	uint16 Test16UInt;

	UPROPERTY(Replicated)
	uint32 Test32UInt;

	UPROPERTY(Replicated)
	uint64 Test64UInt;
};
