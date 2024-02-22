#pragma once

#include "Driver.h"


class BoardAnyCar
{
public:
	BoardAnyCar() {};
	virtual ~BoardAnyCar() {};

	virtual Driver* BoardDriver() = 0;

	Passenger* BoardPassenger()
	{
		return new Passenger();
	}

protected:
	Driver* driver = nullptr;

};

class BoardTaxi : public BoardAnyCar
{
public:
	BoardTaxi()
	{
		std::cout << "BoardTaxi is created\n";
	}
	Driver* BoardDriver()
	{
		return new TaxiDriver();
	}

	~BoardTaxi() {};
};

class BoardBus : public BoardAnyCar
{
public:
	BoardBus()
	{
		std::cout << "BoardBus is created\n";
	}
	Driver* BoardDriver()
	{
		return new BusDriver();
	}
	~BoardBus() {};
};