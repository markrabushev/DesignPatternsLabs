#pragma once
#include "Car.h"
#include "Driver.h"
#include "Passenger.h"

class CarBuilder
{
protected:
	Car* car;
public:
	CarBuilder() : car(nullptr) {}
	virtual ~CarBuilder() {};
	virtual void createCar() = 0;
	virtual void buildAdult() {};
	virtual void buildPreferential() {};
	virtual void buildChild() {};
	virtual void buildDriver() {};
	virtual void buildSafetySeat() {};
	Car* getCar() { return car; }
};

class TaxiBuilder : public CarBuilder
{
public:
	void createCar() { car = new Car(4); }
	void buildDriver() { car->BoardDriver(new TaxiDriver()); }
	void buildAdult() { car->BoardPassenger(new AdultPassenger()); }
	void buildChild() { 
		if (car->GetNumberOfChildSafetySeats())
		{
			car->BoardPassenger(new ChildPassenger());
			car->DecreaseChildSafetySeats();
		}
		else
		{
			throw "There are not enough child safety seats";
		}
	}
	void buildSafetySeat() { car->IncreaseChildSafetySeats(); }
	~TaxiBuilder()
	{
		delete car;
	}
};

class BusBuilder : public CarBuilder
{
public:
	void createCar() { car = new Car(30); }
	void buildDriver() { car->BoardDriver(new BusDriver()); }
	void buildAdult() { car->BoardPassenger(new AdultPassenger()); }
	void buildChild() { car->BoardPassenger(new ChildPassenger()); }
	void buildPreferential() { car->BoardPassenger(new PreferentialPassenger()); }
	~BusBuilder()
	{
		delete car;
	}
};