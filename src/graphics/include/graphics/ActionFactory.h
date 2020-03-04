#pragma once

#include "Graphics.h"

#include "parser/commandparser.h"

#include <vector>
#include <memory>

namespace nhp::battleplan::graphics
{
	class ActionFactory
	{
	public:
		static std::vector<std::unique_ptr<parser::CommandAction>> CreateAndBindActions(nhp::battleplan::parser::CommandParser& parser, Graphics* graphics);
	};
}