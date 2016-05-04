#ifndef _FINAL_PROJECT_WATERFALL_HPP_
#define _FINAL_PROJECT_WATERFALL_HPP_

#include "Ends.hpp"

class WaterFall : public Ends
{
public:
    WaterFall();
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
