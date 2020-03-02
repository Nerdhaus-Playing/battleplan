#pragma once

#include <string>
#include <map>

namespace nhp::battleplan::parser
{
	class CommandAction
	{
	public:
		virtual bool handleSubcommand(const std::string& subcommand) = 0;
		virtual bool handleEmptyCall() = 0;
		virtual std::string getDescription() const = 0;
		virtual std::string getUsage() const = 0;
	};

	class CommandParser
	{
	public:
		CommandParser();
		bool parse(const std::string& command);
		void setCommandAction(const std::string& command, CommandAction* action);
	private:
		void printHelpLine(const std::string& command, CommandAction* action);

		std::map<std::string, CommandAction*> m_actionDictionary;
		size_t m_maxCommandLength;
		size_t m_maxDescriptionLength;
		size_t m_maxUsageLength;
	};
}