#include "Boulder.hpp"

Boulder::Boulder()
{
    obName = "a boulder";
}

string Boulder::getName()
{
    return obName;
}

bool Boulder::getOverCome()
{
    return overCome;
}

void Boulder::changeOverCome()
{
    overCome = true;
}