// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSampleGame, Log, All);

class SampleGameLogging {
public:
	static FString LogPrefix(class AActor* Actor);
};