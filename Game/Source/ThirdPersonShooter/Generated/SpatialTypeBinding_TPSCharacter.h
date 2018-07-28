// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically
#pragma once

#include "CoreMinimal.h"
#include <improbable/worker.h>
#include <improbable/view.h>
#include <improbable/unreal/gdk/core_types.h>
#include <improbable/unreal/gdk/unreal_metadata.h>
#include <improbable/unreal/generated/UnrealTPSCharacter.h>
#include "ScopedViewCallbacks.h"
#include "SpatialTypeBinding.h"
#include "SpatialTypeBinding_TPSCharacter.generated.h"

UCLASS()
class USpatialTypeBinding_TPSCharacter : public USpatialTypeBinding
{
	GENERATED_BODY()

public:
	const FRepHandlePropertyMap& GetRepHandlePropertyMap() const override;
	const FHandoverHandlePropertyMap& GetHandoverHandlePropertyMap() const override;
	UClass* GetBoundClass() const override;

	void Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap) override;
	void BindToView(bool bIsClient) override;
	void UnbindFromView() override;

	worker::Entity CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const override;
	void SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const FEntityId& EntityId) const override;
	void SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters) override;

	void ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const override;
	worker::Map<worker::ComponentId, worker::InterestOverride> GetInterestOverrideMap(bool bIsClient, bool bAutonomousProxy) const override;

	void BuildSpatialComponentUpdate(
		const FPropertyChangeState& Changes,
		USpatialActorChannel* Channel,
		improbable::unreal::generated::tpscharacter::TPSCharacterSingleClientRepData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::generated::tpscharacter::TPSCharacterMultiClientRepData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		improbable::unreal::generated::tpscharacter::TPSCharacterHandoverData::Update& HandoverDataUpdate,
		bool& bHandoverDataUpdateChanged) const;

private:
	improbable::unreal::callbacks::FScopedViewCallbacks ViewCallbacks;

	// RPC to sender map.
	using FRPCSender = void (USpatialTypeBinding_TPSCharacter::*)(worker::Connection* const, void*, UObject*);
	TMap<FName, FRPCSender> RPCToSenderMap;

	FRepHandlePropertyMap RepHandleToPropertyMap;
	FHandoverHandlePropertyMap HandoverHandleToPropertyMap;

	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::tpscharacter::TPSCharacterSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::tpscharacter::TPSCharacterMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Handover(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::tpscharacter::TPSCharacterHandoverData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::tpscharacter::TPSCharacterSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::tpscharacter::TPSCharacterMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Handover(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::tpscharacter::TPSCharacterHandoverData::Update& Update) const;
	void ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::tpscharacter::TPSCharacterNetMulticastRPCs::Update& Update);

	// RPC command sender functions.
	void RootMotionDebugClientPrintOnScreen_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientVeryShortAdjustPosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCheatWalk_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCheatGhost_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCheatFly_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAdjustRootMotionSourcePosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAdjustRootMotionPosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAdjustPosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAckGoodMove_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerSpawnCube_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void DebugResetCharacter_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveOld_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveNoBase_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveDualNoBase_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveDualHybridRootMotion_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveDual_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMove_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);

	// RPC command request handler functions.
	void RootMotionDebugClientPrintOnScreen_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Rootmotiondebugclientprintonscreen>& Op);
	void ClientVeryShortAdjustPosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientveryshortadjustposition>& Op);
	void ClientCheatWalk_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientcheatwalk>& Op);
	void ClientCheatGhost_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientcheatghost>& Op);
	void ClientCheatFly_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientcheatfly>& Op);
	void ClientAdjustRootMotionSourcePosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientadjustrootmotionsourceposition>& Op);
	void ClientAdjustRootMotionPosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientadjustrootmotionposition>& Op);
	void ClientAdjustPosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientadjustposition>& Op);
	void ClientAckGoodMove_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientackgoodmove>& Op);
	void ServerSpawnCube_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Serverspawncube>& Op);
	void DebugResetCharacter_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Debugresetcharacter>& Op);
	void ServerMoveOld_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Servermoveold>& Op);
	void ServerMoveNoBase_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Servermovenobase>& Op);
	void ServerMoveDualNoBase_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Servermovedualnobase>& Op);
	void ServerMoveDualHybridRootMotion_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Servermovedualhybridrootmotion>& Op);
	void ServerMoveDual_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Servermovedual>& Op);
	void ServerMove_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Servermove>& Op);

	// RPC command response handler functions.
	void RootMotionDebugClientPrintOnScreen_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Rootmotiondebugclientprintonscreen>& Op);
	void ClientVeryShortAdjustPosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientveryshortadjustposition>& Op);
	void ClientCheatWalk_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientcheatwalk>& Op);
	void ClientCheatGhost_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientcheatghost>& Op);
	void ClientCheatFly_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientcheatfly>& Op);
	void ClientAdjustRootMotionSourcePosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientadjustrootmotionsourceposition>& Op);
	void ClientAdjustRootMotionPosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientadjustrootmotionposition>& Op);
	void ClientAdjustPosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientadjustposition>& Op);
	void ClientAckGoodMove_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterClientRPCs::Commands::Clientackgoodmove>& Op);
	void ServerSpawnCube_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Serverspawncube>& Op);
	void DebugResetCharacter_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Debugresetcharacter>& Op);
	void ServerMoveOld_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Servermoveold>& Op);
	void ServerMoveNoBase_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Servermovenobase>& Op);
	void ServerMoveDualNoBase_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Servermovedualnobase>& Op);
	void ServerMoveDualHybridRootMotion_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Servermovedualhybridrootmotion>& Op);
	void ServerMoveDual_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Servermovedual>& Op);
	void ServerMove_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::tpscharacter::TPSCharacterServerRPCs::Commands::Servermove>& Op);
};
