#include <QTimer>
#include <QList>
#include <cstdlib>
#include <QPixmap>
#include "Parameter.h"
#include "Combination.h"
#include "four_of_a_kind.h"
#include "Game.h"

// extern Game *game;

four_of_a_kind::four_of_a_kind(Player *now_player) : Combination()
{
    player = now_player;
    find_all_this_combination();
}

void four_of_a_kind::find_all_this_combination()
{
    player->cardNumberCal();
    if (player->ownCards.size() == 0)
        return;

    std::vector<Card *> currentCombination;
    findCombinations(player->ownCards, currentCombination, 0, player->ownCards.size());
    return;
}

void four_of_a_kind::findCombinations(std::vector<Card *> hand, std::vector<Card *> currentCombination, int index, int count)
{
    if (currentCombination.size() == 5)
    {
        // 若是four_of_a_kind，存到combinations
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

bool four_of_a_kind::is_this_combination(std::vector<Card *> nowC)
{

    if (nowC.size() != 5)
        return false;
    if (nowC[0]->num == nowC[1]->num && nowC[1]->num == nowC[2]->num && nowC[2]->num == nowC[3]->num)
        return true;
    else if (nowC[1]->num == nowC[2]->num && nowC[2]->num == nowC[3]->num && nowC[3]->num == nowC[4]->num)
        return true;
    return false;
}
bool four_of_a_kind::compare_combination(std::vector<Card *> newC, std::vector<Card *> oldC)
{
    if (newC.at(2)->num > oldC.at(2)->num)
        return true;
    else
        return false;
};