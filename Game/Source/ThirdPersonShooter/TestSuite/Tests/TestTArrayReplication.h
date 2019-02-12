// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "ReplicationTestHelperClasses.h"
#include "TestTArrayReplication.generated.h"

UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API ATestTArrayReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestTArrayReplication()
		: bDynamicallyCreatedActorReplicated(false)
		, bReplicationRecievedOnClient(false)
	{ 
		TestName = TEXT("TArray types"); 
	}

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Replicated C-style arrays are not supported in Unreal.
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(const TArray<int>& RepPODArray,
								  const TArray<UTestUObject*>& RepStablyNamedArray, 
								  const TArray<ATestActor*>& RepDynamicallyCreatedActors, 
								  const TArray<FSimpleTestStruct>& RepArrayOfStructs,
								  const TArray<FTestStructWithNetSerialize>& RepArrayOfStructNetSerialize,
								  const TArray<ETest8Enum>& RepEnumTArray,
								  const TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>>& RepUEnumTArray);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void Server_StartTestImpl() override;

	virtual void Server_TearDownImpl() override;

	virtual void ValidateClientReplicationImpl() override;

	virtual void SendTestResponseRPCImpl() override;

private:

	// Test C-style array with POD
	UPROPERTY(Replicated)
	TArray<int> PODArray;

	// Test array Stably name
	UPROPERTY(Replicated)
	TArray<UTestUObject*> StablyNamedArray;

	// Test array Dynamic
	UPROPERTY(ReplicatedUsing = OnRep_DynamicallyCreatedArray)
	TArray<ATestActor*> DynamicallyCreatedArray;

	// Test array of structs
	UPROPERTY(Replicated)
	TArray<FSimpleTestStruct> ArrayOfStructs;

	// Test array of structs net serialize
	UPROPERTY(Replicated)
	TArray<FTestStructWithNetSerialize> ArrayOfStructNetSerialize;

	// Test array of Unreal style enums
	UPROPERTY(Replicated)
	TArray<ETest8Enum> EnumTArray;

	// Test array of enum classes
	UPROPERTY(Replicated)
	TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>> UEnumTArray;

	UFUNCTION()
	void OnRep_DynamicallyCreatedArray();

	void ValidateReplication_Client(const TArray<int>& TestPODArray,
									const TArray<UTestUObject*>& TestStablyNamedArray, 
									const TArray<ATestActor*>& TestDynamicallyCreatedActors, 
									const TArray<FSimpleTestStruct>& TestArrayOfStructs,
									const TArray<FTestStructWithNetSerialize>& TestArrayOfStructNetSerialize,
									const TArray<ETest8Enum>& TestEnumTArray,
									const TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>>& TestUEnumTArray);

	void ValidateRPC_Server(const TArray<int>& TestPODArray,
							const TArray<UTestUObject*>& TestStablyNamedArray, 
							const TArray<ATestActor*>& TestDynamicallyCreatedActors, 
							const TArray<FSimpleTestStruct>& TestArrayOfStructs,
							const TArray<FTestStructWithNetSerialize>& TestArrayOfStructNetSerialize,
							const TArray<ETest8Enum>& TestEnumTArray,
							const TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>>& TestUEnumTArray);

	bool bDynamicallyCreatedActorReplicated;
	bool bReplicationRecievedOnClient;
};
