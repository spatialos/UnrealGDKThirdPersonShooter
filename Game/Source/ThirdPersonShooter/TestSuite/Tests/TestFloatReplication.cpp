// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestFloatReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestFloatReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestFloatReplication, TestFloat, COND_None);
	DOREPLIFETIME_CONDITION(ATestFloatReplication, TestDouble, COND_None);
}

bool ATestFloatReplication::Server_ReportReplication_Validate(float RepFloat, double RepDouble)
{
	return true;
}

void ATestFloatReplication::Server_ReportReplication_Implementation(float RepFloat, double RepDouble)
{
	check(RepFloat == FloatComparisonValue);
	check(RepDouble == DoubleComparisonValue);

	SignalResponseRecieved();
}

void ATestFloatReplication::Server_StartTestImpl()
{
	TestFloat = FloatComparisonValue;
	TestDouble = DoubleComparisonValue;

	SignalReplicationSetup();
}

void ATestFloatReplication::Server_TearDownImpl()
{
	TestFloat = 0.0f;
	TestDouble = 0.0;
}

void ATestFloatReplication::ValidateClientReplicationImpl()
{
	check(TestFloat == FloatComparisonValue);
	check(TestDouble == DoubleComparisonValue);
}

void ATestFloatReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication(TestFloat, TestDouble);
}
