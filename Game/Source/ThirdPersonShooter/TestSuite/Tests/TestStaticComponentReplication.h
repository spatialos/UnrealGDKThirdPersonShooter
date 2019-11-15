// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "Components/ActorComponent.h"
#include "TestStaticComponentReplication.generated.h"

UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API UTestComponent : public UActorComponent
{
	GENERATED_BODY()
public:

	UTestComponent();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_TestProperty();


	UPROPERTY(ReplicatedUsing = OnRep_TestProperty)
	float TestProperty;
};

UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API ATestStaticComponentReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestStaticComponentReplication();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(float RepFloat);

	virtual void Server_StartTestImpl() override;

	virtual void Server_TearDownImpl() override;

	virtual void ValidateClientReplicationImpl() override;

	virtual void SendTestResponseRPCImpl() override;

	virtual void SendServerRPCs() override;

	void SetReadyForServerRPCs();

private:

	UPROPERTY()
	UTestComponent* TestComponent;
};
