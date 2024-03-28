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
	void removeUnit(Unit* u) override
	{
		auto pos = std::find(units.begin(), units.end(), u);
		if(pos != units.end())
			units.erase(pos);
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
