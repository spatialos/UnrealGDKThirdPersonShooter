// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "ScaleTestableCharacter.h"
#include "c_worker.h"
#include "Misc/Parse.h"
#include "PlatformTime.h"
#include "Stats/Stats2.h"
#include "SpatialNetDriver.h"
#include "SpatialWorkerConnection.h"
#include "Logging/LogMacros.h"

#include "CoreMinimal.h"
DEFINE_LOG_CATEGORY(LogBattleNonsense);

#if PLATFORM_WINDOWS
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include "Windows.h"
#elif PLATFORM_UNIX
#include "time.h"
#endif

inline void PrintTimestamp()
{
#if PLATFORM_WINDOWS
	LARGE_INTEGER perfCount;
	QueryPerformanceCounter(&perfCount);
	UE_LOG(LogBattleNonsense, Display, TEXT("%lld"), perfCount.QuadPart);
#elif PLATFORM_UNIX
	timespec time;
	clock_gettime(CLOCK_MONOTONIC_RAW, &time);
	UE_LOG(LogBattleNonsense, Display, TEXT("%lld %d"), time.tv_sec, time.tv_nsec);
#else
#error Function not implemented on this platform.
#endif
}

static TAutoConsoleVariable<int32> CVarBattleNonsenseDoJump(
	TEXT("battle_nonsense.DoJump"),
	0,
	TEXT("Whether to stimulate a jump for the purposes of lag testing"),
	ECVF_Default);

static TAutoConsoleVariable<int32> CVarBattleNonsenseListenForJump(
	TEXT("battle_nonsense.ListenForJump"),
	0,
	TEXT("Whether to listen for jumps for the purposes of lag testing"),
	ECVF_Default);

static TAutoConsoleVariable<int32> CVarBattleNonsenseListenForShoot(
	TEXT("battle_nonsense.ListenForShoot"),
	0,
	TEXT("Whether to listen for shots for the purposes of lag testing"),
	ECVF_Default);

static TAutoConsoleVariable<int32> CVarBattleNonsenseDoShoot(
	TEXT("battle_nonsense.DoShoot"),
	0,
	TEXT("Whether to stimulate shots for the purposes of lag testing"),
	ECVF_Default);

// Sets default values
AScaleTestableCharacter::AScaleTestableCharacter(
    const FObjectInitializer& ObjectInitializer) : ACharacter(ObjectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance
	// if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AScaleTestableCharacter::StimulateJump()
{
	if (Role != ROLE_AutonomousProxy)
	{
		return;
	}

	PrintTimestamp();

	Jump();
}

void AScaleTestableCharacter::StimulateShoot()
{
	if (Role != ROLE_AutonomousProxy)
	{
		return;
	}

	PrintTimestamp();

	ServerShoot();
}

bool AScaleTestableCharacter::ServerShoot_Validate()
{
	return true;
}

void AScaleTestableCharacter::ServerShoot_Implementation()
{
	// Send RPC to clients
	MulticastNotifyHit();
}

void AScaleTestableCharacter::MulticastNotifyHit_Implementation()
{
	if (Role != ROLE_SimulatedProxy)
	{
		return;
	}

	if (CVarBattleNonsenseListenForShoot.GetValueOnGameThread())
	{
		// Notify we have recieved the shot
		PrintTimestamp();
	}
}

// Called when the game starts or when spawned
void AScaleTestableCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (FParse::Param(FCommandLine::Get(), TEXT("simulatedplayer")))
	{
		bIsSimulatedPlayer = true;
	}

	GetWorldTimerManager().SetTimer(TimerHandler, this, &AScaleTestableCharacter::TurnRight, 1.0f,
									true, 0.0f);

	if (CVarBattleNonsenseDoJump.GetValueOnGameThread())
	{
		GetWorldTimerManager().SetTimer(TimerHandler, this, &AScaleTestableCharacter::StimulateJump, 2.0f, true);
	}

	if (CVarBattleNonsenseDoShoot.GetValueOnGameThread())
	{
		GetWorldTimerManager().SetTimer(TimerHandler, this, &AScaleTestableCharacter::StimulateShoot, 2.0f, true);
	}
}

// Called every frame
void AScaleTestableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsSimulatedPlayer)
    {
		AddMovementInput(Directions[DirectionIndex] * Speed);
	}

	if (CVarBattleNonsenseListenForJump.GetValueOnGameThread())
	{
		if (Role == ROLE_SimulatedProxy)
		{
			// Simple latch mechanism to ensure the jump is detected properly
			if (GetCharacterMovement()->MovementMode == MOVE_Walking)
			{
				bHasHitGround = true;
			}

			if (bHasHitGround)
			{
				if (GetCharacterMovement()->MovementMode == MOVE_Falling)
				{
					bHasHitGround = false;

					PrintTimestamp();
				}
			}

		}
	}
}

void AScaleTestableCharacter::TurnRight()
{
	DirectionIndex++;
	if (DirectionIndex >= 4)
	{
		DirectionIndex = 0;
	}
}
