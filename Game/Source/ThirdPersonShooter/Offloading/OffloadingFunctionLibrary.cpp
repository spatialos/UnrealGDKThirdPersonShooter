// Copyright (c) Improbable Worlds Ltd, All Rights Reserved


#include "OffloadingFunctionLibrary.h"
#include "AI/NavigationSystemBase.h"
#include "NavigationSystem/public/NavigationData.h"
#include "Engine/World.h"
#include "Misc/CommandLine.h"

void UOffloadingFunctionLibrary::DisableNavMesh(UObject* WorldContextObject)
{
	if (const UNavigationSystemBase* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemBase>(WorldContextObject->GetWorld()))
	{
		if (ANavigationData* NavData = (ANavigationData*)NavSys->GetMainNavData())
		{
			UE_LOG(LogTemp, Display, TEXT("[DisableNavMesh]: Found NavData: %s"), *NavData->GetName());
			NavData->Destroy();
		}
	}
	
}

int UOffloadingFunctionLibrary::GetNumBotsFromCommandLine(const FString& Arg)
{
	const TCHAR* CommandLine = FCommandLine::Get();
	int Result = 0;
	FParse::Value(CommandLine, *Arg, Result);
	return Result;
}
