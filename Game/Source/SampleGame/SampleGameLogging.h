#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSampleGame, Log, All);

class SampleGameLogging {
public:
	static FString LogPrefix(class AActor* Actor, class UNetDriver* NetDriver);
};