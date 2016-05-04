#ifndef _FINAL_PROJECT_WATERROOM_HPP_
#define _FINAL_PROJECT_WATERROOM_HPP_

#include "Room.hpp"

class WaterRoom : public Room
{
private:
    int roomVariation;
public:
    WaterRoom(int);
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
    int getRoomVariation();
};

#endif
