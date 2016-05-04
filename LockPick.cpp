#include "LockPick.hpp"

LockPick::LockPick()
{
    objectName = "lock pick";
    hidingPlace = "heap of metal";
}

string LockPick::getName()
{
    return objectName;
}

string LockPick::getPlace()
{
    return hidingPlace;
}
int LockPick::getThere()
{
    return 1;
}