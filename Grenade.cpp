#include "Grenade.hpp"

Grenade::Grenade()
{
    objectName = "grenade";
    hidingPlace = "grenade";
}

string Grenade::getName()
{
    return objectName;
}

string Grenade::getPlace()
{
    return hidingPlace;
}
int Grenade::getThere()
{
    return 1;
}