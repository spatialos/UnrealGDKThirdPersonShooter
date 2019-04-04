// Fill out your copyright notice in the Description page of Project Settings.

#include "BigGym/UI/InteractMenuBase.h"


void UInteractMenuBase::Init(class UInteractionManager* InInteractionManager)
{
	InteractionManager = InInteractionManager;
}

UInteractionManager* UInteractMenuBase::GetInteractionManager() const
{
	return InteractionManager;
}
