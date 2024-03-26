#pragma once
#include "Primitives.h"
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
	size_t getSize()
	{
		return units.size();
	}
	~Composite()
	{
		for (const auto& u : units)
			delete u;
	}
private:
	std::vector<Unit*> units;
};
