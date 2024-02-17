#pragma once
#include <vector>
#include "Board.h"
#include "Driver.h"

class BusStation
{
public:
	std::vector<Passenger*> passengers;
	std::vector<Driver*> drivers;

	~BusStation()
	{
		int i;
		for (i = 0; i < passengers.size(); ++i) delete passengers[i];
		for (i = 0; i < drivers.size(); ++i) delete drivers[i];
	}

	int passengersCount()
	{
		return passengers.size();
	}
	int driversCount()
	{
		return drivers.size();
	}
};