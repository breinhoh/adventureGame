#ifndef _FINAL_PROJECT_MAZEROOM_HPP_
#define _FINAL_PROJECT_MAZEROOM_HPP_

#include "Room.hpp"

class MazeRoom : public Room
{
private:
    int path;
public:
    MazeRoom();
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
