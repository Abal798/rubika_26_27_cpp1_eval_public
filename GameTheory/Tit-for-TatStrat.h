#pragma once
#include "IStrategy.h"

class tit_for_tat_strat: public IStrategy
{
public:
    tit_for_tat_strat(const std::string& name): IStrategy(name){}
    
    Choice Decide(const std::vector<Choice>& previousDecisions,
        const std::vector<Choice>& opponentPreviousDecisions) override;
};
