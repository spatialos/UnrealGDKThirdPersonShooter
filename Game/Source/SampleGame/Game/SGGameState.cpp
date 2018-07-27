// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "Game/SGGameState.h"

#include "SampleGameLogging.h"
#include "Teams/SampleGameTeams.h"
#include "UnrealNetwork.h"


ASGGameState::ASGGameState()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ASGGameState::AddPlayer(ESampleGameTeam Team, const FString& Player)
{
	if (Team == ESampleGameTeam::Team_None || Team > ESampleGameTeam::Team_MAX)
	{
		// Ignore invalid teams.
		return;
	}

	if (!PlayerScores.Contains(FName(*Player)))
	{
		AddPlayerInternal(Team, Player);
	}
}

void ASGGameState::AddDeath(const FString& KillerName, ESampleGameTeam KillerTeam, const FString& VictimName, ESampleGameTeam VictimTeam)
{
	// Ignore invalid teams.
	if (VictimTeam >= ESampleGameTeam::Team_MIN && VictimTeam <= ESampleGameTeam::Team_MAX)
	{
		FName VictimKey(*VictimName);
		if (!PlayerScores.Contains(VictimKey))
		{
			AddPlayerInternal(VictimTeam, VictimName);
		}
		++PlayerScores[VictimKey]->Deaths;
	}

	// Ignore invalid teams.
	if (KillerTeam >= ESampleGameTeam::Team_MIN && KillerTeam <= ESampleGameTeam::Team_MAX)
	{
		FName KillerKey(*KillerName);
		if (!PlayerScores.Contains(KillerKey))
		{
			AddPlayerInternal(KillerTeam, KillerName);
		}
		++PlayerScores[KillerKey]->Kills;

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
		const uint32 TeamMin = static_cast<uint32>(ESampleGameTeam::Team_MIN);
		const uint32 TeamMax = static_cast<uint32>(ESampleGameTeam::Team_MAX);
		for (uint32 i = TeamMin; i <= TeamMax; ++i)
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

void ASGGameState::AddPlayerInternal(ESampleGameTeam Team, const FString& Player)
{
	FTeamScore* TeamScore = GetScoreForTeam(Team);
	if (TeamScore == nullptr)
	{
		UE_LOG(LogSampleGame, Error, TEXT("[GameState] Tried to add a player (%s) to the score list with an invalid team (%d)"),
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
