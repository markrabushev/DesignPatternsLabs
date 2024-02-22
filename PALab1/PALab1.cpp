#include "TransportManager.h"
#include <vector>
#include <iostream>
#include <string>

int main()
{
	auto TM = new TransportManager(200, 5, 8);
	auto BF = BusFactory();
	auto TF = TaxiFactory();
	BoardAnyCar* BBus = TM->loadAndDrive(BF);
	BoardAnyCar* BTaxi = TM->loadAndDrive(TF);
	std::cout << BBus->isReady() << std::endl;
	std::cout << BTaxi->isReady() << std::endl;
	std::cout << TM->GetNumberOfPassengers() << std::endl;
	TM->loadAndDrive(BF);
	std::cout << TM->GetNumberOfPassengers() << std::endl;
	system("pause");
	delete TM;
	delete BBus;
	delete BTaxi;
	return 0;
}
