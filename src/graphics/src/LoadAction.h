#pragma once

#include "parser/commandparser.h"


namespace nhp::battleplan::graphics
{
	

	class LoadAction : public parser::CommandAction
	{
	public:
		bool handleSubcommand(const std::string& subcommand) override;
		bool handleEmptyCall() override;
		std::string getDescription() const override;
		std::string getUsage() const override;
	};



}