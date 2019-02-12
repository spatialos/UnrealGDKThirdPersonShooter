// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GDKTestCase.h"
#include "GameFramework/Actor.h"
#include "TestMulticastRPC.generated.h"

UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API ATestMulticastRPC : public AGDKTestCase
{
	GENERATED_BODY()

public:

	ATestMulticastRPC();

	virtual void Tick(float DeltaTime) override;

	virtual void Server_StartTest() override;

	virtual void Server_TearDown() override;

protected:

	UFUNCTION(NetMulticast, Unreliable)
	void MulticastRPC(int32 StartingValue);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportMulticastResult(int32 NewValue);

private:

	int32 BroadcastValue;

	uint32 RPCResponseCount;

	bool bRunning;

	bool bSuccess;
};
