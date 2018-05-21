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
	void OnServerStartedVisualLogger_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Onserverstartedvisuallogger>& Op);
	void ClientWasKicked_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientwaskicked>& Op);
	void ClientVoiceHandshakeComplete_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientvoicehandshakecomplete>& Op);
	void ClientUpdateMultipleLevelsStreamingStatus_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientupdatemultiplelevelsstreamingstatus>& Op);
	void ClientUpdateLevelStreamingStatus_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientupdatelevelstreamingstatus>& Op);
	void ClientUnmutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientunmuteplayer>& Op);
	void ClientTravelInternal_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clienttravelinternal>& Op);
	void ClientTeamMessage_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientteammessage>& Op);
	void ClientStopForceFeedback_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientstopforcefeedback>& Op);
	void ClientStopCameraShake_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientstopcamerashake>& Op);
	void ClientStopCameraAnim_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientstopcameraanim>& Op);
	void ClientStartOnlineSession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientstartonlinesession>& Op);
	void ClientSpawnCameraLensEffect_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientspawncameralenseffect>& Op);
	void ClientSetViewTarget_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetviewtarget>& Op);
	void ClientSetSpectatorWaiting_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetspectatorwaiting>& Op);
	void ClientSetHUD_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsethud>& Op);
	void ClientSetForceMipLevelsToBeResident_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetforcemiplevelstoberesident>& Op);
	void ClientSetCinematicMode_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetcinematicmode>& Op);
	void ClientSetCameraMode_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetcameramode>& Op);
	void ClientSetCameraFade_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetcamerafade>& Op);
	void ClientSetBlockOnAsyncLoading_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetblockonasyncloading>& Op);
	void ClientReturnToMainMenuWithTextReason_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientreturntomainmenuwithtextreason>& Op);
	void ClientReturnToMainMenu_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientreturntomainmenu>& Op);
	void ClientRetryClientRestart_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientretryclientrestart>& Op);
	void ClientRestart_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientrestart>& Op);
	void ClientReset_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientreset>& Op);
	void ClientRepObjRef_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientrepobjref>& Op);
	void ClientReceiveLocalizedMessage_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientreceivelocalizedmessage>& Op);
	void ClientPrestreamTextures_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientprestreamtextures>& Op);
	void ClientPrepareMapChange_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientpreparemapchange>& Op);
	void ClientPlaySoundAtLocation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientplaysoundatlocation>& Op);
	void ClientPlaySound_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientplaysound>& Op);
	void ClientPlayForceFeedback_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientplayforcefeedback>& Op);
	void ClientPlayCameraShake_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientplaycamerashake>& Op);
	void ClientPlayCameraAnim_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientplaycameraanim>& Op);
	void ClientMutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientmuteplayer>& Op);
	void ClientMessage_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientmessage>& Op);
	void ClientIgnoreMoveInput_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientignoremoveinput>& Op);
	void ClientIgnoreLookInput_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientignorelookinput>& Op);
	void ClientGotoState_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientgotostate>& Op);
	void ClientGameEnded_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientgameended>& Op);
	void ClientForceGarbageCollection_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientforcegarbagecollection>& Op);
	void ClientFlushLevelStreaming_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientflushlevelstreaming>& Op);
	void ClientEndOnlineSession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientendonlinesession>& Op);
	void ClientEnableNetworkVoice_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientenablenetworkvoice>& Op);
	void ClientCommitMapChange_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientcommitmapchange>& Op);
	void ClientClearCameraLensEffects_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientclearcameralenseffects>& Op);
	void ClientCapBandwidth_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientcapbandwidth>& Op);
	void ClientCancelPendingMapChange_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientcancelpendingmapchange>& Op);
	void ClientAddTextureStreamingLoc_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientaddtexturestreamingloc>& Op);
	void ClientSetRotation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetrotation>& Op);
	void ClientSetLocation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetlocation>& Op);
	void ServerViewSelf_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverviewself>& Op);
	void ServerViewPrevPlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverviewprevplayer>& Op);
	void ServerViewNextPlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverviewnextplayer>& Op);
	void ServerVerifyViewTarget_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serververifyviewtarget>& Op);
	void ServerUpdateMultipleLevelsVisibility_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverupdatemultiplelevelsvisibility>& Op);
	void ServerUpdateLevelVisibility_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverupdatelevelvisibility>& Op);
	void ServerUpdateCamera_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverupdatecamera>& Op);
	void ServerUnmutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverunmuteplayer>& Op);
	void ServerToggleAILogging_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Servertoggleailogging>& Op);
	void ServerShortTimeout_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Servershorttimeout>& Op);
	void ServerSetSpectatorWaiting_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serversetspectatorwaiting>& Op);
	void ServerSetSpectatorLocation_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serversetspectatorlocation>& Op);
	void ServerRestartPlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverrestartplayer>& Op);
	void ServerPause_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverpause>& Op);
	void ServerNotifyLoadedWorld_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Servernotifyloadedworld>& Op);
	void ServerMutePlayer_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Servermuteplayer>& Op);
	void ServerCheckClientPossessionReliable_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Servercheckclientpossessionreliable>& Op);
	void ServerCheckClientPossession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Servercheckclientpossession>& Op);
	void ServerChangeName_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverchangename>& Op);
	void ServerCamera_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Servercamera>& Op);
	void ServerAcknowledgePossession_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serveracknowledgepossession>& Op);

	// RPC command response handler functions.
	void OnServerStartedVisualLogger_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Onserverstartedvisuallogger>& Op);
	void ClientWasKicked_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientwaskicked>& Op);
	void ClientVoiceHandshakeComplete_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientvoicehandshakecomplete>& Op);
	void ClientUpdateMultipleLevelsStreamingStatus_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientupdatemultiplelevelsstreamingstatus>& Op);
	void ClientUpdateLevelStreamingStatus_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientupdatelevelstreamingstatus>& Op);
	void ClientUnmutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientunmuteplayer>& Op);
	void ClientTravelInternal_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clienttravelinternal>& Op);
	void ClientTeamMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientteammessage>& Op);
	void ClientStopForceFeedback_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientstopforcefeedback>& Op);
	void ClientStopCameraShake_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientstopcamerashake>& Op);
	void ClientStopCameraAnim_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientstopcameraanim>& Op);
	void ClientStartOnlineSession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientstartonlinesession>& Op);
	void ClientSpawnCameraLensEffect_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientspawncameralenseffect>& Op);
	void ClientSetViewTarget_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetviewtarget>& Op);
	void ClientSetSpectatorWaiting_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetspectatorwaiting>& Op);
	void ClientSetHUD_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsethud>& Op);
	void ClientSetForceMipLevelsToBeResident_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetforcemiplevelstoberesident>& Op);
	void ClientSetCinematicMode_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetcinematicmode>& Op);
	void ClientSetCameraMode_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetcameramode>& Op);
	void ClientSetCameraFade_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetcamerafade>& Op);
	void ClientSetBlockOnAsyncLoading_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetblockonasyncloading>& Op);
	void ClientReturnToMainMenuWithTextReason_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientreturntomainmenuwithtextreason>& Op);
	void ClientReturnToMainMenu_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientreturntomainmenu>& Op);
	void ClientRetryClientRestart_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientretryclientrestart>& Op);
	void ClientRestart_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientrestart>& Op);
	void ClientReset_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientreset>& Op);
	void ClientRepObjRef_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientrepobjref>& Op);
	void ClientReceiveLocalizedMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientreceivelocalizedmessage>& Op);
	void ClientPrestreamTextures_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientprestreamtextures>& Op);
	void ClientPrepareMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientpreparemapchange>& Op);
	void ClientPlaySoundAtLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientplaysoundatlocation>& Op);
	void ClientPlaySound_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientplaysound>& Op);
	void ClientPlayForceFeedback_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientplayforcefeedback>& Op);
	void ClientPlayCameraShake_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientplaycamerashake>& Op);
	void ClientPlayCameraAnim_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientplaycameraanim>& Op);
	void ClientMutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientmuteplayer>& Op);
	void ClientMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientmessage>& Op);
	void ClientIgnoreMoveInput_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientignoremoveinput>& Op);
	void ClientIgnoreLookInput_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientignorelookinput>& Op);
	void ClientGotoState_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientgotostate>& Op);
	void ClientGameEnded_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientgameended>& Op);
	void ClientForceGarbageCollection_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientforcegarbagecollection>& Op);
	void ClientFlushLevelStreaming_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientflushlevelstreaming>& Op);
	void ClientEndOnlineSession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientendonlinesession>& Op);
	void ClientEnableNetworkVoice_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientenablenetworkvoice>& Op);
	void ClientCommitMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientcommitmapchange>& Op);
	void ClientClearCameraLensEffects_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientclearcameralenseffects>& Op);
	void ClientCapBandwidth_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientcapbandwidth>& Op);
	void ClientCancelPendingMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientcancelpendingmapchange>& Op);
	void ClientAddTextureStreamingLoc_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientaddtexturestreamingloc>& Op);
	void ClientSetRotation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetrotation>& Op);
	void ClientSetLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Commands::Clientsetlocation>& Op);
	void ServerViewSelf_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverviewself>& Op);
	void ServerViewPrevPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverviewprevplayer>& Op);
	void ServerViewNextPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverviewnextplayer>& Op);
	void ServerVerifyViewTarget_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serververifyviewtarget>& Op);
	void ServerUpdateMultipleLevelsVisibility_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverupdatemultiplelevelsvisibility>& Op);
	void ServerUpdateLevelVisibility_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverupdatelevelvisibility>& Op);
	void ServerUpdateCamera_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverupdatecamera>& Op);
	void ServerUnmutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverunmuteplayer>& Op);
	void ServerToggleAILogging_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Servertoggleailogging>& Op);
	void ServerShortTimeout_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Servershorttimeout>& Op);
	void ServerSetSpectatorWaiting_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serversetspectatorwaiting>& Op);
	void ServerSetSpectatorLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serversetspectatorlocation>& Op);
	void ServerRestartPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverrestartplayer>& Op);
	void ServerPause_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverpause>& Op);
	void ServerNotifyLoadedWorld_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Servernotifyloadedworld>& Op);
	void ServerMutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Servermuteplayer>& Op);
	void ServerCheckClientPossessionReliable_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Servercheckclientpossessionreliable>& Op);
	void ServerCheckClientPossession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Servercheckclientpossession>& Op);
	void ServerChangeName_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serverchangename>& Op);
	void ServerCamera_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Servercamera>& Op);
	void ServerAcknowledgePossession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Commands::Serveracknowledgepossession>& Op);
};
