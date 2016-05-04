#include "Pick.hpp"

Pick::Pick()
{
    objectName = "miner's pick";
    hidingPlace = "pile of dirt";
}

string Pick::getName()
{
    return objectName;
}

string Pick::getPlace()
{
    return hidingPlace;
}
int Pick::getThere()
{
    return 1;
}