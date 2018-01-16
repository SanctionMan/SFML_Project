#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System.hpp>

#include "Source/Managers/StateManager.h"
#include "Source/Utilities/Window.h"


class Game
{
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

	Window m_window;
	sf::Clock m_clock;
	sf::Time m_elapsed;

	//Managers
	StateManager m_stateManager;
	SharedContext m_context;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
};

