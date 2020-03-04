#include "SizeAction.h"

#include "ErrorStrings.h"

#include <iostream>
#include <stdexcept>


using namespace nhp::battleplan::graphics;

SizeAction::SizeAction(Graphics* graphic)
{
	m_graphic = graphic;
}

bool SizeAction::handleSubcommand(const std::string& subcommand)
{
	std::cout << "0 Entities resized to " << subcommand << std::endl;
	return true;
}

bool SizeAction::handleEmptyCall()
{
	throw std::runtime_error(NOT_CALLABLE_WITHOUT_ARGS);
}

std::string SizeAction::getDescription() const
{
	return "Scales all entites";
}

std::string SizeAction::getUsage() const
{
	return "<new size>";
}
