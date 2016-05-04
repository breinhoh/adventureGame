#ifndef _FINAL_PROJECT_ROOM_HPP_
#define _FINAL_PROJECT_ROOM_HPP_

#include <string>
#include <vector>

#include "Obstacle.hpp"
#include "Object.hpp"

using std::string;
using std::vector;

class Room
{
protected:
    string roomName;
    string roomType;
    Room * room1;
    Room * room2;
    Room * room3;
    Room * room4;
    Object * object1;
    Obstacle * obstacle1;
public:
    virtual void setTunnels(Room *, Room *, Room *, Room *) = 0;
    virtual string getRoomName() = 0;
    virtual string getRoomType() = 0;
    virtual void lookAround() = 0;
    virtual int investigateItem(Object **) = 0;
    virtual void addObstacle(Obstacle *) = 0;
    virtual void addObject(Object *) = 0;
    virtual Room * goToRoom(int) = 0;
    virtual string getObName() = 0;
    virtual string getObPlace() = 0;
    virtual bool getIsObThere() = 0;
    virtual Object * takeOb() = 0;
    virtual ~Room();
};

#endif
