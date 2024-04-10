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
		context.SetText(std::regex_replace(context.GetText(), std::regex("\\s+"), " "));
	}
};

class DashInterpreter : public TextInterpreter
{
public:
	DashInterpreter() {};
	void Interpret(Context& context)
	{
		context.SetText(std::regex_replace(context.GetText(), std::regex("-"), "–"));
	}
};

class QuotationMarksInterpreter : public TextInterpreter
{
public:
	QuotationMarksInterpreter() {};
	void Interpret(Context& context)
	{
		std::string temp = std::regex_replace(context.GetText(), std::regex("“"), "«");
		context.SetText(std::regex_replace(temp, std::regex("”"), "»"));
	}
};

class TabsInterpreter : public TextInterpreter
{
public:
	TabsInterpreter() {};
	void Interpret(Context& context)
	{
		context.SetText(std::regex_replace(context.GetText(), std::regex("\t{2,}"), "\t"));
	}
};

class BracketInterpreter : public TextInterpreter
{
public:
	BracketInterpreter() {};
	void Interpret(Context& context)
	{
		std::string temp = std::regex_replace(context.GetText(), std::regex("\\(\\s+"), "(");
		temp = std::regex_replace(context.GetText(), std::regex("\\s+\\)"), ")");
		temp = std::regex_replace(context.GetText(), std::regex("\\s+,"), ",");
		temp = std::regex_replace(context.GetText(), std::regex("\\s+\\."), ".");
		context.SetText(temp);
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