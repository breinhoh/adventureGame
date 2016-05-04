#include "Abyss.hpp"

Abyss::Abyss()
{
    roomName = "the Abyss";
    roomType = "Game Over";
}

string Abyss::getRoomName()
{
    return roomName;
}

string Abyss::getRoomType()
{
    return roomType;
}

void Abyss::lookAround()
{
    
}

int Abyss::investigateItem(Object * pockets[])
{
    return 0;
}

void Abyss::addObstacle(Obstacle * obIn)
{
    obstacle1 = obIn;
}

void Abyss::addObject(Object * objIn)
{
    object1 = objIn;
}

string Abyss::getObName()
{
    return object1->getName();
}

string Abyss::getObPlace()
{
    return object1->getPlace();
}

void Abyss::setTunnels(Room * roomIn1, Room * roomIn2, Room * roomIn3, Room * roomIn4)
{
    room1 = roomIn1;
    room2 = roomIn2;
    room3 = roomIn3;
    room4 = roomIn4;
}

bool Abyss::getIsObThere()
{
    if (object1 == NULL)
    {
        return false;
    }
    else
        return true;
}

Object * Abyss::takeOb()
{
    if (getIsObThere())
    {
        Object * temp = object1;
        object1 = NULL;
        return temp;
    }
    else
        return NULL;
}

Room * Abyss::goToRoom(int pathIn)
{
    if (pathIn == 1)
    {
        return room1;
    }
    else if (pathIn == 2)
    {
        return room2;
    }
    else if (pathIn == 3)
    {
        return room3;
    }
    else
    {
        return room4;
    }
}