#include "Rocks.hpp"

Rocks::Rocks()
{
    obName = "pile of rocks";
    overCome = false;
}

string Rocks::getName()
{
    return obName;
}

bool Rocks::getOverCome()
{
    return overCome;
}

void Rocks::changeOverCome()
{
    overCome = true;
}