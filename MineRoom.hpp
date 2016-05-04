#ifndef _FINAL_PROJECT_MINEROOM_HPP_
#define _FINAL_PROJECT_MINEROOM_HPP_

#include "Room.hpp"

class MineRoom : public Room
{
private:
    int roomVariation;
public:
    MineRoom(int);
    void setTunnels(Room *, Room *, Room *, Room *);
    string getRoomName();
    string getRoomType();
    void lookAround();
    int investigateItem(Object **);
    void addObstacle(Obstacle *);
    void addObject(Object *);
    string getObName();
    string getObPlace();
    bool getIsObThere();
    Object * takeOb();
    Room * goToRoom(int);
};

#endif
