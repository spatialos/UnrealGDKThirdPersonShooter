// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Misc/Char.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestCharReplication.generated.h"

UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API ATestCharReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestCharReplication() { TestName = TEXT("Char types"); }

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void Server_StartTestImpl() override;

	virtual void Server_TearDownImpl() override;

	virtual void ValidateClientReplicationImpl() override;

	virtual void SendTestResponseRPCImpl() override;
};
