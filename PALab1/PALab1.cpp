#include "Director.h"
#include <vector>
#include <iostream>
#include <string>

int main()
{
	Director dir;
	BusBuilder bus_builder;
	TaxiBuilder taxi_builder;
	BoardAnyCar* BB = dir.createBoard(bus_builder, 5, 3, 2);
	std::cout << std::endl;
	BoardAnyCar* BT = dir.createBoard(taxi_builder, 2, 1);

	return 0;
}
