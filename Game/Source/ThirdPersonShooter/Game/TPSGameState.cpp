// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "Game/TPSGameState.h"

#include "TPSLogging.h"
#include "Teams/TPSTeams.h"
#include "UnrealNetwork.h"


ATPSGameState::ATPSGameState()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATPSGameState::AddPlayer(ETPSTeam Team, const FString& Player)
{
	if (Team == ETPSTeam::Team_None || Team > ETPSTeam::Team_MAX)
	{
		// Ignore invalid teams.
		return;
	}

	if (!PlayerScores.Contains(FName(*Player)))
	{
		AddPlayerInternal(Team, Player);
	}
}

void ATPSGameState::AddDeath(const FString& KillerName, ETPSTeam KillerTeam, const FString& VictimName, ETPSTeam VictimTeam)
{
	// Ignore invalid teams.
	if (VictimTeam >= ETPSTeam::Team_MIN && VictimTeam <= ETPSTeam::Team_MAX)
	{
		FName VictimKey(*VictimName);
		if (!PlayerScores.Contains(VictimKey))
		{
			AddPlayerInternal(VictimTeam, VictimName);
		}
		++PlayerScores[VictimKey]->Deaths;
	}

	// Ignore invalid teams.
	if (KillerTeam >= ETPSTeam::Team_MIN && KillerTeam <= ETPSTeam::Team_MAX)
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

void ATPSGameState::RegisterScoreChangeListener(FSGTeamScoresUpdatedDelegate Callback)
{
	check(GetNetMode() != NM_DedicatedServer);

	TeamScoresUpdatedCallback = Callback;
	Callback.ExecuteIfBound(TeamScores);
}

void ATPSGameState::BeginPlay()
{
	if (HasAuthority() && TeamScores.Num() == 0)
	{
		// Initialize team scores for all possible teams.
		const uint32 TeamMin = static_cast<uint32>(ETPSTeam::Team_MIN);
		const uint32 TeamMax = static_cast<uint32>(ETPSTeam::Team_MAX);
		for (uint32 i = TeamMin; i <= TeamMax; ++i)
		{
			FTeamScore TeamScore;
			TeamScore.Team = static_cast<ETPSTeam>(i);
			TeamScore.TeamKills = 0;
			TeamScores.Add(TeamScore);
		}
	}
}

void ATPSGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATPSGameState, TeamScores);
}

void ATPSGameState::OnRep_TeamScores()
{
	TeamScoresUpdatedCallback.ExecuteIfBound(TeamScores);
}

FTeamScore* ATPSGameState::GetScoreForTeam(ETPSTeam Team)
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

void ATPSGameState::AddPlayerInternal(ETPSTeam Team, const FString& Player)
{
	FTeamScore* TeamScore = GetScoreForTeam(Team);
	if (TeamScore == nullptr)
	{
		UE_LOG(LogTPS, Error, TEXT("[GameState] Tried to add a player (%s) to the score list with an invalid team (%d)"),
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
