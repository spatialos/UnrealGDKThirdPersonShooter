// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestsuiteTestClasses.h"
#include "UnrealNetwork.h"

//////////////////////////////////////////////////////////////////////////
// AS_TestUnderscoreClassName

AS_TestUnderscoreClassName::AS_TestUnderscoreClassName()
{
	
}

void AS_TestUnderscoreClassName::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(AS_TestUnderscoreClassName, foo_bar_car, COND_None);
}

void AS_TestUnderscoreClassName::ClientUnderscoreRPC_Implementation()
{

}

void AS_TestUnderscoreClassName::Client_Bar_RPC_Implementation()
{

}

ARepCmdConfusion::ARepCmdConfusion()
{

}

void ARepCmdConfusion::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//DOREPLIFETIME_CONDITION(ARepCmdConfusion, MyStruct, COND_None);
}
