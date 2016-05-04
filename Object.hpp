#ifndef _FINAL_PROJECT_OBJECT_HPP_
#define _FINAL_PROJECT_OBJECT_HPP_

#include <string>

using std::string;

class Object
{
protected:
    string objectName;
    string hidingPlace;    
    
public:
    virtual string getName() = 0;
    virtual string getPlace() = 0;
    virtual int getThere() = 0;
};

#endif
