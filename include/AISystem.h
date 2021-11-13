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
    void pickHeading();

    const float c_MAX_TIME = 2.5f;
    float m_currentTime = 0.0f;
    float m_speed = 100.0f;
    Vector2 m_heading{0.0f, 0.0f};
};

#endif