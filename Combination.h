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

    virtual void find_all_this_combination()=0;
    virtual bool is_this_combination(std::vector<Card *>)=0;
    virtual bool compare_combination(std::vector<Card *>,std::vector<Card *>)=0;
    Player *player;
    std::vector<std::vector<Card *>> combinations;

    //
    bool has_this_kind();
    void find_enable();
    

private:
};

#endif
