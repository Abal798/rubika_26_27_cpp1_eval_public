#include "Tit-for-TatStrat.h"

Choice tit_for_tat_strat::Decide(const std::vector<Choice>& previousDecisions,
    const std::vector<Choice>& opponentPreviousDecisions)
{
    if (previousDecisions.empty())return Choice::Cooperate;
    return opponentPreviousDecisions.back();
}
