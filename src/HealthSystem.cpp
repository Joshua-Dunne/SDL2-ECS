#include "../include/HealthSystem.h"

void HealthSystem::addEntity(Entity e)
{
    std::cout << "Attempting to add " << e.getName() << " to Health System" << std::endl;

    if(e.hasComponent("hp"))
    {
        std::cout << e.getName() << " has Health Component, adding to Health System." << std::endl;
        entities.push_back(e);
    }
    else
    {
        std::cout << e.getName() << " is missing a required component, not adding to Health System." << std::endl;
    }
}

void HealthSystem::update(float& dt)
{
    for(auto ent : entities)
    {
        std::vector<Component*> comps = ent.getComponents();

        HealthComponent* hc;

        for(auto comp : comps)
        {
            if(comp->id == "hp")
            {
                hc = dynamic_cast<HealthComponent*>(comp);
            }
        }

        // slowly decay the hp of any entity with a hp component
        // as long as they aren't currently dead
        if(hc->health > 0.0f)
        {
            hc->health -= dt * m_decayRate;

            if(hc->health < 0.0f) // if their HP goes under 0, set it back to 0
                hc->health = 0.0f;
        }
            
    }
}