#pragma once
#include "Observer.h"
#include <vector>

class Subject 
{
private:
    std::vector<Observer*> observers;
public:
    virtual void Attach(Observer* observer) {
        observers.push_back(observer);
    }

    virtual void Detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    virtual void Notify() = 0;
};
