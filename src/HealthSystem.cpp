#include "../include/HealthSystem.h"

void HealthSystem::addEntity(Entity e)
{
    std::cout << "Attempting to add Entity to Health System" << std::endl;

    // Requires a Position and a Texture Component
    // This is because it wouldn't make sense to render an Entity
    // that only has a Position, and vice versa.
    if(e.hasComponent("hp"))
    {
        std::cout << "Entity has Health Component, Adding to Health System." << std::endl;
        entities.push_back(e);
    }
    else
    {
        std::cout << "Entity is missing a required component, not adding to Health System." << std::endl;
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
            std::cout << hc->health << std::endl;

            if(hc->health < 0.0f) // if their HP goes under 0, set it back to 0
                hc->health = 0.0f;
        }
            
    }
}