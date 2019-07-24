// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "ScaleTestableCharacter.h"
#include "Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Logging/LogMacros.h"
#include "Misc/Parse.h"
#include "PlatformTime.h"
#include "SpatialNetDriver.h"
#include "SpatialWorkerConnection.h"
#include "Stats/Stats2.h"
#include "SimPlayerBPFunctionLibrary.h"
#include "c_worker.h"

// Windows latency measurements do not build in CI.
// If you are running latency measurements locally on Windows you will
// have to enable this definition.
//
// See https://answers.unrealengine.com/questions/813258/updated-to-420-now-i-cant-build-error-c4668.html
// for details on the build issue.
#define ENABLE_WINDOWS_LATENCY_OUTPUT 0

#if PLATFORM_WINDOWS && ENABLE_WINDOWS_LATENCY_OUTPUT == 1
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include "Windows.h"
#elif PLATFORM_UNIX
#include "time.h"
#endif

DEFINE_LOG_CATEGORY(LogSpatialLatencyTest);

inline void PrintTimestamp()
{
#if PLATFORM_WINDOWS
#if ENABLE_WINDOWS_LATENCY_OUTPUT == 0
	UE_LOG(LogSpatialLatencyTest, Display, TEXT("Latency timestamps have been disabled on Windows."));
#else
	LARGE_INTEGER PerfCount;
	QueryPerformanceCounter(&PerfCount);
	UE_LOG(LogSpatialLatencyTest, Display, TEXT("%lld"), PerfCount.QuadPart);
#endif
#elif PLATFORM_UNIX
	timespec Time;
	clock_gettime(CLOCK_MONOTONIC_RAW, &Time);
	UE_LOG(LogSpatialLatencyTest, Display, TEXT("%lld %d"), Time.tv_sec, Time.tv_nsec);
#else
#error Function not implemented on this platform.
#endif
}

static TAutoConsoleVariable<int32> CVarSpatialLatencyTestDoJump(
	TEXT("SpatialLatencyTest.DoJump"),
	0,
	TEXT("Whether to stimulate a jump for the purposes of lag testing"),
	ECVF_Default);

static TAutoConsoleVariable<int32> CVarSpatialLatencyTestListenForJump(
	TEXT("SpatialLatencyTest.ListenForJump"),
	0,
	TEXT("Whether to listen for jumps for the purposes of lag testing"),
	ECVF_Default);

static TAutoConsoleVariable<int32> CVarSpatialLatencyTestDoShoot(
	TEXT("SpatialLatencyTest.DoShoot"),
	0,
	TEXT("Whether to stimulate shots for the purposes of lag testing"),
	ECVF_Default);

static TAutoConsoleVariable<int32> CVarSpatialLatencyTestListenForShoot(
	TEXT("SpatialLatencyTest.ListenForShoot"),
	0,
	TEXT("Whether to listen for shots for the purposes of lag testing"),
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

	if (CVarSpatialLatencyTestListenForShoot.GetValueOnGameThread())
	{
		// Notify we have recieved the shot
		PrintTimestamp();
	}
}

// Called when the game starts or when spawned
void AScaleTestableCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (USimPlayerBPFunctionLibrary::IsSimulatedPlayer(this))
	{
		bIsSimulatedPlayer = true;
	}

	GetWorldTimerManager().SetTimer(TimerHandler, this, &AScaleTestableCharacter::TurnRight, 1.0f,
									true, 0.0f);

	if (CVarSpatialLatencyTestDoJump.GetValueOnGameThread())
	{
		GetWorldTimerManager().SetTimer(TimerHandler, this, &AScaleTestableCharacter::StimulateJump, 2.0f, true);
	}

	if (CVarSpatialLatencyTestDoShoot.GetValueOnGameThread())
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

	if (CVarSpatialLatencyTestListenForJump.GetValueOnGameThread())
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
