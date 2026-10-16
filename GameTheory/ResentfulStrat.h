#pragma once
#include "IStrategy.h"

class resentful_strat : public IStrategy
{
public:
    resentful_strat(const std::string& name): IStrategy(name){}
    
    Choice Decide(const std::vector<Choice>& previousDecisions,
        const std::vector<Choice>& opponentPreviousDecisions) override;
};
