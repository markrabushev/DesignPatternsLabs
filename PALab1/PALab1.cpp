#include <iostream>
#include "Subject.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Teacher teacher;
	DeanOffice deanOffice;


	teacher.Attach(&deanOffice);


	teacher.createProgress("Математический анализ", "ПИН-14", 1);

	teacher.createProgress("Алгебра и геометрия", "ПИН-14", 0);

	return 0;
}
