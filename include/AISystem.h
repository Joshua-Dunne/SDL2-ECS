#ifndef AI_SYSTEM_H
#define AI_SYSTEM_H

#include <iostream>
#include "../include/Entity.h"

class AISystem
{
std::vector<Entity> entities;

public:
    void addEntity(Entity e){ std::cout << "Adding Entity to AI System" << std::endl;}
    void update(float& dt) {std::cout << "Updating AI System" << std::endl;}
};

#endif