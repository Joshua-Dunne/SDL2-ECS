#ifndef HEALTH_SYSTEM_H
#define HEALTH_SYSTEM_H

#include "Entity.h"
#include "HealthComponent.h"
#include "InputComponent.h"

class HealthSystem
{
std::vector<Entity> entities;

public:
    void addEntity(Entity e);
    void update(float& dt);

private:
    float m_decayRate = 5.0f;
};

#endif