#pragma once

class Unit
{
public:
	virtual unsigned getWeight() const = 0;
	virtual	void addUnit(Unit*) {};
};