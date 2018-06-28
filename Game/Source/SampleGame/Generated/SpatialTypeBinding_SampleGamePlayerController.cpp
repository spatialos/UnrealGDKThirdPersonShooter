// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically

#include "SpatialTypeBinding_SampleGamePlayerController.h"

#include "GameFramework/PlayerState.h"
#include "NetworkGuid.h"

#include "SpatialOS.h"
#include "EntityBuilder.h"

#include "SpatialConstants.h"
#include "SpatialConditionMapFilter.h"
#include "SpatialUnrealObjectRef.h"
#include "SpatialActorChannel.h"
#include "SpatialPackageMapClient.h"
#include "SpatialNetDriver.h"
#include "SpatialInterop.h"
#include "SampleGamePlayerController.h"
#include "Camera/CameraAnim.h"
#include "Camera/CameraShake.h"
#include "GameFramework/HUD.h"
#include "GameFramework/LocalMessage.h"
#include "Particles/EmitterCameraLensEffectBase.h"

#include "UnrealSampleGamePlayerControllerSingleClientRepDataAddComponentOp.h"
#include "UnrealSampleGamePlayerControllerMultiClientRepDataAddComponentOp.h"
#include "UnrealSampleGamePlayerControllerMigratableDataAddComponentOp.h"

const FRepHandlePropertyMap& USpatialTypeBinding_SampleGamePlayerController::GetRepHandlePropertyMap() const
{
	return RepHandleToPropertyMap;
}

const FMigratableHandlePropertyMap& USpatialTypeBinding_SampleGamePlayerController::GetMigratableHandlePropertyMap() const
{
	return MigratableHandleToPropertyMap;
}

UClass* USpatialTypeBinding_SampleGamePlayerController::GetBoundClass() const
{
	return ASampleGamePlayerController::StaticClass();
}

void USpatialTypeBinding_SampleGamePlayerController::Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap)
{
	Super::Init(InInterop, InPackageMap);

	RPCToSenderMap.Emplace("ClientJoinResults", &USpatialTypeBinding_SampleGamePlayerController::ClientJoinResults_SendCommand);
	RPCToSenderMap.Emplace("OnServerStartedVisualLogger", &USpatialTypeBinding_SampleGamePlayerController::OnServerStartedVisualLogger_SendCommand);
	RPCToSenderMap.Emplace("ClientWasKicked", &USpatialTypeBinding_SampleGamePlayerController::ClientWasKicked_SendCommand);
	RPCToSenderMap.Emplace("ClientVoiceHandshakeComplete", &USpatialTypeBinding_SampleGamePlayerController::ClientVoiceHandshakeComplete_SendCommand);
	RPCToSenderMap.Emplace("ClientUpdateMultipleLevelsStreamingStatus", &USpatialTypeBinding_SampleGamePlayerController::ClientUpdateMultipleLevelsStreamingStatus_SendCommand);
	RPCToSenderMap.Emplace("ClientUpdateLevelStreamingStatus", &USpatialTypeBinding_SampleGamePlayerController::ClientUpdateLevelStreamingStatus_SendCommand);
	RPCToSenderMap.Emplace("ClientUnmutePlayer", &USpatialTypeBinding_SampleGamePlayerController::ClientUnmutePlayer_SendCommand);
	RPCToSenderMap.Emplace("ClientTravelInternal", &USpatialTypeBinding_SampleGamePlayerController::ClientTravelInternal_SendCommand);
	RPCToSenderMap.Emplace("ClientTeamMessage", &USpatialTypeBinding_SampleGamePlayerController::ClientTeamMessage_SendCommand);
	RPCToSenderMap.Emplace("ClientStopForceFeedback", &USpatialTypeBinding_SampleGamePlayerController::ClientStopForceFeedback_SendCommand);
	RPCToSenderMap.Emplace("ClientStopCameraShake", &USpatialTypeBinding_SampleGamePlayerController::ClientStopCameraShake_SendCommand);
	RPCToSenderMap.Emplace("ClientStopCameraAnim", &USpatialTypeBinding_SampleGamePlayerController::ClientStopCameraAnim_SendCommand);
	RPCToSenderMap.Emplace("ClientStartOnlineSession", &USpatialTypeBinding_SampleGamePlayerController::ClientStartOnlineSession_SendCommand);
	RPCToSenderMap.Emplace("ClientSpawnCameraLensEffect", &USpatialTypeBinding_SampleGamePlayerController::ClientSpawnCameraLensEffect_SendCommand);
	RPCToSenderMap.Emplace("ClientSetViewTarget", &USpatialTypeBinding_SampleGamePlayerController::ClientSetViewTarget_SendCommand);
	RPCToSenderMap.Emplace("ClientSetSpectatorWaiting", &USpatialTypeBinding_SampleGamePlayerController::ClientSetSpectatorWaiting_SendCommand);
	RPCToSenderMap.Emplace("ClientSetHUD", &USpatialTypeBinding_SampleGamePlayerController::ClientSetHUD_SendCommand);
	RPCToSenderMap.Emplace("ClientSetForceMipLevelsToBeResident", &USpatialTypeBinding_SampleGamePlayerController::ClientSetForceMipLevelsToBeResident_SendCommand);
	RPCToSenderMap.Emplace("ClientSetCinematicMode", &USpatialTypeBinding_SampleGamePlayerController::ClientSetCinematicMode_SendCommand);
	RPCToSenderMap.Emplace("ClientSetCameraMode", &USpatialTypeBinding_SampleGamePlayerController::ClientSetCameraMode_SendCommand);
	RPCToSenderMap.Emplace("ClientSetCameraFade", &USpatialTypeBinding_SampleGamePlayerController::ClientSetCameraFade_SendCommand);
	RPCToSenderMap.Emplace("ClientSetBlockOnAsyncLoading", &USpatialTypeBinding_SampleGamePlayerController::ClientSetBlockOnAsyncLoading_SendCommand);
	RPCToSenderMap.Emplace("ClientReturnToMainMenuWithTextReason", &USpatialTypeBinding_SampleGamePlayerController::ClientReturnToMainMenuWithTextReason_SendCommand);
	RPCToSenderMap.Emplace("ClientReturnToMainMenu", &USpatialTypeBinding_SampleGamePlayerController::ClientReturnToMainMenu_SendCommand);
	RPCToSenderMap.Emplace("ClientRetryClientRestart", &USpatialTypeBinding_SampleGamePlayerController::ClientRetryClientRestart_SendCommand);
	RPCToSenderMap.Emplace("ClientRestart", &USpatialTypeBinding_SampleGamePlayerController::ClientRestart_SendCommand);
	RPCToSenderMap.Emplace("ClientReset", &USpatialTypeBinding_SampleGamePlayerController::ClientReset_SendCommand);
	RPCToSenderMap.Emplace("ClientRepObjRef", &USpatialTypeBinding_SampleGamePlayerController::ClientRepObjRef_SendCommand);
	RPCToSenderMap.Emplace("ClientReceiveLocalizedMessage", &USpatialTypeBinding_SampleGamePlayerController::ClientReceiveLocalizedMessage_SendCommand);
	RPCToSenderMap.Emplace("ClientPrestreamTextures", &USpatialTypeBinding_SampleGamePlayerController::ClientPrestreamTextures_SendCommand);
	RPCToSenderMap.Emplace("ClientPrepareMapChange", &USpatialTypeBinding_SampleGamePlayerController::ClientPrepareMapChange_SendCommand);
	RPCToSenderMap.Emplace("ClientPlaySoundAtLocation", &USpatialTypeBinding_SampleGamePlayerController::ClientPlaySoundAtLocation_SendCommand);
	RPCToSenderMap.Emplace("ClientPlaySound", &USpatialTypeBinding_SampleGamePlayerController::ClientPlaySound_SendCommand);
	RPCToSenderMap.Emplace("ClientPlayForceFeedback", &USpatialTypeBinding_SampleGamePlayerController::ClientPlayForceFeedback_SendCommand);
	RPCToSenderMap.Emplace("ClientPlayCameraShake", &USpatialTypeBinding_SampleGamePlayerController::ClientPlayCameraShake_SendCommand);
	RPCToSenderMap.Emplace("ClientPlayCameraAnim", &USpatialTypeBinding_SampleGamePlayerController::ClientPlayCameraAnim_SendCommand);
	RPCToSenderMap.Emplace("ClientMutePlayer", &USpatialTypeBinding_SampleGamePlayerController::ClientMutePlayer_SendCommand);
	RPCToSenderMap.Emplace("ClientMessage", &USpatialTypeBinding_SampleGamePlayerController::ClientMessage_SendCommand);
	RPCToSenderMap.Emplace("ClientIgnoreMoveInput", &USpatialTypeBinding_SampleGamePlayerController::ClientIgnoreMoveInput_SendCommand);
	RPCToSenderMap.Emplace("ClientIgnoreLookInput", &USpatialTypeBinding_SampleGamePlayerController::ClientIgnoreLookInput_SendCommand);
	RPCToSenderMap.Emplace("ClientGotoState", &USpatialTypeBinding_SampleGamePlayerController::ClientGotoState_SendCommand);
	RPCToSenderMap.Emplace("ClientGameEnded", &USpatialTypeBinding_SampleGamePlayerController::ClientGameEnded_SendCommand);
	RPCToSenderMap.Emplace("ClientForceGarbageCollection", &USpatialTypeBinding_SampleGamePlayerController::ClientForceGarbageCollection_SendCommand);
	RPCToSenderMap.Emplace("ClientFlushLevelStreaming", &USpatialTypeBinding_SampleGamePlayerController::ClientFlushLevelStreaming_SendCommand);
	RPCToSenderMap.Emplace("ClientEndOnlineSession", &USpatialTypeBinding_SampleGamePlayerController::ClientEndOnlineSession_SendCommand);
	RPCToSenderMap.Emplace("ClientEnableNetworkVoice", &USpatialTypeBinding_SampleGamePlayerController::ClientEnableNetworkVoice_SendCommand);
	RPCToSenderMap.Emplace("ClientCommitMapChange", &USpatialTypeBinding_SampleGamePlayerController::ClientCommitMapChange_SendCommand);
	RPCToSenderMap.Emplace("ClientClearCameraLensEffects", &USpatialTypeBinding_SampleGamePlayerController::ClientClearCameraLensEffects_SendCommand);
	RPCToSenderMap.Emplace("ClientCapBandwidth", &USpatialTypeBinding_SampleGamePlayerController::ClientCapBandwidth_SendCommand);
	RPCToSenderMap.Emplace("ClientCancelPendingMapChange", &USpatialTypeBinding_SampleGamePlayerController::ClientCancelPendingMapChange_SendCommand);
	RPCToSenderMap.Emplace("ClientAddTextureStreamingLoc", &USpatialTypeBinding_SampleGamePlayerController::ClientAddTextureStreamingLoc_SendCommand);
	RPCToSenderMap.Emplace("ClientSetRotation", &USpatialTypeBinding_SampleGamePlayerController::ClientSetRotation_SendCommand);
	RPCToSenderMap.Emplace("ClientSetLocation", &USpatialTypeBinding_SampleGamePlayerController::ClientSetLocation_SendCommand);
	RPCToSenderMap.Emplace("ServerTryJoinGame", &USpatialTypeBinding_SampleGamePlayerController::ServerTryJoinGame_SendCommand);
	RPCToSenderMap.Emplace("ServerViewSelf", &USpatialTypeBinding_SampleGamePlayerController::ServerViewSelf_SendCommand);
	RPCToSenderMap.Emplace("ServerViewPrevPlayer", &USpatialTypeBinding_SampleGamePlayerController::ServerViewPrevPlayer_SendCommand);
	RPCToSenderMap.Emplace("ServerViewNextPlayer", &USpatialTypeBinding_SampleGamePlayerController::ServerViewNextPlayer_SendCommand);
	RPCToSenderMap.Emplace("ServerVerifyViewTarget", &USpatialTypeBinding_SampleGamePlayerController::ServerVerifyViewTarget_SendCommand);
	RPCToSenderMap.Emplace("ServerUpdateMultipleLevelsVisibility", &USpatialTypeBinding_SampleGamePlayerController::ServerUpdateMultipleLevelsVisibility_SendCommand);
	RPCToSenderMap.Emplace("ServerUpdateLevelVisibility", &USpatialTypeBinding_SampleGamePlayerController::ServerUpdateLevelVisibility_SendCommand);
	RPCToSenderMap.Emplace("ServerUpdateCamera", &USpatialTypeBinding_SampleGamePlayerController::ServerUpdateCamera_SendCommand);
	RPCToSenderMap.Emplace("ServerUnmutePlayer", &USpatialTypeBinding_SampleGamePlayerController::ServerUnmutePlayer_SendCommand);
	RPCToSenderMap.Emplace("ServerToggleAILogging", &USpatialTypeBinding_SampleGamePlayerController::ServerToggleAILogging_SendCommand);
	RPCToSenderMap.Emplace("ServerShortTimeout", &USpatialTypeBinding_SampleGamePlayerController::ServerShortTimeout_SendCommand);
	RPCToSenderMap.Emplace("ServerSetSpectatorWaiting", &USpatialTypeBinding_SampleGamePlayerController::ServerSetSpectatorWaiting_SendCommand);
	RPCToSenderMap.Emplace("ServerSetSpectatorLocation", &USpatialTypeBinding_SampleGamePlayerController::ServerSetSpectatorLocation_SendCommand);
	RPCToSenderMap.Emplace("ServerRestartPlayer", &USpatialTypeBinding_SampleGamePlayerController::ServerRestartPlayer_SendCommand);
	RPCToSenderMap.Emplace("ServerPause", &USpatialTypeBinding_SampleGamePlayerController::ServerPause_SendCommand);
	RPCToSenderMap.Emplace("ServerNotifyLoadedWorld", &USpatialTypeBinding_SampleGamePlayerController::ServerNotifyLoadedWorld_SendCommand);
	RPCToSenderMap.Emplace("ServerMutePlayer", &USpatialTypeBinding_SampleGamePlayerController::ServerMutePlayer_SendCommand);
	RPCToSenderMap.Emplace("ServerCheckClientPossessionReliable", &USpatialTypeBinding_SampleGamePlayerController::ServerCheckClientPossessionReliable_SendCommand);
	RPCToSenderMap.Emplace("ServerCheckClientPossession", &USpatialTypeBinding_SampleGamePlayerController::ServerCheckClientPossession_SendCommand);
	RPCToSenderMap.Emplace("ServerChangeName", &USpatialTypeBinding_SampleGamePlayerController::ServerChangeName_SendCommand);
	RPCToSenderMap.Emplace("ServerCamera", &USpatialTypeBinding_SampleGamePlayerController::ServerCamera_SendCommand);
	RPCToSenderMap.Emplace("ServerAcknowledgePossession", &USpatialTypeBinding_SampleGamePlayerController::ServerAcknowledgePossession_SendCommand);

	UClass* Class = FindObject<UClass>(ANY_PACKAGE, TEXT("SampleGamePlayerController"));

	// Populate RepHandleToPropertyMap.
	RepHandleToPropertyMap.Add(1, FRepHandleData(Class, {"bHidden"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(2, FRepHandleData(Class, {"bReplicateMovement"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(3, FRepHandleData(Class, {"bTearOff"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(4, FRepHandleData(Class, {"bCanBeDamaged"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(5, FRepHandleData(Class, {"RemoteRole"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(6, FRepHandleData(Class, {"ReplicatedMovement"}, COND_SimulatedOrPhysics, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(7, FRepHandleData(Class, {"AttachmentReplication", "AttachParent"}, COND_Custom, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(8, FRepHandleData(Class, {"AttachmentReplication", "LocationOffset"}, COND_Custom, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(9, FRepHandleData(Class, {"AttachmentReplication", "RelativeScale3D"}, COND_Custom, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(10, FRepHandleData(Class, {"AttachmentReplication", "RotationOffset"}, COND_Custom, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(11, FRepHandleData(Class, {"AttachmentReplication", "AttachSocket"}, COND_Custom, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(12, FRepHandleData(Class, {"AttachmentReplication", "AttachComponent"}, COND_Custom, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(13, FRepHandleData(Class, {"Owner"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(14, FRepHandleData(Class, {"Role"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(15, FRepHandleData(Class, {"Instigator"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(16, FRepHandleData(Class, {"PlayerState"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(17, FRepHandleData(Class, {"Pawn"}, COND_None, REPNOTIFY_Always, 0));
	RepHandleToPropertyMap.Add(18, FRepHandleData(Class, {"TargetViewRotation"}, COND_OwnerOnly, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(19, FRepHandleData(Class, {"SpawnLocation"}, COND_OwnerOnly, REPNOTIFY_OnChanged, 0));
}

void USpatialTypeBinding_SampleGamePlayerController::BindToView()
{
	TSharedPtr<worker::View> View = Interop->GetSpatialOS()->GetView().Pin();
	ViewCallbacks.Init(View);

	if (Interop->GetNetDriver()->GetNetMode() == NM_Client)
	{
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_SingleClient(ActorChannel, Op.Update);
		}));
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_MultiClient(ActorChannel, Op.Update);
		}));
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_Migratable(ActorChannel, Op.Update);
		}));
	}

	using ClientRPCCommandTypes = improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands;
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientjoinresults>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientJoinResults_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrolleronserverstartedvisuallogger>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::OnServerStartedVisualLogger_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientwaskicked>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientWasKicked_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientvoicehandshakecomplete>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientVoiceHandshakeComplete_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientupdatemultiplelevelsstreamingstatus>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientUpdateMultipleLevelsStreamingStatus_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientupdatelevelstreamingstatus>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientUpdateLevelStreamingStatus_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientunmuteplayer>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientUnmutePlayer_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclienttravelinternal>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientTravelInternal_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientteammessage>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientTeamMessage_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientstopforcefeedback>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientStopForceFeedback_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientstopcamerashake>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientStopCameraShake_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientstopcameraanim>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientStopCameraAnim_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientstartonlinesession>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientStartOnlineSession_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientspawncameralenseffect>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSpawnCameraLensEffect_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetviewtarget>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetViewTarget_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetspectatorwaiting>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetSpectatorWaiting_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientsethud>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetHUD_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetforcemiplevelstoberesident>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetForceMipLevelsToBeResident_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetcinematicmode>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetCinematicMode_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetcameramode>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetCameraMode_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetcamerafade>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetCameraFade_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetblockonasyncloading>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetBlockOnAsyncLoading_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientreturntomainmenuwithtextreason>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientReturnToMainMenuWithTextReason_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientreturntomainmenu>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientReturnToMainMenu_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientretryclientrestart>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientRetryClientRestart_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientrestart>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientRestart_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientreset>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientReset_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientrepobjref>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientRepObjRef_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientreceivelocalizedmessage>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientReceiveLocalizedMessage_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientprestreamtextures>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientPrestreamTextures_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientpreparemapchange>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientPrepareMapChange_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientplaysoundatlocation>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientPlaySoundAtLocation_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientplaysound>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientPlaySound_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientplayforcefeedback>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientPlayForceFeedback_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientplaycamerashake>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientPlayCameraShake_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientplaycameraanim>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientPlayCameraAnim_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientmuteplayer>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientMutePlayer_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientmessage>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientMessage_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientignoremoveinput>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientIgnoreMoveInput_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientignorelookinput>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientIgnoreLookInput_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientgotostate>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientGotoState_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientgameended>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientGameEnded_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientforcegarbagecollection>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientForceGarbageCollection_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientflushlevelstreaming>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientFlushLevelStreaming_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientendonlinesession>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientEndOnlineSession_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientenablenetworkvoice>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientEnableNetworkVoice_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientcommitmapchange>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientCommitMapChange_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientclearcameralenseffects>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientClearCameraLensEffects_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientcapbandwidth>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientCapBandwidth_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientcancelpendingmapchange>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientCancelPendingMapChange_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientaddtexturestreamingloc>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientAddTextureStreamingLoc_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetrotation>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetRotation_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetlocation>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetLocation_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientjoinresults>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientJoinResults_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrolleronserverstartedvisuallogger>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::OnServerStartedVisualLogger_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientwaskicked>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientWasKicked_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientvoicehandshakecomplete>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientVoiceHandshakeComplete_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientupdatemultiplelevelsstreamingstatus>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientUpdateMultipleLevelsStreamingStatus_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientupdatelevelstreamingstatus>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientUpdateLevelStreamingStatus_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientunmuteplayer>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientUnmutePlayer_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclienttravelinternal>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientTravelInternal_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientteammessage>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientTeamMessage_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientstopforcefeedback>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientStopForceFeedback_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientstopcamerashake>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientStopCameraShake_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientstopcameraanim>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientStopCameraAnim_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientstartonlinesession>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientStartOnlineSession_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientspawncameralenseffect>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSpawnCameraLensEffect_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetviewtarget>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetViewTarget_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetspectatorwaiting>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetSpectatorWaiting_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientsethud>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetHUD_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetforcemiplevelstoberesident>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetForceMipLevelsToBeResident_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetcinematicmode>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetCinematicMode_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetcameramode>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetCameraMode_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetcamerafade>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetCameraFade_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetblockonasyncloading>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetBlockOnAsyncLoading_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientreturntomainmenuwithtextreason>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientReturnToMainMenuWithTextReason_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientreturntomainmenu>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientReturnToMainMenu_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientretryclientrestart>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientRetryClientRestart_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientrestart>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientRestart_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientreset>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientReset_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientrepobjref>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientRepObjRef_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientreceivelocalizedmessage>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientReceiveLocalizedMessage_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientprestreamtextures>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientPrestreamTextures_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientpreparemapchange>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientPrepareMapChange_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientplaysoundatlocation>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientPlaySoundAtLocation_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientplaysound>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientPlaySound_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientplayforcefeedback>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientPlayForceFeedback_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientplaycamerashake>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientPlayCameraShake_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientplaycameraanim>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientPlayCameraAnim_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientmuteplayer>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientMutePlayer_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientmessage>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientMessage_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientignoremoveinput>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientIgnoreMoveInput_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientignorelookinput>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientIgnoreLookInput_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientgotostate>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientGotoState_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientgameended>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientGameEnded_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientforcegarbagecollection>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientForceGarbageCollection_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientflushlevelstreaming>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientFlushLevelStreaming_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientendonlinesession>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientEndOnlineSession_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientenablenetworkvoice>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientEnableNetworkVoice_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientcommitmapchange>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientCommitMapChange_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientclearcameralenseffects>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientClearCameraLensEffects_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientcapbandwidth>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientCapBandwidth_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientcancelpendingmapchange>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientCancelPendingMapChange_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientaddtexturestreamingloc>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientAddTextureStreamingLoc_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetrotation>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetRotation_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Samplegameplayercontrollerclientsetlocation>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ClientSetLocation_OnCommandResponse, this, std::placeholders::_1)));

	using ServerRPCCommandTypes = improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands;
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerservertryjoingame>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerTryJoinGame_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerserverviewself>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerViewSelf_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerserverviewprevplayer>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerViewPrevPlayer_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerserverviewnextplayer>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerViewNextPlayer_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerserververifyviewtarget>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerVerifyViewTarget_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerserverupdatemultiplelevelsvisibility>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerUpdateMultipleLevelsVisibility_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerserverupdatelevelvisibility>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerUpdateLevelVisibility_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerserverupdatecamera>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerUpdateCamera_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerserverunmuteplayer>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerUnmutePlayer_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerservertoggleailogging>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerToggleAILogging_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerservershorttimeout>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerShortTimeout_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerserversetspectatorwaiting>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerSetSpectatorWaiting_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerserversetspectatorlocation>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerSetSpectatorLocation_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerserverrestartplayer>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerRestartPlayer_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerserverpause>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerPause_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerservernotifyloadedworld>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerNotifyLoadedWorld_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerservermuteplayer>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerMutePlayer_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerservercheckclientpossessionreliable>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerCheckClientPossessionReliable_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerservercheckclientpossession>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerCheckClientPossession_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerserverchangename>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerChangeName_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerservercamera>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerCamera_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Samplegameplayercontrollerserveracknowledgepossession>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerAcknowledgePossession_OnCommandRequest, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerservertryjoingame>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerTryJoinGame_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerserverviewself>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerViewSelf_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerserverviewprevplayer>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerViewPrevPlayer_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerserverviewnextplayer>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerViewNextPlayer_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerserververifyviewtarget>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerVerifyViewTarget_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerserverupdatemultiplelevelsvisibility>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerUpdateMultipleLevelsVisibility_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerserverupdatelevelvisibility>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerUpdateLevelVisibility_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerserverupdatecamera>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerUpdateCamera_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerserverunmuteplayer>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerUnmutePlayer_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerservertoggleailogging>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerToggleAILogging_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerservershorttimeout>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerShortTimeout_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerserversetspectatorwaiting>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerSetSpectatorWaiting_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerserversetspectatorlocation>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerSetSpectatorLocation_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerserverrestartplayer>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerRestartPlayer_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerserverpause>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerPause_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerservernotifyloadedworld>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerNotifyLoadedWorld_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerservermuteplayer>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerMutePlayer_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerservercheckclientpossessionreliable>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerCheckClientPossessionReliable_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerservercheckclientpossession>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerCheckClientPossession_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerserverchangename>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerChangeName_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerservercamera>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerCamera_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Samplegameplayercontrollerserveracknowledgepossession>(std::bind(&USpatialTypeBinding_SampleGamePlayerController::ServerAcknowledgePossession_OnCommandResponse, this, std::placeholders::_1)));
}

void USpatialTypeBinding_SampleGamePlayerController::UnbindFromView()
{
	ViewCallbacks.Reset();
}

worker::Entity USpatialTypeBinding_SampleGamePlayerController::CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const
{
	// Validate replication list.
	const uint16 RepHandlePropertyMapCount = GetRepHandlePropertyMap().Num();
	for (auto& Rep : InitialChanges.RepChanged)
	{
		checkf(Rep <= RepHandlePropertyMapCount, TEXT("Attempting to replicate a property with a handle that the type binding is not aware of. Have additional replicated properties been added in a non generated child object?"))
	}

	// Setup initial data.
	improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData::Data SingleClientData;
	improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData::Update SingleClientUpdate;
	bool bSingleClientUpdateChanged = false;
	improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData::Data MultiClientData;
	improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData::Update MultiClientUpdate;
	bool bMultiClientUpdateChanged = false;
	improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData::Data MigratableData;
	improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData::Update MigratableDataUpdate;
	bool bMigratableDataUpdateChanged = false;
	BuildSpatialComponentUpdate(InitialChanges, Channel, SingleClientUpdate, bSingleClientUpdateChanged, MultiClientUpdate, bMultiClientUpdateChanged, MigratableDataUpdate, bMigratableDataUpdateChanged);
	SingleClientUpdate.ApplyTo(SingleClientData);
	MultiClientUpdate.ApplyTo(MultiClientData);
	MigratableDataUpdate.ApplyTo(MigratableData);

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
		.AddComponent<improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData>(SingleClientData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData>(MultiClientData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData>(MigratableData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs>(improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Data{}, OwningClientOnly)
		.AddComponent<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs>(improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Data{}, WorkersOnly)
		.Build();
}

void USpatialTypeBinding_SampleGamePlayerController::SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const FEntityId& EntityId) const
{
	// Build SpatialOS updates.
	improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData::Update SingleClientUpdate;
	bool bSingleClientUpdateChanged = false;
	improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData::Update MultiClientUpdate;
	bool bMultiClientUpdateChanged = false;
	improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData::Update MigratableDataUpdate;
	bool bMigratableDataUpdateChanged = false;
	BuildSpatialComponentUpdate(Changes, Channel, SingleClientUpdate, bSingleClientUpdateChanged, MultiClientUpdate, bMultiClientUpdateChanged, MigratableDataUpdate, bMigratableDataUpdateChanged);

	// Send SpatialOS updates if anything changed.
	TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
	if (bSingleClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData>(EntityId.ToSpatialEntityId(), SingleClientUpdate);
	}
	if (bMultiClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData>(EntityId.ToSpatialEntityId(), MultiClientUpdate);
	}
	if (bMigratableDataUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData>(EntityId.ToSpatialEntityId(), MigratableDataUpdate);
	}
}

void USpatialTypeBinding_SampleGamePlayerController::SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters)
{
	TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
	auto SenderFuncIterator = RPCToSenderMap.Find(Function->GetFName());
	if (SenderFuncIterator == nullptr)
	{
		UE_LOG(LogSpatialOSInterop, Error, TEXT("Sender for %s has not been registered with RPCToSenderMap."), *Function->GetFName().ToString());
		return;
	}
	checkf(*SenderFuncIterator, TEXT("Sender for %s has been registered as null."), *Function->GetFName().ToString());
	(this->*(*SenderFuncIterator))(Connection.Get(), Parameters, TargetObject);
}

void USpatialTypeBinding_SampleGamePlayerController::ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const
{
	auto* SingleClientAddOp = Cast<UUnrealSampleGamePlayerControllerSingleClientRepDataAddComponentOp>(AddComponentOp);
	if (SingleClientAddOp)
	{
		auto Update = improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData::Update::FromInitialData(*SingleClientAddOp->Data.data());
		ReceiveUpdate_SingleClient(Channel, Update);
	}
	auto* MultiClientAddOp = Cast<UUnrealSampleGamePlayerControllerMultiClientRepDataAddComponentOp>(AddComponentOp);
	if (MultiClientAddOp)
	{
		auto Update = improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData::Update::FromInitialData(*MultiClientAddOp->Data.data());
		ReceiveUpdate_MultiClient(Channel, Update);
	}
	auto* MigratableDataAddOp = Cast<UUnrealSampleGamePlayerControllerMigratableDataAddComponentOp>(AddComponentOp);
	if (MigratableDataAddOp)
	{
		auto Update = improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData::Update::FromInitialData(*MigratableDataAddOp->Data.data());
		ReceiveUpdate_Migratable(Channel, Update);
	}
}

worker::Map<worker::ComponentId, worker::InterestOverride> USpatialTypeBinding_SampleGamePlayerController::GetInterestOverrideMap(bool bIsClient, bool bAutonomousProxy) const
{
	worker::Map<worker::ComponentId, worker::InterestOverride> Interest;
	if (bIsClient)
	{
		if (!bAutonomousProxy)
		{
			Interest.emplace(improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData::ComponentId, worker::InterestOverride{false});
		}
		Interest.emplace(improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData::ComponentId, worker::InterestOverride{false});
	}
	return Interest;
}

void USpatialTypeBinding_SampleGamePlayerController::BuildSpatialComponentUpdate(
	const FPropertyChangeState& Changes,
	USpatialActorChannel* Channel,
	improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData::Update& SingleClientUpdate,
	bool& bSingleClientUpdateChanged,
	improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData::Update& MultiClientUpdate,
	bool& bMultiClientUpdateChanged,
	improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData::Update& MigratableDataUpdate,
	bool& bMigratableDataUpdateChanged) const
{
	const FRepHandlePropertyMap& RepPropertyMap = GetRepHandlePropertyMap();
	const FMigratableHandlePropertyMap& MigPropertyMap = GetMigratableHandlePropertyMap();
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
			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending property update. actor %s (%lld), property %s (handle %d)"),
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

	// Populate the migrated data component update from the migrated property changelist.
	for (uint16 ChangedHandle : Changes.MigChanged)
	{
		const FMigratableHandleData& PropertyMapData = MigPropertyMap[ChangedHandle];
		const uint8* Data = PropertyMapData.GetPropertyData(Changes.SourceData);
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending migratable property update. actor %s (%lld), property %s (handle %d)"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*Channel->Actor->GetName(),
			Channel->GetEntityId().ToSpatialEntityId(),
			*PropertyMapData.Property->GetName(),
			ChangedHandle);
		ServerSendUpdate_Migratable(Data, ChangedHandle, PropertyMapData.Property, Channel, MigratableDataUpdate);
		bMigratableDataUpdateChanged = true;
	}
}

void USpatialTypeBinding_SampleGamePlayerController::ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 18: // field_targetviewrotation
		{
			const FRotator& Value = *(reinterpret_cast<FRotator const*>(Data));

			OutUpdate.set_field_targetviewrotation(improbable::unreal::UnrealFRotator(Value.Yaw, Value.Pitch, Value.Roll));
			break;
		}
		case 19: // field_spawnlocation
		{
			const FVector& Value = *(reinterpret_cast<FVector const*>(Data));

			OutUpdate.set_field_spawnlocation(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
	default:
		checkf(false, TEXT("Unknown replication handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_SampleGamePlayerController::ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 1: // field_bhidden
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bhidden(Value);
			break;
		}
		case 2: // field_breplicatemovement
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_breplicatemovement(Value);
			break;
		}
		case 3: // field_btearoff
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_btearoff(Value);
			break;
		}
		case 4: // field_bcanbedamaged
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bcanbedamaged(Value);
			break;
		}
		case 5: // field_remoterole
		{
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(Data));

			OutUpdate.set_field_remoterole(uint32_t(Value));
			break;
		}
		case 6: // field_replicatedmovement
		{
			const FRepMovement& Value = *(reinterpret_cast<FRepMovement const*>(Data));

			{
				TArray<uint8> ValueData;
				FMemoryWriter ValueDataWriter(ValueData);
				bool Success;
				(const_cast<FRepMovement&>(Value)).NetSerialize(ValueDataWriter, PackageMap, Success);
				OutUpdate.set_field_replicatedmovement(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			break;
		}
		case 7: // field_attachmentreplication_attachparent
		{
			AActor* Value = *(reinterpret_cast<AActor* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 7);
				}
				else
				{
					OutUpdate.set_field_attachmentreplication_attachparent(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_attachmentreplication_attachparent(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 8: // field_attachmentreplication_locationoffset
		{
			const FVector_NetQuantize100& Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(Data));

			OutUpdate.set_field_attachmentreplication_locationoffset(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
		case 9: // field_attachmentreplication_relativescale3d
		{
			const FVector_NetQuantize100& Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(Data));

			OutUpdate.set_field_attachmentreplication_relativescale3d(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
		case 10: // field_attachmentreplication_rotationoffset
		{
			const FRotator& Value = *(reinterpret_cast<FRotator const*>(Data));

			OutUpdate.set_field_attachmentreplication_rotationoffset(improbable::unreal::UnrealFRotator(Value.Yaw, Value.Pitch, Value.Roll));
			break;
		}
		case 11: // field_attachmentreplication_attachsocket
		{
			FName Value = *(reinterpret_cast<FName const*>(Data));

			OutUpdate.set_field_attachmentreplication_attachsocket(TCHAR_TO_UTF8(*Value.ToString()));
			break;
		}
		case 12: // field_attachmentreplication_attachcomponent
		{
			USceneComponent* Value = *(reinterpret_cast<USceneComponent* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 12);
				}
				else
				{
					OutUpdate.set_field_attachmentreplication_attachcomponent(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_attachmentreplication_attachcomponent(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 13: // field_owner
		{
			AActor* Value = *(reinterpret_cast<AActor* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 13);
				}
				else
				{
					OutUpdate.set_field_owner(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_owner(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 14: // field_role
		{
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(Data));

			OutUpdate.set_field_role(uint32_t(Value));
			break;
		}
		case 15: // field_instigator
		{
			APawn* Value = *(reinterpret_cast<APawn* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 15);
				}
				else
				{
					OutUpdate.set_field_instigator(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_instigator(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 16: // field_playerstate
		{
			APlayerState* Value = *(reinterpret_cast<APlayerState* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 16);
				}
				else
				{
					OutUpdate.set_field_playerstate(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_playerstate(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 17: // field_pawn
		{
			APawn* Value = *(reinterpret_cast<APawn* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 17);
				}
				else
				{
					OutUpdate.set_field_pawn(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_pawn(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
	default:
		checkf(false, TEXT("Unknown replication handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_SampleGamePlayerController::ServerSendUpdate_Migratable(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData::Update& OutUpdate) const
{
}

void USpatialTypeBinding_SampleGamePlayerController::ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData::Update& Update) const
{
	Interop->PreReceiveSpatialUpdate(ActorChannel);
	TSet<UProperty*> RepNotifies;

	const bool bIsServer = Interop->GetNetDriver()->IsServer();
	const bool bAutonomousProxy = ActorChannel->IsClientAutonomousProxy(improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::ComponentId);
	const FRepHandlePropertyMap& HandleToPropertyMap = GetRepHandlePropertyMap();
	FSpatialConditionMapFilter ConditionMap(ActorChannel, bAutonomousProxy);

	if (!Update.field_targetviewrotation().empty())
	{
		// field_targetviewrotation
		uint16 Handle = 18;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FRotator Value = *(reinterpret_cast<FRotator const*>(PropertyData));

			{
				auto& Rotator = (*Update.field_targetviewrotation().data());
				Value.Yaw = Rotator.yaw();
				Value.Pitch = Rotator.pitch();
				Value.Roll = Rotator.roll();
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_spawnlocation().empty())
	{
		// field_spawnlocation
		uint16 Handle = 19;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FVector Value = *(reinterpret_cast<FVector const*>(PropertyData));

			{
				auto& Vector = (*Update.field_spawnlocation().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	Interop->PostReceiveSpatialUpdate(ActorChannel, RepNotifies.Array());
}

void USpatialTypeBinding_SampleGamePlayerController::ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData::Update& Update) const
{
	Interop->PreReceiveSpatialUpdate(ActorChannel);
	TSet<UProperty*> RepNotifies;

	const bool bIsServer = Interop->GetNetDriver()->IsServer();
	const bool bAutonomousProxy = ActorChannel->IsClientAutonomousProxy(improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::ComponentId);
	const FRepHandlePropertyMap& HandleToPropertyMap = GetRepHandlePropertyMap();
	FSpatialConditionMapFilter ConditionMap(ActorChannel, bAutonomousProxy);

	if (!Update.field_bhidden().empty())
	{
		// field_bhidden
		uint16 Handle = 1;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bhidden().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_breplicatemovement().empty())
	{
		// field_breplicatemovement
		uint16 Handle = 2;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_breplicatemovement().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_btearoff().empty())
	{
		// field_btearoff
		uint16 Handle = 3;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_btearoff().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_bcanbedamaged().empty())
	{
		// field_bcanbedamaged
		uint16 Handle = 4;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bcanbedamaged().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_remoterole().empty())
	{
		// field_remoterole
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

			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(PropertyData));

			Value = TEnumAsByte<ENetRole>(uint8((*Update.field_remoterole().data())));

			// Downgrade role from AutonomousProxy to SimulatedProxy if we aren't authoritative over
			// the server RPCs component.
			if (!bIsServer && Value == ROLE_AutonomousProxy && !bAutonomousProxy)
			{
				Value = ROLE_SimulatedProxy;
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedmovement().empty())
	{
		// field_replicatedmovement
		uint16 Handle = 6;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FRepMovement Value = *(reinterpret_cast<FRepMovement const*>(PropertyData));

			{
				auto& ValueDataStr = (*Update.field_replicatedmovement().data());
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FMemoryReader ValueDataReader(ValueData);
				bool bSuccess;
				Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication_attachparent().empty())
	{
		// field_attachmentreplication_attachparent
		uint16 Handle = 7;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			AActor* Value = *(reinterpret_cast<AActor* const*>(PropertyData));

			{
				improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_attachmentreplication_attachparent().data());
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
						Value = Cast<AActor>(Object_Raw);
						checkf(Value, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					}
					else
					{
						UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
							*Interop->GetSpatialOS()->GetWorkerId(),
							*ObjectRefToString(ObjectRef),
							*ActorChannel->Actor->GetName(),
							ActorChannel->GetEntityId().ToSpatialEntityId(),
							*RepData->Property->GetName(),
							Handle);
						bWriteObjectProperty = false;
						Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
					}
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_attachmentreplication_locationoffset().empty())
	{
		// field_attachmentreplication_locationoffset
		uint16 Handle = 8;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FVector_NetQuantize100 Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(PropertyData));

			{
				auto& Vector = (*Update.field_attachmentreplication_locationoffset().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication_relativescale3d().empty())
	{
		// field_attachmentreplication_relativescale3d
		uint16 Handle = 9;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FVector_NetQuantize100 Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(PropertyData));

			{
				auto& Vector = (*Update.field_attachmentreplication_relativescale3d().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication_rotationoffset().empty())
	{
		// field_attachmentreplication_rotationoffset
		uint16 Handle = 10;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FRotator Value = *(reinterpret_cast<FRotator const*>(PropertyData));

			{
				auto& Rotator = (*Update.field_attachmentreplication_rotationoffset().data());
				Value.Yaw = Rotator.yaw();
				Value.Pitch = Rotator.pitch();
				Value.Roll = Rotator.roll();
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication_attachsocket().empty())
	{
		// field_attachmentreplication_attachsocket
		uint16 Handle = 11;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FName Value = *(reinterpret_cast<FName const*>(PropertyData));

			Value = FName(((*Update.field_attachmentreplication_attachsocket().data())).data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication_attachcomponent().empty())
	{
		// field_attachmentreplication_attachcomponent
		uint16 Handle = 12;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			USceneComponent* Value = *(reinterpret_cast<USceneComponent* const*>(PropertyData));

			{
				improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_attachmentreplication_attachcomponent().data());
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
						Value = Cast<USceneComponent>(Object_Raw);
						checkf(Value, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					}
					else
					{
						UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
							*Interop->GetSpatialOS()->GetWorkerId(),
							*ObjectRefToString(ObjectRef),
							*ActorChannel->Actor->GetName(),
							ActorChannel->GetEntityId().ToSpatialEntityId(),
							*RepData->Property->GetName(),
							Handle);
						bWriteObjectProperty = false;
						Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
					}
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_owner().empty())
	{
		// field_owner
		uint16 Handle = 13;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			AActor* Value = *(reinterpret_cast<AActor* const*>(PropertyData));

			{
				improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_owner().data());
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
						Value = Cast<AActor>(Object_Raw);
						checkf(Value, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					}
					else
					{
						UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
							*Interop->GetSpatialOS()->GetWorkerId(),
							*ObjectRefToString(ObjectRef),
							*ActorChannel->Actor->GetName(),
							ActorChannel->GetEntityId().ToSpatialEntityId(),
							*RepData->Property->GetName(),
							Handle);
						bWriteObjectProperty = false;
						Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
					}
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_role().empty())
	{
		// field_role
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

			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(PropertyData));

			Value = TEnumAsByte<ENetRole>(uint8((*Update.field_role().data())));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_instigator().empty())
	{
		// field_instigator
		uint16 Handle = 15;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			APawn* Value = *(reinterpret_cast<APawn* const*>(PropertyData));

			{
				improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_instigator().data());
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
						Value = Cast<APawn>(Object_Raw);
						checkf(Value, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					}
					else
					{
						UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
							*Interop->GetSpatialOS()->GetWorkerId(),
							*ObjectRefToString(ObjectRef),
							*ActorChannel->Actor->GetName(),
							ActorChannel->GetEntityId().ToSpatialEntityId(),
							*RepData->Property->GetName(),
							Handle);
						bWriteObjectProperty = false;
						Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
					}
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_playerstate().empty())
	{
		// field_playerstate
		uint16 Handle = 16;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			APlayerState* Value = *(reinterpret_cast<APlayerState* const*>(PropertyData));

			{
				improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_playerstate().data());
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
						Value = Cast<APlayerState>(Object_Raw);
						checkf(Value, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					}
					else
					{
						UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
							*Interop->GetSpatialOS()->GetWorkerId(),
							*ObjectRefToString(ObjectRef),
							*ActorChannel->Actor->GetName(),
							ActorChannel->GetEntityId().ToSpatialEntityId(),
							*RepData->Property->GetName(),
							Handle);
						bWriteObjectProperty = false;
						Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
					}
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_pawn().empty())
	{
		// field_pawn
		uint16 Handle = 17;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			APawn* Value = *(reinterpret_cast<APawn* const*>(PropertyData));

			{
				improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_pawn().data());
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
						Value = Cast<APawn>(Object_Raw);
						checkf(Value, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					}
					else
					{
						UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
							*Interop->GetSpatialOS()->GetWorkerId(),
							*ObjectRefToString(ObjectRef),
							*ActorChannel->Actor->GetName(),
							ActorChannel->GetEntityId().ToSpatialEntityId(),
							*RepData->Property->GetName(),
							Handle);
						bWriteObjectProperty = false;
						Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
					}
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	Interop->PostReceiveSpatialUpdate(ActorChannel, RepNotifies.Array());
}

void USpatialTypeBinding_SampleGamePlayerController::ReceiveUpdate_Migratable(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData::Update& Update) const
{
}

void USpatialTypeBinding_SampleGamePlayerController::ClientJoinResults_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in SampleGamePlayerController.generated.h (in a macro that is then put in SampleGamePlayerController.h UCLASS macro)
	SampleGamePlayerController_eventClientJoinResults_Parms StructuredParams = *static_cast<SampleGamePlayerController_eventClientJoinResults_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientJoinResults queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientJoinResultsRequest Request;
		Request.set_field_bjoinsucceeded(StructuredParams.bJoinSucceeded);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientJoinResults, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientjoinresults>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::OnServerStartedVisualLogger_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventOnServerStartedVisualLogger_Parms StructuredParams = *static_cast<PlayerController_eventOnServerStartedVisualLogger_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC OnServerStartedVisualLogger queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealOnServerStartedVisualLoggerRequest Request;
		Request.set_field_bislogging(StructuredParams.bIsLogging);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: OnServerStartedVisualLogger, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrolleronserverstartedvisuallogger>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientWasKicked_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientWasKicked_Parms StructuredParams = *static_cast<PlayerController_eventClientWasKicked_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientWasKicked queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientWasKickedRequest Request;
		// UNSUPPORTED UTextProperty (unhandled) Request.set_field_kickreason(StructuredParams.KickReason)

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientWasKicked, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientwaskicked>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientVoiceHandshakeComplete_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientVoiceHandshakeComplete queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientVoiceHandshakeCompleteRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientVoiceHandshakeComplete, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientvoicehandshakecomplete>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientUpdateMultipleLevelsStreamingStatus_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientUpdateMultipleLevelsStreamingStatus_Parms StructuredParams = *static_cast<PlayerController_eventClientUpdateMultipleLevelsStreamingStatus_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientUpdateMultipleLevelsStreamingStatus queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientUpdateMultipleLevelsStreamingStatusRequest Request;
		{
			::worker::List<std::string> List;
			for(int i = 0; i < StructuredParams.LevelStatuses.Num(); i++)
			{
				TArray<uint8> ValueData;
				FMemoryWriter ValueDataWriter(ValueData);
				FUpdateLevelStreamingLevelStatus::StaticStruct()->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FUpdateLevelStreamingLevelStatus*>(&StructuredParams.LevelStatuses[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			Request.set_field_levelstatuses(List);
		}

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientUpdateMultipleLevelsStreamingStatus, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientupdatemultiplelevelsstreamingstatus>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientUpdateLevelStreamingStatus_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientUpdateLevelStreamingStatus_Parms StructuredParams = *static_cast<PlayerController_eventClientUpdateLevelStreamingStatus_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientUpdateLevelStreamingStatus queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientUpdateLevelStreamingStatusRequest Request;
		Request.set_field_packagename(TCHAR_TO_UTF8(*StructuredParams.PackageName.ToString()));
		Request.set_field_bnewshouldbeloaded(StructuredParams.bNewShouldBeLoaded);
		Request.set_field_bnewshouldbevisible(StructuredParams.bNewShouldBeVisible);
		Request.set_field_bnewshouldblockonload(StructuredParams.bNewShouldBlockOnLoad);
		Request.set_field_lodindex(int32_t(StructuredParams.LODIndex));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientUpdateLevelStreamingStatus, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientupdatelevelstreamingstatus>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientUnmutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientUnmutePlayer_Parms StructuredParams = *static_cast<PlayerController_eventClientUnmutePlayer_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientUnmutePlayer queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientUnmutePlayerRequest Request;
		{
			TArray<uint8> ValueData;
			FMemoryWriter ValueDataWriter(ValueData);
			bool Success;
			(const_cast<FUniqueNetIdRepl&>(StructuredParams.PlayerId)).NetSerialize(ValueDataWriter, PackageMap, Success);
			Request.set_field_playerid(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientUnmutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientunmuteplayer>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientTravelInternal_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientTravelInternal_Parms StructuredParams = *static_cast<PlayerController_eventClientTravelInternal_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientTravelInternal queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientTravelInternalRequest Request;
		Request.set_field_url(TCHAR_TO_UTF8(*StructuredParams.URL));
		Request.set_field_traveltype(uint32_t(StructuredParams.TravelType));
		Request.set_field_bseamless(StructuredParams.bSeamless);
		Request.set_field_mappackageguid_a(int32_t(StructuredParams.MapPackageGuid.A));
		Request.set_field_mappackageguid_b(int32_t(StructuredParams.MapPackageGuid.B));
		Request.set_field_mappackageguid_c(int32_t(StructuredParams.MapPackageGuid.C));
		Request.set_field_mappackageguid_d(int32_t(StructuredParams.MapPackageGuid.D));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientTravelInternal, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclienttravelinternal>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientTeamMessage_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientTeamMessage_Parms StructuredParams = *static_cast<PlayerController_eventClientTeamMessage_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientTeamMessage queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientTeamMessageRequest Request;
		if (StructuredParams.SenderPlayerState != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.SenderPlayerState);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientTeamMessage queued. StructuredParams.SenderPlayerState is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.SenderPlayerState};
			}
			else
			{
				Request.set_field_senderplayerstate(ObjectRef);
			}
		}
		else
		{
			Request.set_field_senderplayerstate(SpatialConstants::NULL_OBJECT_REF);
		}
		Request.set_field_s(TCHAR_TO_UTF8(*StructuredParams.S));
		Request.set_field_type(TCHAR_TO_UTF8(*StructuredParams.Type.ToString()));
		Request.set_field_msglifetime(StructuredParams.MsgLifeTime);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientTeamMessage, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientteammessage>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientStopForceFeedback_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientStopForceFeedback_Parms StructuredParams = *static_cast<PlayerController_eventClientStopForceFeedback_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientStopForceFeedback queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientStopForceFeedbackRequest Request;
		if (StructuredParams.ForceFeedbackEffect != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ForceFeedbackEffect);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientStopForceFeedback queued. StructuredParams.ForceFeedbackEffect is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.ForceFeedbackEffect};
			}
			else
			{
				Request.set_field_forcefeedbackeffect(ObjectRef);
			}
		}
		else
		{
			Request.set_field_forcefeedbackeffect(SpatialConstants::NULL_OBJECT_REF);
		}
		Request.set_field_tag(TCHAR_TO_UTF8(*StructuredParams.Tag.ToString()));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientStopForceFeedback, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopforcefeedback>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientStopCameraShake_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientStopCameraShake_Parms StructuredParams = *static_cast<PlayerController_eventClientStopCameraShake_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientStopCameraShake queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientStopCameraShakeRequest Request;
		Request.set_field_shake(PackageMap->GetHashFromStaticClass(StructuredParams.Shake));
		Request.set_field_bimmediately(StructuredParams.bImmediately);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientStopCameraShake, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopcamerashake>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientStopCameraAnim_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientStopCameraAnim_Parms StructuredParams = *static_cast<PlayerController_eventClientStopCameraAnim_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientStopCameraAnim queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientStopCameraAnimRequest Request;
		if (StructuredParams.AnimToStop != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.AnimToStop);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientStopCameraAnim queued. StructuredParams.AnimToStop is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.AnimToStop};
			}
			else
			{
				Request.set_field_animtostop(ObjectRef);
			}
		}
		else
		{
			Request.set_field_animtostop(SpatialConstants::NULL_OBJECT_REF);
		}

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientStopCameraAnim, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopcameraanim>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientStartOnlineSession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientStartOnlineSession queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientStartOnlineSessionRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientStartOnlineSession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstartonlinesession>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSpawnCameraLensEffect_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSpawnCameraLensEffect_Parms StructuredParams = *static_cast<PlayerController_eventClientSpawnCameraLensEffect_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSpawnCameraLensEffect queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSpawnCameraLensEffectRequest Request;
		Request.set_field_lenseffectemitterclass(PackageMap->GetHashFromStaticClass(StructuredParams.LensEffectEmitterClass));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSpawnCameraLensEffect, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientspawncameralenseffect>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetViewTarget_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSetViewTarget_Parms StructuredParams = *static_cast<PlayerController_eventClientSetViewTarget_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetViewTarget queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetViewTargetRequest Request;
		if (StructuredParams.A != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.A);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetViewTarget queued. StructuredParams.A is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.A};
			}
			else
			{
				Request.set_field_a(ObjectRef);
			}
		}
		else
		{
			Request.set_field_a(SpatialConstants::NULL_OBJECT_REF);
		}
		Request.set_field_transitionparams_blendtime(StructuredParams.TransitionParams.BlendTime);
		Request.set_field_transitionparams_blendfunction(uint32_t(StructuredParams.TransitionParams.BlendFunction));
		Request.set_field_transitionparams_blendexp(StructuredParams.TransitionParams.BlendExp);
		Request.set_field_transitionparams_blockoutgoing(StructuredParams.TransitionParams.bLockOutgoing);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetViewTarget, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetviewtarget>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetSpectatorWaiting_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSetSpectatorWaiting_Parms StructuredParams = *static_cast<PlayerController_eventClientSetSpectatorWaiting_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetSpectatorWaiting queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetSpectatorWaitingRequest Request;
		Request.set_field_bwaiting(StructuredParams.bWaiting);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetSpectatorWaiting, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetspectatorwaiting>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetHUD_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSetHUD_Parms StructuredParams = *static_cast<PlayerController_eventClientSetHUD_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetHUD queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetHUDRequest Request;
		Request.set_field_newhudclass(PackageMap->GetHashFromStaticClass(StructuredParams.NewHUDClass));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetHUD, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsethud>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetForceMipLevelsToBeResident_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSetForceMipLevelsToBeResident_Parms StructuredParams = *static_cast<PlayerController_eventClientSetForceMipLevelsToBeResident_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetForceMipLevelsToBeResident queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetForceMipLevelsToBeResidentRequest Request;
		if (StructuredParams.Material != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.Material);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetForceMipLevelsToBeResident queued. StructuredParams.Material is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.Material};
			}
			else
			{
				Request.set_field_material(ObjectRef);
			}
		}
		else
		{
			Request.set_field_material(SpatialConstants::NULL_OBJECT_REF);
		}
		Request.set_field_forceduration(StructuredParams.ForceDuration);
		Request.set_field_cinematictexturegroups(int32_t(StructuredParams.CinematicTextureGroups));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetForceMipLevelsToBeResident, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetforcemiplevelstoberesident>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetCinematicMode_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSetCinematicMode_Parms StructuredParams = *static_cast<PlayerController_eventClientSetCinematicMode_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetCinematicMode queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetCinematicModeRequest Request;
		Request.set_field_bincinematicmode(StructuredParams.bInCinematicMode);
		Request.set_field_baffectsmovement(StructuredParams.bAffectsMovement);
		Request.set_field_baffectsturning(StructuredParams.bAffectsTurning);
		Request.set_field_baffectshud(StructuredParams.bAffectsHUD);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetCinematicMode, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcinematicmode>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetCameraMode_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSetCameraMode_Parms StructuredParams = *static_cast<PlayerController_eventClientSetCameraMode_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetCameraMode queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetCameraModeRequest Request;
		Request.set_field_newcammode(TCHAR_TO_UTF8(*StructuredParams.NewCamMode.ToString()));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetCameraMode, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcameramode>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetCameraFade_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSetCameraFade_Parms StructuredParams = *static_cast<PlayerController_eventClientSetCameraFade_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetCameraFade queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetCameraFadeRequest Request;
		Request.set_field_benablefading(StructuredParams.bEnableFading);
		Request.set_field_fadecolor_b(uint32_t(StructuredParams.FadeColor.B));
		Request.set_field_fadecolor_g(uint32_t(StructuredParams.FadeColor.G));
		Request.set_field_fadecolor_r(uint32_t(StructuredParams.FadeColor.R));
		Request.set_field_fadecolor_a(uint32_t(StructuredParams.FadeColor.A));
		Request.set_field_fadealpha_x(StructuredParams.FadeAlpha.X);
		Request.set_field_fadealpha_y(StructuredParams.FadeAlpha.Y);
		Request.set_field_fadetime(StructuredParams.FadeTime);
		Request.set_field_bfadeaudio(StructuredParams.bFadeAudio);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetCameraFade, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcamerafade>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetBlockOnAsyncLoading_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetBlockOnAsyncLoading queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetBlockOnAsyncLoadingRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetBlockOnAsyncLoading, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetblockonasyncloading>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientReturnToMainMenuWithTextReason_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientReturnToMainMenuWithTextReason_Parms StructuredParams = *static_cast<PlayerController_eventClientReturnToMainMenuWithTextReason_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientReturnToMainMenuWithTextReason queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientReturnToMainMenuWithTextReasonRequest Request;
		// UNSUPPORTED UTextProperty (unhandled) Request.set_field_returnreason(StructuredParams.ReturnReason)

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientReturnToMainMenuWithTextReason, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreturntomainmenuwithtextreason>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientReturnToMainMenu_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientReturnToMainMenu_Parms StructuredParams = *static_cast<PlayerController_eventClientReturnToMainMenu_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientReturnToMainMenu queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientReturnToMainMenuRequest Request;
		Request.set_field_returnreason(TCHAR_TO_UTF8(*StructuredParams.ReturnReason));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientReturnToMainMenu, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreturntomainmenu>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientRetryClientRestart_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientRetryClientRestart_Parms StructuredParams = *static_cast<PlayerController_eventClientRetryClientRestart_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientRetryClientRestart queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientRetryClientRestartRequest Request;
		if (StructuredParams.NewPawn != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.NewPawn);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientRetryClientRestart queued. StructuredParams.NewPawn is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.NewPawn};
			}
			else
			{
				Request.set_field_newpawn(ObjectRef);
			}
		}
		else
		{
			Request.set_field_newpawn(SpatialConstants::NULL_OBJECT_REF);
		}

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientRetryClientRestart, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientretryclientrestart>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientRestart_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientRestart_Parms StructuredParams = *static_cast<PlayerController_eventClientRestart_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientRestart queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientRestartRequest Request;
		if (StructuredParams.NewPawn != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.NewPawn);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientRestart queued. StructuredParams.NewPawn is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.NewPawn};
			}
			else
			{
				Request.set_field_newpawn(ObjectRef);
			}
		}
		else
		{
			Request.set_field_newpawn(SpatialConstants::NULL_OBJECT_REF);
		}

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientRestart, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientrestart>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientReset_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientReset queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientResetRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientReset, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreset>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientRepObjRef_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientRepObjRef_Parms StructuredParams = *static_cast<PlayerController_eventClientRepObjRef_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientRepObjRef queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientRepObjRefRequest Request;
		if (StructuredParams.Object != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.Object);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientRepObjRef queued. StructuredParams.Object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.Object};
			}
			else
			{
				Request.set_field_object(ObjectRef);
			}
		}
		else
		{
			Request.set_field_object(SpatialConstants::NULL_OBJECT_REF);
		}

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientRepObjRef, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientrepobjref>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientReceiveLocalizedMessage_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientReceiveLocalizedMessage_Parms StructuredParams = *static_cast<PlayerController_eventClientReceiveLocalizedMessage_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientReceiveLocalizedMessage queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientReceiveLocalizedMessageRequest Request;
		Request.set_field_message(PackageMap->GetHashFromStaticClass(StructuredParams.Message));
		Request.set_field_switch(int32_t(StructuredParams.Switch));
		if (StructuredParams.RelatedPlayerState_1 != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.RelatedPlayerState_1);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientReceiveLocalizedMessage queued. StructuredParams.RelatedPlayerState_1 is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.RelatedPlayerState_1};
			}
			else
			{
				Request.set_field_relatedplayerstate1(ObjectRef);
			}
		}
		else
		{
			Request.set_field_relatedplayerstate1(SpatialConstants::NULL_OBJECT_REF);
		}
		if (StructuredParams.RelatedPlayerState_2 != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.RelatedPlayerState_2);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientReceiveLocalizedMessage queued. StructuredParams.RelatedPlayerState_2 is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.RelatedPlayerState_2};
			}
			else
			{
				Request.set_field_relatedplayerstate2(ObjectRef);
			}
		}
		else
		{
			Request.set_field_relatedplayerstate2(SpatialConstants::NULL_OBJECT_REF);
		}
		if (StructuredParams.OptionalObject != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.OptionalObject);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientReceiveLocalizedMessage queued. StructuredParams.OptionalObject is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.OptionalObject};
			}
			else
			{
				Request.set_field_optionalobject(ObjectRef);
			}
		}
		else
		{
			Request.set_field_optionalobject(SpatialConstants::NULL_OBJECT_REF);
		}

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientReceiveLocalizedMessage, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreceivelocalizedmessage>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPrestreamTextures_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientPrestreamTextures_Parms StructuredParams = *static_cast<PlayerController_eventClientPrestreamTextures_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPrestreamTextures queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientPrestreamTexturesRequest Request;
		if (StructuredParams.ForcedActor != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ForcedActor);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPrestreamTextures queued. StructuredParams.ForcedActor is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.ForcedActor};
			}
			else
			{
				Request.set_field_forcedactor(ObjectRef);
			}
		}
		else
		{
			Request.set_field_forcedactor(SpatialConstants::NULL_OBJECT_REF);
		}
		Request.set_field_forceduration(StructuredParams.ForceDuration);
		Request.set_field_benablestreaming(StructuredParams.bEnableStreaming);
		Request.set_field_cinematictexturegroups(int32_t(StructuredParams.CinematicTextureGroups));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientPrestreamTextures, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientprestreamtextures>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPrepareMapChange_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientPrepareMapChange_Parms StructuredParams = *static_cast<PlayerController_eventClientPrepareMapChange_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPrepareMapChange queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientPrepareMapChangeRequest Request;
		Request.set_field_levelname(TCHAR_TO_UTF8(*StructuredParams.LevelName.ToString()));
		Request.set_field_bfirst(StructuredParams.bFirst);
		Request.set_field_blast(StructuredParams.bLast);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientPrepareMapChange, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientpreparemapchange>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlaySoundAtLocation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientPlaySoundAtLocation_Parms StructuredParams = *static_cast<PlayerController_eventClientPlaySoundAtLocation_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlaySoundAtLocation queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientPlaySoundAtLocationRequest Request;
		if (StructuredParams.Sound != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.Sound);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlaySoundAtLocation queued. StructuredParams.Sound is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.Sound};
			}
			else
			{
				Request.set_field_sound(ObjectRef);
			}
		}
		else
		{
			Request.set_field_sound(SpatialConstants::NULL_OBJECT_REF);
		}
		Request.set_field_location(improbable::Vector3f(StructuredParams.Location.X, StructuredParams.Location.Y, StructuredParams.Location.Z));
		Request.set_field_volumemultiplier(StructuredParams.VolumeMultiplier);
		Request.set_field_pitchmultiplier(StructuredParams.PitchMultiplier);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientPlaySoundAtLocation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaysoundatlocation>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlaySound_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientPlaySound_Parms StructuredParams = *static_cast<PlayerController_eventClientPlaySound_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlaySound queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientPlaySoundRequest Request;
		if (StructuredParams.Sound != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.Sound);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlaySound queued. StructuredParams.Sound is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.Sound};
			}
			else
			{
				Request.set_field_sound(ObjectRef);
			}
		}
		else
		{
			Request.set_field_sound(SpatialConstants::NULL_OBJECT_REF);
		}
		Request.set_field_volumemultiplier(StructuredParams.VolumeMultiplier);
		Request.set_field_pitchmultiplier(StructuredParams.PitchMultiplier);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientPlaySound, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaysound>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlayForceFeedback_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientPlayForceFeedback_Parms StructuredParams = *static_cast<PlayerController_eventClientPlayForceFeedback_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlayForceFeedback queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientPlayForceFeedbackRequest Request;
		if (StructuredParams.ForceFeedbackEffect != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ForceFeedbackEffect);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlayForceFeedback queued. StructuredParams.ForceFeedbackEffect is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.ForceFeedbackEffect};
			}
			else
			{
				Request.set_field_forcefeedbackeffect(ObjectRef);
			}
		}
		else
		{
			Request.set_field_forcefeedbackeffect(SpatialConstants::NULL_OBJECT_REF);
		}
		Request.set_field_blooping(StructuredParams.bLooping);
		Request.set_field_bignoretimedilation(StructuredParams.bIgnoreTimeDilation);
		Request.set_field_tag(TCHAR_TO_UTF8(*StructuredParams.Tag.ToString()));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientPlayForceFeedback, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplayforcefeedback>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlayCameraShake_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientPlayCameraShake_Parms StructuredParams = *static_cast<PlayerController_eventClientPlayCameraShake_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlayCameraShake queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientPlayCameraShakeRequest Request;
		Request.set_field_shake(PackageMap->GetHashFromStaticClass(StructuredParams.Shake));
		Request.set_field_scale(StructuredParams.Scale);
		Request.set_field_playspace(uint32_t(StructuredParams.PlaySpace));
		Request.set_field_userplayspacerot(improbable::unreal::UnrealFRotator(StructuredParams.UserPlaySpaceRot.Yaw, StructuredParams.UserPlaySpaceRot.Pitch, StructuredParams.UserPlaySpaceRot.Roll));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientPlayCameraShake, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaycamerashake>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlayCameraAnim_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientPlayCameraAnim_Parms StructuredParams = *static_cast<PlayerController_eventClientPlayCameraAnim_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlayCameraAnim queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientPlayCameraAnimRequest Request;
		if (StructuredParams.AnimToPlay != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.AnimToPlay);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlayCameraAnim queued. StructuredParams.AnimToPlay is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.AnimToPlay};
			}
			else
			{
				Request.set_field_animtoplay(ObjectRef);
			}
		}
		else
		{
			Request.set_field_animtoplay(SpatialConstants::NULL_OBJECT_REF);
		}
		Request.set_field_scale(StructuredParams.Scale);
		Request.set_field_rate(StructuredParams.Rate);
		Request.set_field_blendintime(StructuredParams.BlendInTime);
		Request.set_field_blendouttime(StructuredParams.BlendOutTime);
		Request.set_field_bloop(StructuredParams.bLoop);
		Request.set_field_brandomstarttime(StructuredParams.bRandomStartTime);
		Request.set_field_space(uint32_t(StructuredParams.Space));
		Request.set_field_customplayspace(improbable::unreal::UnrealFRotator(StructuredParams.CustomPlaySpace.Yaw, StructuredParams.CustomPlaySpace.Pitch, StructuredParams.CustomPlaySpace.Roll));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientPlayCameraAnim, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaycameraanim>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientMutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientMutePlayer_Parms StructuredParams = *static_cast<PlayerController_eventClientMutePlayer_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientMutePlayer queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientMutePlayerRequest Request;
		{
			TArray<uint8> ValueData;
			FMemoryWriter ValueDataWriter(ValueData);
			bool Success;
			(const_cast<FUniqueNetIdRepl&>(StructuredParams.PlayerId)).NetSerialize(ValueDataWriter, PackageMap, Success);
			Request.set_field_playerid(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientMutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientmuteplayer>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientMessage_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientMessage_Parms StructuredParams = *static_cast<PlayerController_eventClientMessage_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientMessage queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientMessageRequest Request;
		Request.set_field_s(TCHAR_TO_UTF8(*StructuredParams.S));
		Request.set_field_type(TCHAR_TO_UTF8(*StructuredParams.Type.ToString()));
		Request.set_field_msglifetime(StructuredParams.MsgLifeTime);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientMessage, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientmessage>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientIgnoreMoveInput_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientIgnoreMoveInput_Parms StructuredParams = *static_cast<PlayerController_eventClientIgnoreMoveInput_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientIgnoreMoveInput queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientIgnoreMoveInputRequest Request;
		Request.set_field_bignore(StructuredParams.bIgnore);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientIgnoreMoveInput, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientignoremoveinput>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientIgnoreLookInput_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientIgnoreLookInput_Parms StructuredParams = *static_cast<PlayerController_eventClientIgnoreLookInput_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientIgnoreLookInput queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientIgnoreLookInputRequest Request;
		Request.set_field_bignore(StructuredParams.bIgnore);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientIgnoreLookInput, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientignorelookinput>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientGotoState_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientGotoState_Parms StructuredParams = *static_cast<PlayerController_eventClientGotoState_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientGotoState queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientGotoStateRequest Request;
		Request.set_field_newstate(TCHAR_TO_UTF8(*StructuredParams.NewState.ToString()));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientGotoState, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientgotostate>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientGameEnded_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientGameEnded_Parms StructuredParams = *static_cast<PlayerController_eventClientGameEnded_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientGameEnded queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientGameEndedRequest Request;
		if (StructuredParams.EndGameFocus != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.EndGameFocus);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientGameEnded queued. StructuredParams.EndGameFocus is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.EndGameFocus};
			}
			else
			{
				Request.set_field_endgamefocus(ObjectRef);
			}
		}
		else
		{
			Request.set_field_endgamefocus(SpatialConstants::NULL_OBJECT_REF);
		}
		Request.set_field_biswinner(StructuredParams.bIsWinner);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientGameEnded, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientgameended>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientForceGarbageCollection_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientForceGarbageCollection queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientForceGarbageCollectionRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientForceGarbageCollection, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientforcegarbagecollection>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientFlushLevelStreaming_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientFlushLevelStreaming queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientFlushLevelStreamingRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientFlushLevelStreaming, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientflushlevelstreaming>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientEndOnlineSession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientEndOnlineSession queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientEndOnlineSessionRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientEndOnlineSession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientendonlinesession>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientEnableNetworkVoice_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientEnableNetworkVoice_Parms StructuredParams = *static_cast<PlayerController_eventClientEnableNetworkVoice_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientEnableNetworkVoice queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientEnableNetworkVoiceRequest Request;
		Request.set_field_benable(StructuredParams.bEnable);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientEnableNetworkVoice, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientenablenetworkvoice>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientCommitMapChange_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientCommitMapChange queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientCommitMapChangeRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientCommitMapChange, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcommitmapchange>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientClearCameraLensEffects_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientClearCameraLensEffects queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientClearCameraLensEffectsRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientClearCameraLensEffects, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientclearcameralenseffects>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientCapBandwidth_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientCapBandwidth_Parms StructuredParams = *static_cast<PlayerController_eventClientCapBandwidth_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientCapBandwidth queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientCapBandwidthRequest Request;
		Request.set_field_cap(int32_t(StructuredParams.Cap));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientCapBandwidth, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcapbandwidth>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientCancelPendingMapChange_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientCancelPendingMapChange queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientCancelPendingMapChangeRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientCancelPendingMapChange, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcancelpendingmapchange>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientAddTextureStreamingLoc_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientAddTextureStreamingLoc_Parms StructuredParams = *static_cast<PlayerController_eventClientAddTextureStreamingLoc_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientAddTextureStreamingLoc queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientAddTextureStreamingLocRequest Request;
		Request.set_field_inloc(improbable::Vector3f(StructuredParams.InLoc.X, StructuredParams.InLoc.Y, StructuredParams.InLoc.Z));
		Request.set_field_duration(StructuredParams.Duration);
		Request.set_field_boverridelocation(StructuredParams.bOverrideLocation);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientAddTextureStreamingLoc, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientaddtexturestreamingloc>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetRotation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Controller.generated.h (in a macro that is then put in Controller.h UCLASS macro)
	Controller_eventClientSetRotation_Parms StructuredParams = *static_cast<Controller_eventClientSetRotation_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetRotation queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetRotationRequest Request;
		Request.set_field_newrotation(improbable::unreal::UnrealFRotator(StructuredParams.NewRotation.Yaw, StructuredParams.NewRotation.Pitch, StructuredParams.NewRotation.Roll));
		Request.set_field_bresetcamera(StructuredParams.bResetCamera);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetRotation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetrotation>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetLocation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Controller.generated.h (in a macro that is then put in Controller.h UCLASS macro)
	Controller_eventClientSetLocation_Parms StructuredParams = *static_cast<Controller_eventClientSetLocation_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetLocation queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetLocationRequest Request;
		Request.set_field_newlocation(improbable::Vector3f(StructuredParams.NewLocation.X, StructuredParams.NewLocation.Y, StructuredParams.NewLocation.Z));
		Request.set_field_newrotation(improbable::unreal::UnrealFRotator(StructuredParams.NewRotation.Yaw, StructuredParams.NewRotation.Pitch, StructuredParams.NewRotation.Roll));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetLocation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetlocation>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerTryJoinGame_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in SampleGamePlayerController.generated.h (in a macro that is then put in SampleGamePlayerController.h UCLASS macro)
	SampleGamePlayerController_eventServerTryJoinGame_Parms StructuredParams = *static_cast<SampleGamePlayerController_eventServerTryJoinGame_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerTryJoinGame queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerTryJoinGameRequest Request;
		Request.set_field_newplayername(TCHAR_TO_UTF8(*StructuredParams.NewPlayerName));
		Request.set_field_newplayerteam(uint32(StructuredParams.NewPlayerTeam));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerTryJoinGame, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservertryjoingame>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerViewSelf_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerViewSelf_Parms StructuredParams = *static_cast<PlayerController_eventServerViewSelf_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerViewSelf queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerViewSelfRequest Request;
		Request.set_field_transitionparams_blendtime(StructuredParams.TransitionParams.BlendTime);
		Request.set_field_transitionparams_blendfunction(uint32_t(StructuredParams.TransitionParams.BlendFunction));
		Request.set_field_transitionparams_blendexp(StructuredParams.TransitionParams.BlendExp);
		Request.set_field_transitionparams_blockoutgoing(StructuredParams.TransitionParams.bLockOutgoing);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerViewSelf, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewself>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerViewPrevPlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerViewPrevPlayer queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerViewPrevPlayerRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerViewPrevPlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewprevplayer>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerViewNextPlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerViewNextPlayer queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerViewNextPlayerRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerViewNextPlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewnextplayer>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerVerifyViewTarget_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerVerifyViewTarget queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerVerifyViewTargetRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerVerifyViewTarget, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserververifyviewtarget>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerUpdateMultipleLevelsVisibility_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerUpdateMultipleLevelsVisibility_Parms StructuredParams = *static_cast<PlayerController_eventServerUpdateMultipleLevelsVisibility_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerUpdateMultipleLevelsVisibility queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerUpdateMultipleLevelsVisibilityRequest Request;
		{
			::worker::List<std::string> List;
			for(int i = 0; i < StructuredParams.LevelVisibilities.Num(); i++)
			{
				TArray<uint8> ValueData;
				FMemoryWriter ValueDataWriter(ValueData);
				FUpdateLevelVisibilityLevelInfo::StaticStruct()->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FUpdateLevelVisibilityLevelInfo*>(&StructuredParams.LevelVisibilities[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			Request.set_field_levelvisibilities(List);
		}

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerUpdateMultipleLevelsVisibility, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatemultiplelevelsvisibility>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerUpdateLevelVisibility_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerUpdateLevelVisibility_Parms StructuredParams = *static_cast<PlayerController_eventServerUpdateLevelVisibility_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerUpdateLevelVisibility queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerUpdateLevelVisibilityRequest Request;
		Request.set_field_packagename(TCHAR_TO_UTF8(*StructuredParams.PackageName.ToString()));
		Request.set_field_bisvisible(StructuredParams.bIsVisible);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerUpdateLevelVisibility, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatelevelvisibility>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerUpdateCamera_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerUpdateCamera_Parms StructuredParams = *static_cast<PlayerController_eventServerUpdateCamera_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerUpdateCamera queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerUpdateCameraRequest Request;
		Request.set_field_camloc(improbable::Vector3f(StructuredParams.CamLoc.X, StructuredParams.CamLoc.Y, StructuredParams.CamLoc.Z));
		Request.set_field_campitchandyaw(int32_t(StructuredParams.CamPitchAndYaw));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerUpdateCamera, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatecamera>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerUnmutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerUnmutePlayer_Parms StructuredParams = *static_cast<PlayerController_eventServerUnmutePlayer_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerUnmutePlayer queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerUnmutePlayerRequest Request;
		{
			TArray<uint8> ValueData;
			FMemoryWriter ValueDataWriter(ValueData);
			bool Success;
			(const_cast<FUniqueNetIdRepl&>(StructuredParams.PlayerId)).NetSerialize(ValueDataWriter, PackageMap, Success);
			Request.set_field_playerid(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerUnmutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverunmuteplayer>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerToggleAILogging_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerToggleAILogging queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerToggleAILoggingRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerToggleAILogging, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservertoggleailogging>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerShortTimeout_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerShortTimeout queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerShortTimeoutRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerShortTimeout, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservershorttimeout>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerSetSpectatorWaiting_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerSetSpectatorWaiting_Parms StructuredParams = *static_cast<PlayerController_eventServerSetSpectatorWaiting_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerSetSpectatorWaiting queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerSetSpectatorWaitingRequest Request;
		Request.set_field_bwaiting(StructuredParams.bWaiting);

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerSetSpectatorWaiting, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserversetspectatorwaiting>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerSetSpectatorLocation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerSetSpectatorLocation_Parms StructuredParams = *static_cast<PlayerController_eventServerSetSpectatorLocation_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerSetSpectatorLocation queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerSetSpectatorLocationRequest Request;
		Request.set_field_newloc(improbable::Vector3f(StructuredParams.NewLoc.X, StructuredParams.NewLoc.Y, StructuredParams.NewLoc.Z));
		Request.set_field_newrot(improbable::unreal::UnrealFRotator(StructuredParams.NewRot.Yaw, StructuredParams.NewRot.Pitch, StructuredParams.NewRot.Roll));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerSetSpectatorLocation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserversetspectatorlocation>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerRestartPlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerRestartPlayer queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerRestartPlayerRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerRestartPlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverrestartplayer>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerPause_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerPause queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerPauseRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerPause, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverpause>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerNotifyLoadedWorld_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerNotifyLoadedWorld_Parms StructuredParams = *static_cast<PlayerController_eventServerNotifyLoadedWorld_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerNotifyLoadedWorld queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerNotifyLoadedWorldRequest Request;
		Request.set_field_worldpackagename(TCHAR_TO_UTF8(*StructuredParams.WorldPackageName.ToString()));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerNotifyLoadedWorld, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservernotifyloadedworld>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerMutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerMutePlayer_Parms StructuredParams = *static_cast<PlayerController_eventServerMutePlayer_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerMutePlayer queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerMutePlayerRequest Request;
		{
			TArray<uint8> ValueData;
			FMemoryWriter ValueDataWriter(ValueData);
			bool Success;
			(const_cast<FUniqueNetIdRepl&>(StructuredParams.PlayerId)).NetSerialize(ValueDataWriter, PackageMap, Success);
			Request.set_field_playerid(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerMutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservermuteplayer>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerCheckClientPossessionReliable_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerCheckClientPossessionReliable queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerCheckClientPossessionReliableRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerCheckClientPossessionReliable, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercheckclientpossessionreliable>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerCheckClientPossession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerCheckClientPossession queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerCheckClientPossessionRequest Request;

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerCheckClientPossession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercheckclientpossession>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerChangeName_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerChangeName_Parms StructuredParams = *static_cast<PlayerController_eventServerChangeName_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerChangeName queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerChangeNameRequest Request;
		Request.set_field_s(TCHAR_TO_UTF8(*StructuredParams.S));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerChangeName, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverchangename>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerCamera_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerCamera_Parms StructuredParams = *static_cast<PlayerController_eventServerCamera_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerCamera queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerCameraRequest Request;
		Request.set_field_newmode(TCHAR_TO_UTF8(*StructuredParams.NewMode.ToString()));

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerCamera, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercamera>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerAcknowledgePossession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerAcknowledgePossession_Parms StructuredParams = *static_cast<PlayerController_eventServerAcknowledgePossession_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerAcknowledgePossession queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerAcknowledgePossessionRequest Request;
		if (StructuredParams.P != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.P);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerAcknowledgePossession queued. StructuredParams.P is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.P};
			}
			else
			{
				Request.set_field_p(ObjectRef);
			}
		}
		else
		{
			Request.set_field_p(SpatialConstants::NULL_OBJECT_REF);
		}

		// Send command request.
		Request.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerAcknowledgePossession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserveracknowledgepossession>(TargetObjectRef.entity(), Request, 0);
		return {RequestId.Id};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientJoinResults_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientjoinresults>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientJoinResults_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientJoinResults_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in SampleGamePlayerController.generated.h (in a macro that is then put in SampleGamePlayerController.h UCLASS macro)
		SampleGamePlayerController_eventClientJoinResults_Parms Parameters;

		// Extract from request data.
		Parameters.bJoinSucceeded = Op.Request.field_bjoinsucceeded();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientJoinResults, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientJoinResults"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientJoinResults_OnCommandRequest: Function not found. Object: %s, Function: ClientJoinResults."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientjoinresults>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::OnServerStartedVisualLogger_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrolleronserverstartedvisuallogger>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: OnServerStartedVisualLogger_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: OnServerStartedVisualLogger_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventOnServerStartedVisualLogger_Parms Parameters;

		// Extract from request data.
		Parameters.bIsLogging = Op.Request.field_bislogging();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: OnServerStartedVisualLogger, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("OnServerStartedVisualLogger"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: OnServerStartedVisualLogger_OnCommandRequest: Function not found. Object: %s, Function: OnServerStartedVisualLogger."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrolleronserverstartedvisuallogger>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientWasKicked_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientwaskicked>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientWasKicked_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientWasKicked_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientWasKicked_Parms Parameters;

		// Extract from request data.
		// UNSUPPORTED UTextProperty (unhandled) Parameters.KickReason Op.Request.field_kickreason()

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientWasKicked, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientWasKicked"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientWasKicked_OnCommandRequest: Function not found. Object: %s, Function: ClientWasKicked."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientwaskicked>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientVoiceHandshakeComplete_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientvoicehandshakecomplete>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientVoiceHandshakeComplete_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientVoiceHandshakeComplete_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientVoiceHandshakeComplete, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientVoiceHandshakeComplete"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientVoiceHandshakeComplete_OnCommandRequest: Function not found. Object: %s, Function: ClientVoiceHandshakeComplete."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientvoicehandshakecomplete>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientUpdateMultipleLevelsStreamingStatus_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientupdatemultiplelevelsstreamingstatus>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientUpdateMultipleLevelsStreamingStatus_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientUpdateMultipleLevelsStreamingStatus_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientUpdateMultipleLevelsStreamingStatus_Parms Parameters;

		// Extract from request data.
		{
			auto& List = Op.Request.field_levelstatuses();
			Parameters.LevelStatuses.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FMemoryReader ValueDataReader(ValueData);
				FUpdateLevelStreamingLevelStatus::StaticStruct()->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Parameters.LevelStatuses[i]));
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientUpdateMultipleLevelsStreamingStatus, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientUpdateMultipleLevelsStreamingStatus"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientUpdateMultipleLevelsStreamingStatus_OnCommandRequest: Function not found. Object: %s, Function: ClientUpdateMultipleLevelsStreamingStatus."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientupdatemultiplelevelsstreamingstatus>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientUpdateLevelStreamingStatus_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientupdatelevelstreamingstatus>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientUpdateLevelStreamingStatus_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientUpdateLevelStreamingStatus_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientUpdateLevelStreamingStatus_Parms Parameters;

		// Extract from request data.
		Parameters.PackageName = FName((Op.Request.field_packagename()).data());
		Parameters.bNewShouldBeLoaded = Op.Request.field_bnewshouldbeloaded();
		Parameters.bNewShouldBeVisible = Op.Request.field_bnewshouldbevisible();
		Parameters.bNewShouldBlockOnLoad = Op.Request.field_bnewshouldblockonload();
		Parameters.LODIndex = Op.Request.field_lodindex();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientUpdateLevelStreamingStatus, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientUpdateLevelStreamingStatus"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientUpdateLevelStreamingStatus_OnCommandRequest: Function not found. Object: %s, Function: ClientUpdateLevelStreamingStatus."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientupdatelevelstreamingstatus>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientUnmutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientunmuteplayer>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientUnmutePlayer_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientUnmutePlayer_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientUnmutePlayer_Parms Parameters;

		// Extract from request data.
		{
			auto& ValueDataStr = Op.Request.field_playerid();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FMemoryReader ValueDataReader(ValueData);
			bool bSuccess;
			Parameters.PlayerId.NetSerialize(ValueDataReader, PackageMap, bSuccess);
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientUnmutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientUnmutePlayer"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientUnmutePlayer_OnCommandRequest: Function not found. Object: %s, Function: ClientUnmutePlayer."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientunmuteplayer>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientTravelInternal_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclienttravelinternal>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientTravelInternal_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientTravelInternal_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientTravelInternal_Parms Parameters;

		// Extract from request data.
		Parameters.URL = FString(UTF8_TO_TCHAR(Op.Request.field_url().c_str()));
		Parameters.TravelType = TEnumAsByte<ETravelType>(uint8(Op.Request.field_traveltype()));
		Parameters.bSeamless = Op.Request.field_bseamless();
		Parameters.MapPackageGuid.A = Op.Request.field_mappackageguid_a();
		Parameters.MapPackageGuid.B = Op.Request.field_mappackageguid_b();
		Parameters.MapPackageGuid.C = Op.Request.field_mappackageguid_c();
		Parameters.MapPackageGuid.D = Op.Request.field_mappackageguid_d();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientTravelInternal, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientTravelInternal"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientTravelInternal_OnCommandRequest: Function not found. Object: %s, Function: ClientTravelInternal."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclienttravelinternal>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientTeamMessage_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientteammessage>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientTeamMessage_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientTeamMessage_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientTeamMessage_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_senderplayerstate();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.SenderPlayerState = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.SenderPlayerState = Cast<APlayerState>(Object_Raw);
					checkf(Parameters.SenderPlayerState, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientTeamMessage_OnCommandRequest: Parameters.SenderPlayerState %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.S = FString(UTF8_TO_TCHAR(Op.Request.field_s().c_str()));
		Parameters.Type = FName((Op.Request.field_type()).data());
		Parameters.MsgLifeTime = Op.Request.field_msglifetime();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientTeamMessage, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientTeamMessage"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientTeamMessage_OnCommandRequest: Function not found. Object: %s, Function: ClientTeamMessage."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientteammessage>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientStopForceFeedback_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopforcefeedback>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientStopForceFeedback_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientStopForceFeedback_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientStopForceFeedback_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_forcefeedbackeffect();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ForceFeedbackEffect = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.ForceFeedbackEffect = Cast<UForceFeedbackEffect>(Object_Raw);
					checkf(Parameters.ForceFeedbackEffect, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientStopForceFeedback_OnCommandRequest: Parameters.ForceFeedbackEffect %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.Tag = FName((Op.Request.field_tag()).data());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientStopForceFeedback, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientStopForceFeedback"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientStopForceFeedback_OnCommandRequest: Function not found. Object: %s, Function: ClientStopForceFeedback."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopforcefeedback>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientStopCameraShake_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopcamerashake>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientStopCameraShake_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientStopCameraShake_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientStopCameraShake_Parms Parameters;

		// Extract from request data.
		Parameters.Shake = PackageMap->GetStaticClassFromHash(Op.Request.field_shake());
		Parameters.bImmediately = Op.Request.field_bimmediately();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientStopCameraShake, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientStopCameraShake"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientStopCameraShake_OnCommandRequest: Function not found. Object: %s, Function: ClientStopCameraShake."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopcamerashake>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientStopCameraAnim_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopcameraanim>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientStopCameraAnim_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientStopCameraAnim_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientStopCameraAnim_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_animtostop();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.AnimToStop = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.AnimToStop = Cast<UCameraAnim>(Object_Raw);
					checkf(Parameters.AnimToStop, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientStopCameraAnim_OnCommandRequest: Parameters.AnimToStop %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientStopCameraAnim, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientStopCameraAnim"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientStopCameraAnim_OnCommandRequest: Function not found. Object: %s, Function: ClientStopCameraAnim."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopcameraanim>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientStartOnlineSession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstartonlinesession>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientStartOnlineSession_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientStartOnlineSession_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientStartOnlineSession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientStartOnlineSession"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientStartOnlineSession_OnCommandRequest: Function not found. Object: %s, Function: ClientStartOnlineSession."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstartonlinesession>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSpawnCameraLensEffect_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientspawncameralenseffect>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSpawnCameraLensEffect_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSpawnCameraLensEffect_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSpawnCameraLensEffect_Parms Parameters;

		// Extract from request data.
		Parameters.LensEffectEmitterClass = PackageMap->GetStaticClassFromHash(Op.Request.field_lenseffectemitterclass());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSpawnCameraLensEffect, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSpawnCameraLensEffect"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSpawnCameraLensEffect_OnCommandRequest: Function not found. Object: %s, Function: ClientSpawnCameraLensEffect."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientspawncameralenseffect>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetViewTarget_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetviewtarget>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetViewTarget_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetViewTarget_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSetViewTarget_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_a();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.A = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.A = Cast<AActor>(Object_Raw);
					checkf(Parameters.A, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetViewTarget_OnCommandRequest: Parameters.A %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.TransitionParams.BlendTime = Op.Request.field_transitionparams_blendtime();
		Parameters.TransitionParams.BlendFunction = TEnumAsByte<EViewTargetBlendFunction>(uint8(Op.Request.field_transitionparams_blendfunction()));
		Parameters.TransitionParams.BlendExp = Op.Request.field_transitionparams_blendexp();
		Parameters.TransitionParams.bLockOutgoing = Op.Request.field_transitionparams_blockoutgoing();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetViewTarget, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetViewTarget"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetViewTarget_OnCommandRequest: Function not found. Object: %s, Function: ClientSetViewTarget."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetviewtarget>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetSpectatorWaiting_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetspectatorwaiting>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetSpectatorWaiting_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetSpectatorWaiting_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSetSpectatorWaiting_Parms Parameters;

		// Extract from request data.
		Parameters.bWaiting = Op.Request.field_bwaiting();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetSpectatorWaiting, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetSpectatorWaiting"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetSpectatorWaiting_OnCommandRequest: Function not found. Object: %s, Function: ClientSetSpectatorWaiting."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetspectatorwaiting>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetHUD_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsethud>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetHUD_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetHUD_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSetHUD_Parms Parameters;

		// Extract from request data.
		Parameters.NewHUDClass = PackageMap->GetStaticClassFromHash(Op.Request.field_newhudclass());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetHUD, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetHUD"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetHUD_OnCommandRequest: Function not found. Object: %s, Function: ClientSetHUD."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsethud>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetForceMipLevelsToBeResident_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetforcemiplevelstoberesident>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetForceMipLevelsToBeResident_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetForceMipLevelsToBeResident_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSetForceMipLevelsToBeResident_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_material();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.Material = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.Material = Cast<UMaterialInterface>(Object_Raw);
					checkf(Parameters.Material, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetForceMipLevelsToBeResident_OnCommandRequest: Parameters.Material %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.ForceDuration = Op.Request.field_forceduration();
		Parameters.CinematicTextureGroups = Op.Request.field_cinematictexturegroups();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetForceMipLevelsToBeResident, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetForceMipLevelsToBeResident"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetForceMipLevelsToBeResident_OnCommandRequest: Function not found. Object: %s, Function: ClientSetForceMipLevelsToBeResident."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetforcemiplevelstoberesident>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetCinematicMode_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcinematicmode>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetCinematicMode_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetCinematicMode_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSetCinematicMode_Parms Parameters;

		// Extract from request data.
		Parameters.bInCinematicMode = Op.Request.field_bincinematicmode();
		Parameters.bAffectsMovement = Op.Request.field_baffectsmovement();
		Parameters.bAffectsTurning = Op.Request.field_baffectsturning();
		Parameters.bAffectsHUD = Op.Request.field_baffectshud();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetCinematicMode, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetCinematicMode"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetCinematicMode_OnCommandRequest: Function not found. Object: %s, Function: ClientSetCinematicMode."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcinematicmode>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetCameraMode_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcameramode>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetCameraMode_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetCameraMode_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSetCameraMode_Parms Parameters;

		// Extract from request data.
		Parameters.NewCamMode = FName((Op.Request.field_newcammode()).data());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetCameraMode, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetCameraMode"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetCameraMode_OnCommandRequest: Function not found. Object: %s, Function: ClientSetCameraMode."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcameramode>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetCameraFade_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcamerafade>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetCameraFade_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetCameraFade_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSetCameraFade_Parms Parameters;

		// Extract from request data.
		Parameters.bEnableFading = Op.Request.field_benablefading();
		Parameters.FadeColor.B = uint8(uint8(Op.Request.field_fadecolor_b()));
		Parameters.FadeColor.G = uint8(uint8(Op.Request.field_fadecolor_g()));
		Parameters.FadeColor.R = uint8(uint8(Op.Request.field_fadecolor_r()));
		Parameters.FadeColor.A = uint8(uint8(Op.Request.field_fadecolor_a()));
		Parameters.FadeAlpha.X = Op.Request.field_fadealpha_x();
		Parameters.FadeAlpha.Y = Op.Request.field_fadealpha_y();
		Parameters.FadeTime = Op.Request.field_fadetime();
		Parameters.bFadeAudio = Op.Request.field_bfadeaudio();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetCameraFade, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetCameraFade"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetCameraFade_OnCommandRequest: Function not found. Object: %s, Function: ClientSetCameraFade."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcamerafade>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetBlockOnAsyncLoading_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetblockonasyncloading>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetBlockOnAsyncLoading_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetBlockOnAsyncLoading_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetBlockOnAsyncLoading, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetBlockOnAsyncLoading"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetBlockOnAsyncLoading_OnCommandRequest: Function not found. Object: %s, Function: ClientSetBlockOnAsyncLoading."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetblockonasyncloading>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientReturnToMainMenuWithTextReason_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreturntomainmenuwithtextreason>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientReturnToMainMenuWithTextReason_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientReturnToMainMenuWithTextReason_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientReturnToMainMenuWithTextReason_Parms Parameters;

		// Extract from request data.
		// UNSUPPORTED UTextProperty (unhandled) Parameters.ReturnReason Op.Request.field_returnreason()

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientReturnToMainMenuWithTextReason, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientReturnToMainMenuWithTextReason"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientReturnToMainMenuWithTextReason_OnCommandRequest: Function not found. Object: %s, Function: ClientReturnToMainMenuWithTextReason."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreturntomainmenuwithtextreason>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientReturnToMainMenu_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreturntomainmenu>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientReturnToMainMenu_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientReturnToMainMenu_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientReturnToMainMenu_Parms Parameters;

		// Extract from request data.
		Parameters.ReturnReason = FString(UTF8_TO_TCHAR(Op.Request.field_returnreason().c_str()));

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientReturnToMainMenu, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientReturnToMainMenu"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientReturnToMainMenu_OnCommandRequest: Function not found. Object: %s, Function: ClientReturnToMainMenu."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreturntomainmenu>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientRetryClientRestart_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientretryclientrestart>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientRetryClientRestart_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientRetryClientRestart_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientRetryClientRestart_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_newpawn();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.NewPawn = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.NewPawn = Cast<APawn>(Object_Raw);
					checkf(Parameters.NewPawn, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientRetryClientRestart_OnCommandRequest: Parameters.NewPawn %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientRetryClientRestart, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientRetryClientRestart"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientRetryClientRestart_OnCommandRequest: Function not found. Object: %s, Function: ClientRetryClientRestart."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientretryclientrestart>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientRestart_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientrestart>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientRestart_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientRestart_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientRestart_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_newpawn();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.NewPawn = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.NewPawn = Cast<APawn>(Object_Raw);
					checkf(Parameters.NewPawn, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientRestart_OnCommandRequest: Parameters.NewPawn %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientRestart, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientRestart"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientRestart_OnCommandRequest: Function not found. Object: %s, Function: ClientRestart."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientrestart>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientReset_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreset>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientReset_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientReset_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientReset, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientReset"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientReset_OnCommandRequest: Function not found. Object: %s, Function: ClientReset."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreset>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientRepObjRef_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientrepobjref>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientRepObjRef_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientRepObjRef_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientRepObjRef_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_object();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.Object = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.Object = Cast<UObject>(Object_Raw);
					checkf(Parameters.Object, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientRepObjRef_OnCommandRequest: Parameters.Object %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientRepObjRef, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientRepObjRef"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientRepObjRef_OnCommandRequest: Function not found. Object: %s, Function: ClientRepObjRef."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientrepobjref>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientReceiveLocalizedMessage_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreceivelocalizedmessage>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientReceiveLocalizedMessage_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientReceiveLocalizedMessage_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientReceiveLocalizedMessage_Parms Parameters;

		// Extract from request data.
		Parameters.Message = PackageMap->GetStaticClassFromHash(Op.Request.field_message());
		Parameters.Switch = Op.Request.field_switch();
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_relatedplayerstate1();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.RelatedPlayerState_1 = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.RelatedPlayerState_1 = Cast<APlayerState>(Object_Raw);
					checkf(Parameters.RelatedPlayerState_1, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientReceiveLocalizedMessage_OnCommandRequest: Parameters.RelatedPlayerState_1 %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_relatedplayerstate2();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.RelatedPlayerState_2 = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.RelatedPlayerState_2 = Cast<APlayerState>(Object_Raw);
					checkf(Parameters.RelatedPlayerState_2, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientReceiveLocalizedMessage_OnCommandRequest: Parameters.RelatedPlayerState_2 %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_optionalobject();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.OptionalObject = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.OptionalObject = Cast<UObject>(Object_Raw);
					checkf(Parameters.OptionalObject, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientReceiveLocalizedMessage_OnCommandRequest: Parameters.OptionalObject %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientReceiveLocalizedMessage, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientReceiveLocalizedMessage"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientReceiveLocalizedMessage_OnCommandRequest: Function not found. Object: %s, Function: ClientReceiveLocalizedMessage."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreceivelocalizedmessage>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPrestreamTextures_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientprestreamtextures>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPrestreamTextures_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientPrestreamTextures_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientPrestreamTextures_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_forcedactor();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ForcedActor = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.ForcedActor = Cast<AActor>(Object_Raw);
					checkf(Parameters.ForcedActor, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPrestreamTextures_OnCommandRequest: Parameters.ForcedActor %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.ForceDuration = Op.Request.field_forceduration();
		Parameters.bEnableStreaming = Op.Request.field_benablestreaming();
		Parameters.CinematicTextureGroups = Op.Request.field_cinematictexturegroups();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientPrestreamTextures, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientPrestreamTextures"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientPrestreamTextures_OnCommandRequest: Function not found. Object: %s, Function: ClientPrestreamTextures."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientprestreamtextures>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPrepareMapChange_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientpreparemapchange>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPrepareMapChange_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientPrepareMapChange_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientPrepareMapChange_Parms Parameters;

		// Extract from request data.
		Parameters.LevelName = FName((Op.Request.field_levelname()).data());
		Parameters.bFirst = Op.Request.field_bfirst();
		Parameters.bLast = Op.Request.field_blast();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientPrepareMapChange, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientPrepareMapChange"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientPrepareMapChange_OnCommandRequest: Function not found. Object: %s, Function: ClientPrepareMapChange."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientpreparemapchange>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlaySoundAtLocation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaysoundatlocation>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlaySoundAtLocation_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientPlaySoundAtLocation_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientPlaySoundAtLocation_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_sound();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.Sound = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.Sound = Cast<USoundBase>(Object_Raw);
					checkf(Parameters.Sound, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlaySoundAtLocation_OnCommandRequest: Parameters.Sound %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			auto& Vector = Op.Request.field_location();
			Parameters.Location.X = Vector.x();
			Parameters.Location.Y = Vector.y();
			Parameters.Location.Z = Vector.z();
		}
		Parameters.VolumeMultiplier = Op.Request.field_volumemultiplier();
		Parameters.PitchMultiplier = Op.Request.field_pitchmultiplier();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientPlaySoundAtLocation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientPlaySoundAtLocation"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientPlaySoundAtLocation_OnCommandRequest: Function not found. Object: %s, Function: ClientPlaySoundAtLocation."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaysoundatlocation>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlaySound_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaysound>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlaySound_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientPlaySound_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientPlaySound_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_sound();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.Sound = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.Sound = Cast<USoundBase>(Object_Raw);
					checkf(Parameters.Sound, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlaySound_OnCommandRequest: Parameters.Sound %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.VolumeMultiplier = Op.Request.field_volumemultiplier();
		Parameters.PitchMultiplier = Op.Request.field_pitchmultiplier();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientPlaySound, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientPlaySound"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientPlaySound_OnCommandRequest: Function not found. Object: %s, Function: ClientPlaySound."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaysound>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlayForceFeedback_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplayforcefeedback>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlayForceFeedback_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientPlayForceFeedback_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientPlayForceFeedback_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_forcefeedbackeffect();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ForceFeedbackEffect = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.ForceFeedbackEffect = Cast<UForceFeedbackEffect>(Object_Raw);
					checkf(Parameters.ForceFeedbackEffect, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlayForceFeedback_OnCommandRequest: Parameters.ForceFeedbackEffect %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.bLooping = Op.Request.field_blooping();
		Parameters.bIgnoreTimeDilation = Op.Request.field_bignoretimedilation();
		Parameters.Tag = FName((Op.Request.field_tag()).data());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientPlayForceFeedback, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientPlayForceFeedback"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientPlayForceFeedback_OnCommandRequest: Function not found. Object: %s, Function: ClientPlayForceFeedback."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplayforcefeedback>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlayCameraShake_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaycamerashake>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlayCameraShake_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientPlayCameraShake_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientPlayCameraShake_Parms Parameters;

		// Extract from request data.
		Parameters.Shake = PackageMap->GetStaticClassFromHash(Op.Request.field_shake());
		Parameters.Scale = Op.Request.field_scale();
		Parameters.PlaySpace = TEnumAsByte<ECameraAnimPlaySpace::Type>(uint8(Op.Request.field_playspace()));
		{
			auto& Rotator = Op.Request.field_userplayspacerot();
			Parameters.UserPlaySpaceRot.Yaw = Rotator.yaw();
			Parameters.UserPlaySpaceRot.Pitch = Rotator.pitch();
			Parameters.UserPlaySpaceRot.Roll = Rotator.roll();
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientPlayCameraShake, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientPlayCameraShake"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientPlayCameraShake_OnCommandRequest: Function not found. Object: %s, Function: ClientPlayCameraShake."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaycamerashake>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlayCameraAnim_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaycameraanim>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlayCameraAnim_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientPlayCameraAnim_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientPlayCameraAnim_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_animtoplay();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.AnimToPlay = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.AnimToPlay = Cast<UCameraAnim>(Object_Raw);
					checkf(Parameters.AnimToPlay, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlayCameraAnim_OnCommandRequest: Parameters.AnimToPlay %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.Scale = Op.Request.field_scale();
		Parameters.Rate = Op.Request.field_rate();
		Parameters.BlendInTime = Op.Request.field_blendintime();
		Parameters.BlendOutTime = Op.Request.field_blendouttime();
		Parameters.bLoop = Op.Request.field_bloop();
		Parameters.bRandomStartTime = Op.Request.field_brandomstarttime();
		Parameters.Space = TEnumAsByte<ECameraAnimPlaySpace::Type>(uint8(Op.Request.field_space()));
		{
			auto& Rotator = Op.Request.field_customplayspace();
			Parameters.CustomPlaySpace.Yaw = Rotator.yaw();
			Parameters.CustomPlaySpace.Pitch = Rotator.pitch();
			Parameters.CustomPlaySpace.Roll = Rotator.roll();
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientPlayCameraAnim, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientPlayCameraAnim"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientPlayCameraAnim_OnCommandRequest: Function not found. Object: %s, Function: ClientPlayCameraAnim."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaycameraanim>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientMutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientmuteplayer>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientMutePlayer_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientMutePlayer_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientMutePlayer_Parms Parameters;

		// Extract from request data.
		{
			auto& ValueDataStr = Op.Request.field_playerid();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FMemoryReader ValueDataReader(ValueData);
			bool bSuccess;
			Parameters.PlayerId.NetSerialize(ValueDataReader, PackageMap, bSuccess);
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientMutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientMutePlayer"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientMutePlayer_OnCommandRequest: Function not found. Object: %s, Function: ClientMutePlayer."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientmuteplayer>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientMessage_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientmessage>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientMessage_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientMessage_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientMessage_Parms Parameters;

		// Extract from request data.
		Parameters.S = FString(UTF8_TO_TCHAR(Op.Request.field_s().c_str()));
		Parameters.Type = FName((Op.Request.field_type()).data());
		Parameters.MsgLifeTime = Op.Request.field_msglifetime();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientMessage, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientMessage"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientMessage_OnCommandRequest: Function not found. Object: %s, Function: ClientMessage."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientmessage>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientIgnoreMoveInput_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientignoremoveinput>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientIgnoreMoveInput_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientIgnoreMoveInput_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientIgnoreMoveInput_Parms Parameters;

		// Extract from request data.
		Parameters.bIgnore = Op.Request.field_bignore();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientIgnoreMoveInput, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientIgnoreMoveInput"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientIgnoreMoveInput_OnCommandRequest: Function not found. Object: %s, Function: ClientIgnoreMoveInput."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientignoremoveinput>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientIgnoreLookInput_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientignorelookinput>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientIgnoreLookInput_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientIgnoreLookInput_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientIgnoreLookInput_Parms Parameters;

		// Extract from request data.
		Parameters.bIgnore = Op.Request.field_bignore();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientIgnoreLookInput, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientIgnoreLookInput"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientIgnoreLookInput_OnCommandRequest: Function not found. Object: %s, Function: ClientIgnoreLookInput."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientignorelookinput>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientGotoState_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientgotostate>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientGotoState_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientGotoState_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientGotoState_Parms Parameters;

		// Extract from request data.
		Parameters.NewState = FName((Op.Request.field_newstate()).data());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientGotoState, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientGotoState"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientGotoState_OnCommandRequest: Function not found. Object: %s, Function: ClientGotoState."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientgotostate>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientGameEnded_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientgameended>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientGameEnded_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientGameEnded_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientGameEnded_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_endgamefocus();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.EndGameFocus = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.EndGameFocus = Cast<AActor>(Object_Raw);
					checkf(Parameters.EndGameFocus, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientGameEnded_OnCommandRequest: Parameters.EndGameFocus %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.bIsWinner = Op.Request.field_biswinner();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientGameEnded, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientGameEnded"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientGameEnded_OnCommandRequest: Function not found. Object: %s, Function: ClientGameEnded."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientgameended>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientForceGarbageCollection_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientforcegarbagecollection>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientForceGarbageCollection_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientForceGarbageCollection_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientForceGarbageCollection, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientForceGarbageCollection"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientForceGarbageCollection_OnCommandRequest: Function not found. Object: %s, Function: ClientForceGarbageCollection."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientforcegarbagecollection>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientFlushLevelStreaming_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientflushlevelstreaming>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientFlushLevelStreaming_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientFlushLevelStreaming_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientFlushLevelStreaming, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientFlushLevelStreaming"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientFlushLevelStreaming_OnCommandRequest: Function not found. Object: %s, Function: ClientFlushLevelStreaming."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientflushlevelstreaming>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientEndOnlineSession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientendonlinesession>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientEndOnlineSession_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientEndOnlineSession_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientEndOnlineSession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientEndOnlineSession"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientEndOnlineSession_OnCommandRequest: Function not found. Object: %s, Function: ClientEndOnlineSession."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientendonlinesession>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientEnableNetworkVoice_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientenablenetworkvoice>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientEnableNetworkVoice_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientEnableNetworkVoice_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientEnableNetworkVoice_Parms Parameters;

		// Extract from request data.
		Parameters.bEnable = Op.Request.field_benable();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientEnableNetworkVoice, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientEnableNetworkVoice"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientEnableNetworkVoice_OnCommandRequest: Function not found. Object: %s, Function: ClientEnableNetworkVoice."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientenablenetworkvoice>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientCommitMapChange_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcommitmapchange>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientCommitMapChange_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientCommitMapChange_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientCommitMapChange, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientCommitMapChange"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientCommitMapChange_OnCommandRequest: Function not found. Object: %s, Function: ClientCommitMapChange."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcommitmapchange>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientClearCameraLensEffects_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientclearcameralenseffects>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientClearCameraLensEffects_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientClearCameraLensEffects_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientClearCameraLensEffects, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientClearCameraLensEffects"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientClearCameraLensEffects_OnCommandRequest: Function not found. Object: %s, Function: ClientClearCameraLensEffects."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientclearcameralenseffects>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientCapBandwidth_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcapbandwidth>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientCapBandwidth_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientCapBandwidth_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientCapBandwidth_Parms Parameters;

		// Extract from request data.
		Parameters.Cap = Op.Request.field_cap();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientCapBandwidth, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientCapBandwidth"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientCapBandwidth_OnCommandRequest: Function not found. Object: %s, Function: ClientCapBandwidth."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcapbandwidth>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientCancelPendingMapChange_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcancelpendingmapchange>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientCancelPendingMapChange_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientCancelPendingMapChange_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientCancelPendingMapChange, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientCancelPendingMapChange"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientCancelPendingMapChange_OnCommandRequest: Function not found. Object: %s, Function: ClientCancelPendingMapChange."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcancelpendingmapchange>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientAddTextureStreamingLoc_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientaddtexturestreamingloc>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientAddTextureStreamingLoc_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientAddTextureStreamingLoc_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientAddTextureStreamingLoc_Parms Parameters;

		// Extract from request data.
		{
			auto& Vector = Op.Request.field_inloc();
			Parameters.InLoc.X = Vector.x();
			Parameters.InLoc.Y = Vector.y();
			Parameters.InLoc.Z = Vector.z();
		}
		Parameters.Duration = Op.Request.field_duration();
		Parameters.bOverrideLocation = Op.Request.field_boverridelocation();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientAddTextureStreamingLoc, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientAddTextureStreamingLoc"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientAddTextureStreamingLoc_OnCommandRequest: Function not found. Object: %s, Function: ClientAddTextureStreamingLoc."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientaddtexturestreamingloc>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetRotation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetrotation>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetRotation_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetRotation_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Controller.generated.h (in a macro that is then put in Controller.h UCLASS macro)
		Controller_eventClientSetRotation_Parms Parameters;

		// Extract from request data.
		{
			auto& Rotator = Op.Request.field_newrotation();
			Parameters.NewRotation.Yaw = Rotator.yaw();
			Parameters.NewRotation.Pitch = Rotator.pitch();
			Parameters.NewRotation.Roll = Rotator.roll();
		}
		Parameters.bResetCamera = Op.Request.field_bresetcamera();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetRotation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetRotation"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetRotation_OnCommandRequest: Function not found. Object: %s, Function: ClientSetRotation."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetrotation>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetLocation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetlocation>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetLocation_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetLocation_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Controller.generated.h (in a macro that is then put in Controller.h UCLASS macro)
		Controller_eventClientSetLocation_Parms Parameters;

		// Extract from request data.
		{
			auto& Vector = Op.Request.field_newlocation();
			Parameters.NewLocation.X = Vector.x();
			Parameters.NewLocation.Y = Vector.y();
			Parameters.NewLocation.Z = Vector.z();
		}
		{
			auto& Rotator = Op.Request.field_newrotation();
			Parameters.NewRotation.Yaw = Rotator.yaw();
			Parameters.NewRotation.Pitch = Rotator.pitch();
			Parameters.NewRotation.Roll = Rotator.roll();
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetLocation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetLocation"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetLocation_OnCommandRequest: Function not found. Object: %s, Function: ClientSetLocation."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetlocation>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerTryJoinGame_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservertryjoingame>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerTryJoinGame_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerTryJoinGame_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in SampleGamePlayerController.generated.h (in a macro that is then put in SampleGamePlayerController.h UCLASS macro)
		SampleGamePlayerController_eventServerTryJoinGame_Parms Parameters;

		// Extract from request data.
		Parameters.NewPlayerName = FString(UTF8_TO_TCHAR(Op.Request.field_newplayername().c_str()));
		Parameters.NewPlayerTeam = ESampleGameTeam(Op.Request.field_newplayerteam());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerTryJoinGame, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerTryJoinGame"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerTryJoinGame_OnCommandRequest: Function not found. Object: %s, Function: ServerTryJoinGame."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservertryjoingame>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerViewSelf_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewself>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerViewSelf_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerViewSelf_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerViewSelf_Parms Parameters;

		// Extract from request data.
		Parameters.TransitionParams.BlendTime = Op.Request.field_transitionparams_blendtime();
		Parameters.TransitionParams.BlendFunction = TEnumAsByte<EViewTargetBlendFunction>(uint8(Op.Request.field_transitionparams_blendfunction()));
		Parameters.TransitionParams.BlendExp = Op.Request.field_transitionparams_blendexp();
		Parameters.TransitionParams.bLockOutgoing = Op.Request.field_transitionparams_blockoutgoing();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerViewSelf, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerViewSelf"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerViewSelf_OnCommandRequest: Function not found. Object: %s, Function: ServerViewSelf."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewself>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerViewPrevPlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewprevplayer>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerViewPrevPlayer_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerViewPrevPlayer_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerViewPrevPlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerViewPrevPlayer"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerViewPrevPlayer_OnCommandRequest: Function not found. Object: %s, Function: ServerViewPrevPlayer."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewprevplayer>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerViewNextPlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewnextplayer>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerViewNextPlayer_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerViewNextPlayer_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerViewNextPlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerViewNextPlayer"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerViewNextPlayer_OnCommandRequest: Function not found. Object: %s, Function: ServerViewNextPlayer."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewnextplayer>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerVerifyViewTarget_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserververifyviewtarget>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerVerifyViewTarget_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerVerifyViewTarget_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerVerifyViewTarget, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerVerifyViewTarget"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerVerifyViewTarget_OnCommandRequest: Function not found. Object: %s, Function: ServerVerifyViewTarget."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserververifyviewtarget>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerUpdateMultipleLevelsVisibility_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatemultiplelevelsvisibility>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerUpdateMultipleLevelsVisibility_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerUpdateMultipleLevelsVisibility_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerUpdateMultipleLevelsVisibility_Parms Parameters;

		// Extract from request data.
		{
			auto& List = Op.Request.field_levelvisibilities();
			Parameters.LevelVisibilities.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FMemoryReader ValueDataReader(ValueData);
				FUpdateLevelVisibilityLevelInfo::StaticStruct()->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Parameters.LevelVisibilities[i]));
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerUpdateMultipleLevelsVisibility, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerUpdateMultipleLevelsVisibility"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerUpdateMultipleLevelsVisibility_OnCommandRequest: Function not found. Object: %s, Function: ServerUpdateMultipleLevelsVisibility."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatemultiplelevelsvisibility>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerUpdateLevelVisibility_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatelevelvisibility>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerUpdateLevelVisibility_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerUpdateLevelVisibility_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerUpdateLevelVisibility_Parms Parameters;

		// Extract from request data.
		Parameters.PackageName = FName((Op.Request.field_packagename()).data());
		Parameters.bIsVisible = Op.Request.field_bisvisible();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerUpdateLevelVisibility, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerUpdateLevelVisibility"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerUpdateLevelVisibility_OnCommandRequest: Function not found. Object: %s, Function: ServerUpdateLevelVisibility."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatelevelvisibility>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerUpdateCamera_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatecamera>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerUpdateCamera_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerUpdateCamera_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerUpdateCamera_Parms Parameters;

		// Extract from request data.
		{
			auto& Vector = Op.Request.field_camloc();
			Parameters.CamLoc.X = Vector.x();
			Parameters.CamLoc.Y = Vector.y();
			Parameters.CamLoc.Z = Vector.z();
		}
		Parameters.CamPitchAndYaw = Op.Request.field_campitchandyaw();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerUpdateCamera, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerUpdateCamera"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerUpdateCamera_OnCommandRequest: Function not found. Object: %s, Function: ServerUpdateCamera."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatecamera>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerUnmutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverunmuteplayer>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerUnmutePlayer_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerUnmutePlayer_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerUnmutePlayer_Parms Parameters;

		// Extract from request data.
		{
			auto& ValueDataStr = Op.Request.field_playerid();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FMemoryReader ValueDataReader(ValueData);
			bool bSuccess;
			Parameters.PlayerId.NetSerialize(ValueDataReader, PackageMap, bSuccess);
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerUnmutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerUnmutePlayer"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerUnmutePlayer_OnCommandRequest: Function not found. Object: %s, Function: ServerUnmutePlayer."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverunmuteplayer>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerToggleAILogging_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservertoggleailogging>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerToggleAILogging_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerToggleAILogging_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerToggleAILogging, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerToggleAILogging"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerToggleAILogging_OnCommandRequest: Function not found. Object: %s, Function: ServerToggleAILogging."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservertoggleailogging>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerShortTimeout_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservershorttimeout>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerShortTimeout_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerShortTimeout_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerShortTimeout, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerShortTimeout"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerShortTimeout_OnCommandRequest: Function not found. Object: %s, Function: ServerShortTimeout."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservershorttimeout>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerSetSpectatorWaiting_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserversetspectatorwaiting>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerSetSpectatorWaiting_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerSetSpectatorWaiting_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerSetSpectatorWaiting_Parms Parameters;

		// Extract from request data.
		Parameters.bWaiting = Op.Request.field_bwaiting();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerSetSpectatorWaiting, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerSetSpectatorWaiting"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerSetSpectatorWaiting_OnCommandRequest: Function not found. Object: %s, Function: ServerSetSpectatorWaiting."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserversetspectatorwaiting>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerSetSpectatorLocation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserversetspectatorlocation>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerSetSpectatorLocation_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerSetSpectatorLocation_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerSetSpectatorLocation_Parms Parameters;

		// Extract from request data.
		{
			auto& Vector = Op.Request.field_newloc();
			Parameters.NewLoc.X = Vector.x();
			Parameters.NewLoc.Y = Vector.y();
			Parameters.NewLoc.Z = Vector.z();
		}
		{
			auto& Rotator = Op.Request.field_newrot();
			Parameters.NewRot.Yaw = Rotator.yaw();
			Parameters.NewRot.Pitch = Rotator.pitch();
			Parameters.NewRot.Roll = Rotator.roll();
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerSetSpectatorLocation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerSetSpectatorLocation"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerSetSpectatorLocation_OnCommandRequest: Function not found. Object: %s, Function: ServerSetSpectatorLocation."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserversetspectatorlocation>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerRestartPlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverrestartplayer>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerRestartPlayer_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerRestartPlayer_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerRestartPlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerRestartPlayer"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerRestartPlayer_OnCommandRequest: Function not found. Object: %s, Function: ServerRestartPlayer."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverrestartplayer>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerPause_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverpause>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerPause_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerPause_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerPause, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerPause"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerPause_OnCommandRequest: Function not found. Object: %s, Function: ServerPause."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverpause>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerNotifyLoadedWorld_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservernotifyloadedworld>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerNotifyLoadedWorld_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerNotifyLoadedWorld_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerNotifyLoadedWorld_Parms Parameters;

		// Extract from request data.
		Parameters.WorldPackageName = FName((Op.Request.field_worldpackagename()).data());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerNotifyLoadedWorld, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerNotifyLoadedWorld"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerNotifyLoadedWorld_OnCommandRequest: Function not found. Object: %s, Function: ServerNotifyLoadedWorld."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservernotifyloadedworld>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerMutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservermuteplayer>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerMutePlayer_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerMutePlayer_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerMutePlayer_Parms Parameters;

		// Extract from request data.
		{
			auto& ValueDataStr = Op.Request.field_playerid();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FMemoryReader ValueDataReader(ValueData);
			bool bSuccess;
			Parameters.PlayerId.NetSerialize(ValueDataReader, PackageMap, bSuccess);
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerMutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerMutePlayer"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerMutePlayer_OnCommandRequest: Function not found. Object: %s, Function: ServerMutePlayer."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservermuteplayer>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerCheckClientPossessionReliable_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercheckclientpossessionreliable>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerCheckClientPossessionReliable_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerCheckClientPossessionReliable_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerCheckClientPossessionReliable, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerCheckClientPossessionReliable"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerCheckClientPossessionReliable_OnCommandRequest: Function not found. Object: %s, Function: ServerCheckClientPossessionReliable."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercheckclientpossessionreliable>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerCheckClientPossession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercheckclientpossession>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerCheckClientPossession_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerCheckClientPossession_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerCheckClientPossession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerCheckClientPossession"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerCheckClientPossession_OnCommandRequest: Function not found. Object: %s, Function: ServerCheckClientPossession."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercheckclientpossession>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerChangeName_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverchangename>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerChangeName_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerChangeName_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerChangeName_Parms Parameters;

		// Extract from request data.
		Parameters.S = FString(UTF8_TO_TCHAR(Op.Request.field_s().c_str()));

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerChangeName, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerChangeName"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerChangeName_OnCommandRequest: Function not found. Object: %s, Function: ServerChangeName."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverchangename>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerCamera_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercamera>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerCamera_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerCamera_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerCamera_Parms Parameters;

		// Extract from request data.
		Parameters.NewMode = FName((Op.Request.field_newmode()).data());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerCamera, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerCamera"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerCamera_OnCommandRequest: Function not found. Object: %s, Function: ServerCamera."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercamera>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ServerAcknowledgePossession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserveracknowledgepossession>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerAcknowledgePossession_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerAcknowledgePossession_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerAcknowledgePossession_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_p();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.P = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.P = Cast<APawn>(Object_Raw);
					checkf(Parameters.P, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerAcknowledgePossession_OnCommandRequest: Parameters.P %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerAcknowledgePossession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerAcknowledgePossession"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerAcknowledgePossession_OnCommandRequest: Function not found. Object: %s, Function: ServerAcknowledgePossession."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserveracknowledgepossession>(Op.RequestId, {});
		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_SampleGamePlayerController::ClientJoinResults_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientjoinresults>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientJoinResults"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::OnServerStartedVisualLogger_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrolleronserverstartedvisuallogger>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("OnServerStartedVisualLogger"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientWasKicked_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientwaskicked>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientWasKicked"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientVoiceHandshakeComplete_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientvoicehandshakecomplete>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientVoiceHandshakeComplete"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientUpdateMultipleLevelsStreamingStatus_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientupdatemultiplelevelsstreamingstatus>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientUpdateMultipleLevelsStreamingStatus"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientUpdateLevelStreamingStatus_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientupdatelevelstreamingstatus>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientUpdateLevelStreamingStatus"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientUnmutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientunmuteplayer>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientUnmutePlayer"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientTravelInternal_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclienttravelinternal>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientTravelInternal"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientTeamMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientteammessage>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientTeamMessage"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientStopForceFeedback_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopforcefeedback>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientStopForceFeedback"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientStopCameraShake_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopcamerashake>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientStopCameraShake"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientStopCameraAnim_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopcameraanim>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientStopCameraAnim"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientStartOnlineSession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstartonlinesession>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientStartOnlineSession"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSpawnCameraLensEffect_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientspawncameralenseffect>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientSpawnCameraLensEffect"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetViewTarget_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetviewtarget>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientSetViewTarget"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetSpectatorWaiting_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetspectatorwaiting>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientSetSpectatorWaiting"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetHUD_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsethud>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientSetHUD"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetForceMipLevelsToBeResident_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetforcemiplevelstoberesident>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientSetForceMipLevelsToBeResident"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetCinematicMode_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcinematicmode>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientSetCinematicMode"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetCameraMode_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcameramode>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientSetCameraMode"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetCameraFade_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcamerafade>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientSetCameraFade"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetBlockOnAsyncLoading_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetblockonasyncloading>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientSetBlockOnAsyncLoading"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientReturnToMainMenuWithTextReason_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreturntomainmenuwithtextreason>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientReturnToMainMenuWithTextReason"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientReturnToMainMenu_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreturntomainmenu>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientReturnToMainMenu"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientRetryClientRestart_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientretryclientrestart>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientRetryClientRestart"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientRestart_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientrestart>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientRestart"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientReset_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreset>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientReset"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientRepObjRef_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientrepobjref>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientRepObjRef"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientReceiveLocalizedMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreceivelocalizedmessage>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientReceiveLocalizedMessage"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPrestreamTextures_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientprestreamtextures>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientPrestreamTextures"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPrepareMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientpreparemapchange>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientPrepareMapChange"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlaySoundAtLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaysoundatlocation>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientPlaySoundAtLocation"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlaySound_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaysound>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientPlaySound"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlayForceFeedback_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplayforcefeedback>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientPlayForceFeedback"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlayCameraShake_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaycamerashake>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientPlayCameraShake"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientPlayCameraAnim_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaycameraanim>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientPlayCameraAnim"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientMutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientmuteplayer>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientMutePlayer"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientmessage>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientMessage"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientIgnoreMoveInput_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientignoremoveinput>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientIgnoreMoveInput"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientIgnoreLookInput_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientignorelookinput>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientIgnoreLookInput"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientGotoState_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientgotostate>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientGotoState"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientGameEnded_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientgameended>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientGameEnded"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientForceGarbageCollection_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientforcegarbagecollection>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientForceGarbageCollection"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientFlushLevelStreaming_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientflushlevelstreaming>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientFlushLevelStreaming"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientEndOnlineSession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientendonlinesession>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientEndOnlineSession"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientEnableNetworkVoice_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientenablenetworkvoice>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientEnableNetworkVoice"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientCommitMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcommitmapchange>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientCommitMapChange"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientClearCameraLensEffects_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientclearcameralenseffects>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientClearCameraLensEffects"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientCapBandwidth_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcapbandwidth>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientCapBandwidth"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientCancelPendingMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcancelpendingmapchange>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientCancelPendingMapChange"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientAddTextureStreamingLoc_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientaddtexturestreamingloc>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientAddTextureStreamingLoc"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetRotation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetrotation>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientSetRotation"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ClientSetLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetlocation>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ClientSetLocation"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerTryJoinGame_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservertryjoingame>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerTryJoinGame"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerViewSelf_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewself>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerViewSelf"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerViewPrevPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewprevplayer>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerViewPrevPlayer"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerViewNextPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewnextplayer>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerViewNextPlayer"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerVerifyViewTarget_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserververifyviewtarget>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerVerifyViewTarget"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerUpdateMultipleLevelsVisibility_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatemultiplelevelsvisibility>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerUpdateMultipleLevelsVisibility"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerUpdateLevelVisibility_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatelevelvisibility>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerUpdateLevelVisibility"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerUpdateCamera_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatecamera>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerUpdateCamera"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerUnmutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverunmuteplayer>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerUnmutePlayer"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerToggleAILogging_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservertoggleailogging>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerToggleAILogging"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerShortTimeout_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservershorttimeout>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerShortTimeout"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerSetSpectatorWaiting_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserversetspectatorwaiting>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerSetSpectatorWaiting"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerSetSpectatorLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserversetspectatorlocation>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerSetSpectatorLocation"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerRestartPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverrestartplayer>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerRestartPlayer"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerPause_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverpause>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerPause"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerNotifyLoadedWorld_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservernotifyloadedworld>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerNotifyLoadedWorld"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerMutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservermuteplayer>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerMutePlayer"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerCheckClientPossessionReliable_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercheckclientpossessionreliable>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerCheckClientPossessionReliable"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerCheckClientPossession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercheckclientpossession>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerCheckClientPossession"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerChangeName_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverchangename>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerChangeName"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerCamera_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercamera>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerCamera"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_SampleGamePlayerController::ServerAcknowledgePossession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserveracknowledgepossession>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("ServerAcknowledgePossession"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}
