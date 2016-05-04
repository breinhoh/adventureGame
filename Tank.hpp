#ifndef _FINAL_PROJECT_TANK_HPP_
#define _FINAL_PROJECT_TANK_HPP_

#include "Object.hpp"

class Tank : public Object
{
public:
    Tank();
    string getName();
    string getPlace();
    int getThere();
};

#endif
