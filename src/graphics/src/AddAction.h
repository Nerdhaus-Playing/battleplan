#pragma once

#include "graphics/Graphics.h"

#include "parser/commandparser.h"


namespace nhp::battleplan::graphics
{
	class AddAction : public parser::CommandAction
	{
	public:
		AddAction(Graphics* graphic);
		bool handleSubcommand(const std::string& subcommand) override;
		bool handleEmptyCall() override;
		std::string getDescription() const override;
		std::string getUsage() const override;
			private:
		Graphics* m_graphic;
	};
}