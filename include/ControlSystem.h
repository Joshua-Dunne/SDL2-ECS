#ifndef CONTROL_SYSTEM_H
#define CONTROL_SYSTEM_H

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "Entity.h"
#include "InputComponent.h"
#include "PositionComponent.h"

class ControlSystem
{
std::vector<Entity> entities;

public:
    void addEntity(Entity e);
    void update(float& dt);
    void processEvents(SDL_Event& e);
    void processMouse(SDL_MouseButtonEvent& b);
    void processKeyPress(SDL_Event& e);
    void processKeyRelease(SDL_Event& e);

private:
    int currentInput = 0;
    float m_speed = 30.0f;

};

#endif