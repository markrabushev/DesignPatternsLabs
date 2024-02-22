#pragma once
#include "Factory.h"

class TransportManager
{
public:
	TransportManager(const unsigned numberP, const unsigned numberB, const unsigned numberT) : 
		numPassengers(numberP),
		numBusDrivers(numberB), 
		numTaxiDrivers(numberT)
	{}
	BoardAnyCar* loadAndDrive(CarFactory& factory)
	{
		BoardAnyCar* board = factory.createBoard();
		board->BoardDriver(factory.createDriver());

		for (size_t i = 0; i < board->GetMaxPassengers(); i++)
		{
			board->BoardPassenger(factory.createPassenger());
			numPassengers--;
		}

		return board;
	}

	unsigned GetNumberOfPassengers()
	{
		return numPassengers;
	}

private:
	unsigned numPassengers;
	unsigned numBusDrivers;
	unsigned numTaxiDrivers;
};
