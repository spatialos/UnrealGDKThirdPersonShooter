// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically
#pragma once

#include "CoreMinimal.h"
#include <improbable/worker.h>
#include <improbable/view.h>
#include <improbable/unreal/gdk/core_types.h>
#include <improbable/unreal/gdk/unreal_metadata.h>
#include <improbable/unreal/generated/UnrealSampleGamePlayerController.h>
#include "ScopedViewCallbacks.h"
#include "SpatialTypeBinding.h"
#include "SpatialTypeBinding_SampleGamePlayerController.generated.h"

UCLASS()
class USpatialTypeBinding_SampleGamePlayerController : public USpatialTypeBinding
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
	using FRPCSender = void (USpatialTypeBinding_SampleGamePlayerController::*)(worker::Connection* const, void*, UObject*);
	TMap<FName, FRPCSender> RPCToSenderMap;

	FRepHandlePropertyMap RepHandleToPropertyMap;
	FMigratableHandlePropertyMap MigratableHandleToPropertyMap;

	// Component update helper functions.
	void BuildSpatialComponentUpdate(
		const FPropertyChangeState& Changes,
		USpatialActorChannel* Channel,
		improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData::Update& MigratableDataUpdate,
		bool& bMigratableDataUpdateChanged) const;
	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Migratable(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealSampleGamePlayerControllerSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealSampleGamePlayerControllerMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Migratable(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealSampleGamePlayerControllerMigratableData::Update& Update) const;

	// RPC command sender functions.
	void ClientJoinResults_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
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
	void ServerTryJoinGame_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
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
	void ClientJoinResults_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientjoinresults>& Op);
	void OnServerStartedVisualLogger_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrolleronserverstartedvisuallogger>& Op);
	void ClientWasKicked_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientwaskicked>& Op);
	void ClientVoiceHandshakeComplete_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientvoicehandshakecomplete>& Op);
	void ClientUpdateMultipleLevelsStreamingStatus_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientupdatemultiplelevelsstreamingstatus>& Op);
	void ClientUpdateLevelStreamingStatus_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientupdatelevelstreamingstatus>& Op);
	void ClientUnmutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientunmuteplayer>& Op);
	void ClientTravelInternal_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclienttravelinternal>& Op);
	void ClientTeamMessage_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientteammessage>& Op);
	void ClientStopForceFeedback_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopforcefeedback>& Op);
	void ClientStopCameraShake_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopcamerashake>& Op);
	void ClientStopCameraAnim_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopcameraanim>& Op);
	void ClientStartOnlineSession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstartonlinesession>& Op);
	void ClientSpawnCameraLensEffect_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientspawncameralenseffect>& Op);
	void ClientSetViewTarget_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetviewtarget>& Op);
	void ClientSetSpectatorWaiting_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetspectatorwaiting>& Op);
	void ClientSetHUD_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsethud>& Op);
	void ClientSetForceMipLevelsToBeResident_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetforcemiplevelstoberesident>& Op);
	void ClientSetCinematicMode_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcinematicmode>& Op);
	void ClientSetCameraMode_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcameramode>& Op);
	void ClientSetCameraFade_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcamerafade>& Op);
	void ClientSetBlockOnAsyncLoading_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetblockonasyncloading>& Op);
	void ClientReturnToMainMenuWithTextReason_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreturntomainmenuwithtextreason>& Op);
	void ClientReturnToMainMenu_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreturntomainmenu>& Op);
	void ClientRetryClientRestart_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientretryclientrestart>& Op);
	void ClientRestart_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientrestart>& Op);
	void ClientReset_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreset>& Op);
	void ClientRepObjRef_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientrepobjref>& Op);
	void ClientReceiveLocalizedMessage_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreceivelocalizedmessage>& Op);
	void ClientPrestreamTextures_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientprestreamtextures>& Op);
	void ClientPrepareMapChange_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientpreparemapchange>& Op);
	void ClientPlaySoundAtLocation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaysoundatlocation>& Op);
	void ClientPlaySound_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaysound>& Op);
	void ClientPlayForceFeedback_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplayforcefeedback>& Op);
	void ClientPlayCameraShake_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaycamerashake>& Op);
	void ClientPlayCameraAnim_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaycameraanim>& Op);
	void ClientMutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientmuteplayer>& Op);
	void ClientMessage_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientmessage>& Op);
	void ClientIgnoreMoveInput_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientignoremoveinput>& Op);
	void ClientIgnoreLookInput_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientignorelookinput>& Op);
	void ClientGotoState_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientgotostate>& Op);
	void ClientGameEnded_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientgameended>& Op);
	void ClientForceGarbageCollection_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientforcegarbagecollection>& Op);
	void ClientFlushLevelStreaming_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientflushlevelstreaming>& Op);
	void ClientEndOnlineSession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientendonlinesession>& Op);
	void ClientEnableNetworkVoice_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientenablenetworkvoice>& Op);
	void ClientCommitMapChange_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcommitmapchange>& Op);
	void ClientClearCameraLensEffects_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientclearcameralenseffects>& Op);
	void ClientCapBandwidth_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcapbandwidth>& Op);
	void ClientCancelPendingMapChange_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcancelpendingmapchange>& Op);
	void ClientAddTextureStreamingLoc_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientaddtexturestreamingloc>& Op);
	void ClientSetRotation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetrotation>& Op);
	void ClientSetLocation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetlocation>& Op);
	void ServerTryJoinGame_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservertryjoingame>& Op);
	void ServerViewSelf_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewself>& Op);
	void ServerViewPrevPlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewprevplayer>& Op);
	void ServerViewNextPlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewnextplayer>& Op);
	void ServerVerifyViewTarget_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserververifyviewtarget>& Op);
	void ServerUpdateMultipleLevelsVisibility_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatemultiplelevelsvisibility>& Op);
	void ServerUpdateLevelVisibility_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatelevelvisibility>& Op);
	void ServerUpdateCamera_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatecamera>& Op);
	void ServerUnmutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverunmuteplayer>& Op);
	void ServerToggleAILogging_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservertoggleailogging>& Op);
	void ServerShortTimeout_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservershorttimeout>& Op);
	void ServerSetSpectatorWaiting_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserversetspectatorwaiting>& Op);
	void ServerSetSpectatorLocation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserversetspectatorlocation>& Op);
	void ServerRestartPlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverrestartplayer>& Op);
	void ServerPause_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverpause>& Op);
	void ServerNotifyLoadedWorld_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservernotifyloadedworld>& Op);
	void ServerMutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservermuteplayer>& Op);
	void ServerCheckClientPossessionReliable_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercheckclientpossessionreliable>& Op);
	void ServerCheckClientPossession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercheckclientpossession>& Op);
	void ServerChangeName_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverchangename>& Op);
	void ServerCamera_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercamera>& Op);
	void ServerAcknowledgePossession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserveracknowledgepossession>& Op);

	// RPC command response handler functions.
	void ClientJoinResults_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientjoinresults>& Op);
	void OnServerStartedVisualLogger_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrolleronserverstartedvisuallogger>& Op);
	void ClientWasKicked_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientwaskicked>& Op);
	void ClientVoiceHandshakeComplete_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientvoicehandshakecomplete>& Op);
	void ClientUpdateMultipleLevelsStreamingStatus_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientupdatemultiplelevelsstreamingstatus>& Op);
	void ClientUpdateLevelStreamingStatus_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientupdatelevelstreamingstatus>& Op);
	void ClientUnmutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientunmuteplayer>& Op);
	void ClientTravelInternal_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclienttravelinternal>& Op);
	void ClientTeamMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientteammessage>& Op);
	void ClientStopForceFeedback_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopforcefeedback>& Op);
	void ClientStopCameraShake_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopcamerashake>& Op);
	void ClientStopCameraAnim_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstopcameraanim>& Op);
	void ClientStartOnlineSession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientstartonlinesession>& Op);
	void ClientSpawnCameraLensEffect_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientspawncameralenseffect>& Op);
	void ClientSetViewTarget_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetviewtarget>& Op);
	void ClientSetSpectatorWaiting_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetspectatorwaiting>& Op);
	void ClientSetHUD_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsethud>& Op);
	void ClientSetForceMipLevelsToBeResident_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetforcemiplevelstoberesident>& Op);
	void ClientSetCinematicMode_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcinematicmode>& Op);
	void ClientSetCameraMode_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcameramode>& Op);
	void ClientSetCameraFade_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetcamerafade>& Op);
	void ClientSetBlockOnAsyncLoading_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetblockonasyncloading>& Op);
	void ClientReturnToMainMenuWithTextReason_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreturntomainmenuwithtextreason>& Op);
	void ClientReturnToMainMenu_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreturntomainmenu>& Op);
	void ClientRetryClientRestart_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientretryclientrestart>& Op);
	void ClientRestart_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientrestart>& Op);
	void ClientReset_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreset>& Op);
	void ClientRepObjRef_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientrepobjref>& Op);
	void ClientReceiveLocalizedMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientreceivelocalizedmessage>& Op);
	void ClientPrestreamTextures_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientprestreamtextures>& Op);
	void ClientPrepareMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientpreparemapchange>& Op);
	void ClientPlaySoundAtLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaysoundatlocation>& Op);
	void ClientPlaySound_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaysound>& Op);
	void ClientPlayForceFeedback_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplayforcefeedback>& Op);
	void ClientPlayCameraShake_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaycamerashake>& Op);
	void ClientPlayCameraAnim_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientplaycameraanim>& Op);
	void ClientMutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientmuteplayer>& Op);
	void ClientMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientmessage>& Op);
	void ClientIgnoreMoveInput_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientignoremoveinput>& Op);
	void ClientIgnoreLookInput_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientignorelookinput>& Op);
	void ClientGotoState_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientgotostate>& Op);
	void ClientGameEnded_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientgameended>& Op);
	void ClientForceGarbageCollection_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientforcegarbagecollection>& Op);
	void ClientFlushLevelStreaming_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientflushlevelstreaming>& Op);
	void ClientEndOnlineSession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientendonlinesession>& Op);
	void ClientEnableNetworkVoice_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientenablenetworkvoice>& Op);
	void ClientCommitMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcommitmapchange>& Op);
	void ClientClearCameraLensEffects_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientclearcameralenseffects>& Op);
	void ClientCapBandwidth_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcapbandwidth>& Op);
	void ClientCancelPendingMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientcancelpendingmapchange>& Op);
	void ClientAddTextureStreamingLoc_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientaddtexturestreamingloc>& Op);
	void ClientSetRotation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetrotation>& Op);
	void ClientSetLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerClientRPCs::Commands::Samplegameplayercontrollerclientsetlocation>& Op);
	void ServerTryJoinGame_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservertryjoingame>& Op);
	void ServerViewSelf_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewself>& Op);
	void ServerViewPrevPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewprevplayer>& Op);
	void ServerViewNextPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverviewnextplayer>& Op);
	void ServerVerifyViewTarget_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserververifyviewtarget>& Op);
	void ServerUpdateMultipleLevelsVisibility_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatemultiplelevelsvisibility>& Op);
	void ServerUpdateLevelVisibility_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatelevelvisibility>& Op);
	void ServerUpdateCamera_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverupdatecamera>& Op);
	void ServerUnmutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverunmuteplayer>& Op);
	void ServerToggleAILogging_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservertoggleailogging>& Op);
	void ServerShortTimeout_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservershorttimeout>& Op);
	void ServerSetSpectatorWaiting_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserversetspectatorwaiting>& Op);
	void ServerSetSpectatorLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserversetspectatorlocation>& Op);
	void ServerRestartPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverrestartplayer>& Op);
	void ServerPause_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverpause>& Op);
	void ServerNotifyLoadedWorld_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservernotifyloadedworld>& Op);
	void ServerMutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservermuteplayer>& Op);
	void ServerCheckClientPossessionReliable_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercheckclientpossessionreliable>& Op);
	void ServerCheckClientPossession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercheckclientpossession>& Op);
	void ServerChangeName_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserverchangename>& Op);
	void ServerCamera_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerservercamera>& Op);
	void ServerAcknowledgePossession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealSampleGamePlayerControllerServerRPCs::Commands::Samplegameplayercontrollerserveracknowledgepossession>& Op);
};
