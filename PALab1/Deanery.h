#pragma once
#include "Subject.h"
#include "Observer.h"
#include "Teacher.h"
#include <map>

class Deanery : public Subject
{
public:
	void Attach(Observer* observer, Teacher* teacher)
	{
        if (observers.find(observer) != observers.end()) {
            observers[observer].push_back(teacher);
        }
        else {
            observers[observer] = { teacher };
        }
	}
	void Detach(Observer* observer) {
		auto it = observers.find(observer);
		if (it != observers.end()) {
			observers.erase(it);
		}
	}
	void Notify()
	{
		for (auto const& x : observers)
		{
			std::vector<Teacher*> teachers;
			for (auto& t : x.second)
			{
				if (!t->IsCreateReport())
				{
					teachers.push_back(t);
				}
			}
			x.first->Update(teachers);
		}
	}
	//void CheckReports();
	
private:
	//std::vector<Teacher> teachers;
	std::map<Observer*, std::vector<Teacher*>> observers;
};