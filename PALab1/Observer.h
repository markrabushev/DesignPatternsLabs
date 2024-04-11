#pragma once
#include <string>
#include <iostream>

class Observer 
{
public:
    virtual void Update(const std::string& discipline, const std::string& group, const bool& status) = 0;
};


class DeanOffice : public Observer 
{
public:
    void Update(const std::string& discipline, const std::string& group, const bool& status) override {
        if (!status) {
            std::cout << "������� ���������� �������: ������������� ���������� " << discipline << " � ������ " << group << " ������� �� ������ ������� ������������!" << std::endl;
        }
    }
};