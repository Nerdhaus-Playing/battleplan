#pragma once

#include "Entity.h"

#include <map>

namespace nhp::battleplan::graphics
{
	class GraphicsImpl
	{
	public:
		GraphicsImpl();
		~GraphicsImpl();

		void setEntitySize(sf::Uint32 size);

		void setEntityTypeColor(const sf::Color& color, EntityType type);
		void setEntityColor(const std::string& entity, const sf::Color& color);

		void addEntity(const std::string& identifier, EntityType type);

		void deleteAllEntities();

		void clearBackground(sf::Color color);
		void loadBackground(const std::string& path);

		void drawingLoop();
	private:

		std::map<std::string, Entity> m_entities;

		sf::Color m_enemyColor;
		sf::Color m_friendColor;
		sf::Color m_neutralColor;
		sf::Uint32 m_currentSize;

		sf::RenderWindow m_window;
		std::unique_ptr<sf::Texture> m_backgroundTexture;
		std::unique_ptr<sf::Sprite> m_backgroundSprite;
		sf::Color m_backgroundColor;

		Entity* m_draggedEntity;
		sf::Vector2f m_lastMousePosition;
	};
}