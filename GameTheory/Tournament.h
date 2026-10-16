#pragma once

#include "Ranking.h"

#include <vector>

#include "IStrategy.h"

struct matchResults
{
	int a = 0;
	int b = 0;
};

class Tournament
{
public:
	void PopulateStrategy();

	void Simulate();
	
	void ResolsveRound(IStrategy* playerA, IStrategy* playerB);
	matchResults ResolveChoices(Choice& playerA, Choice& playerB);

	std::vector<IStrategy*> strategies;
	std::vector<Ranking> GenerateFinalRankingByPoint() const;
	std::vector<Ranking> GenerateFinalRankingByWinDrawLoss() const;
};

