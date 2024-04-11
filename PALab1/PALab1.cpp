#include <iostream>
#include "Interpreter.h"
#include <fstream>
#include <sstream>
#include <Windows.h>

std::string readFile(const std::string& fileName) {
	std::ifstream f(fileName);
	std::stringstream ss;
	ss << f.rdbuf();
	return ss.str();
}

void ProcessText(Context& context)
{
	TextInterpreter* spacesInterpreter = new SpacesInterpreter();
	TextInterpreter* dashInterpreter = new DashInterpreter();
	TextInterpreter* quotesInterpreter = new QuotationMarksInterpreter();
	TextInterpreter* tabsInterpreter = new TabsInterpreter();
	TextInterpreter* bracketInterpreter = new BracketInterpreter();
	TextInterpreter* newlineInterpreter = new NewlineInterpreter();

	spacesInterpreter->Interpret(context);
	dashInterpreter->Interpret(context);
	quotesInterpreter->Interpret(context);
	tabsInterpreter->Interpret(context);
	bracketInterpreter->Interpret(context);
	newlineInterpreter->Interpret(context);

	delete spacesInterpreter;
	delete dashInterpreter;
	delete quotesInterpreter;
	delete tabsInterpreter;
	delete bracketInterpreter;
	delete newlineInterpreter;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	std::string text = readFile("text.txt");
	std::cout << "Оригинальный текст: \n" << text;
	Context context(text);
	ProcessText(context);
	std::ofstream out("corrected_text.txt");
	out << context.GetText();
	std::cout << "\nИсправленный текст: \n" << context.GetText();
	out.close();
	
	return 0;
}
