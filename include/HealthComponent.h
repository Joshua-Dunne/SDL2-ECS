#ifndef HEALTH_COMP_H
#define HEALTH_COMP_H

#include "Component.h"


/* Data only */
struct HealthComponent : public Component
{
    int health;
};

#endif