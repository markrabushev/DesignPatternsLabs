#include <iostream>
#include "Department.h"
#include "Subject.h"
#include "Observer.h"
#include "Deanery.h"
#include "Teacher.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Deanery dean_office;
	Observer* dep1 = new Department("Math");
	Observer* dep2 = new Department("Physics");
	Observer* dep3 = new Department("Microelectronics");
	Teacher t1("Teacher 1");
	dean_office.Attach(dep1, &t1);
	Teacher t2("Teacher 2");
	dean_office.Attach(dep1, &t2);
	Teacher t3("Teacher 3");
	dean_office.Attach(dep1, &t3);
	Teacher t4("Teacher 4");
	dean_office.Attach(dep2, &t4);
	Teacher t5("Teacher 5");
	dean_office.Attach(dep2, &t5);
	Teacher t6("Teacher 6");
	dean_office.Attach(dep2, &t6);
	Teacher t7("Teacher 7");
	dean_office.Attach(dep3, &t7);
	Teacher t8("Teacher 8");
	dean_office.Attach(dep3, &t8);
	Teacher t9("Teacher 9");
	dean_office.Attach(dep3, &t9);

	t1.CreateReport();
	t2.CreateReport();
	t4.CreateReport();
	t5.CreateReport();
	t6.CreateReport();
	t8.CreateReport();
	dean_office.CheckPerformance();

	t1.ResetReport();
	t2.ResetReport();
	t3.ResetReport();
	t4.ResetReport();
	t5.ResetReport();
	t6.ResetReport();
	t7.ResetReport();
	t8.ResetReport();
	t9.ResetReport();

	
	t2.CreateReport();
	t4.CreateReport();
	t6.CreateReport();
	t7.CreateReport();
	dean_office.CheckPerformance();

	return 0;
}
