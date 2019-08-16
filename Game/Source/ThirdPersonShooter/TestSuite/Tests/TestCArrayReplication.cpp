// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestCArrayReplication.h"

#include "GDKTestRunner.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestCArrayReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, PODArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, StablyNamedArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, DynamicallyCreatedArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, ArrayOfStructs, COND_None);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, ArrayOfStructNetSerialize, COND_None);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, EnumCArray, COND_None);
	DOREPLIFETIME_CONDITION(ATestCArrayReplication, UEnumCArray, COND_None);
}

void ATestCArrayReplication::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetNetMode() == NM_Client)
	{
		if (bDynamicallyCreatedActorReplicated && bReplicationRecievedOnClient)
		{
			bDynamicallyCreatedActorReplicated = false;
			bReplicationRecievedOnClient = false;

			ValidateReplication_Client();

			Server_ReportReplication();
		}
	}
}

bool ATestCArrayReplication::Server_ReportReplication_Validate()
{
	return true;
}

void ATestCArrayReplication::Server_ReportReplication_Implementation()
{
	SignalResponseRecieved();
}

void ATestCArrayReplication::Server_StartTestImpl()
{
	// Setup PODs
	PODArray[0] = FirstComparisonValue;
	PODArray[1] = SecondComparisonValue;

	// Setup stably named UObjects
	UTestUObject* StablyNamedObject = LoadObject<UTestUObject>(nullptr, TEXT("/Script/ThirdPersonShooter.Default__TestUObject"));
	check(StablyNamedObject);

	StablyNamedArray[0] = StablyNamedObject;
	StablyNamedArray[1] = StablyNamedObject;

	// Setup dynamically generated actors
	ATestActor* NewActor = GetWorld()->SpawnActor<ATestActor>();
	NewActor->ActorName = NewActor->GetName();
	DynamicallyCreatedArray[0] = NewActor;
	DynamicallyCreatedArray[1] = NewActor;

	// Setup array of structs
	FSimpleTestStruct Entry;
	Entry.RootProp = 42;
	ArrayOfStructs[0] = Entry;
	Entry.RootProp = 37;
	ArrayOfStructs[1] = Entry;
 
	// Setup of array of structs with net serialize
	FTestStructWithNetSerialize NetSerializeEntry;
	NetSerializeEntry.MyInt = 42;
	NetSerializeEntry.MyFloat = 25.0f;
	ArrayOfStructNetSerialize[0] = NetSerializeEntry;
	NetSerializeEntry.MyInt = 43;
	NetSerializeEntry.MyFloat = 50.0f;
	ArrayOfStructNetSerialize[1] = NetSerializeEntry;

	// Setup of array of Unreal style enums
	EnumCArray[0] = ETest8Enum::Enum_1;
	EnumCArray[1] = ETest8Enum::Enum_0;

	// Setup of array of enum classes
	UEnumCArray[0] = EnumNamespace::Enum_1;
	UEnumCArray[1] = EnumNamespace::Enum_0;

	SignalReplicationSetup();
}

void ATestCArrayReplication::Server_TearDownImpl()
{
	PODArray[0] = 0;
	PODArray[1] = 0;

	StablyNamedArray[0] = nullptr;
	StablyNamedArray[1] = nullptr;

	if (!DynamicallyCreatedArray[0]->Destroy(true))
	{
		UE_LOG(LogSpatialGDKTests, Log, TEXT("TestCase %s: Unable to tear down dynamically created actor C style array"), *TestName);
	}

	if (!DynamicallyCreatedArray[1]->Destroy(true))
	{
		UE_LOG(LogSpatialGDKTests, Log, TEXT("TestCase %s: Unable to tear down dynamically created actor C style array"), *TestName);
	}

	DynamicallyCreatedArray[0] = nullptr;
	DynamicallyCreatedArray[1] = nullptr;

	ArrayOfStructs[0].RootProp = 0;
	ArrayOfStructs[1].RootProp = 0;

	ArrayOfStructNetSerialize[0].MyInt = 0;
	ArrayOfStructNetSerialize[0].MyFloat = 0.0f;
	ArrayOfStructNetSerialize[1].MyInt = 0;
	ArrayOfStructNetSerialize[1].MyFloat = 0.0f;

	EnumCArray[0] = ETest8Enum::Enum_0;
	EnumCArray[1] = ETest8Enum::Enum_0;

	UEnumCArray[0] = EnumNamespace::Enum_0;
	UEnumCArray[1] = EnumNamespace::Enum_0;
}

void ATestCArrayReplication::ValidateClientReplicationImpl()
{
	bReplicationRecievedOnClient = true;
}

void ATestCArrayReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication();
}

void ATestCArrayReplication::OnRep_DynamicallyCreatedArray()
{
	bDynamicallyCreatedActorReplicated = true;
}

void ATestCArrayReplication::ValidateReplication_Client()
{
	// Validate PODs
	check(PODArray[0] == FirstComparisonValue);
	check(PODArray[1] == SecondComparisonValue);

	// Validate the stably named object
	check(StablyNamedArray[0]->IsA(UTestUObject::StaticClass()));
	check(StablyNamedArray[0] == UTestUObject::StaticClass()->GetDefaultObject());
	check(StablyNamedArray[0]->GetPathName() == TEXT("/Script/ThirdPersonShooter.Default__TestUObject"));

	check(StablyNamedArray[1]->IsA(UTestUObject::StaticClass()));
	check(StablyNamedArray[1] == UTestUObject::StaticClass()->GetDefaultObject());
	check(StablyNamedArray[1]->GetPathName() == TEXT("/Script/ThirdPersonShooter.Default__TestUObject"));

	// Validate Dynamically created UObjects in the array
	check(DynamicallyCreatedArray[0]->IsA(ATestActor::StaticClass()));
	check(DynamicallyCreatedArray[1]->IsA(ATestActor::StaticClass()));

	// Validate TArray with structs
	check(ArrayOfStructs[0].RootProp == 42);
	check(ArrayOfStructs[1].RootProp == 37);

	// Validate TArray with structs and net serialize
	check(ArrayOfStructNetSerialize[0].MyInt == 42);
	check(ArrayOfStructNetSerialize[0].MyFloat == 25.0f);
	check(ArrayOfStructNetSerialize[1].MyInt == 43);
	check(ArrayOfStructNetSerialize[1].MyFloat == 50.0f);

	// Validate TArray of Unreal style enums
	check(EnumCArray[0] == ETest8Enum::Enum_1);
	check(EnumCArray[1] == ETest8Enum::Enum_0);

	// Setup of array of enum classes
	check(UEnumCArray[0] == EnumNamespace::Enum_1);
	check(UEnumCArray[1] == EnumNamespace::Enum_0);
}
