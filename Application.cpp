#pragma once
#include "GraphicsManager.h"
#include "PhysicsManager.h"
#include "ScriptManager.h"
#include "Storage.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "Application.h"

Applications::Applications()
    {
        Storage = new Storages(this);
        ScriptManager = new ScriptManagers;
        PhysicsManager = new PhysicsManagers;
        GraphicsManager = new GraphicsManagers;
        window_length = 1280;
        window_width = 720;
        window = new sf::RenderWindow(sf::VideoMode(window_length, window_width), "App");
    }

void Applications::Run()
    {
        while (window->isOpen())
        {
            sf::Event event;

            while (window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window->close();
                    break;
                }
            }

            window->clear();
            GraphicsManager->draw(window);
            PhysicsManager->update();
            ScriptManager->update();
            window->display();
        }
    }

Storages* Applications::GetStorage()
{
    return this->Storage;
}

ScriptManagers* Applications::GetScriptManager()
{
    return this->ScriptManager;
}

PhysicsManagers* Applications::GetPhysicsManager()
{
    return this->PhysicsManager;
}

GraphicsManagers* Applications::GetGraphicsManager()
{
    return this->GraphicsManager;
}

sf::RenderWindow* Applications::GetWindow()
{
    return this->window;
}