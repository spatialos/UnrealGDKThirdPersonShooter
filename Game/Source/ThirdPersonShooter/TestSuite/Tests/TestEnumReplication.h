// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "ReplicationTestHelperClasses.h"
#include "TestEnumReplication.generated.h"

UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API ATestEnumReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestEnumReplication() 
	{ 
		TestName = TEXT("Enum types"); 
	}

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(ETest8Enum Rep8, ETest16Enum Rep16, ETest32Enum Rep32, ETest64Enum Rep64, EnumNamespace::EUnrealTestEnum RepU);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void Server_StartTestImpl() override;

	virtual void Server_TearDownImpl() override;

	virtual void ValidateClientReplicationImpl() override;

	virtual void SendTestResponseRPCImpl() override;

	UFUNCTION()
	void Validate(ETest8Enum Test8, ETest16Enum Test16, ETest32Enum Test32, ETest64Enum Test64, EnumNamespace::EUnrealTestEnum TestU);

private:

	UPROPERTY(Replicated)
	ETest8Enum Test8Enum;

	UPROPERTY(Replicated)
	ETest16Enum Test16Enum;

	UPROPERTY(Replicated)
	ETest32Enum Test32Enum;

	UPROPERTY(Replicated)
	ETest64Enum Test64Enum;

	UPROPERTY(Replicated)
	TEnumAsByte<EnumNamespace::EUnrealTestEnum> TestUEnum;
};
