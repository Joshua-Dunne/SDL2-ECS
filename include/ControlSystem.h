#ifndef CONTROL_SYSTEM_H
#define CONTROL_SYSTEM_H

#include <iostream>
#include "../include/Entity.h"

class ControlSystem
{
std::vector<Entity> entities;

public:
    void addEntity(Entity e){ std::cout << "Adding Entity to Control System" << std::endl;}
    void update(float& dt) {std::cout << "Updating Control System" << std::endl;}
};

#endif