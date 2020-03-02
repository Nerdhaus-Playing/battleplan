#include "ExitAction.h"

#include "parser/commandparser.h"

#include <iostream>
#include <string>

using namespace nhp::battleplan;

int main(int argc, char** argv)
{
	nhp::battleplan::parser::CommandParser parser;

	ExitAction exitAction;
	parser.setCommandAction("exit", &exitAction);

	std::cout << "Commandline ready" << std::endl;

	std::string currentString;
	bool parserResult;

	do
	{
		std::getline(std::cin, currentString);
		try
		{
			parserResult = parser.parse(currentString);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			parserResult = true;
		}
	} while (parserResult);
	std::cout << "Application exited successfully" << std::endl;
	return 0;
}