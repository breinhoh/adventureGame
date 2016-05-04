#include "WaterFall.hpp"

WaterFall::WaterFall()
{
    roomName = "the Dead Man Falls";
    roomType = "Game Over";
}

string WaterFall::getRoomName()
{
    return roomName;
}

string WaterFall::getRoomType()
{
    return roomType;
}

void WaterFall::lookAround()
{
    
}

int WaterFall::investigateItem(Object * pockets[])
{
    return 0;
}

void WaterFall::addObstacle(Obstacle * obIn)
{
    obstacle1 = obIn;
}

void WaterFall::addObject(Object * objIn)
{
    object1 = objIn;
}

string WaterFall::getObName()
{
    return object1->getName();
}

string WaterFall::getObPlace()
{
    return object1->getPlace();
}

void WaterFall::setTunnels(Room * roomIn1, Room * roomIn2, Room * roomIn3, Room * roomIn4)
{
    room1 = roomIn1;
    room2 = roomIn2;
    room3 = roomIn3;
    room4 = roomIn4;
}

bool WaterFall::getIsObThere()
{
    if (object1 == NULL)
    {
        return false;
    }
    else
        return true;
}

Object * WaterFall::takeOb()
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

Room * WaterFall::goToRoom(int pathIn)
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