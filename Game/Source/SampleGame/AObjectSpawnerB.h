// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AObjectSpawnerB.generated.h"

UCLASS()
class SAMPLEGAME_API AAObjectSpawnerB : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAObjectSpawnerB();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
