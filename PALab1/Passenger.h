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

class AdultPassenger : public Passenger
{
public:
	AdultPassenger() {};
	void info() const {
		std::cout << "Adult passenger" << std::endl;
	}
};

class PreferentialPassenger : public Passenger
{
public:
	PreferentialPassenger() {};
	void info() const {
		std::cout << "Preferential passenger" << std::endl;
	}
};

class ChildPassenger : public Passenger
{
public:
	ChildPassenger() {};
	void info() const {
		std::cout << "Child passenger" << std::endl;
	}
};
