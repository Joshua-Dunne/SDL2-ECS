#include "../include/Entity.h"

void Entity::addComponent(Component* c)
{
    // Handling whether entities have specific componets or not is done outside this class
    components.push_back(c);
}

void Entity::removeComponent(Component* c)
{

    for(std::vector<Component*>::iterator it = components.begin(); it < components.end(); it++)
    {
        if (*it == c)
        {
            delete(*it);
            components.erase(it);
            break;
        }
    }

}

bool Entity::hasComponent(std::string t_name)
{
    for (auto comp : components)
    {
        if(comp->id == t_name)
        {
            return true;
        }
    }

    return false;
}