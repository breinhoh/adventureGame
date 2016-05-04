#ifndef _FINAL_PROJECT_OBSTACLE_HPP_
#define _FINAL_PROJECT_OBSTACLE_HPP_

#include <string>

using std::string;

class Obstacle
{
protected:
    string obName;
    bool overCome;
    
public:
    virtual string getName() = 0;
    virtual bool getOverCome() = 0;
    virtual void changeOverCome() = 0;
    
};

#endif