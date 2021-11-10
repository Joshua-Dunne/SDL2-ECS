#ifndef HEALTH_COMP_H
#define HEALTH_COMP_H

#include "Component.h"


/* Data only */
struct HealthComponent : public Component
{
    HealthComponent() : Component(1) {};
    int health;
};

#endif