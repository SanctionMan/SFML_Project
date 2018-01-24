#pragma once
#include "Source/Utilities/Window.h"
#include "Source/Managers/EventManager.h"
#include "Source/Managers/StateManager.h"
#include "Source/Managers/TextureManager.h"

#include <iostream>

class Game {
public:
	Game();
	~Game();

	void Update();
	void Render();
	void LateUpdate();

	sf::Time GetElapsed();

	Window* GetWindow();
private:
	void RestartClock();
	sf::Clock m_clock;
	sf::Time m_elapsed;

	Window m_window;
	SharedContext m_context;

	TextureManager m_textureManager;
	FontManager m_fontManager;
	GUI_Manager m_guiManager;

	SystemManager m_systemManager;
	EntityManager m_entityManager;
	StateManager m_stateManager;
};