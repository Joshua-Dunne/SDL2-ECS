#include "../include/ControlSystem.h"

void ControlSystem::addEntity(Entity e)
{
    std::cout << "Attemping to add Entity to Control System" << std::endl;
    if(e.hasComponent("pos") && e.hasComponent("input"))
    {
        std::cout << "Entity has Input and Pos - Adding to Control" << std::endl;
        entities.push_back(e);
    }
    else
    {
        std::cout << "Entity is missing a required component, not adding to Control." << std::endl;
    }
}

void ControlSystem::update(float& dt)
{
    for(auto ent : entities)
    {
        std::vector<Component*> comps = ent.getComponents();

        InputComponent* ic;
        PositionComponent* pc;

        for(auto comp : comps)
        {
            if(comp->id == "pos")
            {
                pc = dynamic_cast<PositionComponent*>(comp);
            }
            else if(comp->id == "input")
            {
                ic = dynamic_cast<InputComponent*>(comp);
                //currentInput = e.key.keysym.sym;
            }
        }

        // Now that we have both necessary items, we can do key presses
        if (ic->type == SDLK_w && ic->press)
            pc->m_pos = pc->m_pos + Vector2(0.0f,-m_speed * dt);

        if (ic->type == SDLK_a && ic->press)
            pc->m_pos = pc->m_pos + Vector2(-m_speed * dt, 0.0f);

        if (ic->type == SDLK_s && ic->press)
            pc->m_pos = pc->m_pos + Vector2(0.0f,m_speed * dt);

        if (ic->type == SDLK_d && ic->press)
            pc->m_pos = pc->m_pos + Vector2(m_speed * dt, 0.0f);
    }
}

void ControlSystem::processEvents(SDL_Event& e)
{
    if (e.type == SDL_KEYDOWN)
	{
        processKeyPress(e);
	}

	if (e.type == SDL_KEYUP)
	{
        processKeyRelease(e);
	}

    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        processMouse(e.button);
    }
}

void ControlSystem::processMouse(SDL_MouseButtonEvent& b)
{
    // process mouse events
}


void ControlSystem::processKeyPress(SDL_Event& e)
{
    InputComponent* ic;

    for(auto ent : entities)
    {
        std::vector<Component*> comps = ent.getComponents();

        for(auto comp : comps)
        {
            if(comp->id != "input")
                continue;
            else
            {
                ic = dynamic_cast<InputComponent*>(comp);
                ic->type = e.key.keysym.sym;
                ic->press = true;
                //currentInput = e.key.keysym.sym;
            }
        }
    }
}

void ControlSystem::processKeyRelease(SDL_Event& e)
{
    InputComponent* ic;

    for(auto ent : entities)
    {
        std::vector<Component*> comps = ent.getComponents();

        for(auto comp : comps)
        {
            if(comp->id != "input")
                continue;
            else
            {
                ic = dynamic_cast<InputComponent*>(comp);
                ic->type = e.key.keysym.sym;
                ic->press = false;
                //currentInput = e.key.keysym.sym;
            }
        }
    }
}