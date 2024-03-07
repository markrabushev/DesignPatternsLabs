#include "Director.h"
#include <vector>
#include <iostream>
#include <string>

int main()
{
	Director dir;
	BusBuilder bus_builder;
	TaxiBuilder taxi_builder;
	try 
	{
		Car* Bus = dir.createBoard(bus_builder, 5, 3, 0, 6);
		Bus->info();
	}
	catch (const char* error_message)
	{
		std::cout << error_message << std::endl;
	}
	std::cout << std::endl;
	try 
	{
		Car* Taxi = dir.createBoard(taxi_builder, 2, 1, 1);
		Taxi->info();
	}
	catch (const char* error_message)
	{
		std::cout << error_message << std::endl;
	}

	return 0;
}
