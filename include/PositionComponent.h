#ifndef POSITION_COMP_H
#define POSITION_COMP_H

#include "Component.h"
#include "Vector2.h"

/* Data only */
struct PositionComponent : public Component
{
    PositionComponent() : Component("pos") {};
    void setName(std::string t_name) {id = t_name;};
    Vector2 m_pos;
};

#endif