#ifndef HEALTH_SYSTEM_H
#define HEALTH_SYSTEM_H

#include <iostream>
#include "../include/Entity.h"

class HealthSystem
{
std::vector<Entity> entities;

public:
    void addEntity(Entity e){ std::cout << "Adding Entity to Health System" << std::endl;}
    void update() {std::cout << "Updating Health System" << std::endl;}
};

#endif