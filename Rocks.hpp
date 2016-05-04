#ifndef _FINAL_PROJECT_ROCKS_HPP_
#define _FINAL_PROJECT_ROCKS_HPP_

#include "Obstacle.hpp"

class Rocks : public Obstacle
{
public:
    Rocks();
    string getName();
    bool getOverCome();
    void changeOverCome();
};

#endif
