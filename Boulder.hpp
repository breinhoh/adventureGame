#ifndef _FINAL_PROJECT_BOULDER_HPP_
#define _FINAL_PROJECT_BOULDER_HPP_

#include "Obstacle.hpp"

class Boulder : public Obstacle
{
public:
    Boulder();
    string getName();
    bool getOverCome();
    void changeOverCome();
};

#endif
