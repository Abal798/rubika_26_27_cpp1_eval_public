#pragma once
#include "IStrategy.h"

class always_betray_strat : public IStrategy
{
public:
    always_betray_strat(const std::string& name): IStrategy(name){}

    Choice Decide(const std::vector<Choice>& previousDecisions,
                  const std::vector<Choice>& opponentPreviousDecisions) override;
};
