#include "ColorAction.h"

#include "ErrorStrings.h"

#include <stdexcept>
#include <iostream>

using namespace nhp::battleplan::graphics;

ColorAction::ColorAction(Graphics* graphic)
{
	m_graphic = graphic;
}

bool ColorAction::handleSubcommand(const std::string& subcommand)
{
	auto position = subcommand.find(" ");
	std::string colorString = subcommand.substr(position + 1);
	sf::Color newColor = sf::Color::White;
	if (colorString == "red")
	{
		newColor = sf::Color::Red;
	}
	else if (colorString == "blue")
	{
		newColor = sf::Color::Blue;
	}
	else if (colorString == "green")
	{
		newColor = sf::Color::Green;
	}
	else if (colorString == "magenta")
	{
		newColor = sf::Color::Magenta;
	}
	else if (colorString == "yellow")
	{
		newColor = sf::Color::Yellow;
	}
	else if (colorString == "black")
	{
		newColor = sf::Color::Black;
	}
	else if (colorString == "white")
	{
		newColor = sf::Color::White;
	}
	else
	{
		throw std::runtime_error("Unknown color identifier");
	}



	if (subcommand.substr(0, position) == "friend")
	{
		m_graphic->setFriendColor(newColor);
	}
	else if (subcommand.substr(0, position) == "enemy")
	{
		m_graphic->setEnemyColor(newColor);
	}
	else if (subcommand.substr(0, position) == "neutral")
	{
		m_graphic->setNeutralColor(newColor);
	}
	else
	{
		m_graphic->setEntityColor(subcommand.substr(0, position), newColor);
	}
	return true;
}

bool ColorAction::handleEmptyCall()
{
	throw std::runtime_error(NOT_CALLABLE_WITHOUT_ARGS);
}

std::string ColorAction::getDescription() const
{
	return "Sets the color of specific entities";
}

std::string ColorAction::getUsage() const
{
	return "[friend|enemy|<identifier>] <color>";
}
