#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "../../Source/Managers/EventManager.h"

class Window 
{
public:
	Window();
	Window(const std::string& title, const sf::Vector2u& size);
	~Window();

	void DrawStart();
	void DrawEnd();
	void Draw(sf::Drawable& drawable);

	void Update();

	bool IsRunning();
	bool IsFullscreen();
	bool IsFocused();

	void ToggleFullscreen(EventDetails* details);
	void Close(EventDetails* details = nullptr);

	sf::RenderWindow* GetRenderWindow();
	sf::Vector2u GetWindowSize();
	EventManager* GetEventManager();
private:
	void Setup(const std::string title, const sf::Vector2u& size);
	void Create();

	sf::RenderWindow m_window;
	EventManager m_eventManager;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isRunning;
	bool m_isFullscreen;
	bool m_isFocused;
};

