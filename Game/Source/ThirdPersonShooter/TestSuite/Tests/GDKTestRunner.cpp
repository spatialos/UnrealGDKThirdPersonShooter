// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "GDKTestRunner.h"

#include "UnrealNetwork.h"
#include "GameFramework/GameModeBase.h"

#include "TestSuite/Tests/TestIntReplication.h"
#include "TestSuite/Tests/TestFloatReplication.h"
#include "TestSuite/Tests/TestBoolReplication.h"
#include "TestSuite/Tests/TestCharReplication.h"
#include "TestSuite/Tests/TestFStringReplication.h"
#include "TestSuite/Tests/TestCArrayReplication.h"
#include "TestSuite/Tests/TestTArrayReplication.h"
#include "TestSuite/Tests/TestEnumReplication.h"
#include "TestSuite/Tests/TestFTextReplication.h"
#include "TestSuite/Tests/TestFNameReplication.h"
#include "TestSuite/Tests/TestUStructReplication.h"
#include "TestSuite/Tests/TestUObjectReplication.h"
#include "TestSuite/Tests/TestMulticastRPC.h"
#include "TestSuite/Tests/TestStaticComponentReplication.h"

DEFINE_LOG_CATEGORY(LogSpatialGDKTests);

AGDKTestRunner::AGDKTestRunner()
	: bIsRunning(false)
	, CurrentTestIndex(0)
	, ReadyClientsCount(0)
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	bAlwaysRelevant = true;
}

// Called every frame
void AGDKTestRunner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsRunning)
	{
		UWorld* World = GetWorld();
		if (!World)
		{
			return;
		}

		AGameModeBase* GameMode = World->GetAuthGameMode();
		if (GetNetMode() != NM_DedicatedServer || !GameMode || !(ReadyClientsCount == GameMode->GetNumPlayers()))
		{
			return;
		}

		// execute the tests
		if (TestCases[CurrentTestIndex]->IsFinished())
		{
			CurrentTestIndex++;

			if (CurrentTestIndex == TestCases.Num())
			{
				bIsRunning = false;
				ReadyClientsCount = 0;
				CurrentTestIndex = 0;
				Server_TearDownTestCases();
				UE_LOG(LogSpatialGDKTests, Log, TEXT("TestRunner: All Test completed successfully!"));
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("TestRunner: All Test completed successfully!"));
			}
			else
			{
				TestCases[CurrentTestIndex]->Server_StartTest();
			}
		}
	}
}

bool AGDKTestRunner::Server_RunTests_Validate()
{
	return true;
}

void AGDKTestRunner::Server_RunTests_Implementation()
{
	if (!bIsRunning)
	{
		ReadyClientsCount = 0;
		bIsRunning = true;

		Server_SetupTestCases();
	}
	else
	{
		UE_LOG(LogSpatialGDKTests, Log, TEXT("TestRunner: Could not start the test runner, it is already running."));
	}

}

bool AGDKTestRunner::IsRunning() const
{
	return bIsRunning;
}

void AGDKTestRunner::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AGDKTestRunner, TestCases, COND_None);
	DOREPLIFETIME_CONDITION(AGDKTestRunner, bIsRunning, COND_None);
}

bool AGDKTestRunner::Server_SignalClientReady_Validate()
{
	return true;
}

void AGDKTestRunner::Server_SignalClientReady_Implementation()
{
	ReadyClientsCount++;

	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	AGameModeBase* GameMode = World->GetAuthGameMode();
	if (!GameMode || !(ReadyClientsCount == GameMode->GetNumPlayers()))
	{
		return;
	}

	// Start the new test case as we are ready
	CurrentTestIndex = 0;
	TestCases[CurrentTestIndex]->Server_StartTest();
}

void AGDKTestRunner::Server_SetupTestCases()
{
	// Setup the test cases here.
	if (GetNetMode() != NM_DedicatedServer)
	{
		return;
	}

	AddTestCase<ATestIntReplication>();
	AddTestCase<ATestFloatReplication>();
	AddTestCase<ATestBoolReplication>();
	AddTestCase<ATestCharReplication>();
	AddTestCase<ATestFStringReplication>();
	AddTestCase<ATestCArrayReplication>();
	AddTestCase<ATestTArrayReplication>();
	AddTestCase<ATestEnumReplication>();
	AddTestCase<ATestFTextReplication>();
	AddTestCase<ATestFNameReplication>();
	AddTestCase<ATestUObjectReplication>();
	AddTestCase<ATestUStructReplication>();
	AddTestCase<ATestMulticastRPC>();
	AddTestCase<ATestStaticComponentReplication>();
}

void AGDKTestRunner::Server_TearDownTestCases()
{
	for (AGDKTestCase* TestCase : TestCases)
	{
		TestCase->Server_TearDown();
	}

	TestCases.Empty();
}

void AGDKTestRunner::OnRep_TestCases()
{
	// Local workaround to allow every client to call server RPCs. This simplifies our testing suite immensely.
	bool bReadyForTests = true;
	if (GetNetMode() == NM_Client)
	{
		AActor* PlayerController = GetWorld()->GetFirstLocalPlayerFromController()->GetPlayerController(nullptr);
		SetOwner(PlayerController);

		for (auto TestCase : TestCases)
		{
			if (TestCase != nullptr)
			{
				TestCase->SetOwner(PlayerController);
			}
			else
			{
				bReadyForTests = false;
			}
		}
	}

	if (TestCases.Num() > 0 && bReadyForTests)
	{
		Server_SignalClientReady();
	}
}
