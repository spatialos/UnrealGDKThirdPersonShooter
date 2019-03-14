// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
#include "TestStaticComponentReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

UTestComponent::UTestComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	TestProperty = 42.f;
}

void UTestComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(UTestComponent, TestProperty, COND_None);
}

void UTestComponent::OnRep_TestProperty()
{
	auto Owner = Cast<ATestStaticComponentReplication>(GetOwner());
	check(Owner);
	Owner->Server_ReportReplication(TestProperty);
}

ATestStaticComponentReplication::ATestStaticComponentReplication()
{
	TestName = TEXT("Static component replication");
	TestComponent = CreateDefaultSubobject<UTestComponent>(TEXT("TestComponent"));
	check(TestComponent);
	TestComponent->SetIsReplicated(true);
}

bool ATestStaticComponentReplication::Server_ReportReplication_Validate(float RepFloat)
{
	return true;
}

void ATestStaticComponentReplication::Server_ReportReplication_Implementation(float RepFloat)
{
	check(RepFloat == TestComponent->TestProperty);

	SignalResponseRecieved();
}

void ATestStaticComponentReplication::Server_StartTestImpl()
{
	TestComponent->TestProperty = FMath::RandRange(-100.f, 100.f);

	SignalReplicationSetup();
}

void ATestStaticComponentReplication::Server_TearDownImpl()
{
}

void ATestStaticComponentReplication::ValidateClientReplicationImpl()
{
}

void ATestStaticComponentReplication::SendTestResponseRPCImpl()
{
	// ILB - Send test response on UTestComponent::OnRep_TestProperty instead so we're certain the TestProperty
	// has been replicated by that point.
}