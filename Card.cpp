#include <QTimer>
// #include <QGraphicsScene>
#include <QList>
#include <cstdlib>
#include <QPixmap>
#include "Parameter.h"
#include "Card.h"
#include <QGraphicsPixmapItem>

// extern Game *game;

Card::Card(Number n, Suit s, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    num = n;
    suit = s;

    //Card Path
    switch (num)
    {
    case (C2):
        cardPath += "2";
        break;
    case (C3):
        cardPath += "3";
        break;
    case (C4):
        cardPath += "4";
        break;
    case (C5):
        cardPath += "5";
        break;
    case (C6):
        cardPath += "6";
        break;
    case (C7):
        cardPath += "7";
        break;
    case (C8):
        cardPath += "8";
        break;
    case (C9):
        cardPath += "9";
        break;
    case (C10):
        cardPath += "10";
        break;
    case (J):
        cardPath += "jack";
        break;
    case (Q):
        cardPath += "queen";
        break;
    case (K):
        cardPath += "king";
        break;
    case (A):
        cardPath += "ace";
        break;

    default:
        break;
    }
    cardPath += "_of_";
    switch (suit)
    {
    case (Clubs):
        cardPath += "clubs";
        break;
    case (Hearts):
        cardPath += "hearts";
        break;
    case (Diamonds):
        cardPath += "diamonds";
        break;
    case (Spades):
        cardPath += "spades";
        break;

    default:
        break;
    }
    cardPath += ".png";
}
