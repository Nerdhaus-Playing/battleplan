#include "parser/commandparser.h"
#include <exception>
#include <stdexcept>
#include <iostream>

using namespace nhp::battleplan::parser;


bool CommandParser::parse(const std::string& command)
{
	for (const auto& action : m_actionDictionary)
	{
		const auto commandLength = action.first.size();
		if (command.size() < commandLength)
		{
			continue;
		}
		if (command.size() == commandLength && command == action.first)
		{
			return action.second->handleEmptyCall();
		}
		if (command.substr(0, commandLength + 1) == action.first + " ")
		{
			return action.second->handleSubcommand(command.substr(commandLength + 1));
		}
	}
	if (command == "help")
	{
		for (const auto& action : m_actionDictionary)
		{
			printHelpLine(action.first, action.second);
		}
	}
	throw std::runtime_error("unknown command");
}

void CommandParser::setCommandAction(const std::string& command, CommandAction* action)
{
	if (m_actionDictionary.find(command) != m_actionDictionary.end())
	{
		m_actionDictionary[command] = action;
		if (m_maxCommandLength < command.size())
		{
			m_maxCommandLength = command.size();
		}
		if (m_maxDescriptionLength < action->getDescription().size())
		{
			m_maxDescriptionLength = action->getDescription().size();
		}
		if (m_maxUsageLength < action->getUsage().size())
		{
			m_maxUsageLength = action->getUsage().size();
		}
	}
	else
	{
		throw std::runtime_error("command already installed");
	}
}

void printStringWithForcedLength(size_t length, const std::string& text)
{
	std::cout << text;
	int i = text.size();
	for (int i = text.size(); i < length + 1; i++)
	{
		std::cout << " ";
	}
}

void CommandParser::printHelpLine(const std::string& command, CommandAction* action)
{
	printStringWithForcedLength(m_maxCommandLength, command);
	printStringWithForcedLength(m_maxUsageLength, action->getUsage());
	printStringWithForcedLength(m_maxDescriptionLength, action->getDescription());
	std::cout << std::endl;
}