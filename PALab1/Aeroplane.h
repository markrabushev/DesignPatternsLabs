#pragma once
#include "Composite.h"

enum MaxNumberOfPassengers { EconomClass = 150, BusinessClass = 20, FirstClass = 10 };
enum BagWeight { EconomClass = 20, BusinessClass = 35, General = 60, Min = 5 };

class Aeroplane
{
	Aeroplane(unsigned p_weignt)
	{
		maxWeight = p_weignt;
	}
	Composite* CreateAeroplane(size_t economPass, size_t businessPass, size_t firstPass)
	{
		Composite* Aeroplane = new Composite();
		for (size_t i = 0; i < 2; i++)
			Aeroplane->addUnit(new Primitive(0));
		for (size_t i = 0; i < 6; i++)
			Aeroplane->addUnit(new Primitive(0));

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
		Aeroplane->addUnit(firstClass);
		Aeroplane->addUnit(businessClass);
		Aeroplane->addUnit(economClass);
	}
private:
	unsigned maxWeight;
};
