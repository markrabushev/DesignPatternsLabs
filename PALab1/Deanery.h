#pragma once
#include "Subject.h"
#include <map>
#include "Department.h"

class Deanery : public Subject
{
public:
	void CheckReports();
	void Notify() 
	{
		
	}
private:
	std::vector<Teacher> teachers;
};