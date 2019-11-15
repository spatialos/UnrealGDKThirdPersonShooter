// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GDKTestCase.generated.h"

class AGDKTestRunner;

/*
* GDKTestCase is the interface for any test executed by the GDKTestRunner.
* It contains the two server RPCs for starting the test and tearing it down once it
* has finished its execution.
*/
UCLASS(Abstract)
class THIRDPERSONSHOOTER_API AGDKTestCase : public AActor
{
	GENERATED_BODY()

public:

	AGDKTestCase();

	void Tick(float DeltaSeconds) override;

	/* 
	* Indicates if the test has finished its execution. 
	*/
	UFUNCTION()
	bool IsFinished() const;

	UFUNCTION()
	virtual void SendServerRPCs()
	PURE_VIRTUAL(AGDKTestCase::SendServerRPCs(), );

	/* 
	* The GDKTestRunner triggers this function to start the execution of the test.
	*/
	UFUNCTION()
	virtual void Server_StartTest()
	PURE_VIRTUAL(AGDKTestCase::Server_StartTest(), );

	/* 
	* The GDKTestRunner triggers this function to start tearing down the test after its completion. 
	*/
	UFUNCTION()
	virtual void Server_TearDown()
	PURE_VIRTUAL(AGDKTestCase::Server_TearDown(), );

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void InitializeGDKTestRunnersForThisTestCase(TArray<AGDKTestRunner*> InRunners);

protected:

	TArray<AGDKTestRunner*> Runners;
	int CurrentRunnerIndex;
	void SetupNewGDKRunner();
	bool bReadyToSendServerRPCs;

	UPROPERTY()
	FString TestName;

	UPROPERTY()
	bool bIsFinished;
};
