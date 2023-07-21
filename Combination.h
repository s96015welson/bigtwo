#ifndef COMBINATION_H
#define COMBINATION_H


#include <QObject>

#include "Parameter.h"
#include "Player.h"
class Combination : public QObject
{
    Q_OBJECT
public:
    Combination(); // constructor


    virtual void find_all_this_combination() = 0;
    Player* player;

    //
    bool has_this_kind = false;

private:
};

#endif
