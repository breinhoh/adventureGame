#include <iostream>

#include "MazeRoom.hpp"

using std::cout;
using std::cin;
using std::endl;

MazeRoom::MazeRoom()
{
    roomName = "The Maze of Lost Souls";
    roomType = "Maze Room";
    path = 0;
}

void MazeRoom::setTunnels(Room * roomIn1, Room * roomIn2, Room * roomIn3, Room * roomIn4)
{
    room1 = roomIn1;
    room2 = roomIn2;
    room3 = roomIn3;
    room4 = roomIn4;
}

string MazeRoom::getRoomName()
{
    return roomName;
}

string MazeRoom::getRoomType()
{
    return roomType;
}

void MazeRoom::lookAround()
{
    cout << "3 tunnels. " << endl;
    cout << "a sign" << endl;
    if (object1 != NULL)
    {
        cout << object1->getPlace() << endl;
    }

}

int MazeRoom::investigateItem(Object * pockets[])
{
    string userInvestigates;
    while (true)
    {
        cout << "What do you want to investigate?" << endl;
        lookAround();
        cout << "Enter the name of your selection: ";
        getline(cin, userInvestigates);
        cout << endl;
        if (userInvestigates == "3 tunnels" || userInvestigates == "tunnels" || userInvestigates == "3 Tunnels" || userInvestigates == "Tunnels")
        {
            for (int index = 0; index < 3; index++)
            {
                while (true)
                {
                    cout << "There are three tunnels." << endl
                    << "One to your left, strait ahead, and one to your right" << endl
                    << "Which one you you want to go through? " << endl;
                    cout << "Input the direction of the tunnel only: ";
                    getline(cin, userInvestigates);
                    cout << endl << endl;
                    if (userInvestigates == "left" || userInvestigates == "Left" || userInvestigates == "LEFT")
                    {
                        path += 0;
                        break;
                    }
                    else if (userInvestigates == "strait" || userInvestigates == "Strait" || userInvestigates == "STRAIT")
                    {
                        path += 1;
                        break;
                    }
                    else if (userInvestigates == "right" || userInvestigates == "Right" || userInvestigates == "RIGHT")
                    {
                        path += 2;
                        break;
                    }
                    else
                    {
                        cout << "That is not a valid direction. " << endl;
                    }
                }
            }
            if (path == 0 || path == 6)
            {
                cout << "You are back where you started. " << endl;
                path = 0;
                return 0;
            }
            else if (path == 1 || path == 5)
            {
                path = 0;
                return 1;
            }
            else if (path == 2 || path == 4)
            {
                path = 0;
                return 2;
            }
            else
            {
                return 4;
            }
        }
        else if (userInvestigates == "a sign" || userInvestigates == "A sign" || userInvestigates == "A Sign" || userInvestigates == "sign" || userInvestigates == "Sign" || userInvestigates == "SIGN" || userInvestigates == "a Sign")
        {
            cout << "The sign reads: " << roomName << "." << endl << endl;
            return 0;
        }
        else if (userInvestigates == "Scuba Tank" || userInvestigates == "Scuba tank" || userInvestigates == "scuba tank" || userInvestigates == "scuba" || userInvestigates == "Scuba" || userInvestigates == "tank" || userInvestigates == "Tank" || userInvestigates == "TANK" || userInvestigates == "SCUBA")
        {
            return 5;
        }
        else
            cout << "That is not a valid item. " << endl << endl;
    }
}

void MazeRoom::addObstacle(Obstacle * obIn)
{
    obstacle1 = obIn;
}

void MazeRoom::addObject(Object * objIn)
{
    object1 = objIn;
}

string MazeRoom::getObName()
{
    return object1->getName();
}

string MazeRoom::getObPlace()
{
    return object1->getPlace();
}

bool MazeRoom::getIsObThere()
{
    if (object1 == NULL)
    {
        return false;
    }
    else
        return true;
}

Object * MazeRoom::takeOb()
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

Room * MazeRoom::goToRoom(int pathIn)
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