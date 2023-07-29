#ifndef CARD_H
#define CARD_H
#include <QObject>
#include <QGraphicsPixmapItem>

#include "Parameter.h"

class Card : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card(Number n, Suit s, QGraphicsItem *parent = 0); // constructor
    void initPixmap();
    Suit suit;                             // 花色
    Number num;                            // 數字
    QString cardPath = "./Dataset/Image/"; // 素材路徑
    bool enable = false;

private:
};

#endif
