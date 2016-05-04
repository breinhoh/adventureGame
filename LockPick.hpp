#ifndef _FINAL_PROJECT_LOCKPICK_HPP_
#define _FINAL_PROJECT_LOCKPICK_HPP_

#include "Object.hpp"

class LockPick : public Object
{
public:
    LockPick();
    string getName();
    string getPlace();
    int getThere();
};

#endif
