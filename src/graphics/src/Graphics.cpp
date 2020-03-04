#include "graphics/Graphics.h"

#include "GraphicsImpl.h"

using namespace nhp::battleplan::graphics;

Graphics::Graphics()
{
	m_impl = std::make_unique<GraphicsImpl>();
}

Graphics::~Graphics() = default;

void Graphics::setEntitySize(sf::Uint32 size)
{
	m_impl->setEntitySize(size);
}

void Graphics::setEnemyColor(const sf::Color& color)
{
	m_impl->setEntityTypeColor(color, EntityType::Enemy);
}

void Graphics::setFriendColor(const sf::Color& color)
{
	m_impl->setEntityTypeColor(color, EntityType::Friend);
}

void Graphics::setNeutralColor(const sf::Color& color)
{
	m_impl->setEntityTypeColor(color, EntityType::Neutral);
}

void Graphics::setEntityColor(const std::string& entity, const sf::Color& color)
{
	m_impl->setEntityColor(entity, color);
}

void Graphics::addFriendEntity(const std::string& identifier)
{
	m_impl->addEntity(identifier, EntityType::Friend);
}

void Graphics::addEnemyEntity(const std::string& identifier)
{
	m_impl->addEntity(identifier, EntityType::Enemy);
}

void Graphics::addNeutralEntity(const std::string& identifier)
{
	m_impl->addEntity(identifier, EntityType::Neutral);
}

void Graphics::deleteAllEntities()
{
	m_impl->deleteAllEntities();
}

void Graphics::clearBackground(sf::Color color)
{
	m_impl->clearBackground(color);
}

void Graphics::loadBackground(const std::string& path)
{
	m_impl->loadBackground(path);
}

void Graphics::drawingLoop()
{
	m_impl->drawingLoop();
}