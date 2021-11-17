#include "../include/RenderSystem.h"

void RenderSystem::addEntity(Entity e)
{
    std::cout << "Attempting to add " << e.getName() << " to Render System" << std::endl;

    // Requires a Position or a Texture Component
    // If the Entity only has a Position,
    // the Entity is drawn as a black square
    if(e.hasComponent("pos"))
    {
        if(e.hasComponent("tex"))
        {
            std::cout << e.getName() << " has both Position and Texture, adding to Render." << std::endl;
        }
        else
            std::cout << e.getName() << " has only a Position, adding to Render as a Square." << std::endl;

        // if an entity contains either a position or texture, we're good to add it to the vector
        entities.push_back(e);
    }
    else
    {
        std::cout << e.getName() << " is missing a required component, not adding to Render." << std::endl;
    }
}

void RenderSystem::render(SDL_Renderer* r, SDL_Window* t_window)
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
        else
        {
            std::vector<Component*> comps = entity.getComponents();
            PositionComponent* pc;

            for (auto comp : comps)
            {
                if(comp->id == "pos")
                {
                    pc = dynamic_cast<PositionComponent*>(comp);
                    break;
                }
            }

            //Render red filled quad
            SDL_Rect fillRect = { static_cast<int>(pc->m_pos.x), static_cast<int>(pc->m_pos.y), 50, 50 };
            SDL_SetRenderDrawColor( r, 0x00, 0x00, 0x00, 0xFF );
            SDL_RenderFillRect( r, &fillRect );
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