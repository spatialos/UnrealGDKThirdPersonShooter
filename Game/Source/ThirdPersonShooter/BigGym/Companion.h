// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Companion.generated.h"

UCLASS()
class ACompanion : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACompanion();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	void NavigateToOwner(float DeltaTime);

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* MyRoot;

	UPROPERTY(EditDefaultsOnly, Category = "Companion")
	float FollowDistance;

	UPROPERTY(EditDefaultsOnly, Category = "Companion")
	float FollowSpeed;
};
