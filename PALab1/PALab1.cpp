#include <iostream>
#include "Interpreter.h"


int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	/*std::string text_spaces = "Какой-то  текст,  содержащий       множественные   пробелы";
	std::string text = "Какой-то  текст,  содержащий       множественные   пробелы";
	TextInterpreter* TI = new SpacesInterpreter();
	std::cout << TI->Interpret(text);*/
	std::string input = “This is a «sample» sentence with "double" quotes.”;
	std::cout << "Original input: " << input << std::endl;
	std::string converted = convertQuotationMarks(input);
	std::cout << "Converted input: " << converted << std::endl;
	return 0;
}
