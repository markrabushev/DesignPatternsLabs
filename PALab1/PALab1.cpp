#include <vector>
#include <iostream>
#include <string>
#include "Aeroplane.h"

int main()
{
	srand(time(0));
	try {
		Aeroplane a(500, 5, 5, 5);
		std::cout << a.getAeroplane()->getWeight();
	}catch(E)

	return 0;
}
