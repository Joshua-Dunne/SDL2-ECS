#include "../include/RenderSystem.h"

void RenderSystem::addEntity(Entity e)
{
    std::cout << "Attempting to add " << e.getName() << " to Render System" << std::endl;

    // Requires a Position and a Texture Component
    // This is because it wouldn't make sense to render an Entity
    // that only has a Position, and vice versa.
    if(e.hasComponent("pos") && e.hasComponent("tex"))
    {
        std::cout << e.getName() << " has both Position and Texture, adding to Render." << std::endl;
        entities.push_back(e);
    }
    else
    {
        std::cout << e.getName() << " is missing a required component, not adding to Render." << std::endl;
    }
}

void RenderSystem::render(SDL_Renderer* r)
{
    for(auto entity : entities)
    {
        if(entity.hasComponent("pos") && entity.hasComponent("tex"))
        {
            std::vector<Component*> comps = entity.getComponents();
            PositionComponent* pc;
            TextureComponent* tc;

            for (auto comp : comps)
            {
                if(comp->id == "pos")
                    pc = dynamic_cast<PositionComponent*>(comp);
                else if(comp->id == "tex")
                    tc = dynamic_cast<TextureComponent*>(comp);
            }
            renderTexture(r, pc, tc);
        }
    }
}

void RenderSystem::renderTexture(SDL_Renderer* r, PositionComponent* pos, TextureComponent* tex)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad;
    renderQuad.x = tex->data.x;
    renderQuad.y = tex->data.y;
    renderQuad.w = tex->data.width;
    renderQuad.h = tex->data.height;

    SDL_FRect fRenderQuad;
    fRenderQuad.x = pos->m_pos.x;
    fRenderQuad.y = pos->m_pos.y;
    fRenderQuad.w = tex->data.width;
    fRenderQuad.h = tex->data.height;

    //Render to screen
    SDL_RenderCopyF(r, tex->texture, &renderQuad, &fRenderQuad);
    SDL_RenderDrawRectF(r, &fRenderQuad);
}