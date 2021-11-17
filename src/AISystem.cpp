#include "../include/AISystem.h"

void AISystem::addEntity(Entity e)
{
    std::cout << "Attempting to add " << e.getName() << " to AI System" << std::endl;
    // Don't add any Entity that has an input component
    // there's no need for the two components to overlap, since it will cause movement issues
    if(e.hasComponent("hp") && e.hasComponent("pos") &&!e.hasComponent("input"))
    {
        std::cout << e.getName() << " has Health and Position - adding to AI System" << std::endl;
        entities.push_back(e);
    }
    else
    {
        std::cout << e.getName() << " is missing a required component, not adding to AI System." << std::endl;
    }
}

void AISystem::update(float& dt)
{
    m_currentTime += dt;

    if(m_currentTime >= c_MAX_TIME)
    {
        m_currentTime = 0.0f;

        for(auto ent : entities)
        {
            std::vector<Component*> comps = ent.getComponents();
            HealthComponent* hc;

            for(auto comp : comps)
            {
                if(comp->id == "hp")
                {
                    hc = dynamic_cast<HealthComponent*>(comp);
                    //currentInput = e.key.keysym.sym;
                }
            }

            // Pick a new heading if alive
            if(hc->health > 0.0f)
            {
                pickHeading();
            }
        }
    }
    else if (m_currentTime < c_MAX_TIME)
    {
        for(auto ent : entities)
        {
            std::vector<Component*> comps = ent.getComponents();

            PositionComponent* pc;
            HealthComponent* hc;

            for(auto comp : comps)
            {
                if(comp->id == "pos")
                {
                    pc = dynamic_cast<PositionComponent*>(comp);
                }
                else if(comp->id == "hp")
                {
                    hc = dynamic_cast<HealthComponent*>(comp);
                    //currentInput = e.key.keysym.sym;
                }
            }

            // AI will only move if they are alive
            if(hc->health > 0.0f)
            {
                pc->m_pos = pc->m_pos + (m_heading * dt);
                pc->m_pos = boundaryCheck(pc->m_pos);
            }
        }
    }
}

Vector2 AISystem::boundaryCheck(Vector2 t_currentPos)
{
    // Keeps AI in-bounds
    // If AI hits a boundary, turns them around,
    // and resets their timer to decide next movement
    if(t_currentPos.x < 0.0f)
    {
        t_currentPos.x = 0.0f;
        m_heading.x *= -1;
        m_currentTime = 0.0f;
    }
    else if(t_currentPos.x > SCREEN_WIDTH)
    {
        t_currentPos.x = SCREEN_WIDTH;
        m_heading.x *= -1;
        m_currentTime = 0.0f;
    }
    if(t_currentPos.y < 0.0f)
    {
        t_currentPos.y = 0.0f;
        m_heading.y *= -1;
        m_currentTime = 0.0f;
    }
    else if(t_currentPos.y > SCREEN_HEIGHT)
    {
        t_currentPos.y = SCREEN_HEIGHT;
        m_heading.y *= -1;
        m_currentTime = 0.0f;
    }

    return t_currentPos;
}

void AISystem::pickHeading()
{
    int random = (rand() % 5) + 1; // range of 0 - 4 (+ 1, so 1 - 5)
    switch(random)
    {
        case 1:
            m_heading.x = 0.0f;
            m_heading.y = -m_speed; // Up
            break;
        case 2:
            m_heading.x = -m_speed; // Left
            m_heading.y = 0.0f;
            break;
        case 3:
            m_heading.x = 0.0f;
            m_heading.y = m_speed; // Down
            break;
        case 4:
            m_heading.x = m_speed; // Right
            m_heading.y = 0.0f;
            break;
        case 5: // in this case the AI chooses not to move
            m_heading.x = 0.0f;
            m_heading.y = 0.0f;
            break;
    }
}