// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically
#pragma once

#include "CoreMinimal.h"
#include <improbable/worker.h>
#include <improbable/view.h>
#include <improbable/unreal/gdk/core_types.h>
#include <improbable/unreal/gdk/unreal_metadata.h>
#include <improbable/unreal/generated/UnrealSGGameState.h>
#include "ScopedViewCallbacks.h"
#include "SpatialTypeBinding.h"
#include "SpatialTypeBinding_SGGameState.generated.h"

UCLASS()
class USpatialTypeBinding_SGGameState : public USpatialTypeBinding
{
	GENERATED_BODY()

public:
	const FRepHandlePropertyMap& GetRepHandlePropertyMap() const override;
	const FMigratableHandlePropertyMap& GetMigratableHandlePropertyMap() const override;
	UClass* GetBoundClass() const override;

	void Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap) override;
	void BindToView(bool bIsClient) override;
	void UnbindFromView() override;

	worker::Entity CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const override;
	void SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const FEntityId& EntityId) const override;
	void SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters) override;

	void ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const override;
	worker::Map<worker::ComponentId, worker::InterestOverride> GetInterestOverrideMap(bool bIsClient, bool bAutonomousProxy) const override;

private:
	improbable::unreal::callbacks::FScopedViewCallbacks ViewCallbacks;

	// RPC to sender map.
	using FRPCSender = void (USpatialTypeBinding_SGGameState::*)(worker::Connection* const, void*, UObject*);
	TMap<FName, FRPCSender> RPCToSenderMap;

	FRepHandlePropertyMap RepHandleToPropertyMap;
	FMigratableHandlePropertyMap MigratableHandleToPropertyMap;

	// Component update helper functions.
	void BuildSpatialComponentUpdate(
		const FPropertyChangeState& Changes,
		USpatialActorChannel* Channel,
		improbable::unreal::generated::sggamestate::SGGameStateSingleClientRepData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::generated::sggamestate::SGGameStateMultiClientRepData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		improbable::unreal::generated::sggamestate::SGGameStateMigratableData::Update& MigratableDataUpdate,
		bool& bMigratableDataUpdateChanged) const;
	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::sggamestate::SGGameStateSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::sggamestate::SGGameStateMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Migratable(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::sggamestate::SGGameStateMigratableData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::sggamestate::SGGameStateSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::sggamestate::SGGameStateMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Migratable(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::sggamestate::SGGameStateMigratableData::Update& Update) const;
	void ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::sggamestate::SGGameStateNetMulticastRPCs::Update& Update);

	// RPC command sender functions.

	// RPC command request handler functions.

	// RPC command response handler functions.
};
