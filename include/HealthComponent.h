#ifndef HEALTH_COMP_H
#define HEALTH_COMP_H

#include "../include/Component.h"

class HealthComponent : public Component
{
public:
    HealthComponent() : health(100) {}
    /* Data only */
    int getHealth() { return health; }
    void setHealth(int t_health) { this->health = t_health; }
private:
    int health;
};

#endif