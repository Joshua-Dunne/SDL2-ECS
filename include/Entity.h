#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include "Component.h"

class Entity
{
    std::string name;
public:
    Entity() {};
    Entity(std::string t_name) : name(t_name) {};
    void addComponent(Component* c);
    void removeComponent(Component* c);
    std::vector<Component*> getComponents() {return components;}
    bool hasComponent(std::string t_name);
    std::string getName() {return name;}

private:
    std::vector<Component*> components;
};

#endif