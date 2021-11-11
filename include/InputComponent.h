#ifndef CONTROL_COMP_H
#define CONTROL_COMP_H

#include "Component.h"
#include <SDL2/SDL.h>

/* Data only */
struct InputComponent : public Component
{
    InputComponent() : Component("input") {};
    void setName(std::string t_name) {id = t_name;};
    int type{0};
    bool press{false};
};

#endif