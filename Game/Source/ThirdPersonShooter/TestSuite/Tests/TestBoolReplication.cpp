// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestBoolReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestBoolReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestBoolReplication, TestBool, COND_None);
}

bool ATestBoolReplication::Server_ReportReplication_Validate(bool RepBool)
{
	return true;
}

void ATestBoolReplication::Server_ReportReplication_Implementation(bool RepBool)
{
	check(RepBool == true);

	SignalResponseRecieved();
}

void ATestBoolReplication::Server_StartTestImpl()
{
	TestBool = true;

	SignalReplicationSetup();
}

void ATestBoolReplication::Server_TearDownImpl()
{
	TestBool = false;
}

void ATestBoolReplication::ValidateClientReplicationImpl()
{
	check(TestBool == true);
}

void ATestBoolReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication(TestBool);
}
