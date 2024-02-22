#pragma once
#include "Driver.h"
#include "Passenger.h"
#include <vector>

class BoardAnyCar
{
public:

	~BoardAnyCar()
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
		if (d)
			driver = d;
		else
			throw "NullPointer";
	}
	void BoardPassenger(Passenger* p)
	{
		if (passengers.size() == maxPassengers)
			throw "Exceeding the maximum number of passengers.";
		else
			passengers.push_back(p);
	}
	unsigned GetMaxPassengers() const
	{
		return maxPassengers;
	}

protected:
	Driver* driver = nullptr;
	std::vector<Passenger*> passengers;
	unsigned maxPassengers = 0;
};

class BoardTaxi : public BoardAnyCar
{
public:
	BoardTaxi()
	{
		maxPassengers = 4;
		passengers.reserve(maxPassengers);
	}

	~BoardTaxi() {};
};

class BoardBus : public BoardAnyCar
{
public:
	BoardBus()
	{
		maxPassengers = 30;
		passengers.reserve(maxPassengers);
	}

	~BoardBus() {};
};