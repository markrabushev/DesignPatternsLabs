#pragma once
#include "Driver.h"
#include "Passenger.h"
#include <vector>

class Car
{
public:
	Car(unsigned p_maxPassengers) : maxPassengers(p_maxPassengers) {}
	~Car()
	{
		if (driver)
			delete driver;
		for (auto p : passengers)
			delete p;
	}
	bool isReady()
	{
		if (driver == nullptr)
			return false;
		if (passengers.size() < 1)
			return false;
		return true;
	}
	void BoardDriver(Driver* d)
	{
		if (d == nullptr)
			throw "NullPointer";
		else if (driver != nullptr)
			throw "There is already a driver in the car";
		else
			driver = d;
	}
	void BoardPassenger(Passenger* p)
	{
		if (passengers.size() == maxPassengers)
			throw "Exceeding the maximum number of passengers.";
		else
			passengers.push_back(p);
	}
	/*unsigned GetMaxPassengers() const
	{
		return maxPassengers;
	}
	Driver* GetDriver()
	{
		if (driver)
			return driver;
		else
			throw "NullPointer";
	}*/
	/*unsigned GetCurrentNumberOfPassengers()
	{
		return passengers.size();
	}*/
	unsigned GetNumberOfChildSafetySeats()
	{
		return childSafetySeats;
	}
	void IncreaseChildSafetySeats()
	{
		childSafetySeats++;
	}
	void DecreaseChildSafetySeats()
	{
		if (childSafetySeats) childSafetySeats--;
	}
	void info()
	{
		driver->info();
		std::cout << " with " << passengers.size() << " passengers:" << std::endl;
		for (auto& p : passengers)
		{
			p->info();
		}
	}

protected:
	Driver* driver = nullptr;
	std::vector<Passenger*> passengers;
	unsigned maxPassengers = 0;
	unsigned childSafetySeats = 0;
};

//class Taxi : public Car
//{
//public:
//	Taxi()
//	{
//		maxPassengers = 4;
//		passengers.reserve(maxPassengers);
//	}
//
//	~Taxi() {};
//
//};
//
//class Bus : public Car
//{
//public:
//	Bus()
//	{
//		maxPassengers = 30;
//		passengers.reserve(maxPassengers);
//	}
//
//	~Bus() {};
//};