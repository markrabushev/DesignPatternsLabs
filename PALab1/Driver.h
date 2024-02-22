#pragma once

#include <iostream>

enum class Licenze { BCategory, DCategory };

class Driver
{
public:
	Licenze licenze;
	virtual void info() = 0;
	virtual ~Driver() {};
};

class TaxiDriver : public Driver
{
public:
	TaxiDriver()
	{
		licenze = Licenze::BCategory;
	}
	void info() {
		std::cout << "TaxiDriver" << std::endl;
	}
};

class BusDriver : public Driver
{
public:
	BusDriver()
	{
		licenze = Licenze::DCategory;
	}
	void info() {
		std::cout << "BusDriver" << std::endl;
	}
};

class Passenger
{
public:
	Passenger() {};
	void info() {
		std::cout << "Passenger" << std::endl;
	}
};
