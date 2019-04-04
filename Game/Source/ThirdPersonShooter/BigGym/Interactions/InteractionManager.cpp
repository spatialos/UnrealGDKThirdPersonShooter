// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractionManager.h"

#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

#include "InteractAction.h"
#include "BigGym/UI/InteractMenuBase.h"


UInteractionManager::UInteractionManager()
{
	SetIsReplicated(true);
}

void UInteractionManager::OpenMenu(AActor* Target)
{
	TargetActor = Target;

	if (GetOwner()->Role < ROLE_Authority)
	{
		ServerOpenMenu(Target);
	}

	if (GetNetMode() == NM_Standalone || GetNetMode() > NM_DedicatedServer)
	{
		FName MenuName = Target->GetClass()->GetFName();
		FInteractionMenuData* MenuData = MenuDataTable->FindRow<FInteractionMenuData>(MenuName, TEXT(""));
		if (MenuData == nullptr)
		{
			return;
		}

		APlayerController* PC = Cast<APlayerController>(Cast<ACharacter>(GetOwner())->GetController());
		UUserWidget* Menu = InteractMenuCache.FindRef(MenuName);
		if (Menu == nullptr)
		{
			Menu = CreateWidget(PC, MenuData->MenuType);
			if (!Menu->IsA(UInteractMenuBase::StaticClass()))
			{
				return;
			}
			Cast<UInteractMenuBase>(Menu)->Init(this);
			InteractMenuCache.Add(MenuName, Menu);
		}
		Menu->AddToViewport(0);
		CurrentMenu = Menu;
		PC->SetInputMode(FInputModeGameAndUI());
		PC->bShowMouseCursor = true;
	}
}

void UInteractionManager::ServerOpenMenu_Implementation(AActor* Target)
{
	OpenMenu(Target);
}

bool UInteractionManager::ServerOpenMenu_Validate(AActor* Target)
{
	return true;
}

void UInteractionManager::CloseMenu()
{
	if (CurrentMenu != nullptr)
	{
		CurrentMenu->RemoveFromViewport();
		CurrentMenu = nullptr;
		TargetActor = nullptr;
		APlayerController* PC = Cast<APlayerController>(Cast<ACharacter>(GetOwner())->GetController());
		PC->SetInputMode(FInputModeGameOnly());
		PC->bShowMouseCursor = false;
	}
}

void UInteractionManager::ServerCloseMenu_Implementation()
{
	TargetActor = nullptr;
}

bool UInteractionManager::ServerCloseMenu_Validate()
{
	return true;
}

void UInteractionManager::DoAction(FName ActionName)
{
	FInteractionActionData* ActionData = ActionDataTable->FindRow<FInteractionActionData>(ActionName, TEXT(""));
	if (ActionData == nullptr)
	{
		return;
	}

	if (GetOwner() && GetOwner()->Role < ROLE_Authority && ActionData->bRunOnServer)
	{
		ServerDoAction(ActionName);
		return;
	}

	if (TargetActor == nullptr)
	{
		return;
	}

	AInteractAction* Action = InteractActionCache.FindRef(ActionName);
	if (Action == nullptr)
	{
		FActorSpawnParameters SpawnParams;
		Action = GetWorld()->SpawnActor<AInteractAction>(ActionData->ActionType, FTransform::Identity, SpawnParams);
		InteractActionCache.Add(ActionName, Action);
	}
	Action->DoAction(TargetActor);
}

bool UInteractionManager::IsActorInteractable(AActor* Target)
{
	if (Target == nullptr)
	{
		return false;
	}
	FName MenuName = Target->GetClass()->GetFName();
	FInteractionMenuData* MenuData = MenuDataTable->FindRow<FInteractionMenuData>(MenuName, TEXT(""));
	return MenuData != nullptr;
}

void UInteractionManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//DOREPLIFETIME(UInteractionManager, TargetActor);
}

void UInteractionManager::OnRep_TargetActor()
{
	OpenMenu(TargetActor);
}

void UInteractionManager::ServerDoAction_Implementation(FName ActionName)
{
	DoAction(ActionName);
}

bool UInteractionManager::ServerDoAction_Validate(FName ActionName)
{
	return true;
}
