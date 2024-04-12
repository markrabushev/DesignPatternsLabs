#pragma once
#include <string>
#include <regex>
#include "Context.h"

class TextInterpreter
{
public:
	TextInterpreter() {};
	virtual ~TextInterpreter() {};
	virtual void Interpret(Context& context) = 0;
};

class SpacesInterpreter : public TextInterpreter
{
public:
	SpacesInterpreter() {};
	void Interpret(Context& context)
	{
		context.SetText(std::regex_replace(context.GetText(), std::regex(" {2,}"), " "));
	}
};

class DashInterpreter : public TextInterpreter
{
public:
	DashInterpreter() {};
	void Interpret(Context& context)
	{
		std::string temp = std::regex_replace(context.GetText(), std::regex("\\s*-\\s*"), "-");
		context.SetText(std::regex_replace(temp, std::regex("\\s*�\\s*"), " � "));
	}
};

class QuotationMarksInterpreter : public TextInterpreter
{
public:
	QuotationMarksInterpreter() {};
	void Interpret(Context& context)
	{
		context.SetText(std::regex_replace(context.GetText(), std::regex("(\"|�)\\s*(.+?)\\s*(\"|�)"), "�$2�"));
	}
};

class TabsInterpreter : public TextInterpreter
{
public:
	TabsInterpreter() {};
	void Interpret(Context& context)
	{
		context.SetText(std::regex_replace(context.GetText(), std::regex("( *\t{2,} *)|^ +"), "\t"));
	}
};

class BracketInterpreter : public TextInterpreter
{
public:
	BracketInterpreter() {};
	void Interpret(Context& context)
	{
		context.SetText(std::regex_replace(context.GetText(), std::regex("\\(\\s+"), "("));
		context.SetText(std::regex_replace(context.GetText(), std::regex("\\s+\\)"), ")"));
		context.SetText(std::regex_replace(context.GetText(), std::regex("\\s+,"), ","));
		context.SetText(std::regex_replace(context.GetText(), std::regex("\\s+\\."), "."));
	}
};

class NewlineInterpreter : public TextInterpreter
{
public:
	NewlineInterpreter() {};
	void Interpret(Context& context)
	{
		context.SetText(std::regex_replace(context.GetText(), std::regex("\n+"), "\n"));
	}
};