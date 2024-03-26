#pragma once
#include "Composite.h"

enum MaxNumberOfPassengers { EconomClassP = 150, BusinessClassP = 20, FirstClass = 10 };
enum BagWeight { EconomClass = 20, BusinessClass = 35, General = 60, Min = 5 };

class Aeroplane
{
public:
	Aeroplane(const unsigned p_weignt, size_t economPass, size_t businessPass, size_t firstPass)
	{
		maxWeight = p_weignt;
		aeroplane = new Composite();
		for (size_t i = 0; i < 2; i++)
			aeroplane->addUnit(new Primitive(0));
		for (size_t i = 0; i < 6; i++)
			aeroplane->addUnit(new Primitive(0));
		throw "fhsjkfhdskf";
		Composite* firstClass = new Composite();
		for (size_t i = 0; i < firstPass; i++)
		{
			firstClass->addUnit(new Primitive(rand() % (BagWeight::General - BagWeight::Min) + BagWeight::Min));
		}
		Composite* businessClass = new Composite();
		for (size_t i = 0; i < businessPass; i++)
		{
			businessClass->addUnit(new Primitive(rand() % (BagWeight::General - BagWeight::Min) + BagWeight::Min));
		}
		Composite* economClass = new Composite();
		for (size_t i = 0; i < economPass; i++)
		{
			economClass->addUnit(new Primitive(rand() % (BagWeight::General - BagWeight::Min) + BagWeight::Min));
		}
		aeroplane->addUnit(firstClass);
		aeroplane->addUnit(businessClass);
		aeroplane->addUnit(economClass);
	}
	~Aeroplane()
	{
		delete aeroplane;
		std::cout << "destr";
	}
	Composite* getAeroplane()
	{
		return aeroplane;
	}
	unsigned getMaxWeight()
	{
		return maxWeight;
	}
private:
	unsigned maxWeight;
	Composite* aeroplane;
};
