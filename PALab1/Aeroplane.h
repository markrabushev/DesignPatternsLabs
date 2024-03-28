#pragma once
#include "Composite.h"

enum MaxNumberOfPassengers { EconomClassP = 150, BusinessClassP = 20, FirstClass = 10 };
enum BagWeight { EconomClass = 20, BusinessClass = 35, General = 60, Min = 5 };

class Aeroplane
{
public:
	Aeroplane(const unsigned p_weignt, size_t economPass, size_t businessPass, size_t firstPass)
	{
		if (economPass > MaxNumberOfPassengers::EconomClassP or businessPass > MaxNumberOfPassengers::BusinessClassP or firstPass > MaxNumberOfPassengers::FirstClass)
		{
			throw std::exception("The maximum number of passengers has been exceeded");
		}
		maxWeight = p_weignt;
		aeroplane = new Composite();
		for (size_t i = 0; i < 2; i++)
			aeroplane->addUnit(new Pilot());
		for (size_t i = 0; i < 6; i++)
			aeroplane->addUnit(new Stewardess());
		Composite* firstClass = new Composite();
		for (size_t i = 0; i < firstPass; i++)
		{
			unsigned w = rand() % (BagWeight::General - BagWeight::Min) + BagWeight::Min;
			weight += w;
			firstClass->addUnit(new Passenger(w));
		}
		Composite* businessClass = new Composite();
		for (size_t i = 0; i < businessPass; i++)
		{
			unsigned w = rand() % (BagWeight::General - BagWeight::Min) + BagWeight::Min;
			weight += w;
			if (w > BagWeight::BusinessClass)
			{
				amountBusiness++;
			}
			businessClass->addUnit(new Passenger(w));
		}
		Composite* economClass = new Composite();
		for (size_t i = 0; i < economPass; i++)
		{
			unsigned w = rand() % (BagWeight::General - BagWeight::Min) + BagWeight::Min;
			if (weight + w > maxWeight)
			{
				economClass->addUnit(new Passenger(0));
				weightOverTheLimit += w;
				passengersOverTheLimit++;
			}
			else
			{
				weight += w;
				if (w > BagWeight::EconomClass)
				{
					amountEconom++;
				}
				economClass->addUnit(new Passenger(w));
			}
		}
		aeroplane->addUnit(firstClass);
		aeroplane->addUnit(businessClass);
		aeroplane->addUnit(economClass);
	}
	~Aeroplane()
	{
		delete aeroplane;
	}
	void info()
	{
		std::cout << "Total weight: \t" << aeroplane->getWeight() << std::endl;
		std::cout << "Business class passengers with additional baggage charges: " << amountBusiness << std::endl;
		std::cout << "Econom class passengers with additional baggage charges: " << amountEconom << std::endl;
		if (passengersOverTheLimit)
		{
			std::cout << passengersOverTheLimit <<
				" bags with a total weight of " << weightOverTheLimit << " were removed from the flight" << std::endl;
		}
	}

private:
	unsigned maxWeight, weight = 0, amountEconom = 0, amountBusiness = 0, weightOverTheLimit = 0, passengersOverTheLimit = 0;
	Composite* aeroplane;
};
