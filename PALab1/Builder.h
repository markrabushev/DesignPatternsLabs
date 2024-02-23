#pragma once
#include "Board.h"
#include "Driver.h"
#include "Passenger.h"

class CarBuilder
{
protected:
	BoardAnyCar* board;
public:
	CarBuilder() : board(nullptr) {}
	virtual void createBoard() = 0;
	virtual void buildAdult() = 0;
	virtual void buildPreferential() = 0;
	virtual void buildChild() = 0;
	virtual void buildDriver() = 0;
	BoardAnyCar* getBoard() { return board; }
};

class TaxiBuilder : public CarBuilder
{
public:
	void createBoard() { board = new BoardTaxi; }
	void buildDriver() { board->BoardDriver(new TaxiDriver()); }
	void buildAdult() { board->BoardPassenger(new AdultPassenger()); }
	void buildChild() { board->BoardPassenger(new ChildPassenger()); board->IncreaseChildSafetySeats(); }
	void buildPreferential() {};
};

class BusBuilder : public CarBuilder
{
public:
	void createBoard() { board = new BoardBus; }
	void buildDriver() { board->BoardDriver(new BusDriver()); }
	void buildAdult() { board->BoardPassenger(new AdultPassenger()); }
	void buildChild() { board->BoardPassenger(new ChildPassenger()); }
	void buildPreferential() { board->BoardPassenger(new PreferentialPassenger()); }
};