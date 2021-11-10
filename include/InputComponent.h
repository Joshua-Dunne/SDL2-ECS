#ifndef CONTROL_COMP_H
#define CONTROL_COMP_H

#include "Component.h"
#include <SDL2/SDL.h>

/* Data only */
class InputComponent : public Component
{
    InputComponent() : Component(2) {};
    int type;
};

#endif