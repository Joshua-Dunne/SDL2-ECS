#ifndef POSITION_COMP_H
#define POSITION_COMP_H

#include "Component.h"
#include "Vector2.h"

/* Data only */
struct PositionComponent : public Component
{
    PositionComponent() : Component(3) {};
    Vector2 m_pos;
};

#endif