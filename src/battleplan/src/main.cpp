#include "ExitAction.h"

#include "parser/commandparser.h"

#include "graphics/ActionFactory.h"
#include "graphics/Graphics.h"

#include <iostream>
#include <string>
#include <thread>

using namespace nhp::battleplan;

parser::CommandParser g_parser;
volatile bool g_running;

void handleInput()
{
	std::string currentString;
	bool parserResult;
	do
	{
		std::getline(std::cin, currentString);
		try
		{
			parserResult = g_parser.parse(currentString);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			parserResult = true;
		}
	} while (parserResult);
	g_running = false;
}

int main(int argc, char** argv)
{

	ExitAction exitAction;
	g_parser.setCommandAction("exit", &exitAction);

	graphics::Graphics m_graphics;

	m_graphics.setEntitySize(30);
	m_graphics.setEnemyColor(sf::Color::Red);
	m_graphics.setFriendColor(sf::Color::Green);
	m_graphics.setNeutralColor(sf::Color::Magenta);

	auto graphicsActions = graphics::ActionFactory::CreateAndBindActions(g_parser, &m_graphics);

	g_running = true;
	std::cout << "Commandline ready" << std::endl;

	std::thread m_thread(handleInput);

	while (g_running)
	{
		m_graphics.drawingLoop();
	}
	m_thread.join();

	std::cout << "Application exited successfully" << std::endl;
	return 0;
}