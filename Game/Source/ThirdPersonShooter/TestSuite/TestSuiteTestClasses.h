// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EntityRegistry.h"
#include "GameFramework/Character.h"
#include "TestsuiteTestClasses.generated.h"


USTRUCT()
struct FRootStruct
{
	GENERATED_BODY()

	UPROPERTY()
	int RootProp;
};

USTRUCT()
struct FContainerStruct
{
	GENERATED_BODY()

	UPROPERTY()
	FRootStruct Struct_1;

	UPROPERTY()
	FRootStruct Struct_2;
};

UCLASS(SpatialType)
class ARepCmdConfusion : public AActor
{
	GENERATED_BODY()

public:
	ARepCmdConfusion();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	//UPROPERTY(Replicated)
	//FContainerStruct MyStruct;
};

UCLASS(SpatialType, config=Game)
class AS_TestUnderscoreClassName : public AActor
{
	GENERATED_BODY()

public:
	AS_TestUnderscoreClassName();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(replicated)
	int foo_bar_car;

	UFUNCTION(Client, Reliable)
	void ClientUnderscoreRPC();

	UFUNCTION(Client, Reliable)
	void Client_Bar_RPC();
};

