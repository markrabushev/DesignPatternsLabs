#pragma once
#include "Builder.h"

class Director
{
public:
	Car* createBoard(CarBuilder& builder, size_t AdultNum = 1, size_t ChildNum = 1, size_t BeneficiaryNum = 0)
	{
		builder.createCar();
		builder.buildDriver();
		for (size_t i = 0; i < AdultNum; i++)
			builder.buildAdult();
		for (size_t i = 0; i < ChildNum; i++)
			builder.buildChild();
		for (size_t i = 0; i < BeneficiaryNum; i++)
			builder.buildPreferential();
		return builder.getCar();
	}
};