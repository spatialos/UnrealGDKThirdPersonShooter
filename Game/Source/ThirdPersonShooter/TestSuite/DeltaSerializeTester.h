// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeltaSerializeTester.generated.h"

USTRUCT()
struct FFastItem : public FFastArraySerializerItem
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	int32 MyInt;

	UPROPERTY()
	AActor* MyActor;

	void PreReplicatedRemove(const struct FFastArray& InArraySerializer);
	void PostReplicatedAdd(const struct FFastArray& InArraySerializer);
	void PostReplicatedChange(const struct FFastArray& InArraySerializer);
};

USTRUCT()
struct FFastArray : public FFastArraySerializer
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TArray<FFastItem> Items;

	bool NetDeltaSerialize(FNetDeltaSerializeInfo & DeltaParms)
	{
		return FFastArraySerializer::FastArrayDeltaSerialize<FFastItem, FFastArray>(Items, DeltaParms, *this);
	}

	void AddItem();
	void RemoveItem();
	void AddActorItem(AActor* Actor);

	void PreReplicatedRemove(const TArrayView<int32>& RemovedIndices, int32 FinalSize);
	void PostReplicatedAdd(const TArrayView<int32>& AddedIndices, int32 FinalSize);
	void PostReplicatedChange(const TArrayView<int32>& ChangedIndices, int32 FinalSize);
};

template<>
struct TStructOpsTypeTraits< FFastArray > : public TStructOpsTypeTraitsBase2< FFastArray >
{
	enum
	{
		WithNetDeltaSerializer = true,
	};
};

USTRUCT()
struct FNestedFastArray
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	FFastArray FastArray;
};

UCLASS()
class THIRDPERSONSHOOTER_API ADeltaSerializeTester : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeltaSerializeTester();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable)
	void AddActorReferenceItem(AActor* RepActor);

	UFUNCTION()
	void OnFastArrayRep();

	UPROPERTY(Replicated)
	FFastArray FastArray;

	UPROPERTY(ReplicatedUsing=OnFastArrayRep)
	FFastArray FastArrayWithOnRep;
	
	UPROPERTY(Replicated)
	FNestedFastArray NestedFastArray;

	UPROPERTY(Handover)
	FFastArray FastArrayHandover;

	bool bSetupProps;
};
