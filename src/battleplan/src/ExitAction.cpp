#include "ExitAction.h"

#include <stdexcept>

using namespace nhp::battleplan;

bool ExitAction::handleSubcommand(const std::string& subcommand)
{
	throw std::runtime_error("This command does not take arguments");
}

bool ExitAction::handleEmptyCall()
{
	return false;
}

std::string ExitAction::getDescription() const
{
	return "Exits the Application";
}

std::string ExitAction::getUsage() const
{
	return "";
}
