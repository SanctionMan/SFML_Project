#include "Game.h"



Game::Game()
: m_window("Dungeon Crawler", sf::Vector2u(800, 600)), 
m_stateManager(&m_context), 
m_guiManager(m_window.GetEventManager(), &m_context)
{
	m_clock.restart();
	srand(unsigned int(time(nullptr)));

	m_context.m_wind = &m_window;
	m_context.m_eventManager = m_window.GetEventManager();
	m_context.m_textureManager = &m_textureManager;
	m_context.m_fontManager = &m_fontManager;
	m_context.m_guiManager = &m_guiManager;

	m_stateManager.SwitchTo(StateType::Intro);

	m_fontManager.RequireResource("Main");
}


Game::~Game()
{
	m_fontManager.ReleaseResource("Main"); // new
}

void Game::Update()
{
	m_window.Update();
	m_stateManager.Update(m_elapsed);
	m_context.m_guiManager->Update(m_elapsed.asSeconds());

	GUI_Event guiEvent;
	while (m_context.m_guiManager->PollEvent(guiEvent)) {
		m_window.GetEventManager()->HandleEvent(guiEvent);
	}
}

void Game::Render()
{
	m_window.DrawStart();
	//RENDER
	m_stateManager.Draw();

	sf::View CurrentView = m_window.GetRenderWindow()->getView();
	m_window.GetRenderWindow()->setView(m_window.GetRenderWindow()->getDefaultView());
	m_context.m_guiManager->Render(m_window.GetRenderWindow());
	m_window.GetRenderWindow()->setView(CurrentView);

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
