#ifndef FULL_HOUSE_H
#define FULL_HOUSE_H

#include <QObject>

#include "Parameter.h"
#include "Combination.h"
#include "Game.h"

class full_house : public Combination
{
    Q_OBJECT
public:
    full_house(Player *now_player = nullptr); // constructor

    virtual void find_all_this_combination() ;
    virtual bool is_this_combination(std::vector<Card *>);
    CombinationType combination_type = Full_House;

private:
    void findCombinations(const std::vector<Card *> , std::vector<Card *> , int, int );
};

#endif
