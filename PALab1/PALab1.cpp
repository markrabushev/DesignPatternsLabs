#include <vector>
#include <iostream>
#include <string>
#include "Aeroplane.h"

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	try {
		Aeroplane a(5000, 145, 15, 9);
		a.info();
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
