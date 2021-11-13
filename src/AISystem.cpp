#include "../include/AISystem.h"

void AISystem::addEntity(Entity e)
{
    std::cout << "Attemping to add Entity to AI System" << std::endl;
    if(e.hasComponent("hp") && e.hasComponent("pos"))
    {
        std::cout << "Entity has Health and Position - Adding to AI System" << std::endl;
        entities.push_back(e);
    }
    else
    {
        std::cout << "Entity is missing a required component, not adding to AI System." << std::endl;
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
            if(hc->health > 0)
            {
                int random = (rand() % 4) + 1; // range of 0 - 3 (+ 1, so 1 - 4)
                // Now that we have both necessary items, we can do key presses
                switch(random)
                {
                    case 1:
                        pc->m_pos = pc->m_pos + Vector2(0.0f,-m_speed * dt); // Up
                        break;
                    case 2:
                        pc->m_pos = pc->m_pos + Vector2(-m_speed * dt, 0.0f); // Left
                        break;
                    case 3:
                        pc->m_pos = pc->m_pos + Vector2(0.0f,m_speed * dt); // Down
                        break;
                    case 4:
                        pc->m_pos = pc->m_pos + Vector2(m_speed * dt, 0.0f); // Right
                        break;
                }

                pc->m_pos = boundaryCheck(pc->m_pos);
            }
        }
    }
}

Vector2 AISystem::boundaryCheck(Vector2 t_currentPos)
{
    if(t_currentPos.x < 0.0f)
        t_currentPos.x = 0.0f;
    if(t_currentPos.x > SCREEN_WIDTH)
        t_currentPos.x = SCREEN_WIDTH;
    if(t_currentPos.y < 0.0f)
        t_currentPos.y = 0.0f;
    if(t_currentPos.y > SCREEN_HEIGHT)
        t_currentPos.y = SCREEN_HEIGHT;

    return t_currentPos;
}