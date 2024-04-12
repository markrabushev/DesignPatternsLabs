#pragma once
#include <vector>
#include "Teacher.h"

class Observer 
{
public:
    virtual void Update(std::vector<Teacher*>& teachers) = 0;
};

