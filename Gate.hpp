#ifndef _FINAL_PROJECT_GATE_HPP_
#define _FINAL_PROJECT_GATE_HPP_

#include "Obstacle.hpp"

class Gate : public Obstacle
{
public:
    Gate();
    string getName();
    bool getOverCome();
    void changeOverCome();
};

#endif