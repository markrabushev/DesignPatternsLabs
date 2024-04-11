#pragma once
#include "Observer.h"
#include <vector>

class Subject 
{
private:
    std::vector<Observer*> observers;
public:
    void Attach(Observer* observer) {
        observers.push_back(observer);
    }

    void Detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void Notify(const std::string& discipline, const std::string& group, const bool& status) {
        for (Observer* observer : observers) {
            observer->Update(discipline, group, status);
        }
    }
};


class Teacher : public Subject 
{
public:
    void createProgress(const std::string& discipline, const std::string& group, const bool& status) {
        std::cout << "Учитель разместил текущую успеваемость " << discipline << " in group " << group << " with status " << status << std::endl;
        Notify(discipline, group, status);
    }
};