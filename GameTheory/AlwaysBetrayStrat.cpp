#include "AlwaysBetrayStrat.h"

Choice always_betray_strat::Decide(const std::vector<Choice>& previousDecisions,
    const std::vector<Choice>& opponentPreviousDecisions)
{
    return Choice::Betray;
}
