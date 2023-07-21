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
}

bool four_of_a_kind::has_this_kind()
{
    player->cardNumberCal();
    if(player==nullptr)
        return false;

    for (int i = 0; i < 13;i++)
    {
        if(player->cardNumber.at(i)>=4 &&player->ownCards.size()>=5)
        return true;
    }
    return false;
}
