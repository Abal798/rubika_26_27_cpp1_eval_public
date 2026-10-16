#include "Tournament.h"

#include "AlwaysBetrayStrat.h"
#include "AlwaysCooperateStrat.h"
#include "ResentfulStrat.h"
#include "Tit-for-TatStrat.h"
#include <algorithm>

#include "RandomStrat.h"

void Tournament::PopulateStrategy()
{
    strategies.clear();
    strategies.reserve(4);
    strategies.emplace_back(new always_cooperate_strat("alwaysCoop"));
    strategies.emplace_back(new always_betray_strat("alwaysBetray"));
    strategies.emplace_back(new tit_for_tat_strat("tit_for_tat"));
    strategies.emplace_back(new resentful_strat("resentful"));
    strategies.emplace_back(new random_strat("randStrat"));
}

void Tournament::Simulate()
{
    for (auto& playerA : strategies)
    {
        for (auto& playerB : strategies)
        {
            if (!playerA || !playerB) return;
            
            for (int i = 0; i < 50; ++i)
            {
                ResolsveRound(playerA, playerB);
            }
            playerA->ResetChoices();
            playerB->ResetChoices();
            if (playerA->Ranking.CurrentPoints > playerB->Ranking.CurrentPoints)
            {
                playerA->Ranking.Win ++;
                playerB->Ranking.Lose ++;
            }
            else if (playerA->Ranking.CurrentPoints < playerB->Ranking.CurrentPoints)
            {
                playerA->Ranking.Lose ++;
                playerB->Ranking.Win ++;
            }
            else
            {
                playerA->Ranking.Draw ++;
                playerB->Ranking.Draw ++;
            }
            playerA->Ranking.TotalPoint += playerA->Ranking.CurrentPoints;
            playerA->Ranking.CurrentPoints = 0;
            playerB->Ranking.TotalPoint += playerB->Ranking.CurrentPoints;
            playerB->Ranking.CurrentPoints = 0;
        }
    }
}

void Tournament::ResolsveRound(IStrategy* playerA, IStrategy* playerB)
{
    Choice a = playerA->Decide(playerA->Choices, playerB->Choices);
    Choice b = playerB->Decide(playerB->Choices, playerA->Choices);
    
    matchResults result = ResolveChoices(a, b);
    
    playerA->Choices.push_back(a);
    playerB->Choices.push_back(b);
    
    playerA->Ranking.CurrentPoints += result.a;
    playerB->Ranking.CurrentPoints += result.b;
    
}

matchResults Tournament::ResolveChoices(Choice& playerA, Choice& playerB)
{
    if (playerA == Choice::Betray && playerB == Choice::Betray ) return matchResults{1,1 };
    if (playerA == Choice::Cooperate && playerB == Choice::Betray ) return matchResults{0,5 };
    if (playerA == Choice::Betray && playerB == Choice::Cooperate ) return matchResults{5,0 };
    if (playerA == Choice::Cooperate && playerB == Choice::Cooperate ) return matchResults{3,3 };
    return matchResults{};
    
}


std::vector<Ranking> Tournament::GenerateFinalRankingByPoint() const
{
    std::vector<Ranking> result;
    result.reserve(strategies.size());

    for (const IStrategy* s : strategies)
    {
        if (s) result.push_back(s->Ranking);
    }

    std::sort(result.begin(), result.end(), [](const Ranking& r1, const Ranking& r2)
    {
        if (r1.TotalPoint != r2.TotalPoint) return r1.TotalPoint > r2.TotalPoint;
        if (r1.Win != r2.Win)               return r1.Win > r2.Win;
        if (r1.Draw != r2.Draw)             return r1.Draw > r2.Draw;
        return r1.Lose > r2.Lose;
    });

    return result;
}

std::vector<Ranking> Tournament::GenerateFinalRankingByWinDrawLoss() const
{
    std::vector<Ranking> result;
    result.reserve(strategies.size());

    for (const IStrategy* s : strategies)
    {
        if (s) result.push_back(s->Ranking);
    }

    std::sort(result.begin(), result.end(), [](const Ranking& r1, const Ranking& r2)
    {
        if (r1.Win != r2.Win)   return r1.Win > r2.Win;
        if (r1.Draw != r2.Draw) return r1.Draw > r2.Draw;
        return r1.Lose > r2.Lose;
    });

    return result;
}
