#include "../include/Entity.h"

void Entity::removeComponent(Component c)
{

    for(std::vector<Component>::iterator it = components.begin(); it < components.end(); it++)
    {
        if (&(*it) == &(c))
        {
            components.erase(it);
            break;
        }
    }


}