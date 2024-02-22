#pragma once
#include "Factory.h"

class TransportManager
{
public:
	TransportManager(const unsigned numberP) : numPassengers(numberP) {}
	BoardAnyCar* loadAndDrive(CarFactory& factory)
	{
		BoardAnyCar* board = factory.createBoard();

		board->BoardDriver(factory.createDriver());

		for (size_t i = 0; i < board->GetMaxPassengers(); i++)
		{
			if (numPassengers)
			{
				board->BoardPassenger(factory.createPassenger());
				numPassengers--;
			}
			else
				break;
		}

		return board;
	}

	unsigned GetNumberOfPassengers()
	{
		return numPassengers;
	}

private:
	unsigned numPassengers;
};
