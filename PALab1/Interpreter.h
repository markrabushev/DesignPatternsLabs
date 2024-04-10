#pragma once
#include <string>
#include <regex>

class TextInterpreter
{
public:
	TextInterpreter() {};
	virtual ~TextInterpreter() {};
	virtual std::string Interpret(std::string& str) = 0;
};

class SpacesInterpreter : public TextInterpreter
{
public:
	SpacesInterpreter() {};
	std::string Interpret(std::string& str)
	{
		return std::regex_replace(str, std::regex("\\s+"), " ");
	}
};

class QuotationMarksInterpreter : public TextInterpreter
{
public:
	QuotationMarksInterpreter() {};
	std::string Interpret(std::string& str)
	{
		return std::regex_replace(str, std::regex(""), "");
	}
};