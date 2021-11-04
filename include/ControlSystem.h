#ifndef CONTROL_SYSTEM_H
#define CONTROL_SYSTEM_H

#include <iostream>
#include "../include/Entity.h"

class ControlSystem
{
std::vector<Entity> entities;

public:
    void addEntity(Entity e){ std::cout << "Adding Entity to Control System" << std::endl;}
    void update(float& dt);
    void processEvents(SDL_Event& e);
    void processMouse(SDL_MouseButtonEvent& b)
    void processKeyPress(SDL_Event& e)
    void processKeyRelease(SDL_Event& e)

};

#endif