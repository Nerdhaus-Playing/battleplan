#include "Entity.h"
#include <thread>

using namespace nhp::battleplan::graphics;

Entity::Entity(const std::string& identifier, EntityType type, const sf::Color& color, sf::Uint32 size)
{
	m_font = std::make_unique<sf::Font>();
	m_font->loadFromFile("arial.ttf");
	m_text = sf::Text(identifier, *m_font, 20);
	m_text.move(-m_text.getGlobalBounds().width / 2, -m_text.getGlobalBounds().height/2);
	m_circle.setOrigin(size, size);
	m_entityType = type;
	setColor(color);
	setSize(size);
}

void Entity::drag(const sf::Vector2f& amount)
{
	m_text.move(amount);
	m_circle.move(amount);
}

void Entity::setColor(const sf::Color& color)
{
	m_circle.setFillColor(color);
	if (color.r + color.g + color.b > 255/2)
	{
		m_text.setFillColor(sf::Color::Black);
	}
	else
	{
		m_text.setFillColor(sf::Color::White);
	}
}

void Entity::setSize(sf::Uint32 size)
{
	m_circle.setRadius(size);
}

EntityType Entity::getEntityType() const
{
	return m_entityType;
}

std::string Entity::getIdentifier() const
{
	return m_text.getString();
}

bool Entity::contains(const sf::Vector2f& position)
{
	sf::Vector2f delta;
	delta = m_circle.getPosition() - position;
	auto rSquare = m_circle.getRadius() * m_circle.getRadius();
	if (rSquare >= delta.x * delta.x + delta.y * delta.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_circle);
	target.draw(m_text);
}
