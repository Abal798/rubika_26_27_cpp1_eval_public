#pragma once
#include "IStrategy.h"

class random_strat : public IStrategy
{
public:
    random_strat(const std::string& name): IStrategy(name){}
    
    Choice Decide(const std::vector<Choice>& previousDecisions,
        const std::vector<Choice>& opponentPreviousDecisions) override;
};
