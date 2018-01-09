#pragma once
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

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
	sf::RenderWindow* GetRenderWindow();
	sf::Vector2u GetWindowSize();

	void ToggleFullscreen();
private:
	void Setup(const std::string title, const sf::Vector2u& size);
	void Create();
	void Destory();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isRunning;
	bool m_isFullscreen;
};

