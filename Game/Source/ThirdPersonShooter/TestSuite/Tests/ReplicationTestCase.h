// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GDKTestCase.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.generated.h"

UCLASS(Abstract)
class THIRDPERSONSHOOTER_API AReplicationTestCase : public AGDKTestCase
{
	GENERATED_BODY()

public:

	AReplicationTestCase();

	virtual void Tick(float DeltaTime) override;

	virtual void Server_StartTest() override;

	virtual void Server_TearDown() override;

	UFUNCTION()
	void OnRep_TestBookend();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:

	UFUNCTION()
	void SignalReplicationSetup();

	UFUNCTION()
	void SignalResponseRecieved();

	UFUNCTION()
	virtual void Server_StartTestImpl()
	PURE_VIRTUAL(AReplicationTestCase::Server_StartTestImpl(), );

	UFUNCTION()
	virtual void Server_TearDownImpl()
	PURE_VIRTUAL(AReplicationTestCase::Server_TearDownImpl(), );

	UFUNCTION()
	virtual void ValidateClientReplicationImpl()
	PURE_VIRTUAL(AReplicationTestCase::ValidateClientReplicationImpl(), );

	UFUNCTION()
	virtual void SendTestResponseRPCImpl()
	PURE_VIRTUAL(AReplicationTestCase::SendTestResponseRPCImpl(), );

private:

	UPROPERTY(ReplicatedUsing = OnRep_TestBookend)
	int TestBookend;

	UPROPERTY()
	int RPCResponseCount;

	bool bRunning;

	bool bSuccess;
};
