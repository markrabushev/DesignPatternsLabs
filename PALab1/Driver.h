#pragma once
#include <iostream>

enum class License { BCategory, DCategory };

class Driver
{
public:
	License license;
	virtual void info() const = 0;
};

class TaxiDriver : public Driver
{
public:
	TaxiDriver()
	{
		license = License::BCategory;
	}
	void info() const {
		std::cout << "TaxiDriver" << std::endl;
	}
};

class BusDriver : public Driver
{
public:
	BusDriver()
	{
		license = License::DCategory;
	}
	void info() const {
		std::cout << "BusDriver" << std::endl;
	}
};

