// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestCube.generated.h"

UCLASS()
class SAMPLEGAME_API ATestCube : public AActor
{
	GENERATED_BODY()
	
public:	
	ATestCube();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	// [client + server] Interact with this cube. In this case, will toggle the cube's color.
	void Interact(class ACharacter* Interactor);

protected:
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerInteract();

	void ToggleColor();

	UFUNCTION()
	void OnRep_Color1();

	UPROPERTY(ReplicatedUsing = OnRep_Color1)
	bool bColor1;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxComponent;

	class UMaterialInstanceDynamic* MaterialInstanceDynamic;

	UPROPERTY(EditAnywhere)
	FLinearColor Color1;

	UPROPERTY(EditAnywhere)
	FLinearColor Color2;
};
