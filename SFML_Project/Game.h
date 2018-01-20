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
	SharedContext m_context;
	StateManager m_stateManager;
	TextureManager m_textureManager;
	FontManager m_fontManager;
	GUI_Manager m_guiManager;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
};

