// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReplicationTestCase.h"
#include "TestFTextReplication.generated.h"

UCLASS(SpatialType)
class THIRDPERSONSHOOTER_API ATestFTextReplication : public AReplicationTestCase
{
	GENERATED_BODY()
public:	

	ATestFTextReplication() 
		: ValidationText(FText::FromString(TEXT("You're gonna need a bigger boat.")))
	{ 
		TestName = TEXT("FText types"); 
	}

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ReportReplication(const FText& RepFText);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void Server_StartTestImpl() override;

	virtual void Server_TearDownImpl() override;

	virtual void ValidateClientReplicationImpl() override;

	virtual void SendTestResponseRPCImpl() override;

private:

	UPROPERTY(Replicated)
	FText TestFText;

	FText ValidationText;
};
