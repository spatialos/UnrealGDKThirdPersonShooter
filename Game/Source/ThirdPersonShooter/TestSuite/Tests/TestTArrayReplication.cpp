// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestTArrayReplication.h"

#include "GDKTestRunner.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"
#include "SpatialNetDriver.h"
#include "SpatialPackageMapClient.h"
#include "GeneralProjectSettings.h"

#include <improbable/c_worker.h>

void ATestTArrayReplication::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetNetMode() != NM_Client)
	{
		return;
	}

	if (bDynamicallyCreatedActorReplicated && bReplicationRecievedOnClient)
	{
		check(DynamicallyCreatedArray.Num() == 1);
		if (DynamicallyCreatedArray[0] != nullptr)
		{
			bDynamicallyCreatedActorReplicated = false;
			bReplicationRecievedOnClient = false;

			ValidateReplication_Client(PODArray, StablyNamedArray, DynamicallyCreatedArray, ArrayOfStructs, ArrayOfStructNetSerialize, EnumTArray, UEnumTArray);

			Server_ReportReplication(PODArray, StablyNamedArray, DynamicallyCreatedArray, ArrayOfStructs, ArrayOfStructNetSerialize, EnumTArray, UEnumTArray);
		}
	}
}

void ATestTArrayReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestTArrayReplication, PODArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestTArrayReplication, StablyNamedArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestTArrayReplication, DynamicallyCreatedArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestTArrayReplication, ArrayOfStructs, COND_None);
	DOREPLIFETIME_CONDITION(ATestTArrayReplication, ArrayOfStructNetSerialize, COND_None);
	DOREPLIFETIME_CONDITION(ATestTArrayReplication, EnumTArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestTArrayReplication, UEnumTArray, COND_None);
}

bool ATestTArrayReplication::Server_ReportReplication_Validate(const TArray<int>& RepPODArray,
															   const TArray<UTestUObject*>& RepStablyNamedArray, 
															   const TArray<ATestActor*>& RepDynamicallyCreatedActors, 
															   const TArray<FSimpleTestStruct>& RepArrayOfStructs,
															   const TArray<FTestStructWithNetSerialize>& RepArrayOfStructNetSerialize,
															   const TArray<ETest8Enum>& RepEnumTArray,
															   const TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>>& RepUEnumTArray)
{
	return true;
}

void ATestTArrayReplication::Server_ReportReplication_Implementation(const TArray<int>& RepPODArray,
																	 const TArray<UTestUObject*>& RepStablyNamedArray, 
																	 const TArray<ATestActor*>& RepDynamicallyCreatedActors, 
																	 const TArray<FSimpleTestStruct>& RepArrayOfStructs,
																	 const TArray<FTestStructWithNetSerialize>& RepArrayOfStructNetSerialize,
																	 const TArray<ETest8Enum>& RepEnumTArray,
																	 const TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>>& RepUEnumTArray)
{
	ValidateRPC_Server(RepPODArray, RepStablyNamedArray, RepDynamicallyCreatedActors, RepArrayOfStructs, RepArrayOfStructNetSerialize, RepEnumTArray, RepUEnumTArray);

	SignalResponseRecieved();
}

void ATestTArrayReplication::Server_StartTestImpl()
{
	// Setup PODs
	PODArray.Add(42);
	PODArray.Add(37);

	// Setup stably named UObjects
	UTestUObject* StablyNamedObject = LoadObject<UTestUObject>(nullptr, TEXT("/Script/ThirdPersonShooter.Default__TestUObject"));
	check(StablyNamedObject);

	StablyNamedArray.Add(StablyNamedObject);
	StablyNamedArray.Add(StablyNamedObject);

	// Setup dynamically generated actors
	ATestActor* NewActor = GetWorld()->SpawnActor<ATestActor>();
	NewActor->ActorName = NewActor->GetName();
	DynamicallyCreatedArray.Add(NewActor);

	// Setup array of structs
	FSimpleTestStruct Entry;
	Entry.RootProp = 42;
	ArrayOfStructs.Add(Entry);
	Entry.RootProp = 37;
	ArrayOfStructs.Add(Entry);

	// Setup of array of structs with net serialize
	FTestStructWithNetSerialize NetSerializeEntry;
	NetSerializeEntry.MyInt = 42;
	NetSerializeEntry.MyFloat = 25.0f;
	ArrayOfStructNetSerialize.Add(NetSerializeEntry);

	// Setup of array of Unreal style enums
	EnumTArray.Push(ETest8Enum::Enum_1);
	EnumTArray.Push(ETest8Enum::Enum_0);

	// Setup of array of enum classes
	UEnumTArray.Push(EnumNamespace::Enum_1);
	UEnumTArray.Push(EnumNamespace::Enum_0);

	SignalReplicationSetup();
}

void ATestTArrayReplication::Server_TearDownImpl()
{
	PODArray.Empty();
	StablyNamedArray.Empty();

	for (ATestActor* Actor : DynamicallyCreatedArray)
	{
		if (!Actor->Destroy(true))
		{
			UE_LOG(LogSpatialGDKTests, Log, TEXT("TestCase %s: Unable to tear down dynamically created actor in TArray"), *TestName);
		}
	}
	DynamicallyCreatedArray.Empty();

	ArrayOfStructs.Empty();

	ArrayOfStructNetSerialize.Empty();

	EnumTArray.Empty();

	UEnumTArray.Empty();
}

void ATestTArrayReplication::ValidateClientReplicationImpl()
{
	bReplicationRecievedOnClient = true;
}

void ATestTArrayReplication::SendTestResponseRPCImpl()
{
	// Empty due to the deferred execution
}

void ATestTArrayReplication::OnRep_DynamicallyCreatedArray()
{
	bDynamicallyCreatedActorReplicated = true;
}

void ATestTArrayReplication::ValidateReplication_Client(const TArray<int>& TestPODArray,
														const TArray<UTestUObject*>& TestStablyNamedArray, 
														const TArray<ATestActor*>& TestDynamicallyCreatedActors, 
														const TArray<FSimpleTestStruct>& TestArrayOfStructs,
														const TArray<FTestStructWithNetSerialize>& TestArrayOfStructNetSerialize,
														const TArray<ETest8Enum>& TestEnumTArray,
														const TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>>& TestUEnumTArray)
{
	// Validate PODs
	check(TestPODArray.Num() == 2);
	check(TestPODArray[0] == 42);
	check(TestPODArray[1] == 37);

	// Validate the stably named object
	check(TestStablyNamedArray.Num() == 2);

	check(TestStablyNamedArray[0]->IsA(UTestUObject::StaticClass()));
	check(TestStablyNamedArray[0] == UTestUObject::StaticClass()->GetDefaultObject());
	check(TestStablyNamedArray[0]->GetPathName() == TEXT("/Script/ThirdPersonShooter.Default__TestUObject"));

	check(TestStablyNamedArray[1]->IsA(UTestUObject::StaticClass()));
	check(TestStablyNamedArray[1] == UTestUObject::StaticClass()->GetDefaultObject());
	check(TestStablyNamedArray[1]->GetPathName() == TEXT("/Script/ThirdPersonShooter.Default__TestUObject"));

	// Validate Dynamically created UObjects in the array
	check(TestDynamicallyCreatedActors.Num() == 1);
	check(TestDynamicallyCreatedActors[0]->IsA(ATestActor::StaticClass()));

	// Validate TArray with structs
	check(TestArrayOfStructs.Num() == 2);
	check(TestArrayOfStructs[0].RootProp == 42);
	check(TestArrayOfStructs[1].RootProp == 37);

	// Validate TArray with structs and net serialize
	check(TestArrayOfStructNetSerialize.Num() == 1);
	check(TestArrayOfStructNetSerialize[0].MyInt == 42);
	check(TestArrayOfStructNetSerialize[0].MyFloat == 25.0f);

	// Validate TArray of Unreal style enums
	check(TestEnumTArray.Num() == 2);
	check(TestEnumTArray[0] == ETest8Enum::Enum_1);
	check(TestEnumTArray[1] == ETest8Enum::Enum_0);

	// Setup of array of enum classes
	check(TestUEnumTArray.Num() == 2);
	check(TestUEnumTArray[0] == EnumNamespace::Enum_1);
	check(TestUEnumTArray[1] == EnumNamespace::Enum_0);
}

void ATestTArrayReplication::ValidateRPC_Server(const TArray<int>& TestPODArray,
												const TArray<UTestUObject*>& TestStablyNamedArray, 
												const TArray<ATestActor*>& TestDynamicallyCreatedActors, 
												const TArray<FSimpleTestStruct>& TestArrayOfStructs,
												const TArray<FTestStructWithNetSerialize>& TestArrayOfStructNetSerialize,
												const TArray<ETest8Enum>& TestEnumTArray,
												const TArray<TEnumAsByte<EnumNamespace::EUnrealTestEnum>>& TestUEnumTArray)
{
	// Validate PODs
	check(TestPODArray.Num() == 2);
	check(TestPODArray[0] == 42);
	check(TestPODArray[1] == 37);

	// Validate the stably named object
	check(TestStablyNamedArray.Num() == 2);

	check(TestStablyNamedArray[0]->IsA(UTestUObject::StaticClass()));
	check(TestStablyNamedArray[0] == UTestUObject::StaticClass()->GetDefaultObject());
	check(TestStablyNamedArray[0]->GetPathName() == TEXT("/Script/ThirdPersonShooter.Default__TestUObject"));

	check(TestStablyNamedArray[1]->IsA(UTestUObject::StaticClass()));
	check(TestStablyNamedArray[1] == UTestUObject::StaticClass()->GetDefaultObject());
	check(TestStablyNamedArray[1]->GetPathName() == TEXT("/Script/ThirdPersonShooter.Default__TestUObject"));

	// Validate Dynamically created UObjects in the array
	check(TestDynamicallyCreatedActors.Num() == 1);

	// If using Spatial - get the net driver
	USpatialNetDriver* NetDriver = Cast<USpatialNetDriver>(GetWorld()->GetNetDriver());
	if (NetDriver)
	{
		check(NetDriver);
		Worker_EntityId RPCEntityId = NetDriver->PackageMap->GetEntityIdFromObject(TestDynamicallyCreatedActors[0]);
		Worker_EntityId ServerEntityId = NetDriver->PackageMap->GetEntityIdFromObject(DynamicallyCreatedArray[0]);
		check(RPCEntityId == ServerEntityId);
	}

	// Validate TArray with structs
	check(TestArrayOfStructs.Num() == 2);
	check(TestArrayOfStructs[0].RootProp == 42);
	check(TestArrayOfStructs[1].RootProp == 37);

	// Validate TArray of Unreal style enums
	check(TestEnumTArray.Num() == 2);
	check(TestEnumTArray[0] == ETest8Enum::Enum_1);
	check(TestEnumTArray[1] == ETest8Enum::Enum_0);

	// Setup of array of enum classes
	check(TestUEnumTArray.Num() == 2);
	check(TestUEnumTArray[0] == EnumNamespace::Enum_1);
	check(TestUEnumTArray[1] == EnumNamespace::Enum_0);
}
