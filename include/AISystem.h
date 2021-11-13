#ifndef AI_SYSTEM_H
#define AI_SYSTEM_H

#include <iostream>
#include "globals.h"
#include "Entity.h"
#include "PositionComponent.h"
#include "HealthComponent.h"

class AISystem
{
std::vector<Entity> entities;

public:
    void addEntity(Entity e);
    void update(float& dt);

private:
    Vector2 boundaryCheck(Vector2 t_currentPos);

    const float c_MAX_TIME = 2.0f;
    float m_currentTime = 0.0f;
    float m_speed = 200.0f;
};

#endif