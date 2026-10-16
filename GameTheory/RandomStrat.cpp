#include "RandomStrat.h"

Choice random_strat::Decide(const std::vector<Choice>& previousDecisions,
    const std::vector<Choice>& opponentPreviousDecisions)
{
    return std::rand() % 2 == 0 ? Choice::Betray : Choice::Cooperate;
}
