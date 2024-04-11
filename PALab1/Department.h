#pragma once
#include "Observer.h"
#include <vector>

class Department : public Observer
{
public:
	Department(const std::string& n)
	{
		name = n;
	}
	void Update(const std::vector<Teacher>& teachers)
	{
		std::cout << "������� " << name << " �������� ������ �� " << teachers.size() << " ��������������, �� ������� �����:" << std::endl;
		for (auto& t : teachers)
		{
			std::cout << t.GetName() << std::endl;
		}
	}
private:
	std::string name;
};
