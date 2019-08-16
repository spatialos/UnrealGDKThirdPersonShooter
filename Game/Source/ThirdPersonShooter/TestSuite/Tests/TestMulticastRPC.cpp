// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestMulticastRPC.h"

#include "GDKTestRunner.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

ATestMulticastRPC::ATestMulticastRPC()
	: bRunning(false)
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	TestName = TEXT("Multicast RPCs");
}

void ATestMulticastRPC::Tick(float DeltaTime)
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

void ATestMulticastRPC::Server_StartTest()
{
	UE_LOG(LogSpatialGDKTests, Log, TEXT("TestCase %s: Test started!"), *TestName);

	bIsFinished = false;
	bRunning = true;
	RPCResponseCount = 0;
	BroadcastValue = FMath::RandRange(-50, 50);

	MulticastRPC(BroadcastValue);
}

void ATestMulticastRPC::Server_TearDown()
{
	// No tear down required for MultiCast RPC
}

void ATestMulticastRPC::MulticastRPC_Implementation(int32 StartingValue)
{
	StartingValue++;
	
	// If we are the server then all we need to do is to validate that the call has been executed correctly. 
	if (GetNetMode() != NM_DedicatedServer)
	{
		Server_ReportMulticastResult(StartingValue);
	}
	else
	{
		check(StartingValue == (BroadcastValue + 1));
	}
}

bool ATestMulticastRPC::Server_ReportMulticastResult_Validate(int32 NewValue)
{
	return true;
}

void ATestMulticastRPC::Server_ReportMulticastResult_Implementation(int32 NewValue)
{
	check(NewValue == (BroadcastValue + 1));
	RPCResponseCount++;
}
