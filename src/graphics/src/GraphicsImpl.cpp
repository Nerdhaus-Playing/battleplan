#include "GraphicsImpl.h"

#include <stdexcept>
#include <thread>

using namespace nhp::battleplan::graphics;

GraphicsImpl::GraphicsImpl() :
	m_window(sf::VideoMode(1024, 786, 32), "Battleplan v1.0.0")
{
	m_draggedEntity = nullptr;
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
	std::this_thread::sleep_for(std::chrono::milliseconds(33));
	m_window.clear();
	for (auto& entity : m_entities)
	{
		m_window.draw(entity.second);

	}
	m_window.display();

	sf::Event e;
	while (m_window.pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::MouseButtonPressed:
			if (e.mouseButton.button == sf::Mouse::Left)
			{
				m_lastMousePosition = sf::Vector2f(e.mouseButton.x, e.mouseButton.y);
				for (auto& entity : m_entities)
				{
					if (entity.second.contains(m_lastMousePosition))
					{
						m_draggedEntity = &entity.second;
						break;
					}
				}
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (e.mouseButton.button == sf::Mouse::Left)
			{
				m_draggedEntity = nullptr;
			}
			break;
		case sf::Event::MouseMoved:
			if (m_draggedEntity != nullptr)
			{
				sf::Vector2f currentPosition = sf::Vector2f(e.mouseMove.x, e.mouseMove.y);
				m_draggedEntity->drag(currentPosition - m_lastMousePosition);
				m_lastMousePosition = currentPosition;
			}
			break;
		default:
			break;
		}
	}


}
