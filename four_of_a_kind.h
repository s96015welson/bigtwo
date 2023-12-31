#ifndef FOUR_OF_A_KIND_H
#define FOUR_OF_A_KIND_H

#include <QObject>

#include "Parameter.h"
#include "Combination.h"
#include "Game.h"

class four_of_a_kind : public Combination
{
    Q_OBJECT
public:
    four_of_a_kind(Player *now_player = nullptr); // constructor

    virtual void find_all_this_combination() ;
    virtual bool is_this_combination(std::vector<Card *>);
    virtual bool compare_combination(std::vector<Card *>,std::vector<Card *>);
    CombinationType combination_type = Four_of_a_Kind;

private:
    void findCombinations(const std::vector<Card *> , std::vector<Card *> , int, int );
};


#endif
