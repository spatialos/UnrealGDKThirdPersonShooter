// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SGGameState.h"

#include "SampleGameLogging.h"
#include "Teams/SampleGameTeams.h"
#include "UnrealNetwork.h"


// Sets default values
ASGGameState::ASGGameState()
{
	PrimaryActorTick.bCanEverTick = false;

	// TODO: not sure if we'll need this once we use AGameStateBase as a parent
	SetReplicates(true);
}

void ASGGameState::AddPlayer(ESampleGameTeam Team, const FString& Player)
{
	if (Team == ESampleGameTeam::Team_None || Team >= ESampleGameTeam::Team_MAX)
	{
		// Ignore invalid teams.
		return;
	}

	if (!PlayerScores.Contains(FName(*Player)))
	{
		AddPlayerImpl(Team, Player);
	}
}

void ASGGameState::AddKill(ESampleGameTeam KillerTeam, const FString& Killer, const FString& Victim)
{
	if (KillerTeam == ESampleGameTeam::Team_None || KillerTeam >= ESampleGameTeam::Team_MAX)
	{
		// Ignore invalid teams.
		return;
	}

	FName KillerKey(*Killer);
	if (!PlayerScores.Contains(KillerKey))
	{
		// TODO: do I need this? Can I just throw an error?
		AddPlayerImpl(KillerTeam, Killer);
	}
	++PlayerScores[KillerKey]->Kills;

	FName VictimKey(*Victim);
	if (!PlayerScores.Contains(VictimKey))
	{
		// TODO: do I need this? Can I just throw an error?
		//AddPlayerImpl(KillerTeam, Killer);
	}
	++PlayerScores[VictimKey]->Deaths;

	if (FTeamScore* TeamScore = GetScoreForTeam(KillerTeam))
	{
		++TeamScore->TeamKills;

		// The player score has already been updated, so re-sort the team's top player array here.
		TeamScore->TopPlayers.Sort([](const FPlayerScore& lhs, const FPlayerScore& rhs)
		{
			// Sort in reverse order.
			return lhs.Kills > rhs.Kills;
		});
	}
	// Re-sort team scores after updating the killer's team score.
	TeamScores.Sort([](const FTeamScore& lhs, const FTeamScore& rhs)
	{
		// Sort in reverse order.
		return lhs.TeamKills > rhs.TeamKills;
	});
}

void ASGGameState::RegisterScoreChangeListener(FSGTeamScoresUpdatedDelegate Callback)
{
	check(GetNetMode() != NM_DedicatedServer);

	TeamScoresUpdatedCallback = Callback;
	Callback.ExecuteIfBound(TeamScores);
}

void ASGGameState::BeginPlay()
{
	if (HasAuthority() && TeamScores.Num() == 0)
	{
		// Initialize team scores for all possible teams.
		const uint32 TeamMax = static_cast<uint32>(ESampleGameTeam::Team_MAX);
		for (uint32 i = 0; i < TeamMax; ++i)
		{
			FTeamScore TeamScore;
			TeamScore.Team = static_cast<ESampleGameTeam>(i);
			TeamScore.TeamKills = 0;
			TeamScores.Add(TeamScore);
		}
	}
}

void ASGGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASGGameState, TeamScores);
}

void ASGGameState::OnRep_TeamScores()
{
	// TODO: delete or disable debug printing of scores
	const uint32 TeamMax = static_cast<uint32>(ESampleGameTeam::Team_MAX);
	for (uint32 i = 0; i < TeamMax; ++i)
	{
		UEnum* pEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("ESampleGameTeam"), true);
		FString TeamName = pEnum ? pEnum->GetNameStringByIndex(static_cast<uint8>(i)) : "null";
		int32 Kills = -1;
		if (FTeamScore* TeamScore = GetScoreForTeam(static_cast<ESampleGameTeam>(i)))
		{
			Kills = TeamScore->TeamKills;
		}
		UE_LOG(LogTemp, Log, TEXT("%s team score: %d"), *TeamName, Kills);
	}

	TeamScoresUpdatedCallback.ExecuteIfBound(TeamScores);
}

FTeamScore* ASGGameState::GetScoreForTeam(ESampleGameTeam Team)
{
	for (int i = 0; i < TeamScores.Num(); ++i)
	{
		if (TeamScores[i].Team == Team)
		{
			return &TeamScores[i];
		}
	}
	
	return nullptr;
}

void ASGGameState::AddPlayerImpl(ESampleGameTeam Team, const FString& Player)
{
	FTeamScore* TeamScore = GetScoreForTeam(Team);
	if (TeamScore == nullptr)
	{
		UE_LOG(LogSampleGame, Warning, TEXT("[GameState] Tried to add a player (%s) to the score list with an invalid team (%d)"),
			*Player, static_cast<uint8>(Team));
		return;
	}

	FPlayerScore NewPlayerScore;
	NewPlayerScore.PlayerName = Player;
	NewPlayerScore.Kills = 0;
	NewPlayerScore.Deaths = 0;
	TeamScore->TopPlayers.Emplace(NewPlayerScore);

	PlayerScores.Emplace(FName(*Player), &TeamScore->TopPlayers.Last());
}
