#pragma once 

#include <SFML/Graphics.hpp>

#include <memory>

namespace nhp::battleplan::graphics
{
	class GraphicsImpl;

	class Graphics
	{
	public:
		Graphics();
		~Graphics();

		void setEntitySize(sf::Uint32 size);

		void setEnemyColor(const sf::Color& color);
		void setFriendColor(const sf::Color& color);
		void setNeutralColor(const sf::Color& color);
		void setEntityColor(const std::string& entity, const sf::Color& color);

		void addFriendEntity(const std::string& identifier);
		void addEnemyEntity(const std::string& identifier);
		void addNeutralEntity(const std::string& identifier);

		void deleteAllEntities();

		void clearBackground(sf::Color color);
		void loadBackground(const std::string& path);

		void drawingLoop();
	private:
		std::unique_ptr<GraphicsImpl> m_impl;
	};
}