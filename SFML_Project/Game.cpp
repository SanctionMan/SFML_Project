#include "Game.h"



Game::Game()
: m_window("Snake", sf::Vector2u(800, 600))
{
	m_clock.restart();
	srand(time(nullptr));
	m_elapsed = 0.0f;

	m_texture.loadFromFile("Resources/Sprites/Mushroom.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
	m_sprite.setPosition(0, 0);

	m_window.GetEventManager()->AddCallback("Move", &Game::MoveSprite, this);

}


Game::~Game()
{
}

void Game::HandleInput()
{
	// Input handling.

}

void Game::Update()
{
	m_window.Update();
}

void Game::Render()
{
	m_window.DrawStart();
	m_window.GetRenderWindow()->draw(m_sprite);
	m_window.DrawEnd();

}

sf::Time Game::GetElapsed()
{
	return m_clock.getElapsedTime();
}

void Game::RestartClock()
{
	m_elapsed += m_clock.restart().asSeconds();
}

Window* Game::GetWindow()
{
	return &m_window;
}

void Game::MoveSprite(EventDetails* details)
{
	sf::Vector2i mousepos = m_window.GetEventManager()->GetMousePos(m_window.GetRenderWindow());
	m_sprite.setPosition(mousepos.x, mousepos.y);
	std::cout << "Moving Sprite: " << mousepos.x << ":" << mousepos.y << std::endl;
}
