#include <QTimer>
#include <QList>
#include <cstdlib>
#include <QPixmap>
#include "Parameter.h"
#include "Combination.h"
#include "pair2.h"
#include "Game.h"

pair2::pair2(Player *now_player) : Combination()
{
    player = now_player;
    find_all_this_combination();
}

void pair2::find_all_this_combination()
{
    player->cardNumberCal();
    if (player->ownCards.size() == 0)
        return;

    std::vector<Card *> currentCombination;
    findCombinations(player->ownCards, currentCombination, 0, player->ownCards.size());
    return;
}

void pair2::findCombinations(std::vector<Card *> hand, std::vector<Card *> currentCombination, int index, int count)
{
    if (currentCombination.size() == 2)
    {
        // 若是pair2，存到combinations
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

bool pair2::is_this_combination(std::vector<Card *> nowC)
{

    if (nowC.size() != 2)
        return false;
    else if (nowC[0]->num == nowC[1]->num)
        return true;
    else
        return false;
}
bool pair2::compare_combination(std::vector<Card *> newC, std::vector<Card *> oldC)
{
    if (newC.at(1)->num > oldC.at(1)->num)
        return true;
    else if (newC.at(1)->num == oldC.at(1)->num && newC.at(1)->suit == oldC.at(1)->suit)
        return true;
    else
        return false;
};
/*

// extern Game *game;

pair2::pair2(Player *now_player) : Combination()
{
    player = now_player;
    find_all_this_combination();
}

void pair2::find_all_this_combination()
{
    player->cardNumberCal();
    player->cardSuitCal();
    if (player->ownCards.size() == 0)
        return;

    for (int i = 0; i < player->ownCards.size(); i++)
    {
        int j = i + 1;
        while (j < player->ownCards.size())
        {
            if (player->ownCards.at(i)->num == player->ownCards.at(j)->num)
            {
                std::vector<Card *> new_combination;
                new_combination.push_back(player->ownCards.at(i));
                new_combination.push_back(player->ownCards.at(j));
                combinations.push_back(new_combination);
            }
        }
    }
}
*/