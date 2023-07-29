#ifndef STRAIGHT_H
#define STRAIGHT_H

#include <QObject>

#include "Parameter.h"
#include "Combination.h"
#include "Game.h"

class straight : public Combination
{
    Q_OBJECT
public:
    straight(Player *now_player = nullptr); // constructor

    virtual void find_all_this_combination() ;
    virtual bool is_this_combination(std::vector<Card *>);
    virtual bool compare_combination(std::vector<Card *>,std::vector<Card *>);
    CombinationType combination_type = Straight;

private:
    void findCombinations(const std::vector<Card *> , std::vector<Card *> , int, int );
};

#endif
