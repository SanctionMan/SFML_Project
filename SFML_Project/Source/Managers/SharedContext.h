#pragma once
#include "../Utilities/Window.h"
#include "EventManager.h"
#include "FontManager.h"
#include "TextureManager.h"
#include "GUI_Manager.h"

struct SharedContext {
	SharedContext() :
		m_wind(nullptr),
		m_eventManager(nullptr),
		m_fontManager(nullptr),
		m_textureManager(nullptr),
		m_guiManager(nullptr)
		{}

	Window* m_wind;
	EventManager* m_eventManager;
	FontManager* m_fontManager;
	TextureManager* m_textureManager;
	GUI_Manager* m_guiManager;
};