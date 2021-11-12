#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include <iostream>
#include <SDL2/SDL.h>
#include "Entity.h"
#include "TextureComponent.h"
#include "PositionComponent.h"

class RenderSystem
{
std::vector<Entity> entities;

public:
    void addEntity(Entity e);
    void update(float& dt) {/*std::cout << "Updating Render System" << std::endl;*/}
    void render(SDL_Renderer* r);
    void renderTexture(SDL_Renderer* r, PositionComponent* pos, TextureComponent* tex);
    
};

#endif