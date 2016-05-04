#include "Tank.hpp"

Tank::Tank()
{
    objectName = "scuba tank";
    hidingPlace = "scuba tank";
}

string Tank::getName()
{
    return objectName;
}

string Tank::getPlace()
{
    return hidingPlace;
}

int Tank::getThere()
{
    return 1;
}