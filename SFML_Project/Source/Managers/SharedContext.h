#pragma once
#include "../Utilities/Window.h"
#include "../Utilities/DebugOverlay.h"
#include "FontManager.h"
#include "GUI_Manager.h"
#include "EventManager.h"
#include "TextureManager.h"
#include "SystemManager.h"
#include "EntityManager.h"

class Map;

struct SharedContext {
	SharedContext() :
		m_wind(nullptr),
		m_eventManager(nullptr),
		m_textureManager(nullptr),
		m_fontManager(nullptr),
		m_systemManager(nullptr),
		m_entityManager(nullptr),
		m_gameMap(nullptr),
		m_guiManager(nullptr) {}

	Window* m_wind;
	EventManager* m_eventManager;
	TextureManager* m_textureManager;
	FontManager* m_fontManager;
	SystemManager* m_systemManager;
	EntityManager* m_entityManager;
	Map* m_gameMap;
	GUI_Manager* m_guiManager;
	DebugOverlay m_debugOverlay;
};