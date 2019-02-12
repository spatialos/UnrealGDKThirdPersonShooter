// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestEnumReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestEnumReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestEnumReplication, Test8Enum, COND_None);
	DOREPLIFETIME_CONDITION(ATestEnumReplication, Test16Enum, COND_None);
	DOREPLIFETIME_CONDITION(ATestEnumReplication, Test32Enum, COND_None);
	DOREPLIFETIME_CONDITION(ATestEnumReplication, Test64Enum, COND_None);
	DOREPLIFETIME_CONDITION(ATestEnumReplication, TestUEnum, COND_None);
}

bool ATestEnumReplication::Server_ReportReplication_Validate(ETest8Enum Rep8, ETest16Enum Rep16, ETest32Enum Rep32, ETest64Enum Rep64, EnumNamespace::EUnrealTestEnum RepU)
{
	return true;
}

void ATestEnumReplication::Server_ReportReplication_Implementation(ETest8Enum Rep8, ETest16Enum Rep16, ETest32Enum Rep32, ETest64Enum Rep64, EnumNamespace::EUnrealTestEnum RepU)
{
	Validate(Rep8, Rep16, Rep32, Rep64, RepU);

	SignalResponseRecieved();
}

void ATestEnumReplication::Server_StartTestImpl()
{
	Test8Enum = ETest8Enum::Enum_1;
	Test16Enum = ETest16Enum::Enum_1;
	Test32Enum = ETest32Enum::Enum_1;
	Test64Enum = ETest64Enum::Enum_1;
	TestUEnum = EnumNamespace::Enum_1;

	SignalReplicationSetup();
}

void ATestEnumReplication::Server_TearDownImpl()
{
	Test8Enum = ETest8Enum::Enum_0;
	Test16Enum = ETest16Enum::Enum_0;
	Test32Enum = ETest32Enum::Enum_0;
	Test64Enum = ETest64Enum::Enum_0;
	TestUEnum = EnumNamespace::Enum_0;
}

void ATestEnumReplication::ValidateClientReplicationImpl()
{
	Validate(Test8Enum, Test16Enum, Test32Enum, Test64Enum, TestUEnum);
}

void ATestEnumReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication(Test8Enum, Test16Enum, Test32Enum, Test64Enum, TestUEnum);
}

void ATestEnumReplication::Validate(ETest8Enum Test8, ETest16Enum Test16, ETest32Enum Test32, ETest64Enum Test64, EnumNamespace::EUnrealTestEnum TestU)
{
	check(Test8 == ETest8Enum::Enum_1);
	check(Test16 == ETest16Enum::Enum_1);
	check(Test32 == ETest32Enum::Enum_1);
	check(Test64 == ETest64Enum::Enum_1);
	check(TestU == EnumNamespace::Enum_1);
}
