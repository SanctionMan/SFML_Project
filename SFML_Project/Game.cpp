#include "Game.h"



Game::Game()
: m_window("Snake", sf::Vector2u(800, 600))
{
	m_clock.restart();
	srand(time(nullptr));
	m_elapsed = 0.0f;

	dot.setPosition(m_window.GetWindowSize().x / 2, m_window.GetWindowSize().y / 2);
	dot.setRadius(20);
	dot.setFillColor(sf::Color::Cyan);
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
	m_window.Draw(dot);
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
