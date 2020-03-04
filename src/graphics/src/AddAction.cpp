#include "AddAction.h"

#include "ErrorStrings.h"

#include <stdexcept>
#include <iostream>

using namespace nhp::battleplan::graphics;

AddAction::AddAction(Graphics* graphic)
{
	m_graphic = graphic;
}

bool AddAction::handleSubcommand(const std::string& subcommand)
{
	auto position = subcommand.find(" ");
	std::string identifier = subcommand.substr(position + 1);
	if (subcommand.substr(0, position) == "friend")
	{
		m_graphic->addFriendEntity(identifier);
	}
	else if (subcommand.substr(0, position) == "enemy")
	{
		m_graphic->addEnemyEntity(identifier);
	}
	else if (subcommand.substr(0, position) == "neutral")
	{
		m_graphic->addNeutralEntity(identifier);
	}
	else
	{
		throw std::runtime_error("Unknown entity type " + subcommand.substr(position + 1));
	}
	return true;
}

bool AddAction::handleEmptyCall()
{
	throw std::runtime_error(NOT_CALLABLE_WITHOUT_ARGS);
}

std::string AddAction::getDescription() const
{
	return "Adds an entity to the battleplan";
}

std::string AddAction::getUsage() const
{
	return "[friend|enemy|neutral] <identifier>";
}
