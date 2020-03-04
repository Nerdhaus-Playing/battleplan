#include "GraphicsImpl.h"

#include <stdexcept>

using namespace nhp::battleplan::graphics;

GraphicsImpl::GraphicsImpl() :
	m_window(sf::VideoMode(1024, 786, 32), "Test 32")
{
}

GraphicsImpl::~GraphicsImpl()
{
}

void GraphicsImpl::setEntitySize(sf::Uint32 size)
{
	m_currentSize = size;
	for (auto& entity : m_entities)
	{
		entity.second.setSize(size);
	}
}

void GraphicsImpl::setEntityTypeColor(const sf::Color& color, EntityType type)
{
	switch (type)
	{
	case EntityType::Enemy:
		m_enemyColor = color;
		break;
	case EntityType::Friend:
		m_friendColor = color;
		break;
	case EntityType::Neutral:
		m_neutralColor = color;
		break;
	default:
		throw std::runtime_error("Invalid Entity Type");
	}
	for (auto& entity : m_entities)
	{
		if (entity.second.getEntityType() == type)
		{
			entity.second.setColor(color);
		}
	}
}
void GraphicsImpl::setEntityColor(const std::string& entity, const sf::Color& color)
{
	for (auto& currEntity : m_entities)
	{
		if (currEntity.first == entity)
		{
			currEntity.second.setColor(color);
			return;
		}
	}
}

void GraphicsImpl::addEntity(const std::string& identifier, EntityType type)
{
	if (m_entities.find(identifier) != m_entities.end())
	{
		throw std::runtime_error("Identifier already used");
	}
	switch (type)
	{
	case EntityType::Enemy:
		m_entities.emplace(identifier, Entity(identifier, type, m_enemyColor, m_currentSize));
		break;
	case EntityType::Friend:
		m_entities.emplace(identifier, Entity(identifier, type, m_friendColor, m_currentSize));
		break;
	case EntityType::Neutral:
		m_entities.emplace(identifier, Entity(identifier, type, m_neutralColor, m_currentSize));
		break;
	default:
		throw std::runtime_error("Invalid Entity Type");
	}
}

void GraphicsImpl::deleteAllEntities()
{
	m_entities.clear();
}

void GraphicsImpl::clearBackground(sf::Color color)
{

}

void GraphicsImpl::loadBackground(const std::string& path)
{

}

void GraphicsImpl::drawingLoop()
{
	for (auto& entity : m_entities)
	{
		m_window.draw(entity.second);

	}

	sf::Event e;
	while (m_window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			m_window.close();
	}

	m_window.display();

}
