#ifndef _FINAL_PROJECT_GRENADE_HPP_
#define _FINAL_PROJECT_GRENADE_HPP_

#include "Object.hpp"

class Grenade : public Object
{
public:
    Grenade();
    string getName();
    string getPlace();
    int getThere();
};

#endif
