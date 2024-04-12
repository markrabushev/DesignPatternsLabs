#pragma once
#include "Observer.h"
#include "Teacher.h"

class Subject 
{
public:
    virtual void Attach(Observer* observer, Teacher* teacher) = 0;

    virtual void Detach(Observer* observer) = 0;

    virtual void Notify() = 0;
};
