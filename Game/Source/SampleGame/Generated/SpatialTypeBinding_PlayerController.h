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
	using FRPCSender = void (USpatialTypeBinding_PlayerController::*)(worker::Connection* const, void*, UObject*);
	TMap<FName, FRPCSender> RPCToSenderMap;

	FRepHandlePropertyMap RepHandleToPropertyMap;
	FMigratableHandlePropertyMap MigratableHandleToPropertyMap;

	// Component update helper functions.
	void BuildSpatialComponentUpdate(
		const FPropertyChangeState& Changes,
		USpatialActorChannel* Channel,
		improbable::unreal::generated::playercontroller::PlayerControllerSingleClientRepData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::generated::playercontroller::PlayerControllerMultiClientRepData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		improbable::unreal::generated::playercontroller::PlayerControllerMigratableData::Update& MigratableDataUpdate,
		bool& bMigratableDataUpdateChanged) const;
	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::playercontroller::PlayerControllerSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::playercontroller::PlayerControllerMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Migratable(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::playercontroller::PlayerControllerMigratableData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::playercontroller::PlayerControllerSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::playercontroller::PlayerControllerMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Migratable(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::playercontroller::PlayerControllerMigratableData::Update& Update) const;
	void ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::playercontroller::PlayerControllerNetMulticastRPCs::Update& Update);

	// RPC command sender functions.
	void OnServerStartedVisualLogger_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientWasKicked_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientVoiceHandshakeComplete_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientUpdateMultipleLevelsStreamingStatus_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientUpdateLevelStreamingStatus_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientUnmutePlayer_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientTravelInternal_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientTeamMessage_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientStopForceFeedback_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientStopCameraShake_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientStopCameraAnim_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientStartOnlineSession_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSpawnCameraLensEffect_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetViewTarget_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetSpectatorWaiting_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetHUD_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetForceMipLevelsToBeResident_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetCinematicMode_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetCameraMode_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetCameraFade_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetBlockOnAsyncLoading_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientReturnToMainMenuWithTextReason_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientReturnToMainMenu_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientRetryClientRestart_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientRestart_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientReset_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientRepObjRef_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientReceiveLocalizedMessage_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPrestreamTextures_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPrepareMapChange_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlaySoundAtLocation_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlaySound_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlayForceFeedback_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlayCameraShake_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlayCameraAnim_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientMutePlayer_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientMessage_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientIgnoreMoveInput_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientIgnoreLookInput_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientGotoState_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientGameEnded_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientForceGarbageCollection_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientFlushLevelStreaming_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientEndOnlineSession_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientEnableNetworkVoice_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCommitMapChange_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientClearCameraLensEffects_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCapBandwidth_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCancelPendingMapChange_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAddTextureStreamingLoc_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetRotation_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetLocation_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerViewSelf_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerViewPrevPlayer_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerViewNextPlayer_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerVerifyViewTarget_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerUpdateMultipleLevelsVisibility_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerUpdateLevelVisibility_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerUpdateCamera_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerUnmutePlayer_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerToggleAILogging_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerShortTimeout_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerSetSpectatorWaiting_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerSetSpectatorLocation_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerRestartPlayer_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerPause_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerNotifyLoadedWorld_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMutePlayer_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerCheckClientPossessionReliable_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerCheckClientPossession_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerChangeName_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerCamera_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerAcknowledgePossession_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);

	// RPC command request handler functions.
	void OnServerStartedVisualLogger_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Onserverstartedvisuallogger>& Op);
	void ClientWasKicked_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientwaskicked>& Op);
	void ClientVoiceHandshakeComplete_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientvoicehandshakecomplete>& Op);
	void ClientUpdateMultipleLevelsStreamingStatus_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientupdatemultiplelevelsstreamingstatus>& Op);
	void ClientUpdateLevelStreamingStatus_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientupdatelevelstreamingstatus>& Op);
	void ClientUnmutePlayer_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientunmuteplayer>& Op);
	void ClientTravelInternal_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clienttravelinternal>& Op);
	void ClientTeamMessage_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientteammessage>& Op);
	void ClientStopForceFeedback_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientstopforcefeedback>& Op);
	void ClientStopCameraShake_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientstopcamerashake>& Op);
	void ClientStopCameraAnim_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientstopcameraanim>& Op);
	void ClientStartOnlineSession_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientstartonlinesession>& Op);
	void ClientSpawnCameraLensEffect_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientspawncameralenseffect>& Op);
	void ClientSetViewTarget_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetviewtarget>& Op);
	void ClientSetSpectatorWaiting_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetspectatorwaiting>& Op);
	void ClientSetHUD_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsethud>& Op);
	void ClientSetForceMipLevelsToBeResident_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetforcemiplevelstoberesident>& Op);
	void ClientSetCinematicMode_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetcinematicmode>& Op);
	void ClientSetCameraMode_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetcameramode>& Op);
	void ClientSetCameraFade_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetcamerafade>& Op);
	void ClientSetBlockOnAsyncLoading_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetblockonasyncloading>& Op);
	void ClientReturnToMainMenuWithTextReason_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientreturntomainmenuwithtextreason>& Op);
	void ClientReturnToMainMenu_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientreturntomainmenu>& Op);
	void ClientRetryClientRestart_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientretryclientrestart>& Op);
	void ClientRestart_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientrestart>& Op);
	void ClientReset_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientreset>& Op);
	void ClientRepObjRef_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientrepobjref>& Op);
	void ClientReceiveLocalizedMessage_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientreceivelocalizedmessage>& Op);
	void ClientPrestreamTextures_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientprestreamtextures>& Op);
	void ClientPrepareMapChange_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientpreparemapchange>& Op);
	void ClientPlaySoundAtLocation_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientplaysoundatlocation>& Op);
	void ClientPlaySound_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientplaysound>& Op);
	void ClientPlayForceFeedback_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientplayforcefeedback>& Op);
	void ClientPlayCameraShake_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientplaycamerashake>& Op);
	void ClientPlayCameraAnim_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientplaycameraanim>& Op);
	void ClientMutePlayer_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientmuteplayer>& Op);
	void ClientMessage_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientmessage>& Op);
	void ClientIgnoreMoveInput_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientignoremoveinput>& Op);
	void ClientIgnoreLookInput_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientignorelookinput>& Op);
	void ClientGotoState_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientgotostate>& Op);
	void ClientGameEnded_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientgameended>& Op);
	void ClientForceGarbageCollection_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientforcegarbagecollection>& Op);
	void ClientFlushLevelStreaming_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientflushlevelstreaming>& Op);
	void ClientEndOnlineSession_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientendonlinesession>& Op);
	void ClientEnableNetworkVoice_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientenablenetworkvoice>& Op);
	void ClientCommitMapChange_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientcommitmapchange>& Op);
	void ClientClearCameraLensEffects_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientclearcameralenseffects>& Op);
	void ClientCapBandwidth_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientcapbandwidth>& Op);
	void ClientCancelPendingMapChange_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientcancelpendingmapchange>& Op);
	void ClientAddTextureStreamingLoc_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientaddtexturestreamingloc>& Op);
	void ClientSetRotation_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetrotation>& Op);
	void ClientSetLocation_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetlocation>& Op);
	void ServerViewSelf_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverviewself>& Op);
	void ServerViewPrevPlayer_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverviewprevplayer>& Op);
	void ServerViewNextPlayer_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverviewnextplayer>& Op);
	void ServerVerifyViewTarget_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serververifyviewtarget>& Op);
	void ServerUpdateMultipleLevelsVisibility_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverupdatemultiplelevelsvisibility>& Op);
	void ServerUpdateLevelVisibility_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverupdatelevelvisibility>& Op);
	void ServerUpdateCamera_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverupdatecamera>& Op);
	void ServerUnmutePlayer_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverunmuteplayer>& Op);
	void ServerToggleAILogging_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Servertoggleailogging>& Op);
	void ServerShortTimeout_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Servershorttimeout>& Op);
	void ServerSetSpectatorWaiting_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serversetspectatorwaiting>& Op);
	void ServerSetSpectatorLocation_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serversetspectatorlocation>& Op);
	void ServerRestartPlayer_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverrestartplayer>& Op);
	void ServerPause_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverpause>& Op);
	void ServerNotifyLoadedWorld_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Servernotifyloadedworld>& Op);
	void ServerMutePlayer_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Servermuteplayer>& Op);
	void ServerCheckClientPossessionReliable_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Servercheckclientpossessionreliable>& Op);
	void ServerCheckClientPossession_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Servercheckclientpossession>& Op);
	void ServerChangeName_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverchangename>& Op);
	void ServerCamera_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Servercamera>& Op);
	void ServerAcknowledgePossession_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serveracknowledgepossession>& Op);

	// RPC command response handler functions.
	void OnServerStartedVisualLogger_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Onserverstartedvisuallogger>& Op);
	void ClientWasKicked_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientwaskicked>& Op);
	void ClientVoiceHandshakeComplete_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientvoicehandshakecomplete>& Op);
	void ClientUpdateMultipleLevelsStreamingStatus_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientupdatemultiplelevelsstreamingstatus>& Op);
	void ClientUpdateLevelStreamingStatus_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientupdatelevelstreamingstatus>& Op);
	void ClientUnmutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientunmuteplayer>& Op);
	void ClientTravelInternal_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clienttravelinternal>& Op);
	void ClientTeamMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientteammessage>& Op);
	void ClientStopForceFeedback_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientstopforcefeedback>& Op);
	void ClientStopCameraShake_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientstopcamerashake>& Op);
	void ClientStopCameraAnim_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientstopcameraanim>& Op);
	void ClientStartOnlineSession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientstartonlinesession>& Op);
	void ClientSpawnCameraLensEffect_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientspawncameralenseffect>& Op);
	void ClientSetViewTarget_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetviewtarget>& Op);
	void ClientSetSpectatorWaiting_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetspectatorwaiting>& Op);
	void ClientSetHUD_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsethud>& Op);
	void ClientSetForceMipLevelsToBeResident_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetforcemiplevelstoberesident>& Op);
	void ClientSetCinematicMode_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetcinematicmode>& Op);
	void ClientSetCameraMode_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetcameramode>& Op);
	void ClientSetCameraFade_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetcamerafade>& Op);
	void ClientSetBlockOnAsyncLoading_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetblockonasyncloading>& Op);
	void ClientReturnToMainMenuWithTextReason_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientreturntomainmenuwithtextreason>& Op);
	void ClientReturnToMainMenu_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientreturntomainmenu>& Op);
	void ClientRetryClientRestart_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientretryclientrestart>& Op);
	void ClientRestart_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientrestart>& Op);
	void ClientReset_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientreset>& Op);
	void ClientRepObjRef_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientrepobjref>& Op);
	void ClientReceiveLocalizedMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientreceivelocalizedmessage>& Op);
	void ClientPrestreamTextures_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientprestreamtextures>& Op);
	void ClientPrepareMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientpreparemapchange>& Op);
	void ClientPlaySoundAtLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientplaysoundatlocation>& Op);
	void ClientPlaySound_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientplaysound>& Op);
	void ClientPlayForceFeedback_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientplayforcefeedback>& Op);
	void ClientPlayCameraShake_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientplaycamerashake>& Op);
	void ClientPlayCameraAnim_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientplaycameraanim>& Op);
	void ClientMutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientmuteplayer>& Op);
	void ClientMessage_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientmessage>& Op);
	void ClientIgnoreMoveInput_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientignoremoveinput>& Op);
	void ClientIgnoreLookInput_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientignorelookinput>& Op);
	void ClientGotoState_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientgotostate>& Op);
	void ClientGameEnded_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientgameended>& Op);
	void ClientForceGarbageCollection_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientforcegarbagecollection>& Op);
	void ClientFlushLevelStreaming_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientflushlevelstreaming>& Op);
	void ClientEndOnlineSession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientendonlinesession>& Op);
	void ClientEnableNetworkVoice_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientenablenetworkvoice>& Op);
	void ClientCommitMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientcommitmapchange>& Op);
	void ClientClearCameraLensEffects_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientclearcameralenseffects>& Op);
	void ClientCapBandwidth_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientcapbandwidth>& Op);
	void ClientCancelPendingMapChange_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientcancelpendingmapchange>& Op);
	void ClientAddTextureStreamingLoc_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientaddtexturestreamingloc>& Op);
	void ClientSetRotation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetrotation>& Op);
	void ClientSetLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerClientRPCs::Commands::Clientsetlocation>& Op);
	void ServerViewSelf_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverviewself>& Op);
	void ServerViewPrevPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverviewprevplayer>& Op);
	void ServerViewNextPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverviewnextplayer>& Op);
	void ServerVerifyViewTarget_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serververifyviewtarget>& Op);
	void ServerUpdateMultipleLevelsVisibility_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverupdatemultiplelevelsvisibility>& Op);
	void ServerUpdateLevelVisibility_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverupdatelevelvisibility>& Op);
	void ServerUpdateCamera_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverupdatecamera>& Op);
	void ServerUnmutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverunmuteplayer>& Op);
	void ServerToggleAILogging_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Servertoggleailogging>& Op);
	void ServerShortTimeout_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Servershorttimeout>& Op);
	void ServerSetSpectatorWaiting_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serversetspectatorwaiting>& Op);
	void ServerSetSpectatorLocation_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serversetspectatorlocation>& Op);
	void ServerRestartPlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverrestartplayer>& Op);
	void ServerPause_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverpause>& Op);
	void ServerNotifyLoadedWorld_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Servernotifyloadedworld>& Op);
	void ServerMutePlayer_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Servermuteplayer>& Op);
	void ServerCheckClientPossessionReliable_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Servercheckclientpossessionreliable>& Op);
	void ServerCheckClientPossession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Servercheckclientpossession>& Op);
	void ServerChangeName_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serverchangename>& Op);
	void ServerCamera_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Servercamera>& Op);
	void ServerAcknowledgePossession_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::playercontroller::PlayerControllerServerRPCs::Commands::Serveracknowledgepossession>& Op);
};
