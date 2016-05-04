#ifndef _FINAL_PROJECT_PICK_HPP_
#define _FINAL_PROJECT_PICK_HPP_

#include "Object.hpp"

class Pick : public Object
{
public:
    Pick();
    string getName();
    string getPlace();
    int getThere();
};

#endif
