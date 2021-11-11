#include "../include/ControlSystem.h"

void ControlSystem::addEntity(Entity e)
{
    std::cout << "Attemping to add Entity to Control System" << std::endl;
    std::vector<Component*> comps = e.getComponents();
    int count = 0;

    // In this implementation, there cannot be duplicate Entities,
    // so we do not need to do checks for duplicates.
    for(auto comp : comps)
    {
        if(comp->id == "input")
            count++;
        if(comp->id == "pos")
            count++;
    }

    // Control System needs Input and Position, so if we count 2 required components, add the Entity
    if(count == 2)
    {
        std::cout << "Entity has Input and Pos - Adding to Control" << std::endl;
        entities.push_back(e);
    }
    else
        std::cout << "Entity is missing a required component, not adding to Control." << std::endl;
}

void ControlSystem::update(float& dt)
{
    std::cout << "Updating Control System" << std::endl;
    /*
    for(auto ent : entities)
    {
        std::vector<Component*> ent = e.getComponents();

        // In this implementation, there cannot be duplicate Entities,
        // so we do not need to do checks for duplicates.
        for(auto comp : comps)
        {
            if(comp->id == "input")
                count++;
            if(comp->id == "pos")
                count++;
        }
    }
    */
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
    // example: e.key.keysym.sym == SDLK_w

}

void ControlSystem::processKeyRelease(SDL_Event& e)
{

}