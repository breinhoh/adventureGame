#ifndef _FINAL_PROJECT_ABYSS_HPP_
#define _FINAL_PROJECT_ABYSS_HPP_

#include "Ends.hpp"

class Abyss : public Ends
{
public:
    Abyss();
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