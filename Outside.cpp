#include "Outside.hpp"

Outside::Outside()
{
    roomName = "Freedom";
    roomType = "You Win!!!";
}

string Outside::getRoomName()
{
    return roomName;
}

string Outside::getRoomType()
{
    return roomType;
}

void Outside::lookAround()
{
    
}

int Outside::investigateItem(Object * pockets[])
{
    return 0;
}

void Outside::addObstacle(Obstacle * obIn)
{
    obstacle1 = obIn;
}

void Outside::addObject(Object * objIn)
{
    object1 = objIn;
}

string Outside::getObName()
{
    return object1->getName();
}

string Outside::getObPlace()
{
    return object1->getPlace();
}

void Outside::setTunnels(Room * roomIn1, Room * roomIn2, Room * roomIn3, Room * roomIn4)
{
    room1 = roomIn1;
    room2 = roomIn2;
    room3 = roomIn3;
    room4 = roomIn4;
}

bool Outside::getIsObThere()
{
    if (object1 == NULL)
    {
        return false;
    }
    else
        return true;
}

Object * Outside::takeOb()
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

Room * Outside::goToRoom(int pathIn)
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