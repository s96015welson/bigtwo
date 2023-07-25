#include <QTimer>
#include <QList>
#include <cstdlib>
#include <iostream>
#include <QPixmap>
#include "Parameter.h"
#include "Combination.h"
#include "straight.h"
#include "Game.h"

// extern Game *game;

straight::straight(Player *now_player) : Combination()
{
    player = now_player;
    find_all_this_combination();
}

void straight::find_all_this_combination()
{
    player->cardNumberCal();
    if (player->ownCards.size() == 0)
        return;

    std::vector<Card *> currentCombination;
    findCombinations(player->ownCards, currentCombination, 0, player->ownCards.size());
    return;
}

void straight::findCombinations(std::vector<Card *> hand, std::vector<Card *> currentCombination, int index, int count)
{
    if (currentCombination.size() == 5)
    {
        // 若是straight，存到combinations
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

bool straight::is_this_combination(std::vector<Card *> nowC)
{
    if (nowC[0]->num == C3 && nowC[1]->num == C4 && nowC[2]->num == C5 && nowC[3]->num == A && nowC[4]->num == C2)
        return true;
    else if (nowC[0]->num == C3 && nowC[1]->num == C4 && nowC[2]->num == C5 && nowC[3]->num == C6 && nowC[4]->num == C2)
        return true;
    else
    {
        for (int i = (int)C3; i < (int)C10; i++)
            if ((nowC[0]->num == (Number)(i)) && nowC[1]->num == (Number)(i + 1) && nowC[2]->num == (Number)(i + 2) && nowC[3]->num == (Number)(i + 3) && nowC[4]->num == (Number)(i + 4))
                return true;
    }
    return false;
}