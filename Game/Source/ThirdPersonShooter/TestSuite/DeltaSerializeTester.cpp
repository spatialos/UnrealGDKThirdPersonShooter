// Fill out your copyright notice in the Description page of Project Settings.

#include "DeltaSerializeTester.h"

#include "UnrealNetwork.h"

// Sets default values
ADeltaSerializeTester::ADeltaSerializeTester()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

}

// Called when the game starts or when spawned
void ADeltaSerializeTester::BeginPlay()
{
	Super::BeginPlay();
	
	bSetupProps = true;
}

// Called every frame
void ADeltaSerializeTester::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		if (bSetupProps)
		{
			FastArray.AddItem();
			FastArray.AddItem();
			FastArray.AddItem();
			FastArray.RemoveItem();

			FastArrayWithOnRep.AddItem();
			FastArrayWithOnRep.AddItem();
			FastArrayWithOnRep.AddItem();
			FastArrayWithOnRep.RemoveItem();
 
			NestedFastArray.FastArray.AddItem();
			NestedFastArray.FastArray.AddItem();
			NestedFastArray.FastArray.AddItem();
			NestedFastArray.FastArray.RemoveItem();

			FastArrayHandover.AddItem();
			FastArrayHandover.AddItem();
			FastArrayHandover.AddItem();
			FastArrayHandover.RemoveItem();

			bSetupProps = false;
		}
	}
}

void ADeltaSerializeTester::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADeltaSerializeTester, FastArray);
	DOREPLIFETIME(ADeltaSerializeTester, FastArrayWithOnRep);
	DOREPLIFETIME(ADeltaSerializeTester, NestedFastArray);
}

void ADeltaSerializeTester::AddActorReferenceItem(AActor* RepActor)
{
	UE_LOG(LogTemp, Warning, TEXT("ADeltaSerializeTester::AddActorReferenceItem 0x%p"), RepActor);

	FastArray.AddActorItem(RepActor);
	FastArrayWithOnRep.AddActorItem(RepActor);
	NestedFastArray.FastArray.AddActorItem(RepActor);
	FastArrayHandover.AddActorItem(RepActor);
}

void ADeltaSerializeTester::OnFastArrayRep()
{
	UE_LOG(LogTemp, Warning, TEXT("ADeltaSerializeTester::OnFastArrayRep"));
}

void FFastItem::PreReplicatedRemove(const struct FFastArray& InArraySerializer)
{
	UE_LOG(LogTemp, Warning, TEXT("FFastItem::PreReplicatedRemove - %d 0x%p"), MyInt, MyActor);
}

void FFastItem::PostReplicatedAdd(const struct FFastArray& InArraySerializer)
{
	UE_LOG(LogTemp, Warning, TEXT("FFastItem::PreReplicatedAdd - %d 0x%p"), MyInt, MyActor);
}

void FFastItem::PostReplicatedChange(const struct FFastArray& InArraySerializer)
{
	UE_LOG(LogTemp, Warning, TEXT("FFastItem::PostReplicatedChange - %d 0x%p"), MyInt, MyActor);
}

void FFastArray::AddItem()
{
	static int NextInt = 0;
	FFastItem NewItem;
	NewItem.MyInt = NextInt++;
	NewItem.MyActor = nullptr;
	Items.Add(NewItem);

	MarkItemDirty(Items.Last());
}

void FFastArray::RemoveItem()
{
	if (Items.Num() > 0)
	{
		Items.RemoveAt(0);
		MarkArrayDirty();
	}
}

void FFastArray::AddActorItem(AActor* Actor)
{
	static int NextInt = 0;
	FFastItem NewItem;
	NewItem.MyInt = NextInt++;
	NewItem.MyActor = Actor;
	Items.Add(NewItem);

	MarkItemDirty(Items.Last());
}

void FFastArray::PreReplicatedRemove(const TArrayView<int32>& RemovedIndices, int32 FinalSize)
{
	UE_LOG(LogTemp, Warning, TEXT("FFastArray::PreReplicatedRemove 0x%p %d"), this, FinalSize);
}

void FFastArray::PostReplicatedAdd(const TArrayView<int32>& RemovedIndices, int32 FinalSize)
{
	UE_LOG(LogTemp, Warning, TEXT("FFastArray::PostReplicatedAdd 0x%p %d"), this, FinalSize);
}

void FFastArray::PostReplicatedChange(const TArrayView<int32>& RemovedIndices, int32 FinalSize)
{
	UE_LOG(LogTemp, Warning, TEXT("FFastArray::PostReplicatedChange 0x%p %d"), this, FinalSize);
}
