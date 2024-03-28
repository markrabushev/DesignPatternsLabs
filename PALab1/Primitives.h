#pragma once
#include "Unit.h"
#include <utility>

class Passenger : public Unit
{
public:

	Passenger(unsigned p_weight)
	{
		weight = p_weight;
	};
	unsigned getWeight() const override { return weight; }
private:
	unsigned weight;
};

class Pilot : public Unit
{
public:
	unsigned getWeight() const override { return 0; }
};

class Stewardess : public Unit
{
public:
	unsigned getWeight() const override { return 0; }
};

