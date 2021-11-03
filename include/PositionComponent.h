#ifndef POSITION_COMP_H
#define POSITION_COMP_H

#include "Component.h"
#include "Vector2.h"

class PositionComponent : public Component
{
public:
    PositionComponent() : m_pos(0,0){}
    /* Data only */
    Vector2 getType() { return m_pos; }
    void setType(Vector2 t_pos) { this->m_pos = t_pos; }
private:
    Vector2 m_pos;
};

#endif