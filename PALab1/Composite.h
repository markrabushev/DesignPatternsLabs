#pragma once
#include "Primitive.h"
#include <vector>


class Composite : public Unit
{
public:

	unsigned getWeight() const override
	{
		unsigned weight = 0;
		for (const auto& u : units)
			weight += u->getWeight();
		return weight;
	}
	void addUnit(Unit* u) override
	{
		units.push_back(u);
	}
	~Composite()
	{
		for (const auto& u : units)
			delete u;
	}
private:
	std::vector<Unit*> units;
};
