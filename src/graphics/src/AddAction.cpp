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
	std::cout << subcommand << std::endl;
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
	return "<identifier> [friend|enemy|neutral]";
}
