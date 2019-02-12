// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestIntReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestIntReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test8Int, COND_None);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test16Int, COND_None);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test32Int, COND_None);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test64Int, COND_None);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test8UInt, COND_None);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test16UInt, COND_None);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test32UInt, COND_None);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test64UInt, COND_None);
}

bool ATestIntReplication::Server_ReportReplication_Validate(int8 Rep8Int, int16 Rep16Int, int32 Rep32Int, int64 Rep64Int, uint8 Rep8UInt, uint16 Rep16UInt, uint32 Rep32UInt, uint64 Rep64UInt)
{
	return true;
}

void ATestIntReplication::Server_ReportReplication_Implementation(int8 Rep8Int, int16 Rep16Int, int32 Rep32Int, int64 Rep64Int, uint8 Rep8UInt, uint16 Rep16UInt, uint32 Rep32UInt, uint64 Rep64UInt)
{
	check(Rep8Int == (1 << 6));
	check(Rep16Int == (1 << 14));
	check(Rep32Int == 0xDEADBEEF);
	check(Rep64Int == 0xDEADBEEFDEADBEEF);
	check(Rep8UInt == 0xDE);
	check(Rep16UInt == 0xDEAD);
	check(Rep32UInt == 0xDEADBEEF);
	check(Rep64UInt == 0xDEADBEEFDEADBEEF);

	SignalResponseRecieved();
}

void ATestIntReplication::Server_StartTestImpl()
{
	Test8Int = (1 << 6);
	Test16Int = (1 << 14);
	Test32Int = 0xDEADBEEF;
	Test64Int = 0xDEADBEEFDEADBEEF;
	Test8UInt = 0xDE;
	Test16UInt = 0xDEAD;
	Test32UInt = 0xDEADBEEF;
	Test64UInt = 0xDEADBEEFDEADBEEF;

	SignalReplicationSetup();
}

void ATestIntReplication::Server_TearDownImpl()
{
	Test8Int = 0;
	Test16Int = 0;
	Test32Int = 0;
	Test64Int = 0;
	Test8UInt = 0;
	Test16UInt = 0;
	Test32UInt = 0;
	Test64UInt = 0;
}

void ATestIntReplication::ValidateClientReplicationImpl()
{
	check(Test8Int == (1 << 6));
	check(Test16Int == (1 << 14));
	check(Test32Int == 0xDEADBEEF);
	check(Test64Int == 0xDEADBEEFDEADBEEF);
	check(Test8UInt == 0xDE);
	check(Test16UInt == 0xDEAD);
	check(Test32UInt == 0xDEADBEEF);
	check(Test64UInt == 0xDEADBEEFDEADBEEF);
}

void ATestIntReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication(Test8Int, Test16Int, Test32Int, Test64Int, Test8UInt, Test16UInt, Test32UInt, Test64UInt);
}
