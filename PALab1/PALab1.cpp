﻿#include "Director.h"
#include <vector>
#include <iostream>
#include <string>

int main()
{
	BusBuilder bus_builder;
	TaxiBuilder taxi_builder;
	Director dir(bus_builder);
	try 
	{
		Car* Bus = dir.CreateBoard(5, 3, 0, 6);
		Bus->info();
	}
	catch (const char* error_message)
	{
		std::cout << error_message << std::endl;
	}
	std::cout << std::endl;
	dir.SetBuilder(taxi_builder);
	try 
	{
		Car* Taxi = dir.CreateBoard(2, 1, 1);
		Taxi->info();
	}
	catch (const char* error_message)
	{
		std::cout << error_message << std::endl;
	}

	return 0;
}
