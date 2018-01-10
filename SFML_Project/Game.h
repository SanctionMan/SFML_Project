#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System.hpp>
#include "Source/Utilities/Window.h"


class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();

	sf::Time GetElapsed();
	void RestartClock();

	Window* GetWindow();

	//Testing
	void MoveSprite(EventDetails* details);
private:
	Window m_window;
	sf::Clock m_clock;
	float m_elapsed;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
};

