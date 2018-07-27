// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically

#include "SpatialTypeBinding_SampleGameCharacter.h"

#include "GameFramework/PlayerState.h"
#include "NetworkGuid.h"

#include "SpatialOS.h"
#include "EntityBuilder.h"

#include "SpatialConstants.h"
#include "SpatialConditionMapFilter.h"
#include "SpatialUnrealObjectRef.h"
#include "SpatialActorChannel.h"
#include "SpatialPackageMapClient.h"
#include "SpatialMemoryReader.h"
#include "SpatialMemoryWriter.h"
#include "SpatialNetDriver.h"
#include "SpatialInterop.h"
#include "Characters/SampleGameCharacter.h"
#include "Teams/SampleGameTeams.h"
#include "Weapons/Weapon.h"

#include "SampleGameCharacterSingleClientRepDataAddComponentOp.h"
#include "SampleGameCharacterMultiClientRepDataAddComponentOp.h"
#include "SampleGameCharacterHandoverDataAddComponentOp.h"

const FRepHandlePropertyMap& USpatialTypeBinding_SampleGameCharacter::GetRepHandlePropertyMap() const
{
	return RepHandleToPropertyMap;
}

const FHandoverHandlePropertyMap& USpatialTypeBinding_SampleGameCharacter::GetHandoverHandlePropertyMap() const
{
	return HandoverHandleToPropertyMap;
}

UClass* USpatialTypeBinding_SampleGameCharacter::GetBoundClass() const
{
	return ASampleGameCharacter::StaticClass();
}

void USpatialTypeBinding_SampleGameCharacter::Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap)
{
	Super::Init(InInterop, InPackageMap);

	RPCToSenderMap.Emplace("RootMotionDebugClientPrintOnScreen", &USpatialTypeBinding_SampleGameCharacter::RootMotionDebugClientPrintOnScreen_SendRPC);
	RPCToSenderMap.Emplace("ClientVeryShortAdjustPosition", &USpatialTypeBinding_SampleGameCharacter::ClientVeryShortAdjustPosition_SendRPC);
	RPCToSenderMap.Emplace("ClientCheatWalk", &USpatialTypeBinding_SampleGameCharacter::ClientCheatWalk_SendRPC);
	RPCToSenderMap.Emplace("ClientCheatGhost", &USpatialTypeBinding_SampleGameCharacter::ClientCheatGhost_SendRPC);
	RPCToSenderMap.Emplace("ClientCheatFly", &USpatialTypeBinding_SampleGameCharacter::ClientCheatFly_SendRPC);
	RPCToSenderMap.Emplace("ClientAdjustRootMotionSourcePosition", &USpatialTypeBinding_SampleGameCharacter::ClientAdjustRootMotionSourcePosition_SendRPC);
	RPCToSenderMap.Emplace("ClientAdjustRootMotionPosition", &USpatialTypeBinding_SampleGameCharacter::ClientAdjustRootMotionPosition_SendRPC);
	RPCToSenderMap.Emplace("ClientAdjustPosition", &USpatialTypeBinding_SampleGameCharacter::ClientAdjustPosition_SendRPC);
	RPCToSenderMap.Emplace("ClientAckGoodMove", &USpatialTypeBinding_SampleGameCharacter::ClientAckGoodMove_SendRPC);
	RPCToSenderMap.Emplace("ServerSpawnCube", &USpatialTypeBinding_SampleGameCharacter::ServerSpawnCube_SendRPC);
	RPCToSenderMap.Emplace("DebugResetCharacter", &USpatialTypeBinding_SampleGameCharacter::DebugResetCharacter_SendRPC);
	RPCToSenderMap.Emplace("ServerMoveOld", &USpatialTypeBinding_SampleGameCharacter::ServerMoveOld_SendRPC);
	RPCToSenderMap.Emplace("ServerMoveNoBase", &USpatialTypeBinding_SampleGameCharacter::ServerMoveNoBase_SendRPC);
	RPCToSenderMap.Emplace("ServerMoveDualNoBase", &USpatialTypeBinding_SampleGameCharacter::ServerMoveDualNoBase_SendRPC);
	RPCToSenderMap.Emplace("ServerMoveDualHybridRootMotion", &USpatialTypeBinding_SampleGameCharacter::ServerMoveDualHybridRootMotion_SendRPC);
	RPCToSenderMap.Emplace("ServerMoveDual", &USpatialTypeBinding_SampleGameCharacter::ServerMoveDual_SendRPC);
	RPCToSenderMap.Emplace("ServerMove", &USpatialTypeBinding_SampleGameCharacter::ServerMove_SendRPC);

	UClass* Class = FindObject<UClass>(ANY_PACKAGE, TEXT("SampleGameCharacter"));

	// Populate RepHandleToPropertyMap.
	RepHandleToPropertyMap.Add(1, FRepHandleData(Class, {"bHidden"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(2, FRepHandleData(Class, {"bReplicateMovement"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(3, FRepHandleData(Class, {"bTearOff"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(4, FRepHandleData(Class, {"bCanBeDamaged"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(5, FRepHandleData(Class, {"RemoteRole"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(6, FRepHandleData(Class, {"ReplicatedMovement"}, {0}, COND_SimulatedOrPhysicsNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(7, FRepHandleData(Class, {"AttachmentReplication", "AttachParent"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(8, FRepHandleData(Class, {"AttachmentReplication", "LocationOffset"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(9, FRepHandleData(Class, {"AttachmentReplication", "RelativeScale3D"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(10, FRepHandleData(Class, {"AttachmentReplication", "RotationOffset"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(11, FRepHandleData(Class, {"AttachmentReplication", "AttachSocket"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(12, FRepHandleData(Class, {"AttachmentReplication", "AttachComponent"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(13, FRepHandleData(Class, {"Owner"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(14, FRepHandleData(Class, {"Role"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(15, FRepHandleData(Class, {"Instigator"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(16, FRepHandleData(Class, {"PlayerState"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(17, FRepHandleData(Class, {"RemoteViewPitch"}, {0}, COND_SkipOwner, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(18, FRepHandleData(Class, {"Controller"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(19, FRepHandleData(Class, {"ReplicatedBasedMovement", "MovementBase"}, {0, 0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(20, FRepHandleData(Class, {"ReplicatedBasedMovement", "BoneName"}, {0, 0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(21, FRepHandleData(Class, {"ReplicatedBasedMovement", "Location"}, {0, 0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(22, FRepHandleData(Class, {"ReplicatedBasedMovement", "Rotation"}, {0, 0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(23, FRepHandleData(Class, {"ReplicatedBasedMovement", "bServerHasBaseComponent"}, {0, 0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(24, FRepHandleData(Class, {"ReplicatedBasedMovement", "bRelativeRotation"}, {0, 0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(25, FRepHandleData(Class, {"ReplicatedBasedMovement", "bServerHasVelocity"}, {0, 0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(26, FRepHandleData(Class, {"AnimRootMotionTranslationScale"}, {0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(27, FRepHandleData(Class, {"ReplicatedServerLastTransformUpdateTimeStamp"}, {0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(28, FRepHandleData(Class, {"ReplicatedMovementMode"}, {0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(29, FRepHandleData(Class, {"bIsCrouched"}, {0}, COND_SimulatedOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(30, FRepHandleData(Class, {"JumpMaxHoldTime"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(31, FRepHandleData(Class, {"JumpMaxCount"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(32, FRepHandleData(Class, {"RepRootMotion", "bIsActive"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(33, FRepHandleData(Class, {"RepRootMotion", "AnimMontage"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(34, FRepHandleData(Class, {"RepRootMotion", "Position"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(35, FRepHandleData(Class, {"RepRootMotion", "Location"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(36, FRepHandleData(Class, {"RepRootMotion", "Rotation"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(37, FRepHandleData(Class, {"RepRootMotion", "MovementBase"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(38, FRepHandleData(Class, {"RepRootMotion", "MovementBaseBoneName"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(39, FRepHandleData(Class, {"RepRootMotion", "bRelativePosition"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(40, FRepHandleData(Class, {"RepRootMotion", "bRelativeRotation"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(41, FRepHandleData(Class, {"RepRootMotion", "AuthoritativeRootMotion"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(42, FRepHandleData(Class, {"RepRootMotion", "Acceleration"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(43, FRepHandleData(Class, {"RepRootMotion", "LinearVelocity"}, {0, 0}, COND_SimulatedOnlyNoReplay, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(44, FRepHandleData(Class, {"EquippedWeapon"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(45, FRepHandleData(Class, {"CurrentHealth"}, {0}, COND_AutonomousOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(46, FRepHandleData(Class, {"bIsRagdoll"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(47, FRepHandleData(Class, {"AimYaw"}, {0}, COND_SkipOwner, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(48, FRepHandleData(Class, {"AimPitch"}, {0}, COND_SkipOwner, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(49, FRepHandleData(Class, {"Team"}, {0}, COND_None, REPNOTIFY_OnChanged));

	// Populate HandoverHandleToPropertyMap.
	HandoverHandleToPropertyMap.Add(1, FHandoverHandleData(Class, {"CharacterMovement", "MovementMode"}));
	HandoverHandleToPropertyMap.Add(2, FHandoverHandleData(Class, {"CharacterMovement", "CustomMovementMode"}));
	HandoverHandleToPropertyMap.Add(3, FHandoverHandleData(Class, {"CharacterMovement", "GroundMovementMode"}));

	bIsSingleton = false;
}

void USpatialTypeBinding_SampleGameCharacter::BindToView(bool bIsClient)
{
	TSharedPtr<worker::View> View = Interop->GetSpatialOS()->GetView().Pin();
	ViewCallbacks.Init(View);

	if (Interop->GetNetDriver()->GetNetMode() == NM_Client)
	{
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterSingleClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterSingleClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::samplegamecharacter::SampleGameCharacterSingleClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_SingleClient(ActorChannel, Op.Update);
		}));
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterMultiClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterMultiClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::samplegamecharacter::SampleGameCharacterMultiClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_MultiClient(ActorChannel, Op.Update);
		}));
		if (!bIsClient)
		{
			ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterHandoverData>([this](
				const worker::ComponentUpdateOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterHandoverData>& Op)
			{
				// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
				if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::samplegamecharacter::SampleGameCharacterHandoverData::ComponentId))
				{
					return;
				}
				USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
				check(ActorChannel);
				ReceiveUpdate_Handover(ActorChannel, Op.Update);
			}));
		}
	}
	ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterNetMulticastRPCs>([this](
		const worker::ComponentUpdateOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterNetMulticastRPCs>& Op)
	{
		// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
		if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::samplegamecharacter::SampleGameCharacterNetMulticastRPCs::ComponentId))
		{
			return;
		}
		ReceiveUpdate_NetMulticastRPCs(Op.EntityId, Op.Update);
	}));

	using ClientRPCCommandTypes = improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands;
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Rootmotiondebugclientprintonscreen>(std::bind(&USpatialTypeBinding_SampleGameCharacter::RootMotionDebugClientPrintOnScreen_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientveryshortadjustposition>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientVeryShortAdjustPosition_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientcheatwalk>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientCheatWalk_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientcheatghost>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientCheatGhost_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientcheatfly>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientCheatFly_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientadjustrootmotionsourceposition>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientAdjustRootMotionSourcePosition_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientadjustrootmotionposition>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientAdjustRootMotionPosition_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientadjustposition>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientAdjustPosition_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Clientackgoodmove>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientAckGoodMove_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Rootmotiondebugclientprintonscreen>(std::bind(&USpatialTypeBinding_SampleGameCharacter::RootMotionDebugClientPrintOnScreen_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientveryshortadjustposition>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientVeryShortAdjustPosition_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientcheatwalk>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientCheatWalk_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientcheatghost>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientCheatGhost_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientcheatfly>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientCheatFly_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientadjustrootmotionsourceposition>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientAdjustRootMotionSourcePosition_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientadjustrootmotionposition>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientAdjustRootMotionPosition_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientadjustposition>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientAdjustPosition_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Clientackgoodmove>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ClientAckGoodMove_OnCommandResponse, this, std::placeholders::_1)));

	using ServerRPCCommandTypes = improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands;
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Serverspawncube>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ServerSpawnCube_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Debugresetcharacter>(std::bind(&USpatialTypeBinding_SampleGameCharacter::DebugResetCharacter_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Servermoveold>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ServerMoveOld_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Servermovenobase>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ServerMoveNoBase_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Servermovedualnobase>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ServerMoveDualNoBase_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Servermovedualhybridrootmotion>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ServerMoveDualHybridRootMotion_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Servermovedual>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ServerMoveDual_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Servermove>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ServerMove_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Serverspawncube>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ServerSpawnCube_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Debugresetcharacter>(std::bind(&USpatialTypeBinding_SampleGameCharacter::DebugResetCharacter_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Servermoveold>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ServerMoveOld_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Servermovenobase>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ServerMoveNoBase_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Servermovedualnobase>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ServerMoveDualNoBase_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Servermovedualhybridrootmotion>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ServerMoveDualHybridRootMotion_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Servermovedual>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ServerMoveDual_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Servermove>(std::bind(&USpatialTypeBinding_SampleGameCharacter::ServerMove_OnCommandResponse, this, std::placeholders::_1)));
}

void USpatialTypeBinding_SampleGameCharacter::UnbindFromView()
{
	ViewCallbacks.Reset();
}

worker::Entity USpatialTypeBinding_SampleGameCharacter::CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const
{
	// Validate replication list.
	const uint16 RepHandlePropertyMapCount = GetRepHandlePropertyMap().Num();
	for (auto& Rep : InitialChanges.RepChanged)
	{
		checkf(Rep <= RepHandlePropertyMapCount, TEXT("Attempting to replicate a property with a handle that the type binding is not aware of. Have additional replicated properties been added in a non generated child object?"))
	}

	// Setup initial data.

	improbable::unreal::generated::samplegamecharacter::SampleGameCharacterSingleClientRepData::Data SingleClientSampleGameCharacterData;
	improbable::unreal::generated::samplegamecharacter::SampleGameCharacterSingleClientRepData::Update SingleClientSampleGameCharacterUpdate;
	bool bSingleClientSampleGameCharacterUpdateChanged = false;
	improbable::unreal::generated::samplegamecharacter::SampleGameCharacterMultiClientRepData::Data MultiClientSampleGameCharacterData;
	improbable::unreal::generated::samplegamecharacter::SampleGameCharacterMultiClientRepData::Update MultiClientSampleGameCharacterUpdate;
	bool bMultiClientSampleGameCharacterUpdateChanged = false;
	improbable::unreal::generated::samplegamecharacter::SampleGameCharacterHandoverData::Data SampleGameCharacterHandoverData;
	improbable::unreal::generated::samplegamecharacter::SampleGameCharacterHandoverData::Update SampleGameCharacterHandoverDataUpdate;
	bool bSampleGameCharacterHandoverDataUpdateChanged = false;

	BuildSpatialComponentUpdate(InitialChanges, Channel, SingleClientSampleGameCharacterUpdate, bSingleClientSampleGameCharacterUpdateChanged, MultiClientSampleGameCharacterUpdate, bMultiClientSampleGameCharacterUpdateChanged, SampleGameCharacterHandoverDataUpdate, bSampleGameCharacterHandoverDataUpdateChanged);
	SingleClientSampleGameCharacterUpdate.ApplyTo(SingleClientSampleGameCharacterData);
	MultiClientSampleGameCharacterUpdate.ApplyTo(MultiClientSampleGameCharacterData);
	SampleGameCharacterHandoverDataUpdate.ApplyTo(SampleGameCharacterHandoverData);

	// Create entity.
	std::string ClientWorkerIdString = TCHAR_TO_UTF8(*ClientWorkerId);

	improbable::WorkerAttributeSet WorkerAttribute{{worker::List<std::string>{"UnrealWorker"}}};
	improbable::WorkerAttributeSet ClientAttribute{{worker::List<std::string>{"UnrealClient"}}};
	improbable::WorkerAttributeSet OwningClientAttribute{{"workerId:" + ClientWorkerIdString}};

	improbable::WorkerRequirementSet WorkersOnly{{WorkerAttribute}};
	improbable::WorkerRequirementSet ClientsOnly{{ClientAttribute}};
	improbable::WorkerRequirementSet OwningClientOnly{{OwningClientAttribute}};
	improbable::WorkerRequirementSet AnyUnrealWorkerOrClient{{WorkerAttribute, ClientAttribute}};
	improbable::WorkerRequirementSet AnyUnrealWorkerOrOwningClient{{WorkerAttribute, OwningClientAttribute}};

	// Set up unreal metadata.
	improbable::unreal::UnrealMetadata::Data UnrealMetadata;
	if (Channel->Actor->IsFullNameStableForNetworking())
	{
		UnrealMetadata.set_static_path({std::string{TCHAR_TO_UTF8(*Channel->Actor->GetPathName(Channel->Actor->GetWorld()))}});
	}
	if (!ClientWorkerIdString.empty())
	{
		UnrealMetadata.set_owner_worker_id({ClientWorkerIdString});
	}

	uint32 CurrentOffset = 1;
	worker::Map<std::string, std::uint32_t> SubobjectNameToOffset;
	ForEachObjectWithOuter(Channel->Actor, [&UnrealMetadata, &CurrentOffset, &SubobjectNameToOffset](UObject* Object)
	{
		// Objects can only be allocated NetGUIDs if this is true.
		if (Object->IsSupportedForNetworking() && !Object->IsPendingKill() && !Object->IsEditorOnly())
		{
			SubobjectNameToOffset.emplace(TCHAR_TO_UTF8(*(Object->GetName())), CurrentOffset);
			CurrentOffset++;
		}
	});
	UnrealMetadata.set_subobject_name_to_offset(SubobjectNameToOffset);

	// Build entity.
	const improbable::Coordinates SpatialPosition = SpatialConstants::LocationToSpatialOSCoordinates(Position);
	return improbable::unreal::FEntityBuilder::Begin()
		.AddPositionComponent(improbable::Position::Data{SpatialPosition}, WorkersOnly)
		.AddMetadataComponent(improbable::Metadata::Data{TCHAR_TO_UTF8(*Metadata)})
		.SetPersistence(true)
		.SetReadAcl(AnyUnrealWorkerOrClient)
		.AddComponent<improbable::unreal::UnrealMetadata>(UnrealMetadata, WorkersOnly)
		.AddComponent<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterSingleClientRepData>(SingleClientSampleGameCharacterData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterMultiClientRepData>(MultiClientSampleGameCharacterData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterHandoverData>(SampleGameCharacterHandoverData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs>(improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Data{}, OwningClientOnly)
		.AddComponent<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs>(improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Data{}, WorkersOnly)
		.AddComponent<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterNetMulticastRPCs>(improbable::unreal::generated::samplegamecharacter::SampleGameCharacterNetMulticastRPCs::Data{}, WorkersOnly)
		.Build();
}

void USpatialTypeBinding_SampleGameCharacter::SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const FEntityId& EntityId) const
{
	// Build SpatialOS updates.
	improbable::unreal::generated::samplegamecharacter::SampleGameCharacterSingleClientRepData::Update SingleClientUpdate;
	bool bSingleClientUpdateChanged = false;
	improbable::unreal::generated::samplegamecharacter::SampleGameCharacterMultiClientRepData::Update MultiClientUpdate;
	bool bMultiClientUpdateChanged = false;
	improbable::unreal::generated::samplegamecharacter::SampleGameCharacterHandoverData::Update HandoverDataUpdate;
	bool bHandoverDataUpdateChanged = false;
	BuildSpatialComponentUpdate(Changes, Channel, SingleClientUpdate, bSingleClientUpdateChanged, MultiClientUpdate, bMultiClientUpdateChanged, HandoverDataUpdate, bHandoverDataUpdateChanged);

	// Send SpatialOS updates if anything changed.
	TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
	if (bSingleClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterSingleClientRepData>(EntityId.ToSpatialEntityId(), SingleClientUpdate);
	}
	if (bMultiClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterMultiClientRepData>(EntityId.ToSpatialEntityId(), MultiClientUpdate);
	}
	if (bHandoverDataUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterHandoverData>(EntityId.ToSpatialEntityId(), HandoverDataUpdate);
	}
}

void USpatialTypeBinding_SampleGameCharacter::SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters)
{
	TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
	auto SenderFuncIterator = RPCToSenderMap.Find(Function->GetFName());
	if (SenderFuncIterator == nullptr)
	{
		UE_LOG(LogSpatialGDKInterop, Error, TEXT("Sender for %s has not been registered with RPCToSenderMap."), *Function->GetFName().ToString());
		return;
	}
	checkf(*SenderFuncIterator, TEXT("Sender for %s has been registered as null."), *Function->GetFName().ToString());
	(this->*(*SenderFuncIterator))(Connection.Get(), Parameters, TargetObject);
}

void USpatialTypeBinding_SampleGameCharacter::ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const
{
	auto* SingleClientAddOp = Cast<USampleGameCharacterSingleClientRepDataAddComponentOp>(AddComponentOp);
	if (SingleClientAddOp)
	{
		auto Update = improbable::unreal::generated::samplegamecharacter::SampleGameCharacterSingleClientRepData::Update::FromInitialData(*SingleClientAddOp->Data.data());
		ReceiveUpdate_SingleClient(Channel, Update);
		return;
	}
	auto* MultiClientAddOp = Cast<USampleGameCharacterMultiClientRepDataAddComponentOp>(AddComponentOp);
	if (MultiClientAddOp)
	{
		auto Update = improbable::unreal::generated::samplegamecharacter::SampleGameCharacterMultiClientRepData::Update::FromInitialData(*MultiClientAddOp->Data.data());
		ReceiveUpdate_MultiClient(Channel, Update);
		return;
	}
	auto* HandoverDataAddOp = Cast<USampleGameCharacterHandoverDataAddComponentOp>(AddComponentOp);
	if (HandoverDataAddOp)
	{
		auto Update = improbable::unreal::generated::samplegamecharacter::SampleGameCharacterHandoverData::Update::FromInitialData(*HandoverDataAddOp->Data.data());
		ReceiveUpdate_Handover(Channel, Update);
		return;
	}
}

worker::Map<worker::ComponentId, worker::InterestOverride> USpatialTypeBinding_SampleGameCharacter::GetInterestOverrideMap(bool bIsClient, bool bAutonomousProxy) const
{
	worker::Map<worker::ComponentId, worker::InterestOverride> Interest;
	if (bIsClient)
	{
		if (!bAutonomousProxy)
		{
			Interest.emplace(improbable::unreal::generated::samplegamecharacter::SampleGameCharacterSingleClientRepData::ComponentId, worker::InterestOverride{false});
		}
		Interest.emplace(improbable::unreal::generated::samplegamecharacter::SampleGameCharacterHandoverData::ComponentId, worker::InterestOverride{false});
	}
	return Interest;
}

void USpatialTypeBinding_SampleGameCharacter::BuildSpatialComponentUpdate(
	const FPropertyChangeState& Changes,
	USpatialActorChannel* Channel,
	improbable::unreal::generated::samplegamecharacter::SampleGameCharacterSingleClientRepData::Update& SingleClientUpdate,
	bool& bSingleClientUpdateChanged,
	improbable::unreal::generated::samplegamecharacter::SampleGameCharacterMultiClientRepData::Update& MultiClientUpdate,
	bool& bMultiClientUpdateChanged,
	improbable::unreal::generated::samplegamecharacter::SampleGameCharacterHandoverData::Update& HandoverDataUpdate,
	bool& bHandoverDataUpdateChanged) const
{
	const FRepHandlePropertyMap& RepPropertyMap = GetRepHandlePropertyMap();
	const FHandoverHandlePropertyMap& HandoverPropertyMap = GetHandoverHandlePropertyMap();
	if (Changes.RepChanged.Num() > 0)
	{
		// Populate the replicated data component updates from the replicated property changelist.
		FChangelistIterator ChangelistIterator(Changes.RepChanged, 0);
		FRepHandleIterator HandleIterator(ChangelistIterator, Changes.RepCmds, Changes.RepBaseHandleToCmdIndex, 0, 1, 0, Changes.RepCmds.Num() - 1);
		while (HandleIterator.NextHandle())
		{
			const FRepLayoutCmd& Cmd = Changes.RepCmds[HandleIterator.CmdIndex];
			const FRepHandleData& PropertyMapData = RepPropertyMap[HandleIterator.Handle];
			const uint8* Data = PropertyMapData.GetPropertyData(Changes.SourceData) + HandleIterator.ArrayOffset;
			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*Channel->Actor->GetName(),
				Channel->GetEntityId().ToSpatialEntityId(),
				*Cmd.Property->GetName(),
				HandleIterator.Handle);
			switch (GetGroupFromCondition(PropertyMapData.Condition))
			{
			case GROUP_SingleClient:
				ServerSendUpdate_SingleClient(Data, HandleIterator.Handle, Cmd.Property, Channel, SingleClientUpdate);
				bSingleClientUpdateChanged = true;
				break;
			case GROUP_MultiClient:
				ServerSendUpdate_MultiClient(Data, HandleIterator.Handle, Cmd.Property, Channel, MultiClientUpdate);
				bMultiClientUpdateChanged = true;
				break;
			}
			if (Cmd.Type == REPCMD_DynamicArray)
			{
				if (!HandleIterator.JumpOverArray())
				{
					break;
				}
			}
		}
	}

	// Populate the handover data component update from the handover property changelist.
	for (uint16 ChangedHandle : Changes.HandoverChanged)
	{
		const FHandoverHandleData& PropertyMapData = HandoverPropertyMap[ChangedHandle];
		const uint8* Data = PropertyMapData.GetPropertyData(Changes.SourceData);
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending handover property update. actor %s (%lld), property %s (handle %d)"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*Channel->Actor->GetName(),
			Channel->GetEntityId().ToSpatialEntityId(),
			*PropertyMapData.Property->GetName(),
			ChangedHandle);
		ServerSendUpdate_Handover(Data, ChangedHandle, PropertyMapData.Property, Channel, HandoverDataUpdate);
		bHandoverDataUpdateChanged = true;
	}
}

void USpatialTypeBinding_SampleGameCharacter::ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::samplegamecharacter::SampleGameCharacterSingleClientRepData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 45: // field_currenthealth0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_currenthealth0(int32_t(Value));
			break;
		}
	default:
		checkf(false, TEXT("Unknown replication handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_SampleGameCharacter::ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::samplegamecharacter::SampleGameCharacterMultiClientRepData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 1: // field_bhidden0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bhidden0(Value);
			break;
		}
		case 2: // field_breplicatemovement0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_breplicatemovement0(Value);
			break;
		}
		case 3: // field_btearoff0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_btearoff0(Value);
			break;
		}
		case 4: // field_bcanbedamaged0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bcanbedamaged0(Value);
			break;
		}
		case 5: // field_remoterole0
		{
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(Data));

			OutUpdate.set_field_remoterole0(uint32_t(Value));
			break;
		}
		case 6: // field_replicatedmovement0
		{
			const FRepMovement& Value = *(reinterpret_cast<FRepMovement const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 6);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FRepMovement&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRepMovement failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_replicatedmovement0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 6);
			}
			break;
		}
		case 7: // field_attachmentreplication0_attachparent0
		{
			AActor* Value = *(reinterpret_cast<AActor* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 7);
				}
				else
				{
					OutUpdate.set_field_attachmentreplication0_attachparent0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_attachmentreplication0_attachparent0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 8: // field_attachmentreplication0_locationoffset0
		{
			const FVector_NetQuantize100& Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 8);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_attachmentreplication0_locationoffset0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 8);
			}
			break;
		}
		case 9: // field_attachmentreplication0_relativescale3d0
		{
			const FVector_NetQuantize100& Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 9);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_attachmentreplication0_relativescale3d0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 9);
			}
			break;
		}
		case 10: // field_attachmentreplication0_rotationoffset0
		{
			const FRotator& Value = *(reinterpret_cast<FRotator const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 10);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FRotator&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRotator failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_attachmentreplication0_rotationoffset0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 10);
			}
			break;
		}
		case 11: // field_attachmentreplication0_attachsocket0
		{
			FName Value = *(reinterpret_cast<FName const*>(Data));

			OutUpdate.set_field_attachmentreplication0_attachsocket0(TCHAR_TO_UTF8(*Value.ToString()));
			break;
		}
		case 12: // field_attachmentreplication0_attachcomponent0
		{
			USceneComponent* Value = *(reinterpret_cast<USceneComponent* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 12);
				}
				else
				{
					OutUpdate.set_field_attachmentreplication0_attachcomponent0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_attachmentreplication0_attachcomponent0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 13: // field_owner0
		{
			AActor* Value = *(reinterpret_cast<AActor* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 13);
				}
				else
				{
					OutUpdate.set_field_owner0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_owner0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 14: // field_role0
		{
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(Data));

			OutUpdate.set_field_role0(uint32_t(Value));
			break;
		}
		case 15: // field_instigator0
		{
			APawn* Value = *(reinterpret_cast<APawn* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 15);
				}
				else
				{
					OutUpdate.set_field_instigator0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_instigator0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 16: // field_playerstate0
		{
			APlayerState* Value = *(reinterpret_cast<APlayerState* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 16);
				}
				else
				{
					OutUpdate.set_field_playerstate0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_playerstate0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 17: // field_remoteviewpitch0
		{
			uint8 Value = *(reinterpret_cast<uint8 const*>(Data));

			OutUpdate.set_field_remoteviewpitch0(uint32_t(Value));
			break;
		}
		case 18: // field_controller0
		{
			AController* Value = *(reinterpret_cast<AController* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 18);
				}
				else
				{
					OutUpdate.set_field_controller0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_controller0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 19: // field_replicatedbasedmovement0_movementbase0
		{
			UPrimitiveComponent* Value = *(reinterpret_cast<UPrimitiveComponent* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 19);
				}
				else
				{
					OutUpdate.set_field_replicatedbasedmovement0_movementbase0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_replicatedbasedmovement0_movementbase0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 20: // field_replicatedbasedmovement0_bonename0
		{
			FName Value = *(reinterpret_cast<FName const*>(Data));

			OutUpdate.set_field_replicatedbasedmovement0_bonename0(TCHAR_TO_UTF8(*Value.ToString()));
			break;
		}
		case 21: // field_replicatedbasedmovement0_location0
		{
			const FVector_NetQuantize100& Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 21);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_replicatedbasedmovement0_location0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 21);
			}
			break;
		}
		case 22: // field_replicatedbasedmovement0_rotation0
		{
			const FRotator& Value = *(reinterpret_cast<FRotator const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 22);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FRotator&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRotator failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_replicatedbasedmovement0_rotation0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 22);
			}
			break;
		}
		case 23: // field_replicatedbasedmovement0_bserverhasbasecomponent0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_replicatedbasedmovement0_bserverhasbasecomponent0(Value);
			break;
		}
		case 24: // field_replicatedbasedmovement0_brelativerotation0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_replicatedbasedmovement0_brelativerotation0(Value);
			break;
		}
		case 25: // field_replicatedbasedmovement0_bserverhasvelocity0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_replicatedbasedmovement0_bserverhasvelocity0(Value);
			break;
		}
		case 26: // field_animrootmotiontranslationscale0
		{
			float Value = *(reinterpret_cast<float const*>(Data));

			OutUpdate.set_field_animrootmotiontranslationscale0(Value);
			break;
		}
		case 27: // field_replicatedserverlasttransformupdatetimestamp0
		{
			float Value = *(reinterpret_cast<float const*>(Data));

			OutUpdate.set_field_replicatedserverlasttransformupdatetimestamp0(Value);
			break;
		}
		case 28: // field_replicatedmovementmode0
		{
			uint8 Value = *(reinterpret_cast<uint8 const*>(Data));

			OutUpdate.set_field_replicatedmovementmode0(uint32_t(Value));
			break;
		}
		case 29: // field_biscrouched0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_biscrouched0(Value);
			break;
		}
		case 30: // field_jumpmaxholdtime0
		{
			float Value = *(reinterpret_cast<float const*>(Data));

			OutUpdate.set_field_jumpmaxholdtime0(Value);
			break;
		}
		case 31: // field_jumpmaxcount0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_jumpmaxcount0(int32_t(Value));
			break;
		}
		case 32: // field_reprootmotion0_bisactive0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_reprootmotion0_bisactive0(Value);
			break;
		}
		case 33: // field_reprootmotion0_animmontage0
		{
			UAnimMontage* Value = *(reinterpret_cast<UAnimMontage* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 33);
				}
				else
				{
					OutUpdate.set_field_reprootmotion0_animmontage0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_reprootmotion0_animmontage0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 34: // field_reprootmotion0_position0
		{
			float Value = *(reinterpret_cast<float const*>(Data));

			OutUpdate.set_field_reprootmotion0_position0(Value);
			break;
		}
		case 35: // field_reprootmotion0_location0
		{
			const FVector_NetQuantize100& Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 35);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_reprootmotion0_location0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 35);
			}
			break;
		}
		case 36: // field_reprootmotion0_rotation0
		{
			const FRotator& Value = *(reinterpret_cast<FRotator const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 36);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FRotator&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRotator failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_reprootmotion0_rotation0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 36);
			}
			break;
		}
		case 37: // field_reprootmotion0_movementbase0
		{
			UPrimitiveComponent* Value = *(reinterpret_cast<UPrimitiveComponent* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 37);
				}
				else
				{
					OutUpdate.set_field_reprootmotion0_movementbase0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_reprootmotion0_movementbase0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 38: // field_reprootmotion0_movementbasebonename0
		{
			FName Value = *(reinterpret_cast<FName const*>(Data));

			OutUpdate.set_field_reprootmotion0_movementbasebonename0(TCHAR_TO_UTF8(*Value.ToString()));
			break;
		}
		case 39: // field_reprootmotion0_brelativeposition0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_reprootmotion0_brelativeposition0(Value);
			break;
		}
		case 40: // field_reprootmotion0_brelativerotation0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_reprootmotion0_brelativerotation0(Value);
			break;
		}
		case 41: // field_reprootmotion0_authoritativerootmotion0
		{
			const FRootMotionSourceGroup& Value = *(reinterpret_cast<FRootMotionSourceGroup const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 41);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FRootMotionSourceGroup&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRootMotionSourceGroup failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_reprootmotion0_authoritativerootmotion0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 41);
			}
			break;
		}
		case 42: // field_reprootmotion0_acceleration0
		{
			const FVector_NetQuantize10& Value = *(reinterpret_cast<FVector_NetQuantize10 const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 42);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_reprootmotion0_acceleration0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 42);
			}
			break;
		}
		case 43: // field_reprootmotion0_linearvelocity0
		{
			const FVector_NetQuantize10& Value = *(reinterpret_cast<FVector_NetQuantize10 const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 43);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_reprootmotion0_linearvelocity0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 43);
			}
			break;
		}
		case 44: // field_equippedweapon0
		{
			AWeapon* Value = *(reinterpret_cast<AWeapon* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 44);
				}
				else
				{
					OutUpdate.set_field_equippedweapon0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_equippedweapon0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 46: // field_bisragdoll0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bisragdoll0(Value);
			break;
		}
		case 47: // field_aimyaw0
		{
			float Value = *(reinterpret_cast<float const*>(Data));

			OutUpdate.set_field_aimyaw0(Value);
			break;
		}
		case 48: // field_aimpitch0
		{
			float Value = *(reinterpret_cast<float const*>(Data));

			OutUpdate.set_field_aimpitch0(Value);
			break;
		}
		case 49: // field_team0
		{
			ESampleGameTeam Value = *(reinterpret_cast<ESampleGameTeam const*>(Data));

			OutUpdate.set_field_team0(uint32(Value));
			break;
		}
	default:
		checkf(false, TEXT("Unknown replication handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_SampleGameCharacter::ServerSendUpdate_Handover(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::samplegamecharacter::SampleGameCharacterHandoverData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 1: // field_charactermovement0_movementmode0
		{
			TEnumAsByte<EMovementMode> Value = *(reinterpret_cast<TEnumAsByte<EMovementMode> const*>(Data));

			OutUpdate.set_field_charactermovement0_movementmode0(uint32_t(Value));
			break;
		}
		case 2: // field_charactermovement0_custommovementmode0
		{
			uint8 Value = *(reinterpret_cast<uint8 const*>(Data));

			OutUpdate.set_field_charactermovement0_custommovementmode0(uint32_t(Value));
			break;
		}
		case 3: // field_charactermovement0_groundmovementmode0
		{
			TEnumAsByte<EMovementMode> Value = *(reinterpret_cast<TEnumAsByte<EMovementMode> const*>(Data));

			OutUpdate.set_field_charactermovement0_groundmovementmode0(uint32_t(Value));
			break;
		}
	default:
		checkf(false, TEXT("Unknown handover property handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_SampleGameCharacter::ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::samplegamecharacter::SampleGameCharacterSingleClientRepData::Update& Update) const
{
	AActor* TargetObject = ActorChannel->Actor;
	ActorChannel->PreReceiveSpatialUpdate(TargetObject);
	TSet<UProperty*> RepNotifies;

	const bool bIsServer = Interop->GetNetDriver()->IsServer();
	const bool bAutonomousProxy = ActorChannel->IsClientAutonomousProxy(improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::ComponentId);
	const FRepHandlePropertyMap& HandleToPropertyMap = GetRepHandlePropertyMap();
	FSpatialConditionMapFilter ConditionMap(ActorChannel, bAutonomousProxy);

	if (!Update.field_currenthealth0().empty())
	{
		// field_currenthealth0
		uint16 Handle = 45;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_currenthealth0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	ActorChannel->PostReceiveSpatialUpdate(TargetObject, RepNotifies.Array());
}

void USpatialTypeBinding_SampleGameCharacter::ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::samplegamecharacter::SampleGameCharacterMultiClientRepData::Update& Update) const
{
	AActor* TargetObject = ActorChannel->Actor;
	ActorChannel->PreReceiveSpatialUpdate(TargetObject);
	TSet<UProperty*> RepNotifies;

	const bool bIsServer = Interop->GetNetDriver()->IsServer();
	const bool bAutonomousProxy = ActorChannel->IsClientAutonomousProxy(improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::ComponentId);
	const FRepHandlePropertyMap& HandleToPropertyMap = GetRepHandlePropertyMap();
	FSpatialConditionMapFilter ConditionMap(ActorChannel, bAutonomousProxy);

	if (!Update.field_bhidden0().empty())
	{
		// field_bhidden0
		uint16 Handle = 1;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bhidden0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_breplicatemovement0().empty())
	{
		// field_breplicatemovement0
		uint16 Handle = 2;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_breplicatemovement0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_btearoff0().empty())
	{
		// field_btearoff0
		uint16 Handle = 3;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_btearoff0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_bcanbedamaged0().empty())
	{
		// field_bcanbedamaged0
		uint16 Handle = 4;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bcanbedamaged0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_remoterole0().empty())
	{
		// field_remoterole0
		uint16 Handle = 5;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			// On the client, we need to swap Role/RemoteRole.
			if (!bIsServer)
			{
				Handle = 14;
				RepData = &HandleToPropertyMap[Handle];
			}

			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(PropertyData));

			Value = TEnumAsByte<ENetRole>(uint8((*Update.field_remoterole0().data())));

			// Downgrade role from AutonomousProxy to SimulatedProxy if we aren't authoritative over
			// the server RPCs component.
			if (!bIsServer && Value == ROLE_AutonomousProxy && !bAutonomousProxy)
			{
				Value = ROLE_SimulatedProxy;
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedmovement0().empty())
	{
		// field_replicatedmovement0
		uint16 Handle = 6;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FRepMovement Value = *(reinterpret_cast<FRepMovement const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_replicatedmovement0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRepMovement failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_attachparent0().empty())
	{
		// field_attachmentreplication0_attachparent0
		uint16 Handle = 7;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			AActor* Value = *(reinterpret_cast<AActor* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_attachmentreplication0_attachparent0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<AActor>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<AActor>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_attachmentreplication0_locationoffset0().empty())
	{
		// field_attachmentreplication0_locationoffset0
		uint16 Handle = 8;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector_NetQuantize100 Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_attachmentreplication0_locationoffset0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_relativescale3d0().empty())
	{
		// field_attachmentreplication0_relativescale3d0
		uint16 Handle = 9;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector_NetQuantize100 Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_attachmentreplication0_relativescale3d0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_rotationoffset0().empty())
	{
		// field_attachmentreplication0_rotationoffset0
		uint16 Handle = 10;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FRotator Value = *(reinterpret_cast<FRotator const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_attachmentreplication0_rotationoffset0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRotator failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_attachsocket0().empty())
	{
		// field_attachmentreplication0_attachsocket0
		uint16 Handle = 11;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FName Value = *(reinterpret_cast<FName const*>(PropertyData));

			Value = FName(((*Update.field_attachmentreplication0_attachsocket0().data())).data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_attachcomponent0().empty())
	{
		// field_attachmentreplication0_attachcomponent0
		uint16 Handle = 12;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			USceneComponent* Value = *(reinterpret_cast<USceneComponent* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_attachmentreplication0_attachcomponent0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<USceneComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<USceneComponent>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_owner0().empty())
	{
		// field_owner0
		uint16 Handle = 13;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			AActor* Value = *(reinterpret_cast<AActor* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_owner0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<AActor>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<AActor>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_role0().empty())
	{
		// field_role0
		uint16 Handle = 14;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			// On the client, we need to swap Role/RemoteRole.
			if (!bIsServer)
			{
				Handle = 5;
				RepData = &HandleToPropertyMap[Handle];
			}

			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(PropertyData));

			Value = TEnumAsByte<ENetRole>(uint8((*Update.field_role0().data())));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_instigator0().empty())
	{
		// field_instigator0
		uint16 Handle = 15;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			APawn* Value = *(reinterpret_cast<APawn* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_instigator0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<APawn>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<APawn>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_playerstate0().empty())
	{
		// field_playerstate0
		uint16 Handle = 16;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			APlayerState* Value = *(reinterpret_cast<APlayerState* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_playerstate0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<APlayerState>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<APlayerState>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_remoteviewpitch0().empty())
	{
		// field_remoteviewpitch0
		uint16 Handle = 17;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			uint8 Value = *(reinterpret_cast<uint8 const*>(PropertyData));

			Value = uint8(uint8((*Update.field_remoteviewpitch0().data())));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_controller0().empty())
	{
		// field_controller0
		uint16 Handle = 18;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			AController* Value = *(reinterpret_cast<AController* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_controller0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<AController>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<AController>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_replicatedbasedmovement0_movementbase0().empty())
	{
		// field_replicatedbasedmovement0_movementbase0
		uint16 Handle = 19;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UPrimitiveComponent* Value = *(reinterpret_cast<UPrimitiveComponent* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_replicatedbasedmovement0_movementbase0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_replicatedbasedmovement0_bonename0().empty())
	{
		// field_replicatedbasedmovement0_bonename0
		uint16 Handle = 20;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FName Value = *(reinterpret_cast<FName const*>(PropertyData));

			Value = FName(((*Update.field_replicatedbasedmovement0_bonename0().data())).data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedbasedmovement0_location0().empty())
	{
		// field_replicatedbasedmovement0_location0
		uint16 Handle = 21;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector_NetQuantize100 Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_replicatedbasedmovement0_location0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedbasedmovement0_rotation0().empty())
	{
		// field_replicatedbasedmovement0_rotation0
		uint16 Handle = 22;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FRotator Value = *(reinterpret_cast<FRotator const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_replicatedbasedmovement0_rotation0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRotator failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedbasedmovement0_bserverhasbasecomponent0().empty())
	{
		// field_replicatedbasedmovement0_bserverhasbasecomponent0
		uint16 Handle = 23;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_replicatedbasedmovement0_bserverhasbasecomponent0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedbasedmovement0_brelativerotation0().empty())
	{
		// field_replicatedbasedmovement0_brelativerotation0
		uint16 Handle = 24;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_replicatedbasedmovement0_brelativerotation0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedbasedmovement0_bserverhasvelocity0().empty())
	{
		// field_replicatedbasedmovement0_bserverhasvelocity0
		uint16 Handle = 25;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_replicatedbasedmovement0_bserverhasvelocity0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_animrootmotiontranslationscale0().empty())
	{
		// field_animrootmotiontranslationscale0
		uint16 Handle = 26;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			float Value = *(reinterpret_cast<float const*>(PropertyData));

			Value = (*Update.field_animrootmotiontranslationscale0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedserverlasttransformupdatetimestamp0().empty())
	{
		// field_replicatedserverlasttransformupdatetimestamp0
		uint16 Handle = 27;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			float Value = *(reinterpret_cast<float const*>(PropertyData));

			Value = (*Update.field_replicatedserverlasttransformupdatetimestamp0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedmovementmode0().empty())
	{
		// field_replicatedmovementmode0
		uint16 Handle = 28;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			uint8 Value = *(reinterpret_cast<uint8 const*>(PropertyData));

			Value = uint8(uint8((*Update.field_replicatedmovementmode0().data())));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_biscrouched0().empty())
	{
		// field_biscrouched0
		uint16 Handle = 29;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_biscrouched0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_jumpmaxholdtime0().empty())
	{
		// field_jumpmaxholdtime0
		uint16 Handle = 30;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			float Value = *(reinterpret_cast<float const*>(PropertyData));

			Value = (*Update.field_jumpmaxholdtime0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_jumpmaxcount0().empty())
	{
		// field_jumpmaxcount0
		uint16 Handle = 31;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_jumpmaxcount0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_bisactive0().empty())
	{
		// field_reprootmotion0_bisactive0
		uint16 Handle = 32;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_reprootmotion0_bisactive0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_animmontage0().empty())
	{
		// field_reprootmotion0_animmontage0
		uint16 Handle = 33;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UAnimMontage* Value = *(reinterpret_cast<UAnimMontage* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_reprootmotion0_animmontage0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UAnimMontage>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<UAnimMontage>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_reprootmotion0_position0().empty())
	{
		// field_reprootmotion0_position0
		uint16 Handle = 34;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			float Value = *(reinterpret_cast<float const*>(PropertyData));

			Value = (*Update.field_reprootmotion0_position0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_location0().empty())
	{
		// field_reprootmotion0_location0
		uint16 Handle = 35;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector_NetQuantize100 Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_reprootmotion0_location0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_rotation0().empty())
	{
		// field_reprootmotion0_rotation0
		uint16 Handle = 36;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FRotator Value = *(reinterpret_cast<FRotator const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_reprootmotion0_rotation0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRotator failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_movementbase0().empty())
	{
		// field_reprootmotion0_movementbase0
		uint16 Handle = 37;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			UPrimitiveComponent* Value = *(reinterpret_cast<UPrimitiveComponent* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_reprootmotion0_movementbase0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_reprootmotion0_movementbasebonename0().empty())
	{
		// field_reprootmotion0_movementbasebonename0
		uint16 Handle = 38;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FName Value = *(reinterpret_cast<FName const*>(PropertyData));

			Value = FName(((*Update.field_reprootmotion0_movementbasebonename0().data())).data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_brelativeposition0().empty())
	{
		// field_reprootmotion0_brelativeposition0
		uint16 Handle = 39;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_reprootmotion0_brelativeposition0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_brelativerotation0().empty())
	{
		// field_reprootmotion0_brelativerotation0
		uint16 Handle = 40;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_reprootmotion0_brelativerotation0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_authoritativerootmotion0().empty())
	{
		// field_reprootmotion0_authoritativerootmotion0
		uint16 Handle = 41;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FRootMotionSourceGroup Value = *(reinterpret_cast<FRootMotionSourceGroup const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_reprootmotion0_authoritativerootmotion0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRootMotionSourceGroup failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_acceleration0().empty())
	{
		// field_reprootmotion0_acceleration0
		uint16 Handle = 42;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector_NetQuantize10 Value = *(reinterpret_cast<FVector_NetQuantize10 const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_reprootmotion0_acceleration0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_reprootmotion0_linearvelocity0().empty())
	{
		// field_reprootmotion0_linearvelocity0
		uint16 Handle = 43;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector_NetQuantize10 Value = *(reinterpret_cast<FVector_NetQuantize10 const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_reprootmotion0_linearvelocity0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_equippedweapon0().empty())
	{
		// field_equippedweapon0
		uint16 Handle = 44;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			AWeapon* Value = *(reinterpret_cast<AWeapon* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_equippedweapon0().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<AWeapon>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<AWeapon>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_bisragdoll0().empty())
	{
		// field_bisragdoll0
		uint16 Handle = 46;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bisragdoll0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_aimyaw0().empty())
	{
		// field_aimyaw0
		uint16 Handle = 47;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			float Value = *(reinterpret_cast<float const*>(PropertyData));

			Value = (*Update.field_aimyaw0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_aimpitch0().empty())
	{
		// field_aimpitch0
		uint16 Handle = 48;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			float Value = *(reinterpret_cast<float const*>(PropertyData));

			Value = (*Update.field_aimpitch0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_team0().empty())
	{
		// field_team0
		uint16 Handle = 49;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			ESampleGameTeam Value = *(reinterpret_cast<ESampleGameTeam const*>(PropertyData));

			Value = ESampleGameTeam((*Update.field_team0().data()));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	ActorChannel->PostReceiveSpatialUpdate(TargetObject, RepNotifies.Array());
}

void USpatialTypeBinding_SampleGameCharacter::ReceiveUpdate_Handover(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::samplegamecharacter::SampleGameCharacterHandoverData::Update& Update) const
{
	const FHandoverHandlePropertyMap& HandleToPropertyMap = GetHandoverHandlePropertyMap();

	if (!Update.field_charactermovement0_movementmode0().empty())
	{
		// field_charactermovement0_movementmode0
		uint16 Handle = 1;
		const FHandoverHandleData* HandoverData = &HandleToPropertyMap[Handle];
		uint8* PropertyData = HandoverData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
		TEnumAsByte<EMovementMode> Value = *(reinterpret_cast<TEnumAsByte<EMovementMode> const*>(PropertyData));

		Value = TEnumAsByte<EMovementMode>(uint8((*Update.field_charactermovement0_movementmode0().data())));

		ApplyIncomingHandoverPropertyUpdate(*HandoverData, ActorChannel->Actor, static_cast<const void*>(&Value));

		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received handover property update. actor %s (%lld), property %s (handle %d)"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ActorChannel->Actor->GetName(),
			ActorChannel->GetEntityId().ToSpatialEntityId(),
			*HandoverData->Property->GetName(),
			Handle);
	}
	if (!Update.field_charactermovement0_custommovementmode0().empty())
	{
		// field_charactermovement0_custommovementmode0
		uint16 Handle = 2;
		const FHandoverHandleData* HandoverData = &HandleToPropertyMap[Handle];
		uint8* PropertyData = HandoverData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
		uint8 Value = *(reinterpret_cast<uint8 const*>(PropertyData));

		Value = uint8(uint8((*Update.field_charactermovement0_custommovementmode0().data())));

		ApplyIncomingHandoverPropertyUpdate(*HandoverData, ActorChannel->Actor, static_cast<const void*>(&Value));

		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received handover property update. actor %s (%lld), property %s (handle %d)"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ActorChannel->Actor->GetName(),
			ActorChannel->GetEntityId().ToSpatialEntityId(),
			*HandoverData->Property->GetName(),
			Handle);
	}
	if (!Update.field_charactermovement0_groundmovementmode0().empty())
	{
		// field_charactermovement0_groundmovementmode0
		uint16 Handle = 3;
		const FHandoverHandleData* HandoverData = &HandleToPropertyMap[Handle];
		uint8* PropertyData = HandoverData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
		TEnumAsByte<EMovementMode> Value = *(reinterpret_cast<TEnumAsByte<EMovementMode> const*>(PropertyData));

		Value = TEnumAsByte<EMovementMode>(uint8((*Update.field_charactermovement0_groundmovementmode0().data())));

		ApplyIncomingHandoverPropertyUpdate(*HandoverData, ActorChannel->Actor, static_cast<const void*>(&Value));

		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received handover property update. actor %s (%lld), property %s (handle %d)"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ActorChannel->Actor->GetName(),
			ActorChannel->GetEntityId().ToSpatialEntityId(),
			*HandoverData->Property->GetName(),
			Handle);
	}
}

void USpatialTypeBinding_SampleGameCharacter::ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::samplegamecharacter::SampleGameCharacterNetMulticastRPCs::Update& Update)
{
}
void USpatialTypeBinding_SampleGameCharacter::RootMotionDebugClientPrintOnScreen_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventRootMotionDebugClientPrintOnScreen_Parms StructuredParams = *static_cast<Character_eventRootMotionDebugClientPrintOnScreen_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC RootMotionDebugClientPrintOnScreen queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::RootMotionDebugClientPrintOnScreenRequest RPCPayload;
		{
			RPCPayload.set_field_instring0(TCHAR_TO_UTF8(*StructuredParams.InString));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: RootMotionDebugClientPrintOnScreen, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Rootmotiondebugclientprintonscreen>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_SampleGameCharacter::ClientVeryShortAdjustPosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventClientVeryShortAdjustPosition_Parms StructuredParams = *static_cast<Character_eventClientVeryShortAdjustPosition_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientVeryShortAdjustPosition queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientVeryShortAdjustPositionRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(StructuredParams.NewLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			RPCPayload.set_field_newloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			if (StructuredParams.NewBase != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.NewBase);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.NewBase->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.NewBase);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientVeryShortAdjustPosition queued. StructuredParams.NewBase is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.NewBase)};
				}
				else
				{
					RPCPayload.set_field_newbase0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_newbase0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_newbasebonename0(TCHAR_TO_UTF8(*StructuredParams.NewBaseBoneName.ToString()));
		}
		{
			RPCPayload.set_field_bhasbase0(StructuredParams.bHasBase);
		}
		{
			RPCPayload.set_field_bbaserelativeposition0(StructuredParams.bBaseRelativePosition);
		}
		{
			RPCPayload.set_field_servermovementmode0(uint32_t(StructuredParams.ServerMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientVeryShortAdjustPosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientveryshortadjustposition>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_SampleGameCharacter::ClientCheatWalk_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientCheatWalk queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientCheatWalkRequest RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientCheatWalk, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientcheatwalk>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_SampleGameCharacter::ClientCheatGhost_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientCheatGhost queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientCheatGhostRequest RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientCheatGhost, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientcheatghost>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_SampleGameCharacter::ClientCheatFly_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientCheatFly queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientCheatFlyRequest RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientCheatFly, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientcheatfly>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_SampleGameCharacter::ClientAdjustRootMotionSourcePosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventClientAdjustRootMotionSourcePosition_Parms StructuredParams = *static_cast<Character_eventClientAdjustRootMotionSourcePosition_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientAdjustRootMotionSourcePosition queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientAdjustRootMotionSourcePositionRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FRootMotionSourceGroup&>(StructuredParams.ServerRootMotion)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRootMotionSourceGroup failed."));
			RPCPayload.set_field_serverrootmotion0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_bhasanimrootmotion0(StructuredParams.bHasAnimRootMotion);
		}
		{
			RPCPayload.set_field_servermontagetrackposition0(StructuredParams.ServerMontageTrackPosition);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(StructuredParams.ServerLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			RPCPayload.set_field_serverloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantizeNormal&>(StructuredParams.ServerRotation)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantizeNormal failed."));
			RPCPayload.set_field_serverrotation0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_servervelz0(StructuredParams.ServerVelZ);
		}
		{
			if (StructuredParams.ServerBase != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ServerBase);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.ServerBase->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.ServerBase);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientAdjustRootMotionSourcePosition queued. StructuredParams.ServerBase is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.ServerBase)};
				}
				else
				{
					RPCPayload.set_field_serverbase0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_serverbase0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_serverbonename0(TCHAR_TO_UTF8(*StructuredParams.ServerBoneName.ToString()));
		}
		{
			RPCPayload.set_field_bhasbase0(StructuredParams.bHasBase);
		}
		{
			RPCPayload.set_field_bbaserelativeposition0(StructuredParams.bBaseRelativePosition);
		}
		{
			RPCPayload.set_field_servermovementmode0(uint32_t(StructuredParams.ServerMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientAdjustRootMotionSourcePosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientadjustrootmotionsourceposition>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_SampleGameCharacter::ClientAdjustRootMotionPosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventClientAdjustRootMotionPosition_Parms StructuredParams = *static_cast<Character_eventClientAdjustRootMotionPosition_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientAdjustRootMotionPosition queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientAdjustRootMotionPositionRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			RPCPayload.set_field_servermontagetrackposition0(StructuredParams.ServerMontageTrackPosition);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(StructuredParams.ServerLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			RPCPayload.set_field_serverloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantizeNormal&>(StructuredParams.ServerRotation)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantizeNormal failed."));
			RPCPayload.set_field_serverrotation0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_servervelz0(StructuredParams.ServerVelZ);
		}
		{
			if (StructuredParams.ServerBase != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ServerBase);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.ServerBase->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.ServerBase);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientAdjustRootMotionPosition queued. StructuredParams.ServerBase is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.ServerBase)};
				}
				else
				{
					RPCPayload.set_field_serverbase0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_serverbase0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_serverbonename0(TCHAR_TO_UTF8(*StructuredParams.ServerBoneName.ToString()));
		}
		{
			RPCPayload.set_field_bhasbase0(StructuredParams.bHasBase);
		}
		{
			RPCPayload.set_field_bbaserelativeposition0(StructuredParams.bBaseRelativePosition);
		}
		{
			RPCPayload.set_field_servermovementmode0(uint32_t(StructuredParams.ServerMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientAdjustRootMotionPosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientadjustrootmotionposition>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_SampleGameCharacter::ClientAdjustPosition_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventClientAdjustPosition_Parms StructuredParams = *static_cast<Character_eventClientAdjustPosition_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientAdjustPosition queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientAdjustPositionRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(StructuredParams.NewLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			RPCPayload.set_field_newloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(StructuredParams.NewVel)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			RPCPayload.set_field_newvel0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			if (StructuredParams.NewBase != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.NewBase);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.NewBase->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.NewBase);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientAdjustPosition queued. StructuredParams.NewBase is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.NewBase)};
				}
				else
				{
					RPCPayload.set_field_newbase0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_newbase0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_newbasebonename0(TCHAR_TO_UTF8(*StructuredParams.NewBaseBoneName.ToString()));
		}
		{
			RPCPayload.set_field_bhasbase0(StructuredParams.bHasBase);
		}
		{
			RPCPayload.set_field_bbaserelativeposition0(StructuredParams.bBaseRelativePosition);
		}
		{
			RPCPayload.set_field_servermovementmode0(uint32_t(StructuredParams.ServerMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientAdjustPosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientadjustposition>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_SampleGameCharacter::ClientAckGoodMove_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventClientAckGoodMove_Parms StructuredParams = *static_cast<Character_eventClientAckGoodMove_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ClientAckGoodMove queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ClientAckGoodMoveRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ClientAckGoodMove, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientackgoodmove>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_SampleGameCharacter::ServerSpawnCube_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerSpawnCube queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::samplegamecharacter::ServerSpawnCubeRequest RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ServerSpawnCube, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Serverspawncube>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_SampleGameCharacter::DebugResetCharacter_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC DebugResetCharacter queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::samplegamecharacter::DebugResetCharacterRequest RPCPayload;

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: DebugResetCharacter, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Debugresetcharacter>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_SampleGameCharacter::ServerMoveOld_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventServerMoveOld_Parms StructuredParams = *static_cast<Character_eventServerMoveOld_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMoveOld queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ServerMoveOldRequest RPCPayload;
		{
			RPCPayload.set_field_oldtimestamp0(StructuredParams.OldTimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.OldAccel)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_oldaccel0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_oldmoveflags0(uint32_t(StructuredParams.OldMoveFlags));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ServerMoveOld, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermoveold>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_SampleGameCharacter::ServerMoveNoBase_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventServerMoveNoBase_Parms StructuredParams = *static_cast<Character_eventServerMoveNoBase_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMoveNoBase queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ServerMoveNoBaseRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(StructuredParams.ClientLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			RPCPayload.set_field_clientloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_compressedmoveflags0(uint32_t(StructuredParams.CompressedMoveFlags));
		}
		{
			RPCPayload.set_field_clientroll0(uint32_t(StructuredParams.ClientRoll));
		}
		{
			RPCPayload.set_field_view0(uint32_t(StructuredParams.View));
		}
		{
			RPCPayload.set_field_clientmovementmode0(uint32_t(StructuredParams.ClientMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ServerMoveNoBase, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovenobase>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_SampleGameCharacter::ServerMoveDualNoBase_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventServerMoveDualNoBase_Parms StructuredParams = *static_cast<Character_eventServerMoveDualNoBase_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMoveDualNoBase queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ServerMoveDualNoBaseRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp00(StructuredParams.TimeStamp0);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel0)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel00(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_pendingflags0(uint32_t(StructuredParams.PendingFlags));
		}
		{
			RPCPayload.set_field_view00(uint32_t(StructuredParams.View0));
		}
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(StructuredParams.ClientLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			RPCPayload.set_field_clientloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_newflags0(uint32_t(StructuredParams.NewFlags));
		}
		{
			RPCPayload.set_field_clientroll0(uint32_t(StructuredParams.ClientRoll));
		}
		{
			RPCPayload.set_field_view0(uint32_t(StructuredParams.View));
		}
		{
			RPCPayload.set_field_clientmovementmode0(uint32_t(StructuredParams.ClientMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ServerMoveDualNoBase, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovedualnobase>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_SampleGameCharacter::ServerMoveDualHybridRootMotion_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventServerMoveDualHybridRootMotion_Parms StructuredParams = *static_cast<Character_eventServerMoveDualHybridRootMotion_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMoveDualHybridRootMotion queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ServerMoveDualHybridRootMotionRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp00(StructuredParams.TimeStamp0);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel0)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel00(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_pendingflags0(uint32_t(StructuredParams.PendingFlags));
		}
		{
			RPCPayload.set_field_view00(uint32_t(StructuredParams.View0));
		}
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(StructuredParams.ClientLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			RPCPayload.set_field_clientloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_newflags0(uint32_t(StructuredParams.NewFlags));
		}
		{
			RPCPayload.set_field_clientroll0(uint32_t(StructuredParams.ClientRoll));
		}
		{
			RPCPayload.set_field_view0(uint32_t(StructuredParams.View));
		}
		{
			if (StructuredParams.ClientMovementBase != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ClientMovementBase);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.ClientMovementBase->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.ClientMovementBase);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMoveDualHybridRootMotion queued. StructuredParams.ClientMovementBase is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.ClientMovementBase)};
				}
				else
				{
					RPCPayload.set_field_clientmovementbase0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_clientmovementbase0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_clientbasebonename0(TCHAR_TO_UTF8(*StructuredParams.ClientBaseBoneName.ToString()));
		}
		{
			RPCPayload.set_field_clientmovementmode0(uint32_t(StructuredParams.ClientMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ServerMoveDualHybridRootMotion, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovedualhybridrootmotion>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_SampleGameCharacter::ServerMoveDual_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventServerMoveDual_Parms StructuredParams = *static_cast<Character_eventServerMoveDual_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMoveDual queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ServerMoveDualRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp00(StructuredParams.TimeStamp0);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel0)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel00(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_pendingflags0(uint32_t(StructuredParams.PendingFlags));
		}
		{
			RPCPayload.set_field_view00(uint32_t(StructuredParams.View0));
		}
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(StructuredParams.ClientLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			RPCPayload.set_field_clientloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_newflags0(uint32_t(StructuredParams.NewFlags));
		}
		{
			RPCPayload.set_field_clientroll0(uint32_t(StructuredParams.ClientRoll));
		}
		{
			RPCPayload.set_field_view0(uint32_t(StructuredParams.View));
		}
		{
			if (StructuredParams.ClientMovementBase != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ClientMovementBase);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.ClientMovementBase->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.ClientMovementBase);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMoveDual queued. StructuredParams.ClientMovementBase is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.ClientMovementBase)};
				}
				else
				{
					RPCPayload.set_field_clientmovementbase0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_clientmovementbase0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_clientbasebonename0(TCHAR_TO_UTF8(*StructuredParams.ClientBaseBoneName.ToString()));
		}
		{
			RPCPayload.set_field_clientmovementmode0(uint32_t(StructuredParams.ClientMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ServerMoveDual, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovedual>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_SampleGameCharacter::ServerMove_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
	Character_eventServerMove_Parms StructuredParams = *static_cast<Character_eventServerMove_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMove queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::character::ServerMoveRequest RPCPayload;
		{
			RPCPayload.set_field_timestamp0(StructuredParams.TimeStamp);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize10&>(StructuredParams.InAccel)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
			RPCPayload.set_field_inaccel0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(StructuredParams.ClientLoc)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			RPCPayload.set_field_clientloc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_compressedmoveflags0(uint32_t(StructuredParams.CompressedMoveFlags));
		}
		{
			RPCPayload.set_field_clientroll0(uint32_t(StructuredParams.ClientRoll));
		}
		{
			RPCPayload.set_field_view0(uint32_t(StructuredParams.View));
		}
		{
			if (StructuredParams.ClientMovementBase != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ClientMovementBase);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.ClientMovementBase->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.ClientMovementBase);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC ServerMove queued. StructuredParams.ClientMovementBase is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.ClientMovementBase)};
				}
				else
				{
					RPCPayload.set_field_clientmovementbase0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_clientmovementbase0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_clientbasebonename0(TCHAR_TO_UTF8(*StructuredParams.ClientBaseBoneName.ToString()));
		}
		{
			RPCPayload.set_field_clientmovementmode0(uint32_t(StructuredParams.ClientMovementMode));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: ServerMove, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermove>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_SampleGameCharacter::RootMotionDebugClientPrintOnScreen_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Rootmotiondebugclientprintonscreen>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RootMotionDebugClientPrintOnScreen_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: RootMotionDebugClientPrintOnScreen_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventRootMotionDebugClientPrintOnScreen_Parms Parameters;

		// Extract from request data.
		{
			Parameters.InString = FString(UTF8_TO_TCHAR(Op.Request.field_instring0().c_str()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: RootMotionDebugClientPrintOnScreen, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("RootMotionDebugClientPrintOnScreen"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: RootMotionDebugClientPrintOnScreen_OnRPCPayload: Function not found. Object: %s, Function: RootMotionDebugClientPrintOnScreen."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Rootmotiondebugclientprintonscreen>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ClientVeryShortAdjustPosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientveryshortadjustposition>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientVeryShortAdjustPosition_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientVeryShortAdjustPosition_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventClientVeryShortAdjustPosition_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_newloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.NewLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_newbase0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.NewBase = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.NewBase = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientVeryShortAdjustPosition_OnRPCPayload: Parameters.NewBase %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.NewBaseBoneName = FName((Op.Request.field_newbasebonename0()).data());
		}
		{
			Parameters.bHasBase = Op.Request.field_bhasbase0();
		}
		{
			Parameters.bBaseRelativePosition = Op.Request.field_bbaserelativeposition0();
		}
		{
			Parameters.ServerMovementMode = uint8(uint8(Op.Request.field_servermovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientVeryShortAdjustPosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientVeryShortAdjustPosition"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientVeryShortAdjustPosition_OnRPCPayload: Function not found. Object: %s, Function: ClientVeryShortAdjustPosition."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientveryshortadjustposition>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ClientCheatWalk_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientcheatwalk>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientCheatWalk_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientCheatWalk_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientCheatWalk, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientCheatWalk"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientCheatWalk_OnRPCPayload: Function not found. Object: %s, Function: ClientCheatWalk."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientcheatwalk>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ClientCheatGhost_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientcheatghost>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientCheatGhost_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientCheatGhost_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientCheatGhost, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientCheatGhost"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientCheatGhost_OnRPCPayload: Function not found. Object: %s, Function: ClientCheatGhost."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientcheatghost>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ClientCheatFly_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientcheatfly>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientCheatFly_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientCheatFly_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientCheatFly, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientCheatFly"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientCheatFly_OnRPCPayload: Function not found. Object: %s, Function: ClientCheatFly."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientcheatfly>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ClientAdjustRootMotionSourcePosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientadjustrootmotionsourceposition>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientAdjustRootMotionSourcePosition_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientAdjustRootMotionSourcePosition_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventClientAdjustRootMotionSourcePosition_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_serverrootmotion0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ServerRootMotion.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRootMotionSourceGroup failed."));
		}
		{
			Parameters.bHasAnimRootMotion = Op.Request.field_bhasanimrootmotion0();
		}
		{
			Parameters.ServerMontageTrackPosition = Op.Request.field_servermontagetrackposition0();
		}
		{
			auto& ValueDataStr = Op.Request.field_serverloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ServerLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_serverrotation0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ServerRotation.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantizeNormal failed."));
		}
		{
			Parameters.ServerVelZ = Op.Request.field_servervelz0();
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_serverbase0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ServerBase = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.ServerBase = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientAdjustRootMotionSourcePosition_OnRPCPayload: Parameters.ServerBase %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.ServerBoneName = FName((Op.Request.field_serverbonename0()).data());
		}
		{
			Parameters.bHasBase = Op.Request.field_bhasbase0();
		}
		{
			Parameters.bBaseRelativePosition = Op.Request.field_bbaserelativeposition0();
		}
		{
			Parameters.ServerMovementMode = uint8(uint8(Op.Request.field_servermovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientAdjustRootMotionSourcePosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientAdjustRootMotionSourcePosition"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientAdjustRootMotionSourcePosition_OnRPCPayload: Function not found. Object: %s, Function: ClientAdjustRootMotionSourcePosition."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientadjustrootmotionsourceposition>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ClientAdjustRootMotionPosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientadjustrootmotionposition>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientAdjustRootMotionPosition_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientAdjustRootMotionPosition_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventClientAdjustRootMotionPosition_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			Parameters.ServerMontageTrackPosition = Op.Request.field_servermontagetrackposition0();
		}
		{
			auto& ValueDataStr = Op.Request.field_serverloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ServerLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_serverrotation0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ServerRotation.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantizeNormal failed."));
		}
		{
			Parameters.ServerVelZ = Op.Request.field_servervelz0();
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_serverbase0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ServerBase = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.ServerBase = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientAdjustRootMotionPosition_OnRPCPayload: Parameters.ServerBase %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.ServerBoneName = FName((Op.Request.field_serverbonename0()).data());
		}
		{
			Parameters.bHasBase = Op.Request.field_bhasbase0();
		}
		{
			Parameters.bBaseRelativePosition = Op.Request.field_bbaserelativeposition0();
		}
		{
			Parameters.ServerMovementMode = uint8(uint8(Op.Request.field_servermovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientAdjustRootMotionPosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientAdjustRootMotionPosition"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientAdjustRootMotionPosition_OnRPCPayload: Function not found. Object: %s, Function: ClientAdjustRootMotionPosition."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientadjustrootmotionposition>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ClientAdjustPosition_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientadjustposition>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientAdjustPosition_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientAdjustPosition_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventClientAdjustPosition_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_newloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.NewLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_newvel0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.NewVel.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_newbase0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.NewBase = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.NewBase = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientAdjustPosition_OnRPCPayload: Parameters.NewBase %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.NewBaseBoneName = FName((Op.Request.field_newbasebonename0()).data());
		}
		{
			Parameters.bHasBase = Op.Request.field_bhasbase0();
		}
		{
			Parameters.bBaseRelativePosition = Op.Request.field_bbaserelativeposition0();
		}
		{
			Parameters.ServerMovementMode = uint8(uint8(Op.Request.field_servermovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientAdjustPosition, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientAdjustPosition"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientAdjustPosition_OnRPCPayload: Function not found. Object: %s, Function: ClientAdjustPosition."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientadjustposition>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ClientAckGoodMove_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientackgoodmove>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ClientAckGoodMove_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientAckGoodMove_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventClientAckGoodMove_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ClientAckGoodMove, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientAckGoodMove"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ClientAckGoodMove_OnRPCPayload: Function not found. Object: %s, Function: ClientAckGoodMove."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientackgoodmove>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ServerSpawnCube_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Serverspawncube>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerSpawnCube_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerSpawnCube_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ServerSpawnCube, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerSpawnCube"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ServerSpawnCube_OnRPCPayload: Function not found. Object: %s, Function: ServerSpawnCube."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Serverspawncube>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::DebugResetCharacter_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Debugresetcharacter>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: DebugResetCharacter_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: DebugResetCharacter_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: DebugResetCharacter, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("DebugResetCharacter"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: DebugResetCharacter_OnRPCPayload: Function not found. Object: %s, Function: DebugResetCharacter."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Debugresetcharacter>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ServerMoveOld_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermoveold>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMoveOld_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerMoveOld_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventServerMoveOld_Parms Parameters;

		// Extract from request data.
		{
			Parameters.OldTimeStamp = Op.Request.field_oldtimestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_oldaccel0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.OldAccel.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			Parameters.OldMoveFlags = uint8(uint8(Op.Request.field_oldmoveflags0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ServerMoveOld, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerMoveOld"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ServerMoveOld_OnRPCPayload: Function not found. Object: %s, Function: ServerMoveOld."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermoveold>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ServerMoveNoBase_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovenobase>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMoveNoBase_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerMoveNoBase_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventServerMoveNoBase_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_clientloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ClientLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
		}
		{
			Parameters.CompressedMoveFlags = uint8(uint8(Op.Request.field_compressedmoveflags0()));
		}
		{
			Parameters.ClientRoll = uint8(uint8(Op.Request.field_clientroll0()));
		}
		{
			Parameters.View = Op.Request.field_view0();
		}
		{
			Parameters.ClientMovementMode = uint8(uint8(Op.Request.field_clientmovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ServerMoveNoBase, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerMoveNoBase"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ServerMoveNoBase_OnRPCPayload: Function not found. Object: %s, Function: ServerMoveNoBase."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovenobase>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ServerMoveDualNoBase_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovedualnobase>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMoveDualNoBase_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerMoveDualNoBase_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventServerMoveDualNoBase_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp0 = Op.Request.field_timestamp00();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel00();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel0.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			Parameters.PendingFlags = uint8(uint8(Op.Request.field_pendingflags0()));
		}
		{
			Parameters.View0 = Op.Request.field_view00();
		}
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_clientloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ClientLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
		}
		{
			Parameters.NewFlags = uint8(uint8(Op.Request.field_newflags0()));
		}
		{
			Parameters.ClientRoll = uint8(uint8(Op.Request.field_clientroll0()));
		}
		{
			Parameters.View = Op.Request.field_view0();
		}
		{
			Parameters.ClientMovementMode = uint8(uint8(Op.Request.field_clientmovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ServerMoveDualNoBase, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerMoveDualNoBase"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ServerMoveDualNoBase_OnRPCPayload: Function not found. Object: %s, Function: ServerMoveDualNoBase."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovedualnobase>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ServerMoveDualHybridRootMotion_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovedualhybridrootmotion>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMoveDualHybridRootMotion_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerMoveDualHybridRootMotion_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventServerMoveDualHybridRootMotion_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp0 = Op.Request.field_timestamp00();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel00();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel0.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			Parameters.PendingFlags = uint8(uint8(Op.Request.field_pendingflags0()));
		}
		{
			Parameters.View0 = Op.Request.field_view00();
		}
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_clientloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ClientLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
		}
		{
			Parameters.NewFlags = uint8(uint8(Op.Request.field_newflags0()));
		}
		{
			Parameters.ClientRoll = uint8(uint8(Op.Request.field_clientroll0()));
		}
		{
			Parameters.View = Op.Request.field_view0();
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_clientmovementbase0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ClientMovementBase = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.ClientMovementBase = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMoveDualHybridRootMotion_OnRPCPayload: Parameters.ClientMovementBase %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.ClientBaseBoneName = FName((Op.Request.field_clientbasebonename0()).data());
		}
		{
			Parameters.ClientMovementMode = uint8(uint8(Op.Request.field_clientmovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ServerMoveDualHybridRootMotion, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerMoveDualHybridRootMotion"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ServerMoveDualHybridRootMotion_OnRPCPayload: Function not found. Object: %s, Function: ServerMoveDualHybridRootMotion."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovedualhybridrootmotion>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ServerMoveDual_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovedual>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMoveDual_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerMoveDual_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventServerMoveDual_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp0 = Op.Request.field_timestamp00();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel00();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel0.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			Parameters.PendingFlags = uint8(uint8(Op.Request.field_pendingflags0()));
		}
		{
			Parameters.View0 = Op.Request.field_view00();
		}
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_clientloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ClientLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
		}
		{
			Parameters.NewFlags = uint8(uint8(Op.Request.field_newflags0()));
		}
		{
			Parameters.ClientRoll = uint8(uint8(Op.Request.field_clientroll0()));
		}
		{
			Parameters.View = Op.Request.field_view0();
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_clientmovementbase0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ClientMovementBase = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.ClientMovementBase = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMoveDual_OnRPCPayload: Parameters.ClientMovementBase %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.ClientBaseBoneName = FName((Op.Request.field_clientbasebonename0()).data());
		}
		{
			Parameters.ClientMovementMode = uint8(uint8(Op.Request.field_clientmovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ServerMoveDual, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerMoveDual"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ServerMoveDual_OnRPCPayload: Function not found. Object: %s, Function: ServerMoveDual."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovedual>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_SampleGameCharacter::ServerMove_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermove>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMove_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerMove_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Character.generated.h (in a macro that is then put in Character.h UCLASS macro)
		Character_eventServerMove_Parms Parameters;

		// Extract from request data.
		{
			Parameters.TimeStamp = Op.Request.field_timestamp0();
		}
		{
			auto& ValueDataStr = Op.Request.field_inaccel0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.InAccel.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize10 failed."));
		}
		{
			auto& ValueDataStr = Op.Request.field_clientloc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.ClientLoc.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
		}
		{
			Parameters.CompressedMoveFlags = uint8(uint8(Op.Request.field_compressedmoveflags0()));
		}
		{
			Parameters.ClientRoll = uint8(uint8(Op.Request.field_clientroll0()));
		}
		{
			Parameters.View = Op.Request.field_view0();
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_clientmovementbase0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ClientMovementBase = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<UPrimitiveComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.ClientMovementBase = Cast<UPrimitiveComponent>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: ServerMove_OnRPCPayload: Parameters.ClientMovementBase %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.ClientBaseBoneName = FName((Op.Request.field_clientbasebonename0()).data());
		}
		{
			Parameters.ClientMovementMode = uint8(uint8(Op.Request.field_clientmovementmode0()));
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: ServerMove, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerMove"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: ServerMove_OnRPCPayload: Function not found. Object: %s, Function: ServerMove."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermove>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}

void USpatialTypeBinding_SampleGameCharacter::RootMotionDebugClientPrintOnScreen_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Rootmotiondebugclientprintonscreen>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("RootMotionDebugClientPrintOnScreen"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ClientVeryShortAdjustPosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientveryshortadjustposition>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientVeryShortAdjustPosition"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ClientCheatWalk_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientcheatwalk>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientCheatWalk"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ClientCheatGhost_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientcheatghost>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientCheatGhost"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ClientCheatFly_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientcheatfly>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientCheatFly"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ClientAdjustRootMotionSourcePosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientadjustrootmotionsourceposition>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientAdjustRootMotionSourcePosition"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ClientAdjustRootMotionPosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientadjustrootmotionposition>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientAdjustRootMotionPosition"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ClientAdjustPosition_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientadjustposition>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientAdjustPosition"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ClientAckGoodMove_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterClientRPCs::Commands::Clientackgoodmove>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientAckGoodMove"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ServerSpawnCube_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Serverspawncube>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerSpawnCube"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::DebugResetCharacter_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Debugresetcharacter>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("DebugResetCharacter"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ServerMoveOld_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermoveold>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerMoveOld"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ServerMoveNoBase_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovenobase>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerMoveNoBase"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ServerMoveDualNoBase_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovedualnobase>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerMoveDualNoBase"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ServerMoveDualHybridRootMotion_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovedualhybridrootmotion>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerMoveDualHybridRootMotion"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ServerMoveDual_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermovedual>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerMoveDual"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGameCharacter::ServerMove_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::samplegamecharacter::SampleGameCharacterServerRPCs::Commands::Servermove>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerMove"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}
