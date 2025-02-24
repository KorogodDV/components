#pragma once
#include "GraphicsManager.h"
#include "PhysicsManager.h"
#include "ScriptManager.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <list>
#include <set>

class Storages;

class Applications {

	Storages* Storage;
	ScriptManagers* ScriptManager;
	PhysicsManagers* PhysicsManager;
	GraphicsManagers* GraphicsManager;
	sf::RenderWindow* window;
	sf::Clock WorkTime;
	float WorkTimeBeforeThisFrame;
	float LastFrameDuration;
	std::set<std::string> ObjectsForRemove;

public:

	Applications(int window_length = 1280, int window_width = 720, std::string background_address = "white_list.png");

	void Run();

	Storages* GetStorage();

	ScriptManagers* GetScriptManager();

	PhysicsManagers* GetPhysicsManager();

	GraphicsManagers* GetGraphicsManager();

	sf::RenderWindow* GetWindow();

	float GetLastFrameDurationAsSeconds();

	float GetWorkTimeAsSeconds();

	std::set<std::string>* GetObjectsForRemove();

};