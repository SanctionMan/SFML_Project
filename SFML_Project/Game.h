#pragma once
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
private:
	Window m_window;
	sf::Clock m_clock;
	float m_elapsed;

	sf::CircleShape dot;

};

