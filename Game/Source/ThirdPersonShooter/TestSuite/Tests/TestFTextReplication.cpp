// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestFTextReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestFTextReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestFTextReplication, TestFText, COND_None);
}

bool ATestFTextReplication::Server_ReportReplication_Validate(const FText& RepFText)
{
	return true;
}

void ATestFTextReplication::Server_ReportReplication_Implementation(const FText& RepFText)
{
	check(RepFText.EqualTo(ValidationText));

	SignalResponseRecieved();
}

void ATestFTextReplication::Server_StartTestImpl()
{
	TestFText = ValidationText;

	SignalReplicationSetup();
}

void ATestFTextReplication::Server_TearDownImpl()
{
	TestFText = FText::FromString(TEXT(""));
}

void ATestFTextReplication::ValidateClientReplicationImpl()
{
	check(TestFText.EqualTo(ValidationText));
}

void ATestFTextReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication(TestFText);
}
