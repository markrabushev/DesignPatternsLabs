#pragma once
#include "Driver.h"
#include "Board.h"
#include "Passenger.h"
#include <iostream>

class CarFactory
{
public:
	virtual ~CarFactory() {}
	virtual Driver* createDriver() = 0;
	virtual BoardAnyCar* createBoard() = 0;
	Passenger* createPassenger()
	{
		return new Passenger();
	}
};

class BusFactory : public CarFactory
{
public:
	BusDriver* createDriver() override
	{
		return new BusDriver();
	}
	BoardBus* createBoard() override
	{
		return new BoardBus();
	}
};

class TaxiFactory : public CarFactory
{
public:
	TaxiDriver* createDriver() override
	{
		return new TaxiDriver();
	}
	BoardTaxi* createBoard() override
	{
		return new BoardTaxi();
	}

};
