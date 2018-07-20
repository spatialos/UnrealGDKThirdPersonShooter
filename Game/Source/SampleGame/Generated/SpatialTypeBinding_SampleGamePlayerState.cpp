// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically

#include "SpatialTypeBinding_SampleGamePlayerState.h"

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
#include "SampleGamePlayerState.h"
#include "Teams/SampleGameTeams.h"

#include "SampleGamePlayerStateSingleClientRepDataAddComponentOp.h"
#include "SampleGamePlayerStateMultiClientRepDataAddComponentOp.h"
#include "SampleGamePlayerStateMigratableDataAddComponentOp.h"

const FRepHandlePropertyMap& USpatialTypeBinding_SampleGamePlayerState::GetRepHandlePropertyMap() const
{
	return RepHandleToPropertyMap;
}

const FMigratableHandlePropertyMap& USpatialTypeBinding_SampleGamePlayerState::GetMigratableHandlePropertyMap() const
{
	return MigratableHandleToPropertyMap;
}

UClass* USpatialTypeBinding_SampleGamePlayerState::GetBoundClass() const
{
	return ASampleGamePlayerState::StaticClass();
}

void USpatialTypeBinding_SampleGamePlayerState::Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap)
{
	Super::Init(InInterop, InPackageMap);


	UClass* Class = FindObject<UClass>(ANY_PACKAGE, TEXT("SampleGamePlayerState"));

	// Populate RepHandleToPropertyMap.
	RepHandleToPropertyMap.Add(1, FRepHandleData(Class, {"bHidden"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(2, FRepHandleData(Class, {"bReplicateMovement"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(3, FRepHandleData(Class, {"bTearOff"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(4, FRepHandleData(Class, {"bCanBeDamaged"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(5, FRepHandleData(Class, {"RemoteRole"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(6, FRepHandleData(Class, {"ReplicatedMovement"}, {0}, COND_SimulatedOrPhysics, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(7, FRepHandleData(Class, {"AttachmentReplication", "AttachParent"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(8, FRepHandleData(Class, {"AttachmentReplication", "LocationOffset"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(9, FRepHandleData(Class, {"AttachmentReplication", "RelativeScale3D"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(10, FRepHandleData(Class, {"AttachmentReplication", "RotationOffset"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(11, FRepHandleData(Class, {"AttachmentReplication", "AttachSocket"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(12, FRepHandleData(Class, {"AttachmentReplication", "AttachComponent"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(13, FRepHandleData(Class, {"Owner"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(14, FRepHandleData(Class, {"Role"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(15, FRepHandleData(Class, {"Instigator"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(16, FRepHandleData(Class, {"Score"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(17, FRepHandleData(Class, {"Ping"}, {0}, COND_SkipOwner, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(18, FRepHandleData(Class, {"PlayerId"}, {0}, COND_InitialOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(19, FRepHandleData(Class, {"bFromPreviousLevel"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(20, FRepHandleData(Class, {"bIsABot"}, {0}, COND_InitialOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(21, FRepHandleData(Class, {"bIsInactive"}, {0}, COND_InitialOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(22, FRepHandleData(Class, {"bIsSpectator"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(23, FRepHandleData(Class, {"bOnlySpectator"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(24, FRepHandleData(Class, {"StartTime"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(25, FRepHandleData(Class, {"UniqueId"}, {0}, COND_InitialOnly, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(26, FRepHandleData(Class, {"PlayerNamePrivate"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(27, FRepHandleData(Class, {"SelectedTeam"}, {0}, COND_None, REPNOTIFY_OnChanged));
}

void USpatialTypeBinding_SampleGamePlayerState::BindToView(bool bIsClient)
{
	TSharedPtr<worker::View> View = Interop->GetSpatialOS()->GetView().Pin();
	ViewCallbacks.Init(View);

	if (Interop->GetNetDriver()->GetNetMode() == NM_Client)
	{
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateSingleClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateSingleClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateSingleClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_SingleClient(ActorChannel, Op.Update);
		}));
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMultiClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMultiClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMultiClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_MultiClient(ActorChannel, Op.Update);
		}));
		if (!bIsClient)
		{
			ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMigratableData>([this](
				const worker::ComponentUpdateOp<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMigratableData>& Op)
			{
				// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
				if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMigratableData::ComponentId))
				{
					return;
				}
				USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
				check(ActorChannel);
				ReceiveUpdate_Migratable(ActorChannel, Op.Update);
			}));
		}
	}
	ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateNetMulticastRPCs>([this](
		const worker::ComponentUpdateOp<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateNetMulticastRPCs>& Op)
	{
		// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
		if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateNetMulticastRPCs::ComponentId))
		{
			return;
		}
		ReceiveUpdate_NetMulticastRPCs(Op.EntityId, Op.Update);
	}));
}

void USpatialTypeBinding_SampleGamePlayerState::UnbindFromView()
{
	ViewCallbacks.Reset();
}

worker::Entity USpatialTypeBinding_SampleGamePlayerState::CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const
{
	// Validate replication list.
	const uint16 RepHandlePropertyMapCount = GetRepHandlePropertyMap().Num();
	for (auto& Rep : InitialChanges.RepChanged)
	{
		checkf(Rep <= RepHandlePropertyMapCount, TEXT("Attempting to replicate a property with a handle that the type binding is not aware of. Have additional replicated properties been added in a non generated child object?"))
	}

	// Setup initial data.

	improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateSingleClientRepData::Data SingleClientSampleGamePlayerStateData;
	improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateSingleClientRepData::Update SingleClientSampleGamePlayerStateUpdate;
	bool bSingleClientSampleGamePlayerStateUpdateChanged = false;
	improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMultiClientRepData::Data MultiClientSampleGamePlayerStateData;
	improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMultiClientRepData::Update MultiClientSampleGamePlayerStateUpdate;
	bool bMultiClientSampleGamePlayerStateUpdateChanged = false;
	improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMigratableData::Data SampleGamePlayerStateMigratableData;
	improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMigratableData::Update SampleGamePlayerStateMigratableDataUpdate;
	bool bSampleGamePlayerStateMigratableDataUpdateChanged = false;

	BuildSpatialComponentUpdate(InitialChanges, Channel, SingleClientSampleGamePlayerStateUpdate, bSingleClientSampleGamePlayerStateUpdateChanged, MultiClientSampleGamePlayerStateUpdate, bMultiClientSampleGamePlayerStateUpdateChanged, SampleGamePlayerStateMigratableDataUpdate, bSampleGamePlayerStateMigratableDataUpdateChanged);
	SingleClientSampleGamePlayerStateUpdate.ApplyTo(SingleClientSampleGamePlayerStateData);
	MultiClientSampleGamePlayerStateUpdate.ApplyTo(MultiClientSampleGamePlayerStateData);
	SampleGamePlayerStateMigratableDataUpdate.ApplyTo(SampleGamePlayerStateMigratableData);

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
		.AddComponent<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateSingleClientRepData>(SingleClientSampleGamePlayerStateData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMultiClientRepData>(MultiClientSampleGamePlayerStateData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMigratableData>(SampleGamePlayerStateMigratableData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateClientRPCs>(improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateClientRPCs::Data{}, OwningClientOnly)
		.AddComponent<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateServerRPCs>(improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateServerRPCs::Data{}, WorkersOnly)
		.AddComponent<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateNetMulticastRPCs>(improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateNetMulticastRPCs::Data{}, WorkersOnly)
		.Build();
}

void USpatialTypeBinding_SampleGamePlayerState::SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const FEntityId& EntityId) const
{
	// Build SpatialOS updates.
	improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateSingleClientRepData::Update SingleClientUpdate;
	bool bSingleClientUpdateChanged = false;
	improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMultiClientRepData::Update MultiClientUpdate;
	bool bMultiClientUpdateChanged = false;
	improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMigratableData::Update MigratableDataUpdate;
	bool bMigratableDataUpdateChanged = false;
	BuildSpatialComponentUpdate(Changes, Channel, SingleClientUpdate, bSingleClientUpdateChanged, MultiClientUpdate, bMultiClientUpdateChanged, MigratableDataUpdate, bMigratableDataUpdateChanged);

	// Send SpatialOS updates if anything changed.
	TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
	if (bSingleClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateSingleClientRepData>(EntityId.ToSpatialEntityId(), SingleClientUpdate);
	}
	if (bMultiClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMultiClientRepData>(EntityId.ToSpatialEntityId(), MultiClientUpdate);
	}
	if (bMigratableDataUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMigratableData>(EntityId.ToSpatialEntityId(), MigratableDataUpdate);
	}
}

void USpatialTypeBinding_SampleGamePlayerState::SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters)
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

void USpatialTypeBinding_SampleGamePlayerState::ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const
{
	auto* SingleClientAddOp = Cast<USampleGamePlayerStateSingleClientRepDataAddComponentOp>(AddComponentOp);
	if (SingleClientAddOp)
	{
		auto Update = improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateSingleClientRepData::Update::FromInitialData(*SingleClientAddOp->Data.data());
		ReceiveUpdate_SingleClient(Channel, Update);
		return;
	}
	auto* MultiClientAddOp = Cast<USampleGamePlayerStateMultiClientRepDataAddComponentOp>(AddComponentOp);
	if (MultiClientAddOp)
	{
		auto Update = improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMultiClientRepData::Update::FromInitialData(*MultiClientAddOp->Data.data());
		ReceiveUpdate_MultiClient(Channel, Update);
		return;
	}
	auto* MigratableDataAddOp = Cast<USampleGamePlayerStateMigratableDataAddComponentOp>(AddComponentOp);
	if (MigratableDataAddOp)
	{
		auto Update = improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMigratableData::Update::FromInitialData(*MigratableDataAddOp->Data.data());
		ReceiveUpdate_Migratable(Channel, Update);
		return;
	}
}

worker::Map<worker::ComponentId, worker::InterestOverride> USpatialTypeBinding_SampleGamePlayerState::GetInterestOverrideMap(bool bIsClient, bool bAutonomousProxy) const
{
	worker::Map<worker::ComponentId, worker::InterestOverride> Interest;
	if (bIsClient)
	{
		if (!bAutonomousProxy)
		{
			Interest.emplace(improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateSingleClientRepData::ComponentId, worker::InterestOverride{false});
		}
		Interest.emplace(improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMigratableData::ComponentId, worker::InterestOverride{false});
	}
	return Interest;
}

void USpatialTypeBinding_SampleGamePlayerState::BuildSpatialComponentUpdate(
	const FPropertyChangeState& Changes,
	USpatialActorChannel* Channel,
	improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateSingleClientRepData::Update& SingleClientUpdate,
	bool& bSingleClientUpdateChanged,
	improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMultiClientRepData::Update& MultiClientUpdate,
	bool& bMultiClientUpdateChanged,
	improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMigratableData::Update& MigratableDataUpdate,
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

	// Populate the migrated data component update from the migrated property changelist.
	for (uint16 ChangedHandle : Changes.MigChanged)
	{
		const FMigratableHandleData& PropertyMapData = MigPropertyMap[ChangedHandle];
		const uint8* Data = PropertyMapData.GetPropertyData(Changes.SourceData);
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending migratable property update. actor %s (%lld), property %s (handle %d)"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*Channel->Actor->GetName(),
			Channel->GetEntityId().ToSpatialEntityId(),
			*PropertyMapData.Property->GetName(),
			ChangedHandle);
		ServerSendUpdate_Migratable(Data, ChangedHandle, PropertyMapData.Property, Channel, MigratableDataUpdate);
		bMigratableDataUpdateChanged = true;
	}
}

void USpatialTypeBinding_SampleGamePlayerState::ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateSingleClientRepData::Update& OutUpdate) const
{
}

void USpatialTypeBinding_SampleGamePlayerState::ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMultiClientRepData::Update& OutUpdate) const
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
		case 16: // field_score0
		{
			float Value = *(reinterpret_cast<float const*>(Data));

			OutUpdate.set_field_score0(Value);
			break;
		}
		case 17: // field_ping0
		{
			uint8 Value = *(reinterpret_cast<uint8 const*>(Data));

			OutUpdate.set_field_ping0(uint32_t(Value));
			break;
		}
		case 18: // field_playerid0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_playerid0(int32_t(Value));
			break;
		}
		case 19: // field_bfrompreviouslevel0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bfrompreviouslevel0(Value);
			break;
		}
		case 20: // field_bisabot0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bisabot0(Value);
			break;
		}
		case 21: // field_bisinactive0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bisinactive0(Value);
			break;
		}
		case 22: // field_bisspectator0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bisspectator0(Value);
			break;
		}
		case 23: // field_bonlyspectator0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bonlyspectator0(Value);
			break;
		}
		case 24: // field_starttime0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_starttime0(int32_t(Value));
			break;
		}
		case 25: // field_uniqueid0
		{
			const FUniqueNetIdRepl& Value = *(reinterpret_cast<FUniqueNetIdRepl const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 25);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FUniqueNetIdRepl&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FUniqueNetIdRepl failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_uniqueid0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 25);
			}
			break;
		}
		case 26: // field_playernameprivate0
		{
			FString Value = *(reinterpret_cast<FString const*>(Data));

			OutUpdate.set_field_playernameprivate0(TCHAR_TO_UTF8(*Value));
			break;
		}
		case 27: // field_selectedteam0
		{
			ESampleGameTeam Value = *(reinterpret_cast<ESampleGameTeam const*>(Data));

			OutUpdate.set_field_selectedteam0(uint32(Value));
			break;
		}
	default:
		checkf(false, TEXT("Unknown replication handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_SampleGamePlayerState::ServerSendUpdate_Migratable(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMigratableData::Update& OutUpdate) const
{
}

void USpatialTypeBinding_SampleGamePlayerState::ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateSingleClientRepData::Update& Update) const
{
	AActor* TargetObject = ActorChannel->Actor;
	ActorChannel->PreReceiveSpatialUpdate(TargetObject);
	TArray<UProperty*> RepNotifies;
	ActorChannel->PostReceiveSpatialUpdate(TargetObject, RepNotifies);
}

void USpatialTypeBinding_SampleGamePlayerState::ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMultiClientRepData::Update& Update) const
{
	AActor* TargetObject = ActorChannel->Actor;
	ActorChannel->PreReceiveSpatialUpdate(TargetObject);
	TSet<UProperty*> RepNotifies;

	const bool bIsServer = Interop->GetNetDriver()->IsServer();
	const bool bAutonomousProxy = ActorChannel->IsClientAutonomousProxy(improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateClientRPCs::ComponentId);
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
	if (!Update.field_score0().empty())
	{
		// field_score0
		uint16 Handle = 16;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			float Value = *(reinterpret_cast<float const*>(PropertyData));

			Value = (*Update.field_score0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_ping0().empty())
	{
		// field_ping0
		uint16 Handle = 17;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			uint8 Value = *(reinterpret_cast<uint8 const*>(PropertyData));

			Value = uint8(uint8((*Update.field_ping0().data())));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_playerid0().empty())
	{
		// field_playerid0
		uint16 Handle = 18;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_playerid0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_bfrompreviouslevel0().empty())
	{
		// field_bfrompreviouslevel0
		uint16 Handle = 19;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bfrompreviouslevel0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_bisabot0().empty())
	{
		// field_bisabot0
		uint16 Handle = 20;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bisabot0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_bisinactive0().empty())
	{
		// field_bisinactive0
		uint16 Handle = 21;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bisinactive0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_bisspectator0().empty())
	{
		// field_bisspectator0
		uint16 Handle = 22;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bisspectator0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_bonlyspectator0().empty())
	{
		// field_bonlyspectator0
		uint16 Handle = 23;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bonlyspectator0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_starttime0().empty())
	{
		// field_starttime0
		uint16 Handle = 24;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_starttime0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_uniqueid0().empty())
	{
		// field_uniqueid0
		uint16 Handle = 25;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FUniqueNetIdRepl Value = *(reinterpret_cast<FUniqueNetIdRepl const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_uniqueid0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FUniqueNetIdRepl failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_playernameprivate0().empty())
	{
		// field_playernameprivate0
		uint16 Handle = 26;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FString Value = *(reinterpret_cast<FString const*>(PropertyData));

			Value = FString(UTF8_TO_TCHAR((*Update.field_playernameprivate0().data()).c_str()));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_selectedteam0().empty())
	{
		// field_selectedteam0
		uint16 Handle = 27;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			ESampleGameTeam Value = *(reinterpret_cast<ESampleGameTeam const*>(PropertyData));

			Value = ESampleGameTeam((*Update.field_selectedteam0().data()));

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

void USpatialTypeBinding_SampleGamePlayerState::ReceiveUpdate_Migratable(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateMigratableData::Update& Update) const
{
}

void USpatialTypeBinding_SampleGamePlayerState::ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::samplegameplayerstate::SampleGamePlayerStateNetMulticastRPCs::Update& Update)
{
}
