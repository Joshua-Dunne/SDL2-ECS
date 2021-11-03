#ifndef CONTROL_COMP_H
#define CONTROL_COMP_H

#include "Component.h"
#include <SDL2/SDL.h>

class InputComponent : public Component
{
public:
    InputComponent() : type(0){}
    /* Data only */
    int getType() { return type; }
    void setType(int t_type) { this->type = t_type; }
private:
    int type;
};

#endif