#pragma once
#include "Builder.h"

class Director
{
private:
	CarBuilder* builder = nullptr;
public:
	Director(CarBuilder& p_builder)
	{
		builder = &p_builder;
	}
	void SetBuilder(CarBuilder& p_builder)
	{
		builder = &p_builder;
	}
	Car* CreateBoard(size_t AdultNum = 1, size_t ChildNum = 1, unsigned safetySeats = 0, size_t PreferentialNum = 0)
	{
		builder->createCar();
		builder->buildDriver();
		for (int i = 0; i < safetySeats; i++)
			builder->buildSafetySeat();
		for (size_t i = 0; i < AdultNum; i++)
			builder->buildAdult();
		for (size_t i = 0; i < ChildNum; i++)
			builder->buildChild();
		for (size_t i = 0; i < PreferentialNum; i++)
			builder->buildPreferential();
		return builder->getCar();
	}
};