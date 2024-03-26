#pragma once
#include "Unit.h"
#include <utility>

class Primitive : public Unit
{
public:

	Primitive(unsigned p_weight)
	{
		weight = p_weight;
	};
	unsigned getWeight() const override { return weight; }
	void setWeight(unsigned p_weight) { weight = p_weight; }
private:
	unsigned weight;
};


