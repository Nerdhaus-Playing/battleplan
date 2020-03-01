#pragma once

#include <string>

namespace nhp::battleplan::parser
{
	class CommandParser
	{

		bool parse(const std::string& command);
	};
}