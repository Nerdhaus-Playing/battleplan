#include "ClearAction.h"

#include "ErrorStrings.h"

#include <stdexcept>

using namespace nhp::battleplan::graphics;

ClearAction::ClearAction(Graphics* graphic)
{
	m_graphic = graphic;
}

bool ClearAction::handleSubcommand(const std::string& subcommand)
{
	throw std::runtime_error(NOT_CALLABLE_WITH_ARGS);
}

bool ClearAction::handleEmptyCall()
{
	m_graphic->clearBackground(sf::Color::Black);
	return true;
}

std::string ClearAction::getDescription() const
{
	return "Sets the background to black";
}

std::string ClearAction::getUsage() const
{
	return "";
}
