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

	//spacesInterpreter->Interpret(context);
	//dashInterpreter->Interpret(context);
	quotesInterpreter->Interpret(context);
	//tabsInterpreter->Interpret(context);
	bracketInterpreter->Interpret(context);
	newlineInterpreter->Interpret(context);
	//spacesInterpreter->Interpret(context);

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


	/*std::string text_spaces = "Какой-то  текст,  содержащий       множественные   пробелы";
	std::string text_quot = "Какой-то “текст”, “содержащий” «кавычки»";
	std::string text_tabs = "	Какой-то	текст,		содержащий			лишние				табы";
	std::string text_br = "Какой-то ,  текст ,  содержащий (множественные), ( пробелы ) .";
	std::string text_n = "\nКакой-то ,  \n\nтекст ,  содержащий \n\n\n(множественные), \n( пробелы ) .\n";
	std::cout << text_n<<std::endl;
	Context c(text_n);
	TextInterpreter* TI = new NewlineInterpreter();
	TI->Interpret(c);
	std::cout << c.GetText();*/
	/*std::ifstream input_file("text.txt");
	std::string file_content = read_file("text.docx");*/
	std::string text = readFile("text.txt");
	std::string text_n = "\nКакой-то ,  \n\nтекст ,  содержащий \n\n\n(множественные), \n( пробелы ) .\n";
	std::cout << text;
	Context context(text_n);
	ProcessText(context);
	std::ofstream out("corrected_text.txt");
	out << context.GetText();
	std::cout << context.GetText();
	out.close();
	
	return 0;
}
