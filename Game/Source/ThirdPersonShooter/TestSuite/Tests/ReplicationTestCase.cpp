// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "ReplicationTestCase.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

AReplicationTestCase::AReplicationTestCase()
	: bRunning(false)
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	bAlwaysRelevant = true;
}

void AReplicationTestCase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bRunning)
	{
		UWorld* World = GetWorld();
		if (!World)
		{
			return;
		}

		AGameModeBase* GameMode = World->GetAuthGameMode();
		if (GetNetMode() != NM_DedicatedServer || !GameMode || !(RPCResponseCount == GameMode->GetNumPlayers()))
		{
			return;
		}

		UE_LOG(LogSpatialGDKTests, Log, TEXT("TestCase: %s: Test complete!"), *TestName);
		bIsFinished = true;
		bRunning = false;
	}
}

void AReplicationTestCase::Server_StartTest()
{
	UE_LOG(LogSpatialGDKTests, Log, TEXT("TestCase %s: Test started!"), *TestName);

	bIsFinished = false;
	bRunning = true;
	RPCResponseCount = 0;

	Server_StartTestImpl();
}

void AReplicationTestCase::Server_TearDown()
{
	Server_TearDownImpl();
}

void AReplicationTestCase::OnRep_TestBookend()
{
	bReadyToSendServerRPCs = true;
}

void AReplicationTestCase::SignalReplicationSetup()
{
	TestBookend += 1;

	UE_LOG(LogSpatialGDKTests, Log, TEXT("TestCase: %s : Replication setup on Server"), *TestName);
}

void AReplicationTestCase::SignalResponseRecieved()
{
	RPCResponseCount++;
	CurrentRunnerIndex++;
	SetupNewGDKRunner();
	UE_LOG(LogSpatialGDKTests, Log, TEXT("TestCase %s: Response RPC recieved from a client"), *TestName);
}

void AReplicationTestCase::SendServerRPCs()
{
	UE_LOG(LogSpatialGDKTests, Log, TEXT("TestCase %s: Validating replication"), *TestName);

	ValidateClientReplicationImpl();

	UE_LOG(LogSpatialGDKTests, Log, TEXT("TestCase %s: Replication successful on client, sending response RPC"), *TestName);

	SendTestResponseRPCImpl();
}

void AReplicationTestCase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AReplicationTestCase, TestBookend, COND_None);
}
