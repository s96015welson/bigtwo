#ifndef STRAIGHT_FLUSH_H
#define STRAIGHT_FLUSH_H

#include <QObject>

#include "Parameter.h"
#include "Combination.h"
#include "Game.h"

class straight_flush : public Combination
{
    Q_OBJECT
public:
    straight_flush(Player *now_player = nullptr); // constructor

    virtual void find_all_this_combination() ;
    virtual bool is_this_combination(std::vector<Card *>);
    CombinationType combination_type = Straight_Flush;

private:
    void findCombinations(const std::vector<Card *> , std::vector<Card *> , int, int );
};

#endif
