#include "ResetAction.h"

#include "ErrorStrings.h"

#include <stdexcept>
#include <iostream>

using namespace nhp::battleplan::graphics;

ResetAction::ResetAction(Graphics* graphic)
{
	m_graphic = graphic;
}

bool ResetAction::handleSubcommand(const std::string& subcommand)
{
	throw std::runtime_error(NOT_CALLABLE_WITH_ARGS);
}

bool ResetAction::handleEmptyCall()
{
	m_graphic->deleteAllEntities();
	return true;
}

std::string ResetAction::getDescription() const
{
	return "Removes all entities from the battleplan";
}

std::string ResetAction::getUsage() const
{
	return "";
}
