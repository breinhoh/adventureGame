#include <iostream>

#include "MineRoom.hpp"
#include "Pick.hpp"

using std::cout;
using std::cin;
using std::endl;

MineRoom::MineRoom(int typeIn)
{
    if (typeIn == 1)
    {
        roomName = "the Room of the Dead";
        roomType = "Mine Room";
        roomVariation = 1;
    }
    else
    {
        roomName = "The Cave Entrance";
        roomType = "Mine Room";
        roomVariation = 2;
    }
}

void MineRoom::setTunnels(Room * roomIn1, Room * roomIn2, Room * roomIn3, Room * roomIn4)
{
    room1 = roomIn1;
    room2 = roomIn2;
    room3 = roomIn3;
    room4 = roomIn4;
}

string MineRoom::getRoomName()
{
    return roomName;
}

string MineRoom::getRoomType()
{
    return roomType;
}

void MineRoom::lookAround()
{
    if (!obstacle1->getOverCome())
    {
        cout << "3 tunnels. " << endl;

    }
    else
    {
        cout << "4 tunnels. " << endl;

    }
    cout << "a sign" << endl;
    if (object1 != NULL)
    {
        cout << object1->getPlace() << endl;
        if (obstacle1 != NULL)
        {
            if (!obstacle1->getOverCome())
            {
                cout << obstacle1->getName() << endl;
            }
        }
    }
    else
    {
        if (obstacle1 != NULL)
        {
            if (!obstacle1->getOverCome())
            {
                cout << obstacle1->getName() << endl;
            }
        }
    }
}

int MineRoom::investigateItem(Object * pockets[])
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
                    cout << "There are three tunnels in this room." << endl << "One to your left, strait ahead, and one to your right" << endl;
                    while (true)
                    {
                        cout << "Which one you you want to go through? " << endl;
                        cout << "Input the direction of the tunnel only: ";
                        getline(cin, userInvestigates);
                        cout << endl;
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
                        cout << endl << endl;
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
                break;
            }
            else if (userInvestigates == "a sign" || userInvestigates == "A sign" || userInvestigates == "A Sign" || userInvestigates == "sign" || userInvestigates == "Sign" || userInvestigates == "SIGN" || userInvestigates == "a Sign")
            {
                cout << "The sign reads: " << roomName << "." << endl << endl;
                return 0;
            }
            else if (userInvestigates == "pile of dirt" || userInvestigates == "Pile of dirt" || userInvestigates == "Pile of Dirt" || userInvestigates == "Pile Of Dirt" || userInvestigates == "dirt" || userInvestigates == "Dirt" || userInvestigates == "DIRT")
            {
                return 5;
            }
            else if (userInvestigates == "pile of rocks" || userInvestigates == "Pile of rocks" || userInvestigates == "Pile of Rocks" || userInvestigates == "Pile Of Rocks" || userInvestigates == "rocks" || userInvestigates == "Rocks" || userInvestigates == "ROCKS")
            {
                int minePick = 5;
                int grenade = 5;
                for (int index = 0; index < 2; index++)
                {
                    if (pockets[index] != NULL)
                    {
                        if (pockets[index]->getThere() == 1)
                        {
                            if (pockets[index]->getName() == "miner's pick")
                            {
                                minePick = index;
                            }
                            else if (pockets[index]->getName() == "grenade")
                            {
                                grenade = index;
                            }
                        }
                    }
                }
                if (minePick != 5 || grenade != 5)
                {
                    while (true)
                    {
                        cout << "Do you want to use a tool to get past the rocks" << endl;
                        cout << "(y/n): ";
                        getline(cin, userInvestigates);
                        cout << endl;
                        if (userInvestigates == "Y" || userInvestigates == "y" || userInvestigates == "yes" || userInvestigates == "YES" || userInvestigates == "Yes")
                        {
                            while (true)
                            {
                                cout << "What tool do you want to use?" << endl;
                                if (minePick != 5)
                                {
                                    cout << pockets[minePick]->getName() << endl;
                                }
                                if (grenade != 5)
                                {
                                    cout << pockets[grenade]->getName() << endl;
                                    cout << "Note: The grenade can only be used 1 time." << endl;
                                }
                                cout << "Enter the name of the tool: ";
                                getline(cin, userInvestigates);
                                cout << endl;
                                if (userInvestigates == "pick" || userInvestigates == "Pick" || userInvestigates == "PICK" || userInvestigates == "Miner's Pick" || userInvestigates == "miner's pick" || userInvestigates == "Miner's pick" || userInvestigates == "miner's Pick")
                                {
                                    cout << "You break thru the rock with the pick. " << endl;
                                    cout << "You have found another tunnel. " << endl;
                                    obstacle1->changeOverCome();
                                    while (true)
                                    {
                                        cout << "Do you want to enter the tunnel? " << endl;
                                        cout << "(y/n): ";
                                        getline(cin, userInvestigates);
                                        cout << endl;
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
                                else if (userInvestigates == "grenade" || userInvestigates == "Grenade" || userInvestigates == "GRENADE")
                                {
                                    cout << "You pull the pin, throw it at the rocks, and run to the other side of the cave. " << endl;
                                    cout << "The grenade blows the rocks all over.  You barely miss being hit" << endl;
                                    cout << "Your ears are ringing very badly but you think you are ok." << endl;
                                    cout << "As the smoke clears you can see you have found another tunnel. " << endl;
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
                            }
                        }
                        else if (userInvestigates == "N" || userInvestigates == "n" || userInvestigates == "no" || userInvestigates == "NO" || userInvestigates == "No")
                        {
                            break;
                        }
                    }
                }
                cout << endl << "The rocks were too heavy to get thru by hand. " << endl;
                return 0;
            }
            else
                cout << "That is not a valid item. " << endl << endl;
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
            if (userInvestigates == "3 tunnels" || userInvestigates == "tunnels" || userInvestigates == "3 Tunnels" || userInvestigates == "Tunnels" || userInvestigates == "4 Tunnels" || userInvestigates == "4 tunnels")
            {
                if (!obstacle1->getOverCome())
                {
                    cout << "There are three tunnels in this room." << endl << "One to your left, strait ahead, and one to your right" << endl;
                    while (true)
                    {
                        cout << "Which one you you want to go through? " << endl;
                        cout << "Input the direction of the tunnel only: ";
                        getline(cin, userInvestigates);
                        cout << endl;
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
                        else
                        {
                            cout << "That is not a valid direction." << endl << endl;
                        }
                    }
                }
                else
                {
                    cout << "There are four tunnels in this room." << endl
                    << "One to your left, strait ahead, one to your right, and one behind you that leads to the outside." << endl;
                    while (true)
                    {
                        cout << "Which one you you want to go through? " << endl;
                        cout << "Input the direction of the tunnel only: ";
                        getline(cin, userInvestigates);
                        cout << endl;
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
                break;
            }
            else if (userInvestigates == "a sign" || userInvestigates == "A sign" || userInvestigates == "A Sign" || userInvestigates == "sign" || userInvestigates == "Sign" || userInvestigates == "SIGN" || userInvestigates == "a Sign")
            {
                cout << "The sign reads: " << roomName << "." << endl << endl;
                return 0;
            }
            else if (userInvestigates == "A gate to the outside" || userInvestigates == "a gate to the outside" || userInvestigates == "A Gate to the Outside" || userInvestigates == "A Gate To The Outside" || userInvestigates == "A GATE TO THE OUTSIDE" || userInvestigates == "gate" || userInvestigates == "Gate" || userInvestigates == "GATE")
            {
                int pick = 5;
                int grenade = 5;
                for (int index = 0; index < 2; index++)
                {
                    if (pockets[index] != NULL)
                    {
                        if (pockets[index]->getThere() == 1)
                        {
                            if (pockets[index]->getName() == "lock pick")
                            {
                                pick = index;
                            }
                            else if (pockets[index]->getName() == "grenade")
                            {
                                grenade = index;
                            }
                        }
                    }
                }
                if (pick != 5 || grenade != 5)
                {
                    while (true)
                    {
                        cout << "Do you want to use a tool to get past the gate." << endl;
                        cout << "(y/n): ";
                        getline(cin, userInvestigates);
                        cout << endl;
                        if (userInvestigates == "Y" || userInvestigates == "y" || userInvestigates == "yes" || userInvestigates == "YES" || userInvestigates == "Yes")
                        {
                            while (true)
                            {
                                cout << "What tool do you want to use?" << endl;
                                if (pick != 5)
                                {
                                    cout << pockets[pick]->getName() << endl;
                                }
                                if (grenade != 5)
                                {
                                    cout << pockets[grenade]->getName() << endl;
                                    cout << "Note: The grenade can only be used 1 time." << endl;
                                }
                                cout << "Enter the name of the tool: ";
                                getline(cin, userInvestigates);
                                cout << endl;
                                if (userInvestigates == "pick" || userInvestigates == "Pick" || userInvestigates == "PICK" || userInvestigates == "Lock Pick" || userInvestigates == "lock pick" || userInvestigates == "Lock pick" || userInvestigates == "lock Pick")
                                {
                                    cout << "You pick the lock to the gate. Not bad for your first time. " << endl;
                                    cout << "You have found the exit to the cave. " << endl;
                                    obstacle1->changeOverCome();
                                    while (true)
                                    {
                                        cout << "Do you want to leave the cave? " << endl;
                                        cout << "(y/n): ";
                                        getline(cin, userInvestigates);
                                        cout << endl;
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
                                else if (userInvestigates == "grenade" || userInvestigates == "Grenade" || userInvestigates == "GRENADE")
                                {
                                    cout << "You pull the pin, throw it at the gate, and run to the other side of the cave. " << endl;
                                    cout << "The grenade blows metal everywhere.  You get cut all over and a large stiff wire spears into your leg.  You better find your way out fast!" << endl;
                                    cout << "Your ears are ringing very badly also but that is the least of your problems." << endl;
                                    cout << "As the smoke clears you can see you have found the tunnel to the outside!. " << endl;
                                    obstacle1->changeOverCome();
                                    pockets[grenade] = NULL;
                                    while (true)
                                    {
                                        cout << "Do you want to leave the cave? " << endl;
                                        cout << "(y/n): ";
                                        getline(cin, userInvestigates);
                                        cout << endl;
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
                            }
                        }
                        else if (userInvestigates == "N" || userInvestigates == "n" || userInvestigates == "no" || userInvestigates == "NO" || userInvestigates == "No")
                        {
                            break;
                        }
                    }
                }
                cout << endl << "The gate is too string to get thru by hand. " << endl << endl;
                return 0;
            }
            else
                cout << "That is not a valid item. " << endl << endl;
        }
    }
    return 0;
}

void MineRoom::addObstacle(Obstacle * obIn)
{
    obstacle1 = obIn;
}

void MineRoom::addObject(Object * objIn)
{
    object1 = objIn;
}

string MineRoom::getObName()
{
    return object1->getName();
}

string MineRoom::getObPlace()
{
    return object1->getPlace();
}

bool MineRoom::getIsObThere()
{
    if (object1 == NULL)
    {
        return false;
    }
    else
        return true;
}

Object * MineRoom::takeOb()
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

Room * MineRoom::goToRoom(int pathIn)
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