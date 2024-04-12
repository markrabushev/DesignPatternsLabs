#include <iostream>
#include "Department.h"
#include "Subject.h"
#include "Observer.h"
#include "Deanery.h"
#include "Teacher.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Subject* dean_office = new Deanery();
	Observer* dep1 = new Department("Math");
	Observer* dep2 = new Department("Physics");
	Observer* dep3 = new Department("Microelectronics");
	Teacher t1("Teacher 1", dep1, dean_office);
	Teacher t2("Teacher 2", dep1, dean_office);
	Teacher t3("Teacher 3", dep1, dean_office);
	Teacher t4("Teacher 4", dep2, dean_office);
	Teacher t5("Teacher 5", dep2, dean_office);
	Teacher t6("Teacher 6", dep2, dean_office);
	Teacher t7("Teacher 7", dep3, dean_office);
	Teacher t8("Teacher 8", dep3, dean_office);
	Teacher t9("Teacher 9", dep3, dean_office);

	t1.CreateReport();
	t2.CreateReport();
	t4.CreateReport();
	t5.CreateReport();
	t6.CreateReport();
	t8.CreateReport();
	dean_office->Notify();

	return 0;
}
