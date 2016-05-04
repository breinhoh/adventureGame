#include "Gate.hpp"

Gate::Gate()
{
    obName = "a metal gate";
}

string Gate::getName()
{
    return obName;
}

bool Gate::getOverCome()
{
    return overCome;
}

void Gate::changeOverCome()
{
    overCome = true;
}