#include <QTimer>
#include <QList>
#include <cstdlib>
#include <QPixmap>
#include "Parameter.h"
#include "Combination.h"

// extern Game *game;

Combination::Combination() : QObject()
{
    combinations.clear();
}

bool Combination::has_this_kind()
{
    if (!combinations.empty())
        return true;
    else
        return false;
}
void Combination::find_enable()
{
    for (Card *card : player->ownCards)
        card->enable = false;
    for (int i = 0; i < combinations.size(); i++)
    {
        for (int j = 0; j < combinations.at(i).size(); j++)
            combinations[i][j]->enable = true;
    }
}
