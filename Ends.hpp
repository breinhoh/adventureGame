#ifndef _FINAL_PROJECT_ENDS_HPP_
#define _FINAL_PROJECT_ENDS_HPP_

#include "Room.hpp"

class Ends : public Room
{
public:
    virtual void setTunnels(Room *, Room *, Room *, Room *) = 0;
    virtual string getRoomName() = 0;
    virtual string getRoomType() = 0;
    virtual void lookAround() = 0;
    virtual int investigateItem(Object **) = 0;
    virtual void addObstacle(Obstacle *) = 0;
    virtual void addObject(Object *) = 0;
    virtual string getObName() = 0;
    virtual string getObPlace() = 0;
    virtual bool getIsObThere() = 0;
    virtual Object * takeOb() = 0;
    virtual Room * goToRoom(int) = 0;
};

#endif