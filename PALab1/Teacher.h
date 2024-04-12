#pragma once


class Teacher
{
public:
    Teacher(const std::string& _name)
    {
        name = _name;
        is_create_report = false;
    }
    void CreateReport()
    {
        is_create_report = true;
    }
    void ResetReport()
    {
        is_create_report = false;
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