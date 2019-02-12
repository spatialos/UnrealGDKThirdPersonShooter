// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestFNameReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestFNameReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestFNameReplication, TestFName, COND_None);
}

bool ATestFNameReplication::Server_ReportReplication_Validate(const FName& RepFName)
{
	return true;
}

void ATestFNameReplication::Server_ReportReplication_Implementation(const FName& RepFName)
{
	check(RepFName.Compare(ValidationName) == 0);

	SignalResponseRecieved();
}

void ATestFNameReplication::Server_StartTestImpl()
{
	TestFName = ValidationName;

	SignalReplicationSetup();
}

void ATestFNameReplication::Server_TearDownImpl()
{
	TestFName = TEXT("");
}

void ATestFNameReplication::ValidateClientReplicationImpl()
{
	check(TestFName.Compare(ValidationName) == 0);
}

void ATestFNameReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication(TestFName);
}
