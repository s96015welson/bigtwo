#include <QTimer>
#include <QList>
#include <cstdlib>
#include <QPixmap>
#include "Parameter.h"
#include "Combination.h"

//extern Game *game;

Combination::Combination() : QObject()
{
    combinations.clear();

}

bool Combination::has_this_kind()
{
    if (!combinations.empty())
        return true;
    else
        return false;
}


