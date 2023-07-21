#include <iostream>
#include <QGraphicsScene>
#include <typeinfo>
#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <utility>
#include "Parameter.h"
#include "Player.h"
#include "Card.h"

// extern Game *game; // there is an external global object called game

Player::Player(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    ownCards.clear();
    cardNumber.clear();
}

void Player::sortCards()
{
    for (int i = 0; i < ownCards.size(); i++)
        for (int j = i + 1; j < ownCards.size(); j++)
        {
            if (((int)(ownCards[i]->num) > (int)(ownCards[j]->num)) ||
                (((int)(ownCards[i]->num) == (int)(ownCards[j]->num)) && ((int)(ownCards[i]->suit) > (int)(ownCards[j])->suit)))
            {
                Card *temp = ownCards.at(i);
                ownCards.at(i) = ownCards.at(j);
                ownCards.at(j) = temp;
            }
        }
}

void Player::cardNumberCal()
{
    cardNumber.clear();
    for (int i = 0; i < 13; i++)
        cardNumber.push_back(0);
    
    for(int i=0;i<ownCards.size();i++)
    {
        cardNumber.at((int)(ownCards.at(i)->num))++;
    }
}
void Player::addCard(Card *new_card)
{
    ownCards.push_back(new_card);
}


