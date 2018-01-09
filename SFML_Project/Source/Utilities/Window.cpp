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
	Destory();
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
	while(m_window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			m_isRunning = false;
		}
		else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
			m_isRunning = false;
		}
		else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)
		{
			ToggleFullscreen();
		}
	}
}

bool Window::IsRunning()
{
	return m_isRunning;
}

bool Window::IsFullscreen()
{
	return m_isFullscreen;
}

sf::RenderWindow* Window::GetRenderWindow()
{
	return &m_window;
}

sf::Vector2u Window::GetWindowSize()
{
	return m_windowSize;
}

void Window::ToggleFullscreen()
{
	m_isFullscreen = !m_isFullscreen;
	m_window.close();
	Create();
}

void Window::Setup(const std::string title, const sf::Vector2u& size)
{
	m_windowTitle = title;
	m_windowSize = size;
	m_isFullscreen = false;
	m_isRunning = true;
	Create();
}

void Window::Create()
{
	auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create( { m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);
}

void Window::Destory()
{
	m_window.close();
}
