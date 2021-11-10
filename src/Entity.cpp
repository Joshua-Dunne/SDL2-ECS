#include "../include/Entity.h"

void Entity::addComponent(Component c)
{
    // Handling whether entities have specific componets or not is done outside this class
    components.push_back(c);
}

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