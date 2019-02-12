// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestFStringReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestFStringReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestFStringReplication, TestFString, COND_None);
}

bool ATestFStringReplication::Server_ReportReplication_Validate(const FString& RepFString)
{
	return true;
}

void ATestFStringReplication::Server_ReportReplication_Implementation(const FString& RepFString)
{
	check(RepFString == ComparisonValue);

	SignalResponseRecieved();
}

void ATestFStringReplication::Server_StartTestImpl()
{
	TestFString = ComparisonValue;

	SignalReplicationSetup();
}

void ATestFStringReplication::Server_TearDownImpl()
{
	TestFString = TEXT("");
}

void ATestFStringReplication::ValidateClientReplicationImpl()
{
	check(TestFString == ComparisonValue);
}

void ATestFStringReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication(TestFString);
}
