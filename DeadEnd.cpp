#include "DeadEnd.hpp"

DeadEnd::DeadEnd()
{
    roomName = "the Never Ending Path";
    roomType = "Game Over";
}

string DeadEnd::getRoomName()
{
    return roomName;
}

string DeadEnd::getRoomType()
{
    return roomType;
}

void DeadEnd::lookAround()
{
    
}

int DeadEnd::investigateItem(Object * pockets[])
{
    return 0;
}

void DeadEnd::addObstacle(Obstacle * obIn)
{
    obstacle1 = obIn;
}

void DeadEnd::addObject(Object * objIn)
{
    object1 = objIn;
}

string DeadEnd::getObName()
{
    return object1->getName();
}

string DeadEnd::getObPlace()
{
    return object1->getPlace();
}

void DeadEnd::setTunnels(Room * roomIn1, Room * roomIn2, Room * roomIn3, Room * roomIn4)
{
    room1 = roomIn1;
    room2 = roomIn2;
    room3 = roomIn3;
    room4 = roomIn4;
}

bool DeadEnd::getIsObThere()
{
    if (object1 == NULL)
    {
        return false;
    }
    else
        return true;
}

Object * DeadEnd::takeOb()
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

Room * DeadEnd::goToRoom(int pathIn)
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