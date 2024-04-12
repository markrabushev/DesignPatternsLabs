#pragma once
#include "Subject.h"
#include "Observer.h"


class Teacher
{
public:
    Teacher(const std::string& _name, Observer* d, Subject* s)
    {
        name = _name;
        s->Attach(d, this);
        is_create_report = false;
    }
    void CreateReport()
    {
        is_create_report = true;
    }
    bool IsCreateReport()
    {
        return is_create_report;
    }
    std::string GetName() const
    {
        return name;
    }
private:
    std::string name;
    bool is_create_report;
};