#pragma once
#include "../Utilities/Window.h"
#include "EventManager.h"
struct SharedContext {
	SharedContext():m_window(nullptr), m_eventManager(nullptr)
	{
		
	}
	Window* m_window;
	EventManager* m_eventManager;
};