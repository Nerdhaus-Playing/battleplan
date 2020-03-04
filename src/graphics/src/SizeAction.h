#pragma once

#include "graphics/Graphics.h"

#include "parser/commandparser.h"


namespace nhp::battleplan::graphics
{

	class SizeAction : public parser::CommandAction
	{
	public:
		SizeAction(Graphics* graphic);

		bool handleSubcommand(const std::string& subcommand) override;
		bool handleEmptyCall() override;
		std::string getDescription() const override;
		std::string getUsage() const override;
	private:
		Graphics* m_graphic;
	};

	

}