// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorCreatorBase.generated.h"

UCLASS()
class AActorCreatorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorCreatorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Actor Creator")
	void CreateActors();

	UFUNCTION(BlueprintCallable, Category = "Actor Creator")
	void ClearActors();

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Actor Creator")
	void OnRep_CreatedActorCount();

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Actor Creator")
	TSubclassOf<AActor> ActorTemplate;

	// X axis
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Actor Creator")
	int32 Rows;

	// Y axis
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Actor Creator")
	int32 Columns;

	// Z axis
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Actor Creator")
	int32 Planes;

	// X axis
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Actor Creator")
	float Width;

	// Y axis
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Actor Creator")
	float Depth;

	// Z axis
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Actor Creator")
	float Height;

	// Origin at which to spawn blocks. This will be the 0,0,0 corner of the spawn space relative to this actor's position.
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Actor Creator")
	FVector SpawnOffset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Actor Creator")
	TArray<AActor*> CreatedActors;

	UPROPERTY(ReplicatedUsing = OnRep_CreatedActorCount, VisibleAnywhere, BlueprintReadOnly, Category = "Actor Creator")
	int CreatedActorCount;
	
};
