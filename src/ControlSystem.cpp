#include "../include/ControlSystem.h"

void ControlSystem::update(float& dt)
{
    std::cout << "Updating Control System" << std::endl;
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