#pragma once

#include "Choice.h"

#include <string>
#include <vector>

#include "Ranking.h"

class IStrategy
{
public:
	IStrategy(const std::string& name) : Name(name)
	{
		Ranking.StrategyName = name;
	}

	virtual ~IStrategy() = default;


	virtual Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) = 0;

	void ResetChoices();
	
	std::string Name;
	
	std::vector<Choice> Choices;
	Ranking Ranking;
	
};
