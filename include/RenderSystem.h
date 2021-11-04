#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include <iostream>
#include "../include/Entity.h"

class RenderSystem
{
std::vector<Entity> entities;

public:
    void addEntity(Entity e){ std::cout << "Adding Entity to Render System" << std::endl;}
    void update(float& dt) {std::cout << "Updating Render System" << std::endl;}
};

#endif