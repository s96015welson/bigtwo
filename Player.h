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
    Player(QGraphicsItem *parent = 0);

    void sortCards();
    void addCard(Card *);
    void cardNumberCal();
    void cardSuitCal();

    std::vector<Card *> ownCards;

    std::vector<std::vector<Card *>> cardNumber;
    std::vector<std::vector<Card *>> cardSuit;

    // Qbutton

private:
};

#endif // PLAYER_H
