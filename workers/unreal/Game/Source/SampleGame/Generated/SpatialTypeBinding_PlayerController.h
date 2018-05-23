// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically
#pragma once

#include "CoreMinimal.h"
#include <improbable/worker.h>
#include <improbable/view.h>
#include <improbable/unreal/gdk/core_types.h>
#include <improbable/unreal/gdk/unreal_metadata.h>
#include <improbable/unreal/generated/UnrealPlayerController.h>
#include "ScopedViewCallbacks.h"
#include "SpatialTypeBinding.h"
#include "SpatialTypeBinding_PlayerController.generated.h"

UCLASS()
class USpatialTypeBinding_PlayerController : public USpatialTypeBinding
{
	GENERATED_BODY()

public:
	const FRepHandlePropertyMap& GetRepHandlePropertyMap() const override;
	const FMigratableHandlePropertyMap& GetMigratableHandlePropertyMap() const override;

	UClass* GetBoundClass() const override;

	void Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap) override;
	void BindToView() override;
	void UnbindFromView() override;

	worker::Entity CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const override;
	void SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const FEntityId& EntityId) const override;
	void SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters) override;

	void ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const override;
	worker::Map<worker::ComponentId, worker::InterestOverride> GetInterestOverrideMap(bool bIsClient, bool bAutonomousProxy) const override;

private:
	improbable::unreal::callbacks::FScopedViewCallbacks ViewCallbacks;

	// RPC to sender map.
	using FRPCSender = void (USpatialTypeBinding_PlayerController::*)(worker::Connection* const, void*, UObject*);
	TMap<FName, FRPCSender> RPCToSenderMap;

	// Component update helper functions.
	void BuildSpatialComponentUpdate(
		const FPropertyChangeState& Changes,
		USpatialActorChannel* Channel,
		improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		improbable::unreal::generated::UnrealPlayerControllerMigratableData::Update& MigratableDataUpdate,
		bool& bMigratableDataUpdateChanged) const;
	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Migratable(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealPlayerControllerMigratableData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Migratable(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealPlayerControllerMigratableData::Update& Update) const;

	// RPC command sender functions.
	void OnServerStartedVisualLogger_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientWasKicked_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientVoiceHandshakeComplete_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientUpdateMultipleLevelsStreamingStatus_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientUpdateLevelStreamingStatus_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientUnmutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientTravelInternal_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientTeamMessage_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientStopForceFeedback_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientStopCameraShake_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientStopCameraAnim_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientStartOnlineSession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSpawnCameraLensEffect_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetViewTarget_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetSpectatorWaiting_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetHUD_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetForceMipLevelsToBeResident_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetCinematicMode_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetCameraMode_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetCameraFade_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetBlockOnAsyncLoading_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientReturnToMainMenuWithTextReason_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientReturnToMainMenu_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientRetryClientRestart_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientRestart_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientReset_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientRepObjRef_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientReceiveLocalizedMessage_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPrestreamTextures_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPrepareMapChange_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlaySoundAtLocation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlaySound_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlayForceFeedback_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlayCameraShake_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlayCameraAnim_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientMutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientMessage_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientIgnoreMoveInput_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientIgnoreLookInput_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientGotoState_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientGameEnded_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientForceGarbageCollection_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientFlushLevelStreaming_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientEndOnlineSession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientEnableNetworkVoice_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCommitMapChange_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientClearCameraLensEffects_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCapBandwidth_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCancelPendingMapChange_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAddTextureStreamingLoc_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetRotation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetLocation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerViewSelf_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerViewPrevPlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerViewNextPlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerVerifyViewTarget_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerUpdateMultipleLevelsVisibility_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerUpdateLevelVisibility_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerUpdateCamera_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerUnmutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerToggleAILogging_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerShortTimeout_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerSetSpectatorWaiting_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerSetSpectatorLocation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerRestartPlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerPause_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerNotifyLoadedWorld_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerCheckClientPossessionReliable_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerCheckClientPossession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerChangeName_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerCamera_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerAcknowledgePossession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);

	// RPC command request handler functions.
	void OnServerStartedVisualLogger_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrolleronserverstartedvisuallogger>& Op);
	void ClientWasKicked_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientwaskicked>& Op);
	void ClientVoiceHandshakeComplete_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientvoicehandshakecomplete>& Op);
	void ClientUpdateMultipleLevelsStreamingStatus_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientupdatemultiplelevelsstreamingstatus>& Op);
	void ClientUpdateLevelStreamingStatus_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientupdatelevelstreamingstatus>& Op);
	void ClientUnmutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientunmuteplayer>& Op);
	void ClientTravelInternal_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclienttravelinternal>& Op);
	void ClientTeamMessage_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientteammessage>& Op);
	void ClientStopForceFeedback_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientstopforcefeedback>& Op);
	void ClientStopCameraShake_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientstopcamerashake>& Op);
	void ClientStopCameraAnim_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientstopcameraanim>& Op);
	void ClientStartOnlineSession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientstartonlinesession>& Op);
	void ClientSpawnCameraLensEffect_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientspawncameralenseffect>& Op);
	void ClientSetViewTarget_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetviewtarget>& Op);
	void ClientSetSpectatorWaiting_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetspectatorwaiting>& Op);
	void ClientSetHUD_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsethud>& Op);
	void ClientSetForceMipLevelsToBeResident_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetforcemiplevelstoberesident>& Op);
	void ClientSetCinematicMode_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetcinematicmode>& Op);
	void ClientSetCameraMode_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetcameramode>& Op);
	void ClientSetCameraFade_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetcamerafade>& Op);
	void ClientSetBlockOnAsyncLoading_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetblockonasyncloading>& Op);
	void ClientReturnToMainMenuWithTextReason_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientreturntomainmenuwithtextreason>& Op);
	void ClientReturnToMainMenu_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientreturntomainmenu>& Op);
	void ClientRetryClientRestart_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientretryclientrestart>& Op);
	void ClientRestart_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientrestart>& Op);
	void ClientReset_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientreset>& Op);
	void ClientRepObjRef_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientrepobjref>& Op);
	void ClientReceiveLocalizedMessage_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientreceivelocalizedmessage>& Op);
	void ClientPrestreamTextures_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientprestreamtextures>& Op);
	void ClientPrepareMapChange_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientpreparemapchange>& Op);
	void ClientPlaySoundAtLocation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientplaysoundatlocation>& Op);
	void ClientPlaySound_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientplaysound>& Op);
	void ClientPlayForceFeedback_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientplayforcefeedback>& Op);
	void ClientPlayCameraShake_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientplaycamerashake>& Op);
	void ClientPlayCameraAnim_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientplaycameraanim>& Op);
	void ClientMutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientmuteplayer>& Op);
	void ClientMessage_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientmessage>& Op);
	void ClientIgnoreMoveInput_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientignoremoveinput>& Op);
	void ClientIgnoreLookInput_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientignorelookinput>& Op);
	void ClientGotoState_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientgotostate>& Op);
	void ClientGameEnded_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientgameended>& Op);
	void ClientForceGarbageCollection_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientforcegarbagecollection>& Op);
	void ClientFlushLevelStreaming_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientflushlevelstreaming>& Op);
	void ClientEndOnlineSession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientendonlinesession>& Op);
	void ClientEnableNetworkVoice_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientenablenetworkvoice>& Op);
	void ClientCommitMapChange_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientcommitmapchange>& Op);
	void ClientClearCameraLensEffects_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientclearcameralenseffects>& Op);
	void ClientCapBandwidth_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientcapbandwidth>& Op);
	void ClientCancelPendingMapChange_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientcancelpendingmapchange>& Op);
	void ClientAddTextureStreamingLoc_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientaddtexturestreamingloc>& Op);
	void ClientSetRotation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetrotation>& Op);
	void ClientSetLocation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetlocation>& Op);
	void ServerViewSelf_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverviewself>& Op);
	void ServerViewPrevPlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverviewprevplayer>& Op);
	void ServerViewNextPlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverviewnextplayer>& Op);
	void ServerVerifyViewTarget_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserververifyviewtarget>& Op);
	void ServerUpdateMultipleLevelsVisibility_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverupdatemultiplelevelsvisibility>& Op);
	void ServerUpdateLevelVisibility_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverupdatelevelvisibility>& Op);
	void ServerUpdateCamera_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverupdatecamera>& Op);
	void ServerUnmutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverunmuteplayer>& Op);
	void ServerToggleAILogging_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerservertoggleailogging>& Op);
	void ServerShortTimeout_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerservershorttimeout>& Op);
	void ServerSetSpectatorWaiting_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserversetspectatorwaiting>& Op);
	void ServerSetSpectatorLocation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserversetspectatorlocation>& Op);
	void ServerRestartPlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverrestartplayer>& Op);
	void ServerPause_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverpause>& Op);
	void ServerNotifyLoadedWorld_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerservernotifyloadedworld>& Op);
	void ServerMutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerservermuteplayer>& Op);
	void ServerCheckClientPossessionReliable_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerservercheckclientpossessionreliable>& Op);
	void ServerCheckClientPossession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerservercheckclientpossession>& Op);
	void ServerChangeName_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverchangename>& Op);
	void ServerCamera_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerservercamera>& Op);
	void ServerAcknowledgePossession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserveracknowledgepossession>& Op);

	// RPC command response handler functions.
	void OnServerStartedVisualLogger_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrolleronserverstartedvisuallogger>& Op);
	void ClientWasKicked_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientwaskicked>& Op);
	void ClientVoiceHandshakeComplete_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientvoicehandshakecomplete>& Op);
	void ClientUpdateMultipleLevelsStreamingStatus_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientupdatemultiplelevelsstreamingstatus>& Op);
	void ClientUpdateLevelStreamingStatus_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientupdatelevelstreamingstatus>& Op);
	void ClientUnmutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientunmuteplayer>& Op);
	void ClientTravelInternal_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclienttravelinternal>& Op);
	void ClientTeamMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientteammessage>& Op);
	void ClientStopForceFeedback_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientstopforcefeedback>& Op);
	void ClientStopCameraShake_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientstopcamerashake>& Op);
	void ClientStopCameraAnim_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientstopcameraanim>& Op);
	void ClientStartOnlineSession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientstartonlinesession>& Op);
	void ClientSpawnCameraLensEffect_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientspawncameralenseffect>& Op);
	void ClientSetViewTarget_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetviewtarget>& Op);
	void ClientSetSpectatorWaiting_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetspectatorwaiting>& Op);
	void ClientSetHUD_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsethud>& Op);
	void ClientSetForceMipLevelsToBeResident_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetforcemiplevelstoberesident>& Op);
	void ClientSetCinematicMode_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetcinematicmode>& Op);
	void ClientSetCameraMode_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetcameramode>& Op);
	void ClientSetCameraFade_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetcamerafade>& Op);
	void ClientSetBlockOnAsyncLoading_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetblockonasyncloading>& Op);
	void ClientReturnToMainMenuWithTextReason_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientreturntomainmenuwithtextreason>& Op);
	void ClientReturnToMainMenu_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientreturntomainmenu>& Op);
	void ClientRetryClientRestart_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientretryclientrestart>& Op);
	void ClientRestart_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientrestart>& Op);
	void ClientReset_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientreset>& Op);
	void ClientRepObjRef_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientrepobjref>& Op);
	void ClientReceiveLocalizedMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientreceivelocalizedmessage>& Op);
	void ClientPrestreamTextures_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientprestreamtextures>& Op);
	void ClientPrepareMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientpreparemapchange>& Op);
	void ClientPlaySoundAtLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientplaysoundatlocation>& Op);
	void ClientPlaySound_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientplaysound>& Op);
	void ClientPlayForceFeedback_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientplayforcefeedback>& Op);
	void ClientPlayCameraShake_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientplaycamerashake>& Op);
	void ClientPlayCameraAnim_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientplaycameraanim>& Op);
	void ClientMutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientmuteplayer>& Op);
	void ClientMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientmessage>& Op);
	void ClientIgnoreMoveInput_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientignoremoveinput>& Op);
	void ClientIgnoreLookInput_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientignorelookinput>& Op);
	void ClientGotoState_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientgotostate>& Op);
	void ClientGameEnded_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientgameended>& Op);
	void ClientForceGarbageCollection_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientforcegarbagecollection>& Op);
	void ClientFlushLevelStreaming_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientflushlevelstreaming>& Op);
	void ClientEndOnlineSession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientendonlinesession>& Op);
	void ClientEnableNetworkVoice_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientenablenetworkvoice>& Op);
	void ClientCommitMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientcommitmapchange>& Op);
	void ClientClearCameraLensEffects_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientclearcameralenseffects>& Op);
	void ClientCapBandwidth_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientcapbandwidth>& Op);
	void ClientCancelPendingMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientcancelpendingmapchange>& Op);
	void ClientAddTextureStreamingLoc_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientaddtexturestreamingloc>& Op);
	void ClientSetRotation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetrotation>& Op);
	void ClientSetLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Playercontrollerclientsetlocation>& Op);
	void ServerViewSelf_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverviewself>& Op);
	void ServerViewPrevPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverviewprevplayer>& Op);
	void ServerViewNextPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverviewnextplayer>& Op);
	void ServerVerifyViewTarget_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserververifyviewtarget>& Op);
	void ServerUpdateMultipleLevelsVisibility_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverupdatemultiplelevelsvisibility>& Op);
	void ServerUpdateLevelVisibility_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverupdatelevelvisibility>& Op);
	void ServerUpdateCamera_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverupdatecamera>& Op);
	void ServerUnmutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverunmuteplayer>& Op);
	void ServerToggleAILogging_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerservertoggleailogging>& Op);
	void ServerShortTimeout_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerservershorttimeout>& Op);
	void ServerSetSpectatorWaiting_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserversetspectatorwaiting>& Op);
	void ServerSetSpectatorLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserversetspectatorlocation>& Op);
	void ServerRestartPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverrestartplayer>& Op);
	void ServerPause_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverpause>& Op);
	void ServerNotifyLoadedWorld_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerservernotifyloadedworld>& Op);
	void ServerMutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerservermuteplayer>& Op);
	void ServerCheckClientPossessionReliable_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerservercheckclientpossessionreliable>& Op);
	void ServerCheckClientPossession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerservercheckclientpossession>& Op);
	void ServerChangeName_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserverchangename>& Op);
	void ServerCamera_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerservercamera>& Op);
	void ServerAcknowledgePossession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Playercontrollerserveracknowledgepossession>& Op);
};
