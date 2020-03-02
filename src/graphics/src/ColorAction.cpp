#include "ColorAction.h"

#include "ErrorStrings.h"

#include <stdexcept>
#include <iostream>

using namespace nhp::battleplan::graphics;

bool ColorAction::handleSubcommand(const std::string& subcommand)
{
	std::cout << "Color of 0 Entities changed to " << subcommand << std::endl;
	return false;
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
