#pragma once
#include <iostream>

class Passenger
{
public:
	Passenger() {};
	virtual void info() const {};
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
