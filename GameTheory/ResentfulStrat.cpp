#include "ResentfulStrat.h"

Choice resentful_strat::Decide(const std::vector<Choice>& previousDecisions,
    const std::vector<Choice>& opponentPreviousDecisions)
{
    for (Choice element : opponentPreviousDecisions)
    {
        if (element == Choice::Betray)return Choice::Betray;
    }
    return Choice::Cooperate;
}
