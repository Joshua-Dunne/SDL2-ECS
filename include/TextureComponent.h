#ifndef TEX_COMP_H
#define TEX_COMP_H

#include "Component.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureData.h"

/* Data only */
struct TextureComponent : public Component
{
    TextureComponent() = delete;
    TextureComponent(std::string filepath, SDL_Renderer* t_renderer) : Component("tex"), r(t_renderer) { loadFromFilePNG(filepath); };
    void setName(std::string t_name) {id = t_name;};
    
    SDL_Renderer* r;
    SDL_Texture* texture;
    TextureData data;

    // function that loads data based on filepath
    // has no other functionality other than loading required data
    inline void loadFromFilePNG(std::string path)
    {
        SDL_Surface* loadedSurface = IMG_Load(path.c_str());

		if (loadedSurface == NULL)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
		}
		else
		{
			texture = SDL_CreateTextureFromSurface(r, loadedSurface);
			if (texture == NULL)
			{
				printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
			}
            else
            {
                //Get image dimensions
                data.width = loadedSurface->w;
                data.height = loadedSurface->h;
            }

			SDL_FreeSurface(loadedSurface);
		}
    };
};

#endif