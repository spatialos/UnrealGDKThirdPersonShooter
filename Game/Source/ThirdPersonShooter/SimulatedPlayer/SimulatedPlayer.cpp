// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SimulatedPlayer.h"
#include "Misc/Parse.h"
#include "Misc/CommandLine.h"


bool USimulatedPlayer::IsSimulatedPlayer()
{
	return FParse::Param(FCommandLine::Get(), TEXT("fakeclient")) 
		|| FParse::Param(FCommandLine::Get(), TEXT("simulatedplayer"));
}

