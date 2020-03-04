#pragma once

#include "Entity.h"

namespace nhp::battleplan::graphics
{
	class GraphicsImpl
	{
	public:
		void setEntitySize(sf::Uint32 size);

		void setEntityTypeColor(const sf::Color& color, EntityType type);
		void setEntityColor(const std::string& entity, const sf::Color& color);

		void addEntity(const std::string& identifier, EntityType type);

		void deleteAllEntities();

		void clearBackground(sf::Color color);
		void loadBackground(const std::string& path);
	};
}