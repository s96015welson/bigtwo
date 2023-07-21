#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include "Parameter.h"
#include "Card.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player( QGraphicsItem *parent = 0);

    void sortCards();
    void addCard(Card *);
    void cardNumberCal();


    std::vector<Card *> ownCards;

    

    std::vector<int> cardNumber;
    // Qbutton

private:
};

#endif // PLAYER_H
