#ifndef HEALTH_COMP_H
#define HEALTH_COMP_H

#include "Component.h"


/* Data only */
struct HealthComponent : public Component
{
    HealthComponent() : Component("hp") {};
    void setName(std::string t_name) {id = t_name;};
    int health{100};
};

#endif