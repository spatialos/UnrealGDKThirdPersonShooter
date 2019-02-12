// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GDKTestCase.h"
#include "GameFramework/Actor.h"
#include "GDKTestRunner.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSpatialGDKTests, Log, All);

/*
* The GDKTestRunner is the testing suite used for Unreal GDK system-level testing.
* It contains a list of test cases that are populated on the server using the `Server_SetupTestCases()` function 
* and then replicated to the clients. To start the execution of the test suite, call the function `Server_RunTests()`
* on a client. This server RPC sets up the test case array on the server and waits for it to replicate to 
* the connected clients. Each client send another RPC once all test cases have been replicated to indicate that the 
* server can start executing the tests.
*
* All test cases must implement the AGDKTestCase interface.You need to add the test cases in the `Server_SetupTestCases()` server RPC.
*/
UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API AGDKTestRunner : public AActor
{
	GENERATED_BODY()

public:

	AGDKTestRunner();

	/* 
	* Used to tick the current test case. 
	*/
	virtual void Tick(float DeltaTime) override;

	/* 
	* Sent from the client to trigger the test setup and execution. 
	*/
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_RunTests();

	/* 
	* Indicates if the test suite has finished its execution. 
	*/
	UFUNCTION()
	bool IsRunning() const;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SignalClientReady();

	void Server_SetupTestCases();

	void Server_TearDownTestCases();

	UFUNCTION()
	void OnRep_TestCases();

	template<typename T>
	void AddTestCase();

	UPROPERTY(ReplicatedUsing = OnRep_TestCases)
	TArray<AGDKTestCase*> TestCases;

	UPROPERTY(Replicated)
	bool bIsRunning;

	UPROPERTY()
	int CurrentTestIndex;

	UPROPERTY()
	int ReadyClientsCount;
};

template<typename T>
void AGDKTestRunner::AddTestCase()
{ 
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	T* TestCase = World->SpawnActor<T>();
	check(TestCase);
	TestCases.Add(TestCase);
}
