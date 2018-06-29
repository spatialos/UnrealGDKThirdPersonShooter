// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically
#pragma once

#include "CoreMinimal.h"
#include <improbable/worker.h>
#include <improbable/view.h>
#include <improbable/unreal/gdk/core_types.h>
#include <improbable/unreal/gdk/unreal_metadata.h>
#include <improbable/unreal/generated/UnrealInstantWeapon.h>
#include "ScopedViewCallbacks.h"
#include "SpatialTypeBinding.h"
#include "SpatialTypeBinding_InstantWeapon.generated.h"

UCLASS()
class USpatialTypeBinding_InstantWeapon : public USpatialTypeBinding
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
	using FRPCSender = void (USpatialTypeBinding_InstantWeapon::*)(worker::Connection* const, void*, UObject*);
	TMap<FName, FRPCSender> RPCToSenderMap;

	FRepHandlePropertyMap RepHandleToPropertyMap;
	FMigratableHandlePropertyMap MigratableHandleToPropertyMap;

	// Component update helper functions.
	void BuildSpatialComponentUpdate(
		const FPropertyChangeState& Changes,
		USpatialActorChannel* Channel,
		improbable::unreal::generated::instantweapon::InstantWeaponSingleClientRepData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::generated::instantweapon::InstantWeaponMultiClientRepData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		improbable::unreal::generated::instantweapon::InstantWeaponMigratableData::Update& MigratableDataUpdate,
		bool& bMigratableDataUpdateChanged) const;
<<<<<<< HEAD
	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealInstantWeaponSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealInstantWeaponMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Migratable(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealInstantWeaponMigratableData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealInstantWeaponSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealInstantWeaponMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Migratable(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealInstantWeaponMigratableData::Update& Update) const;
	void ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::UnrealInstantWeaponNetMulticastRPCs::Update& Update);
=======
	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::instantweapon::InstantWeaponSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::instantweapon::InstantWeaponMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Migratable(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::instantweapon::InstantWeaponMigratableData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::instantweapon::InstantWeaponSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::instantweapon::InstantWeaponMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Migratable(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::instantweapon::InstantWeaponMigratableData::Update& Update) const;
	void ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::instantweapon::InstantWeaponNetMulticastRPCs::Update& Update);
>>>>>>> master

	// RPC command sender functions.
	void ServerDidMiss_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerDidHit_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);

	// RPC command request handler functions.
<<<<<<< HEAD
	void ServerDidMiss_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::UnrealInstantWeaponServerRPCs::Commands::Instantweaponserverdidmiss>& Op);
	void ServerDidHit_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::UnrealInstantWeaponServerRPCs::Commands::Instantweaponserverdidhit>& Op);
=======
	void ServerDidMiss_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::instantweapon::InstantWeaponServerRPCs::Commands::Serverdidmiss>& Op);
	void ServerDidHit_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::instantweapon::InstantWeaponServerRPCs::Commands::Serverdidhit>& Op);
>>>>>>> master

	// RPC command response handler functions.
	void ServerDidMiss_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::instantweapon::InstantWeaponServerRPCs::Commands::Serverdidmiss>& Op);
	void ServerDidHit_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::instantweapon::InstantWeaponServerRPCs::Commands::Serverdidhit>& Op);
};
