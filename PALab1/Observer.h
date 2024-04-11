#pragma once
#include <string>
#include <iostream>
#include "Teacher.h"

class Observer 
{
public:
    virtual void Update(const std::vector<Teacher>& teachers) = 0;
};

