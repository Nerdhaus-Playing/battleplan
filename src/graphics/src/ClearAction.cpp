#include "ClearAction.h"

#include "ErrorStrings.h"

#include <stdexcept>

using namespace nhp::battleplan::graphics;

bool ClearAction::handleSubcommand(const std::string& subcommand)
{
	throw std::runtime_error(NOT_CALLABLE_WITH_ARGS);
}

bool ClearAction::handleEmptyCall()
{
	return true;
}

std::string ClearAction::getDescription() const
{
	return "Sets the background to white";
}

std::string ClearAction::getUsage() const
{
	return "";
}
