#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <memory>

namespace nhp::battleplan::graphics
{
	enum class EntityType
	{
		Friend, Enemy, Neutral
	};

	class Entity : public sf::Drawable
	{
	public:
		Entity(const std::string& identifier, EntityType type, const sf::Color& color, sf::Uint32 size);
		
		void drag(const sf::Vector2f& amount);
		void setColor(const sf::Color& color);
		void setSize(sf::Uint32 size);

		EntityType getEntityType() const;
		std::string getIdentifier() const;
		bool contains(const sf::Vector2f& position);

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	private:
		
		sf::CircleShape m_circle;
		EntityType m_entityType;
		sf::Text m_text;
		std::unique_ptr<sf::Font> m_font;

	};

}