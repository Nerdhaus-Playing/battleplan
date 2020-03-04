#include "graphics/ActionFactory.h"

#include "AddAction.h"
#include "ClearAction.h"
#include "ColorAction.h"
#include "LoadAction.h"
#include "ResetAction.h"
#include "SizeAction.h"


using namespace nhp::battleplan;
using namespace nhp::battleplan::graphics;

std::vector<std::unique_ptr<parser::CommandAction>> graphics::ActionFactory::CreateAndBindActions(nhp::battleplan::parser::CommandParser& parser, Graphics* graphics)
{
	std::vector<std::unique_ptr<parser::CommandAction>> resultVector;

	std::unique_ptr<AddAction> addAction = std::make_unique<AddAction>(graphics);
	parser.setCommandAction("add", addAction.get());
	resultVector.push_back(std::move(addAction));

	std::unique_ptr<ClearAction> clearAction = std::make_unique<ClearAction>(graphics);
	parser.setCommandAction("clear", clearAction.get());
	resultVector.push_back(std::move(clearAction));

	std::unique_ptr<ColorAction> colorAction = std::make_unique<ColorAction>(graphics);
	parser.setCommandAction("color", colorAction.get());
	resultVector.push_back(std::move(colorAction));

	std::unique_ptr<LoadAction> loadAction = std::make_unique<LoadAction>(graphics);
	parser.setCommandAction("load", loadAction.get());
	resultVector.push_back(std::move(loadAction));

	std::unique_ptr<ResetAction> resetAction = std::make_unique<ResetAction>(graphics);
	parser.setCommandAction("reset", resetAction.get());
	resultVector.push_back(std::move(resetAction));

	std::unique_ptr<SizeAction> sizeAction = std::make_unique<SizeAction>(graphics);
	parser.setCommandAction("size", sizeAction.get());
	resultVector.push_back(std::move(sizeAction));

	return resultVector;
}
