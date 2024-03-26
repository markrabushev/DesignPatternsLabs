#include "TransportManager.h"
#include <vector>
#include <iostream>
#include <string>

int main()
{
	auto TM = new TransportManager(50);
	auto BF = BusFactory();
	auto TF = TaxiFactory();
	std::cout << "Number of passengers: " << TM->GetNumberOfPassengers() << std::endl;
	BoardAnyCar* BBus = TM->loadAndDrive(BF);
	BoardAnyCar* BTaxi = TM->loadAndDrive(TF);
	if (BBus->isReady())
	{
		BBus->GetDriver()->info();
		std::cout << " left with " << BBus->GetCurrentPassengers() << " passengers" << std::endl;
	}
	if (BTaxi->isReady())
	{
		BTaxi->GetDriver()->info();
		std::cout << " left with " << BTaxi->GetCurrentPassengers() << " passengers" << std::endl;
	}
	std::cout << "Number of passengers: " << TM->GetNumberOfPassengers() << std::endl;
	BBus = TM->loadAndDrive(BF);
	if (BBus->isReady())
	{
		BBus->GetDriver()->info();
		std::cout << " left with " << BBus->GetCurrentPassengers() << " passengers" << std::endl;
	}
	std::cout << "Number of passengers: " << TM->GetNumberOfPassengers() << std::endl;
	BTaxi = TM->loadAndDrive(TF);
	if (BTaxi->isReady())
	{
		BTaxi->GetDriver()->info();
		std::cout << " left with " << BTaxi->GetCurrentPassengers() << " passengers" << std::endl;
	}


	delete TM;
	delete BBus;
	delete BTaxi;
	return 0;
}
