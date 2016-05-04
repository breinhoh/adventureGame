#include <iostream>

#include "Room.hpp"
#include "MineRoom.hpp"
#include "MazeRoom.hpp"
#include "WaterRoom.hpp"
#include "Ends.hpp"
#include "Abyss.hpp"
#include "DeadEnd.hpp"
#include "WaterFall.hpp"
#include "Outside.hpp"
#include "Obstacle.hpp"
#include "Rocks.hpp"
#include "Gate.hpp"
#include "Boulder.hpp"
#include "Object.hpp"
#include "Pick.hpp"
#include "Tank.hpp"
#include "LockPick.hpp"
#include "Grenade.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::getline;

int main()
{
    
    //set up the cave map, This is hard coded but a later change could make this mix up the map each time the game is played.
    Room * wakeUp = new MineRoom(1);
    Room * maze = new MazeRoom;
    Room * whirlPool = new WaterRoom(2);
    Room * close = new MineRoom(2);
    Room * pool = new WaterRoom(1);
    Room * endA = new Abyss;
    Room * endD = new DeadEnd;
    Room * endF = new WaterFall;
    Room * endO = new Outside;
    wakeUp->setTunnels(maze, whirlPool, pool, endA);
    maze->setTunnels(close, whirlPool, wakeUp, endD);
    whirlPool->setTunnels(maze, close, pool, wakeUp);
    close->setTunnels(maze, whirlPool, pool, endO);
    pool->setTunnels(close, whirlPool, wakeUp, endF);
    endA->setTunnels(NULL, NULL, NULL, NULL);
    endD->setTunnels(NULL, NULL, NULL, NULL);
    endF->setTunnels(NULL, NULL, NULL, NULL);
    endO->setTunnels(NULL, NULL, NULL, NULL);
    Obstacle * pileORocks = new Rocks;
    wakeUp->addObstacle(pileORocks);
    Object * minersPick = new Pick;
    wakeUp->addObject(minersPick);
    Object * airTank = new Tank;
    maze->addObject(airTank);
    Object * lockPick = new LockPick;
    pool->addObject(lockPick);
    Obstacle * boulder = new Boulder;
    pool->addObstacle(boulder);
    Object * grenade = new Grenade;
    whirlPool->addObject(grenade);
    Obstacle * gate = new Gate;
    close->addObstacle(gate);
    Object * pockets[2] = {NULL, NULL};


    Room * currentRoom = wakeUp;
    bool firstTime = false;
    
    cout << "                    You wake up alone in a dark room." << endl
         << "     You don't know where you are, you don't know how you got here." << endl
         << "There is a dim flash light near you. You pick it up and inspect yourself." << endl
         << "          You are not hurt. Your clothes are intact but dirty." << endl
         << "          Your pockets are empty. You think, what do I do now?" << endl << endl;
    
    while (true)
    {
        if (currentRoom == endA)
        {
            cout << endl << "You fell down " << currentRoom->getRoomName() << endl;
            cout << currentRoom->getRoomType() << endl;
            exit(-1);
        }
        else if (currentRoom == endD)
        {
            cout << endl << "You have gone down " << currentRoom->getRoomName() << endl;
            cout << currentRoom->getRoomType() << endl;
            exit(-1);
        }
        else if (currentRoom == endF)
        {
            cout << endl << "You swam over " << currentRoom->getRoomName() << endl;
            cout << currentRoom->getRoomType() << endl;
            exit(-1);
        }
        else if (currentRoom == endO)
        {
            cout << "Congratulations! You have found your way out of the cave." << endl;
            cout << "             Now where in the world are you?" << endl;
            cout << "                   To be continued..." << endl;
            exit(-1);
        }
        else if (currentRoom == pool)
        {
            if (firstTime)
            {
                cout << "You find yourself in a cave filled with water." << endl;
                cout << "As you wade in you are happy to see it is only waist deep, calm, and clear." << endl;
                cout << endl;
                firstTime = false;
            }
        }
        else if (currentRoom == maze)
        {
            if (firstTime)
            {
                cout << "You find yourself in a cave that looks like any you have seen." << endl;
                cout << "However something feels weird about it.  You proceed with caution" << endl;
                cout << endl;
                firstTime = false;
            }
        }
        else if (currentRoom == close)
        {
            if (firstTime)
            {
                cout << "You find yourself in a cave that resembles a mine shaft more then a cave." << endl;
                cout << "There is warm air coming from somewhere but you can't tell where." << endl;
                cout << endl;
                firstTime = false;
            }
        }
        else if (currentRoom == whirlPool)
        {
            if (firstTime)
            {
                cout << "You find yourself in a fast spinning whirlpool. " << endl;
                cout << "You are being pulled under by the current." << endl;
                bool hasTank = false;
                for (int index = 0; index < 4; index++)
                {
                    if (pockets[index] == airTank)
                    {
                        hasTank = true;
                    }
                }
                if (hasTank)
                {
                    cout << "You pull the small scuba tank from you pocket and put it in your mouth." << endl;
                    cout << "As you get pulled down to the bottom the strength of the whirlpool is " << endl;
                    cout << "restricted to just one small area.  You are able to swim in any direction" << endl;
                    cout << "with some effort, as long as you avoid the strong part of the water." << endl << endl;
                }
                else
                {
                    cout << endl << "You have been captured by " << currentRoom->getRoomName() << endl;
                    cout << currentRoom->getRoomType() << endl;
                    exit(-1);
                }
                firstTime = false;
            }
        }
        string userSelection;
        cout << "What do you want to do? " << endl;
        cout << "1, Look around. " << endl;
        cout << "2. Investigate something. " << endl;
        cout << "3. Look in your pockets. " << endl;
        cout << "Enter the number of your selection: ";
        getline(cin, userSelection);
        cout << endl;
        if (userSelection == "1")
        {
            cout << "You look around and see the following things. " << endl;
            currentRoom->lookAround();
            cout << endl;
        }
        else if (userSelection == "2")
        {
            int nextRoom = currentRoom->investigateItem(pockets);
            if (nextRoom == 1 || nextRoom == 2 || nextRoom == 3)
            {
                cout << "You have entered another cave room. " << endl;
                currentRoom = currentRoom->goToRoom(nextRoom);
                firstTime = true;
            }
            else if (nextRoom == 5)
            {
                cout << "You found a " << currentRoom->getObName() << endl;
                while (true)
                {
                    cout << "Do you wnat to take it? " << endl;
                    cout << "(y/n): ";
                    getline(cin, userSelection);
                    if (userSelection == "Y" || userSelection == "y" || userSelection == "yes" || userSelection == "YES" || userSelection == "Yes")
                    {
                        cout << endl;
                        bool haveRoom = false;
                        bool skipIn = false;
                        int emptyPocket = 0;
                        while (true)
                        {
                            for (int index = 0; index < 2; index++)
                            {
                                if (pockets[index] == NULL)
                                {
                                    haveRoom = true;
                                    emptyPocket = index;
                                }
                            }
                            if (haveRoom)
                            {
                                pockets[emptyPocket] = currentRoom->takeOb();
                                break;
                            }
                            else if (skipIn)
                            {
                                break;
                            }
                            else
                            {
                                cout << "Your pockets are full. Would you like to discard something?" << endl;
                                cout << "Note: Once you discard something you cannot get it back." << endl;
                                for (int index = 0; index < 2; index++)
                                {
                                    cout << index + 1 << ". " << pockets[index]->getName() << endl;
                                }
                                while (true)
                                {
                                    string userTake;
                                    cout << "Enter the number of the item you want to discard or n for nothing: ";
                                    getline(cin, userTake);
                                    cout << endl;
                                    if (userTake == "1")
                                    {
                                        if (pockets[0] == airTank && currentRoom == whirlPool)
                                        {
                                            cout << "You cannot discard the airtank while under water. " << endl;
                                            skipIn = true;
                                            break;
                                        }
                                        else
                                            pockets[0] = NULL;
                                            break;
                                    }
                                    else if (userTake == "2")
                                    {
                                        if (pockets[1] == airTank && currentRoom == whirlPool)
                                        {
                                            cout << "You cannot discard the airtank while under water. " << endl;
                                            skipIn = true;
                                            break;
                                        }
                                        else
                                            pockets[1] = NULL;
                                            break;
                                    }
                                    else if (userTake == "n" || userTake == "N")
                                    {
                                        skipIn = true;
                                        break;
                                    }
                                    else
                                        cout << "That is not a valid input. " << endl;
                                }
                            }
                        }
                        break;
                    }
                    else if (userSelection == "N" || userSelection == "n" || userSelection == "no" || userSelection == "NO" || userSelection == "No")
                    {
                        break;
                    }
                    else
                        cout << endl << "That is not a valid input. " << endl;
                }
            }
            else if (nextRoom == 4)
            {
                currentRoom = currentRoom->goToRoom(nextRoom);
                firstTime = true;
            }
        }
        else if (userSelection == "3")
        {
            for (int index = 0; index < 2; index++)
            {
                if (pockets[index] != NULL)
                {
                    cout << pockets[index]->getName() << endl;
                }
            }
            cout << endl;
        }
        else
            cout << "That is not a valid input. " << endl << endl;
    }
    delete wakeUp;
    delete maze;
    delete whirlPool;
    delete pool;
    delete endD;
    delete endF;
    delete endO;
    delete endA;
    delete pileORocks;
    delete boulder;
    delete gate;
    delete minersPick;
    delete lockPick;
    delete airTank;
    delete grenade;
    
    return 0;
}
