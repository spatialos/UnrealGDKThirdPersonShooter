// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "ReplicationTestHelperClasses.h"
#include "TestCArrayReplication.generated.h"

UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API ATestCArrayReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestCArrayReplication()
		: bDynamicallyCreatedActorReplicated(false)
		, bReplicationRecievedOnClient(false)
		, FirstComparisonValue(-42)
		, SecondComparisonValue(56)
	{ 
		TestName = TEXT("C-Style Array types");

		PODArray[0] = 0;
		PODArray[1] = 0;	
	}

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(/*int RepPODArray[2],
								  UTestUObject* RepStablyNamedArray[2],
								  ATestActor* RepDynamicallyCreatedArray[2],
								  FTArrayTestStruct RepArrayOfStructs[2],
								  FTestStructWithNetSerialize RepArrayOfStructNetSerialize[2],
								  TEnumAsByte<EnumNamespace::EUnrealTestEnum> RepTestUEnumCArray[16]*/);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void Server_StartTestImpl() override;

	virtual void Server_TearDownImpl() override;

	virtual void ValidateClientReplicationImpl() override;

	virtual void SendTestResponseRPCImpl() override;

private:

	UFUNCTION()
	void OnRep_DynamicallyCreatedArray();

	void ValidateReplication_Client();

	// Test C-style array with POD
	UPROPERTY(Replicated)
	int PODArray[2];

	// Test C-style array with stably named UObject
	UPROPERTY(Replicated)
	UTestUObject* StablyNamedArray[2];

	// Test C-style array with dynamically created actor
	UPROPERTY(ReplicatedUsing = OnRep_DynamicallyCreatedArray)
	ATestActor* DynamicallyCreatedArray[2];

	// Test C-style array with UStruct
	UPROPERTY(Replicated)
	FSimpleTestStruct ArrayOfStructs[2];

	// Test C-style array with UStruct and net serialize
	UPROPERTY(Replicated)
	FTestStructWithNetSerialize ArrayOfStructNetSerialize[2];

	// Test C-style array with unreal style enums
	UPROPERTY(Replicated)
	ETest8Enum EnumCArray[2];

	// Test C-style array with enum classes
	UPROPERTY(Replicated)
	TEnumAsByte<EnumNamespace::EUnrealTestEnum> UEnumCArray[2];

	bool bDynamicallyCreatedActorReplicated;
	bool bReplicationRecievedOnClient;

	int FirstComparisonValue;
	int SecondComparisonValue;
};
