#include <iostream>

#include "WaterRoom.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::getline;

WaterRoom::WaterRoom(int typeIn)
{
    if (typeIn == 1)
    {
        roomName = "the Swimming Hole";
        roomType = "Pool Room";
        roomVariation = 1;
    }
    else
    {
        roomName = "the Death Swirl";
        roomType = "Game Over";
        roomVariation = 2;
    }
    
}

void WaterRoom::setTunnels(Room * roomIn1, Room * roomIn2, Room * roomIn3, Room * roomIn4)
{
    room1 = roomIn1;
    room2 = roomIn2;
    room3 = roomIn3;
    room4 = roomIn4;
}

string WaterRoom::getRoomName()
{
    return roomName;
}

string WaterRoom::getRoomType()
{
    return roomType;
}

void WaterRoom::lookAround()
{
    if (roomVariation == 1)
    {
        cout << "Above Water:" << endl;
        if (!obstacle1->getOverCome())
        {
            cout << "3 tunnels. " << endl;
        }
        else
        {
            cout << "4 tunnels" << endl;
        }
        cout << "a sign" << endl;
        cout << "Under Water:" << endl;
        if (object1 != NULL)
        {
            cout << object1->getPlace() << endl;
            if (obstacle1 != NULL && !obstacle1->getOverCome())
            {
                cout << obstacle1->getName() << endl;
            }
        }
        else
        {
            if (obstacle1 != NULL && !obstacle1->getOverCome())
            {
                cout << obstacle1->getName() << endl;
            }
        }
    }
    else
    {
        cout << "4 tunnels. " << endl;
        cout << "a sign" << endl;
        if (object1 != NULL)
        {
            cout << object1->getPlace() << endl;
        }
    }
    
}

int WaterRoom::investigateItem(Object * pockets[])
{
    if (roomVariation == 1)
    {
        string userInvestigates;
        while (true)
        {
            cout << "What do you want to investigate?" << endl;
            lookAround();
            cout << "Enter the name of your selection: ";
            getline(cin, userInvestigates);
            cout << endl;
            if (userInvestigates == "3 tunnels" || userInvestigates == "tunnels" || userInvestigates == "3 Tunnels" || userInvestigates == "Tunnels" || userInvestigates == "4 Tunnels" || userInvestigates == "4 tunnels")
            {
                if (!obstacle1->getOverCome())
                {
                    cout << "There are three tunnels in this room." << endl << "One to your left, one to your right, and one right behind you." << endl;
                    while (true)
                    {
                        cout << "Which one you you want to go through? " << endl;
                        cout << "Input the direction of the tunnel only: ";
                        getline(cin, userInvestigates);
                        cout << endl << endl;
                        if (userInvestigates == "left" || userInvestigates == "Left" || userInvestigates == "LEFT")
                        {
                            return 2;
                        }
                        else if (userInvestigates == "behind" || userInvestigates == "Behind" || userInvestigates == "BEHIND")
                        {
                            return 3;
                        }
                        else if (userInvestigates == "right" || userInvestigates == "Right" || userInvestigates == "RIGHT")
                        {
                            return 4;
                        }
                        else
                        {
                            cout << "That is not a valid direction." << endl << endl;
                        }
                    }
                }
                else
                {
                    cout << "There are four tunnels in this room." << endl
                    << "One to your left, strait ahead, one to your right, and one behind you." << endl;
                    while (true)
                    {
                        cout << "Which one you you want to go through? " << endl;
                        cout << "Input the direction of the tunnel only: ";
                        getline(cin, userInvestigates);
                        if (userInvestigates == "left" || userInvestigates == "Left" || userInvestigates == "LEFT")
                        {
                            return 2;
                        }
                        else if (userInvestigates == "strait" || userInvestigates == "Strait" || userInvestigates == "STRAIT")
                        {
                            return 1;
                        }
                        else if (userInvestigates == "right" || userInvestigates == "Right" || userInvestigates == "RIGHT")
                        {
                            return 4;
                        }
                        else if (userInvestigates == "behind" || userInvestigates == "Behind" || userInvestigates == "BEHIND")
                        {
                            return 3;
                        }
                        else
                        {
                            cout << "That is not a valid direction." << endl << endl;
                        }
                    }
                }
                break;
            }
            else if (userInvestigates == "a sign" || userInvestigates == "A sign" || userInvestigates == "A Sign" || userInvestigates == "sign" || userInvestigates == "Sign" || userInvestigates == "SIGN" || userInvestigates == "a Sign")
            {
                cout << "The sign reads: " << roomName << "." << endl << endl;
                return 0;
            }
            else if (userInvestigates == "heap of metal" || userInvestigates == "Heap of metal" || userInvestigates == "Heap of Metal" || userInvestigates == "Heap Of Metal" || userInvestigates == "HEAP OF METAL" || userInvestigates == "heap" || userInvestigates == "Heap" || userInvestigates == "HEAP" || userInvestigates == "metal" || userInvestigates == "Metal" || userInvestigates == "METAL")
            {
                return 5;
            }
            else if (userInvestigates == "boulder" || userInvestigates == "Boulder" || userInvestigates == "BOULDER" || userInvestigates == "boulders" || userInvestigates == "Boulders" || userInvestigates == "BOULDERS")
            {
                int grenade = 5;
                for (int index = 0; index < 2; index++)
                {
                    if (pockets[index] != NULL)
                    {
                        if (pockets[index]->getThere() == 1)
                        {
                            if (pockets[index]->getName() == "grenade")
                            {
                                grenade = index;
                            }
                        }
                    }
                }
                if (grenade != 5)
                {
                    while (true)
                    {
                        cout << "Do you want to use your grenade to get past the boulder?" << endl;
                        cout << "(y/n): ";
                        getline(cin, userInvestigates);
                        cout << endl;
                        if (userInvestigates == "Y" || userInvestigates == "y" || userInvestigates == "yes" || userInvestigates == "YES" || userInvestigates == "Yes")
                        {
                            cout << "You pull the pin, throw it at the boulder, and splash in to the water on the other side of the cave. " << endl;
                            cout << "The grenade blows the boulder up and throws water and rock everywhere. Staying underwater seems to have protected you a bit" << endl;
                            cout << "With water dripping off the walls you can see you have found another tunnel. " << endl;
                            obstacle1->changeOverCome();
                            pockets[grenade] = NULL;
                            while (true)
                            {
                                cout << "Do you want to enter the tunnel? " << endl;
                                cout << "(y/n): ";
                                getline(cin, userInvestigates);
                                if (userInvestigates == "Y" || userInvestigates == "y" || userInvestigates == "yes" || userInvestigates == "YES" || userInvestigates == "Yes")
                                {
                                    return 4;
                                }
                                else if (userInvestigates == "N" || userInvestigates == "n" || userInvestigates == "no" || userInvestigates == "NO" || userInvestigates == "No")
                                {
                                    return 0;
                                }
                                else
                                    cout << endl << "That is not a valid input. " << endl;
                            }
                        }
                        else if (userInvestigates == "N" || userInvestigates == "n" || userInvestigates == "no" || userInvestigates == "NO" || userInvestigates == "No")
                        {
                            break;
                        }
                    }
                }
                else
                    cout << "The boulder is too big to get past by hand." << endl << endl;
            }
            else
                cout << "That is not a valid item. " << endl;
        }
    }
    else
    {
        string userInvestigates;
        while (true)
        {
            cout << "What do you want to investigate?" << endl;
            lookAround();
            cout << "Enter the name of your selection: ";
            getline(cin, userInvestigates);
            cout << endl;
            if (userInvestigates == "tunnels" || userInvestigates == "Tunnels" || userInvestigates == "4 Tunnels" || userInvestigates == "4 tunnels")
            {
                cout << "There are four tunnels in this room." << endl
                << "One to your left, strait ahead, one to your right, and one behind you." << endl;
                while (true)
                {
                    cout << "Which one you you want to go through? " << endl;
                    cout << "Input the direction of the tunnel only: ";
                    getline(cin, userInvestigates);
                    if (userInvestigates == "left" || userInvestigates == "Left" || userInvestigates == "LEFT")
                    {
                        return 1;
                    }
                    else if (userInvestigates == "strait" || userInvestigates == "Strait" || userInvestigates == "STRAIT")
                    {
                        return 2;
                    }
                    else if (userInvestigates == "right" || userInvestigates == "Right" || userInvestigates == "RIGHT")
                    {
                        return 3;
                    }
                    else if (userInvestigates == "behind" || userInvestigates == "Behind" || userInvestigates == "BEHIND")
                    {
                        return 4;
                    }
                    else
                    {
                        cout << "That is not a valid direction." << endl << endl;
                    }
                }
            }
            else if (userInvestigates == "a sign" || userInvestigates == "A sign" || userInvestigates == "A Sign" || userInvestigates == "sign" || userInvestigates == "Sign" || userInvestigates == "SIGN" || userInvestigates == "a Sign")
            {
                cout << "The sign reads: " << roomName << "." << endl << endl;
                return 0;
            }
            else if (userInvestigates == "grenade" || userInvestigates == "Grenade" || userInvestigates == "GRENADE")
            {
                return 5;
            }
            else
                cout << "That is not a valed item. " << endl << endl;
        }

    }
    return 0;
}

void WaterRoom::addObstacle(Obstacle * obIn)
{
    obstacle1 = obIn;
}

void WaterRoom::addObject(Object * objIn)
{
    object1 = objIn;
}

string WaterRoom::getObName()
{
    return object1->getName();
}

string WaterRoom::getObPlace()
{
    return object1->getPlace();
}

bool WaterRoom::getIsObThere()
{
    if (object1 == NULL)
    {
        return false;
    }
    else
        return true;
}

Object * WaterRoom::takeOb()
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

Room * WaterRoom::goToRoom(int pathIn)
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

int WaterRoom::getRoomVariation()
{
    return roomVariation;
}