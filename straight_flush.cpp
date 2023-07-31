#include <QTimer>
#include <QList>
#include <cstdlib>
#include <QPixmap>
#include "Parameter.h"
#include "Combination.h"
#include "straight_flush.h"
#include "Game.h"

// extern Game *game;

straight_flush::straight_flush(Player *now_player) : Combination()
{
    player = now_player;
    find_all_this_combination();
}

void straight_flush::find_all_this_combination()
{
    player->cardNumberCal();
    if (player->ownCards.size() == 0)
        return;

    std::vector<Card *> currentCombination;
    findCombinations(player->ownCards, currentCombination, 0, player->ownCards.size());
    return;
}

void straight_flush::findCombinations(std::vector<Card *> hand, std::vector<Card *> currentCombination, int index, int count)
{
    if (currentCombination.size() == 5)
    {
        // 若是straight_flush，存到combinations
        if (is_this_combination(currentCombination))
            combinations.push_back(currentCombination);

        return;
    }

    for (int i = index; i < count; i++)
    {
        currentCombination.push_back(hand[i]);
        findCombinations(hand, currentCombination, i + 1, count);
        currentCombination.pop_back();
    }
}

bool straight_flush::is_this_combination(std::vector<Card *> nowC)
{
    if (nowC.size() != 5)
        return false;
    if (nowC[0]->suit == nowC[1]->suit && nowC[1]->suit == nowC[2]->suit && nowC[2]->suit == nowC[3]->suit && nowC[3]->suit == nowC[4]->suit)
    {
        if (nowC[0]->num == C3 && nowC[1]->num == C4 && nowC[2]->num == C5 && nowC[3]->num == A && nowC[4]->num == C2)
            return true;
        else if (nowC[0]->num == C3 && nowC[1]->num == C4 && nowC[2]->num == C5 && nowC[3]->num == C6 && nowC[4]->num == C2)
            return true;
        else
        {
            for (int i = (int)C3; i <= (int)C10; i++)
                if ((nowC[0]->num == (Number)(i)) && nowC[1]->num == (Number)(i + 1) && nowC[2]->num == (Number)(i + 2) && nowC[3]->num == (Number)(i + 3) && nowC[4]->num == (Number)(i + 4))
                    return true;
        }
    }

    return false;
}
bool straight_flush::compare_combination(std::vector<Card *> newC, std::vector<Card *> oldC)
{
    if (newC.at(3)->num == A && oldC.at(3)->num != A)
        return false;
    else if (newC.at(3)->num != A && oldC.at(3)->num == A)
        return true;
    else if (newC.at(3)->num == A && oldC.at(3)->num == A)
        return newC.at(3)->suit > oldC.at(3)->suit;
    else if (newC.at(4)->num == C2 && oldC.at(4)->num != C2)
        return true;
    else if (newC.at(4)->num != C2 && oldC.at(4)->num == C2)
        return false;
    else if (newC.at(4)->num == A && oldC.at(4)->num == A)
        return newC.at(4)->suit > oldC.at(4)->suit;
    else if (newC.at(4)->num > oldC.at(4)->num)
        return true;
    else if (newC.at(4)->num == oldC.at(4)->num)
        return newC.at(4)->suit > oldC.at(4)->suit;
    else
        return false;
};