#include <QTimer>
#include <QList>
#include <cstdlib>
#include <QPixmap>
#include "Parameter.h"
#include "Combination.h"
#include "full_house.h"
#include "Game.h"

full_house::full_house(Player *now_player) : Combination()
{
    player = now_player;
    find_all_this_combination();
}

void full_house::find_all_this_combination()
{
    player->cardNumberCal();
    if (player->ownCards.size() == 0)
        return;

    std::vector<Card *> currentCombination;
    findCombinations(player->ownCards, currentCombination, 0, player->ownCards.size());
    return;
}

void full_house::findCombinations(std::vector<Card *> hand, std::vector<Card *> currentCombination, int index, int count)
{
    if (currentCombination.size() == 5)
    {
        // 若是full_house，存到combinations
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

bool full_house::is_this_combination(std::vector<Card *> nowC)
{
    if (nowC.size() != 5)
        return false;
    else if (nowC[0]->num == nowC[1]->num && nowC[2]->num == nowC[3]->num && nowC[3]->num == nowC[4]->num)
        return true;
    else if (nowC[0]->num == nowC[1]->num && nowC[1]->num == nowC[2]->num && nowC[3]->num == nowC[4]->num)
        return true;

    return false;
}
bool full_house::compare_combination(std::vector<Card *> newC, std::vector<Card *> oldC)
{
    if (newC.at(2)->num > oldC.at(2)->num)
        return true;
    else
        return false;
};