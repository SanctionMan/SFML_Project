#include "Window.h"

Window::Window()
{
	Setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string& title, const sf::Vector2u& size)
{
	Setup(title, size);
}

Window::~Window()
{
	m_window.close();
}

void Window::DrawStart()
{
	m_window.clear(sf::Color::Black);
}

void Window::DrawEnd()
{
	m_window.display();
}

void Window::Draw(sf::Drawable& drawable)
{
	m_window.draw(drawable);
}

void Window::Update()
{
	sf::Event event;

	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::LostFocus) { m_isFocused = false; m_eventManager.SetFocus(false); }
		else if (event.type == sf::Event::GainedFocus) { m_isFocused = true; m_eventManager.SetFocus(true); }
		m_eventManager.HandleEvent(event);
	}

	m_eventManager.Update();
}

bool Window::IsRunning()
{
	return m_isRunning;
}

bool Window::IsFullscreen()
{
	return m_isFullscreen;
}

bool Window::IsFocused()
{
	return m_isFocused;
}

sf::RenderWindow* Window::GetRenderWindow()
{
	return &m_window;
}

sf::Vector2u Window::GetWindowSize()
{
	return m_windowSize;
}

EventManager* Window::GetEventManager()
{
	return &m_eventManager;
}

void Window::ToggleFullscreen(EventDetails* details)
{
	m_isFullscreen = !m_isFullscreen;
	m_window.close();
	Create();
}

void Window::Close(EventDetails* details)
{
	m_isRunning = false;
}

void Window::Setup(const std::string title, const sf::Vector2u& size)
{
	m_windowTitle = title;
	m_windowSize = size;
	m_isFullscreen = false;
	m_isRunning = true;
	m_isFocused = true;

	m_eventManager.AddCallback(StateType(0), "Fullscreen_toggle", &Window::ToggleFullscreen, this);
	m_eventManager.AddCallback(StateType(0), "Window_close", &Window::Close, this);

	Create();
}

void Window::Create()
{
	sf::Uint32 style = sf::Style::Default;
	if (m_isFullscreen)
	{
		style = sf::Style::Fullscreen;
	}

	m_window.create(sf::VideoMode(m_windowSize.x, m_windowSize.y, 32), m_windowTitle, style);
}

