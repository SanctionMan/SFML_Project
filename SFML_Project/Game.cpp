#include "Game.h"



Game::Game()
: m_window("Test Game", sf::Vector2u(800, 600)), m_stateManager(&m_context)
{
	m_clock.restart();
	srand(unsigned int(time(nullptr)));

	m_context.m_wind = &m_window;
	m_context.m_eventManager = m_window.GetEventManager();

	m_stateManager.SwitchTo(StateType::Intro);
}


Game::~Game()
{
}

void Game::Update()
{
	m_window.Update();
	m_stateManager.Update(m_elapsed);
}

void Game::Render()
{
	m_window.DrawStart();
	m_stateManager.Draw();
	m_window.DrawEnd();

}

void Game::LateUpdate()
{
	m_stateManager.ProcessRequests();
	RestartClock();
}

sf::Time Game::GetElapsed(){ return m_clock.getElapsedTime(); }
Window* Game::GetWindow(){ return &m_window; }
void Game::RestartClock(){ m_elapsed = m_clock.restart(); }
