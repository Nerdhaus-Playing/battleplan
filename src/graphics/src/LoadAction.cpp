#include "LoadAction.h"

#include "ErrorStrings.h"

#include <stdexcept>
#include <iostream>

using namespace nhp::battleplan::graphics;


LoadAction::LoadAction(Graphics* graphic)
{
	m_graphic = graphic;
}

bool LoadAction::handleSubcommand(const std::string& subcommand)
{
	std::cout << "Loaded file from " << subcommand << std::endl;
	return true;
}

bool LoadAction::handleEmptyCall()
{
	throw std::runtime_error(NOT_CALLABLE_WITHOUT_ARGS);
}

std::string LoadAction::getDescription() const
{
	return "Loads an image from the disk to use a background";
}

std::string LoadAction::getUsage() const
{
	return "<path to image>";
}
