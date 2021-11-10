#ifndef POSITION_COMP_H
#define POSITION_COMP_H

#include "Component.h"
#include "Vector2.h"

/* Data only */
struct PositionComponent : public Component
{
    Vector2 m_pos;
};

#endif