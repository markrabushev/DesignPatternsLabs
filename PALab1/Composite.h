#pragma once
#include "Primitives.h"
#include <vector>

enum MaxNumberOfPassengers { EconomClass = 150, BusinessClass = 20, FirstClass = 10 };
enum MaxWeight { EconomClass = 20, BusinessClass = 35, General = 60, Min = 5 };


class FirstClass : public Unit
{
public:

	unsigned getWeight() const override
	{
		unsigned weight = 0;
		for (const auto& p : passengers)
			weight += p->getWeight();
		return weight;
	}
	void addUnit(Unit* u) override
	{
		if (passengers.size() <= MaxNumberOfPassengers::FirstClass)
			passengers.push_back(u);
	}
	~FirstClass()
	{
		for (const auto& p : passengers)
			delete p;
	}
private:
	std::vector<Unit*> passengers;
};

class EconomClass : public Unit
{
public:

	unsigned getWeight() const override
	{
		unsigned weight = 0;
		for (const auto& p : passengers)
			weight += p->getWeight();
		return weight;
	}
	void addUnit(Unit* u) override
	{
		if (passengers.size() <= MaxNumberOfPassengers::EconomClass)
			passengers.push_back(u);
	}
	~EconomClass()
	{
		for (const auto& p : passengers)
			delete p;
	}
private:
	std::vector<Unit*> passengers;
};

class BusinessClass : public Unit
{
public:

	unsigned getWeight() const override
	{
		unsigned weight = 0;
		for (const auto& p : passengers)
			weight += p->getWeight();
		return weight;
	}
	void addUnit(Unit* u) override
	{
		if (passengers.size() <= MaxNumberOfPassengers::BusinessClass)
			passengers.push_back(u);
	}
	~BusinessClass()
	{
		for (const auto& p : passengers)
			delete p;
	}
private:
	std::vector<Unit*> passengers;
};

class Aeroplane : public Unit
{
	unique_ptr<CompositeBusinessClass> business;
	unique_ptr<CompositeEconomClass> econom;
	unique_ptr<CompositeFirstClass> first;
	std::vector<Stewardess*> stewardesses;
	std::vector<Pilot*> pilots;
	static const uint maxWeight = 500;
public:
	Aeroplane(size_t economPass, size_t businessPass, size_t firstPass)
	{
		weight = 0;
		uint r = 0; uint p = 0;
		cout << "Aeroplane is created\n";
		for (size_t i = 0; i < 2; i++)
			pilots.push_back(new Pilot());
		for (size_t i = 0; i < 6; i++)
			stewardesses.push_back(new Stewardess());
		first = make_unique<CompositeFirstClass>(make_pair<uint, uint>(Ticket::Row, Ticket::Position));
		for (size_t i = 0; i < firstPass; i++)
		{
			p = p++ % Ticket::Position + 1;
			first->addUnit(new Passenger(
				rand() % (MaxWeight::AllWeight - MaxWeight::MinWeight) + MaxWeight::MinWeight),
				make_pair<uint, uint>(
					p == 0 ? ++r : r,
					p)
			);
		}
		business = make_unique<CompositeBusinessClass>(make_pair<uint, uint>(Ticket::Row, Ticket::Position));
		for (size_t i = 0; i < businessPass; i++)
			business->addUnit(new Passenger(rand() % (MaxWeight::BusinessWeight - MaxWeight::MinWeight) + MaxWeight::MinWeight));
		weight = business->getWeight() + first->getWeight();

		econom = make_unique<CompositeEconomClass>(make_pair<uint, uint>(Ticket::Row, Ticket::Position));
		if (weight >= maxWeight)
		{
			for (size_t i = 0; i < economPass; i++)
				econom->addUnit(new Passenger(0));
		}
		else
		{
			static uint rnd = 0;
			for (size_t i = 0; i < economPass; i++)
			{
				rnd = rand() % (MaxWeight::EconomWeight - MaxWeight::MinWeight) + MaxWeight::MinWeight;
				if (weight + rnd > maxWeight)
				{
					econom->addUnit(new Passenger(0));
				}
				else
				{
					weight += rnd;
					econom->addUnit(new Passenger(rnd));
				}

			}
		}
	}
	uint getWeight() const override
	{
		return weight;
	}
	~Aeroplane()
	{
		for (auto& c : stewardesses)
			delete c;
		stewardesses.clear();
		stewardesses.shrink_to_fit();
		for (auto& c : pilots)
			delete c;
		pilots.clear();
		pilots.shrink_to_fit();
	}
};