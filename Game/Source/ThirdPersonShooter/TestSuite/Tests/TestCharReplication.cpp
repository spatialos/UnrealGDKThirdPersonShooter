// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestCharReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestCharReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

bool ATestCharReplication::Server_ReportReplication_Validate()
{
	return true;
}

void ATestCharReplication::Server_ReportReplication_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("TestCase %s: Not Supported by Unreal"), *TestName);

	SignalResponseRecieved();
}

void ATestCharReplication::Server_StartTestImpl()
{
	SignalReplicationSetup();
}

void ATestCharReplication::Server_TearDownImpl()
{
	// Left empty as there is no teardown required for this test.
}

void ATestCharReplication::ValidateClientReplicationImpl()
{
}

void ATestCharReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication();
}
