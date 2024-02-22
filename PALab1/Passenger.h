#pragma once
#include <iostream>

class Passenger
{
public:
	Passenger() {};
	void info() const {
		std::cout << "Passenger" << std::endl;
	}
};
