#include "../include/Game.h"

Game::Game() :
    m_gameIsRunning{ false }
{
}

Game::~Game()
{
    cleanUp();
}

void Game::run()
{
    // get performance counter before initialization to get starting elapsed time
    Uint64 start = SDL_GetPerformanceCounter();

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "Entity Component System", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            // enable VSync when creating renderer
            // passing the flag SDL_RENDERER_PRESENTVSYNC to SDL_CreateRenderer()
            // causes subsequent calls to SDL_RenderPresent() to wait before showing the window.
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        }
    }

    int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
	}

    loadMedia();

    // adding requested components
    player.addComponent(new HealthComponent());
    player.addComponent(new InputComponent());
    player.addComponent(new PositionComponent(Vector2(100.0f, 100.0f)));
    player.addComponent(new TextureComponent("../assets/images/player.png", renderer));

    villain.addComponent(new HealthComponent());
    villain.addComponent(new PositionComponent(Vector2(SCREEN_WIDTH - 100.0f, SCREEN_HEIGHT - 100.0f)));
    villain.addComponent(new TextureComponent("../assets/images/ai.png", renderer));

    cortana.addComponent(new HealthComponent());
    cortana.addComponent(new PositionComponent(Vector2(SCREEN_WIDTH - 200.0f, SCREEN_HEIGHT - 200.0f)));
    cortana.addComponent(new TextureComponent("../assets/images/cortana.png", renderer));

    dinkyDi.addComponent(new PositionComponent(Vector2(SCREEN_WIDTH - 300.0f, SCREEN_HEIGHT - 300.0f)));
    //dinkyDi.addComponent(new TextureComponent("../assets/images/dinky.png", renderer));

    // adding each Entity to all systems
    // this shows that some systems require certain components,
    // so not all systems will accept all entities
    std::cout << "-----------------" << std::endl;
    hs.addEntity(player);
    cs.addEntity(player);
    rs.addEntity(player);
    as.addEntity(player);

    std::cout << "-----------------" << std::endl;

    hs.addEntity(villain);
    cs.addEntity(villain);
    rs.addEntity(villain);
    as.addEntity(villain);

    std::cout << "-----------------" << std::endl;

    hs.addEntity(cortana);
    cs.addEntity(cortana);
    rs.addEntity(cortana);
    as.addEntity(cortana);

    std::cout << "-----------------" << std::endl;

    hs.addEntity(dinkyDi);
    cs.addEntity(dinkyDi);
    rs.addEntity(dinkyDi);
    as.addEntity(dinkyDi);

    std::cout << "-----------------" << std::endl;

    Uint64 end = SDL_GetPerformanceCounter();

    // calculate elapsed time for first frame
	float m_elapsed = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
    // This is only done for the first initial wave, as everything else is calculated as the loop progresses


    m_gameIsRunning = true;

    while (m_gameIsRunning)
    {
        Uint32 current = SDL_GetTicks();
        float dT = (current - m_elapsed) / 1000.0f;

        processEvents();
        update(dT);
        render();

        m_elapsed = current;

    }
}

void Game::loadMedia()
{
    // load necessary information here
    // Example: texture = loadFromFile("path", SDL_Surface, TextureData);
	
}

SDL_Texture* Game::loadFromFileBMP(std::string path, SDL_Texture* tex, TextureData& data)
{
    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());

    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), SDL_GetError());
    }
    else
    {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture from surface pixels
        tex = SDL_CreateTextureFromSurface(renderer, loadedSurface);


        if (tex == NULL)
        {
            std::cout << "Unable to create texture from %s! SDL Error: %s\n" << path.c_str() << SDL_GetError() << std::endl;
        }
        else
        {
            //Get image dimensions
            data.width = loadedSurface->w;
            data.height = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return tex;
}

SDL_Texture* Game::loadFromFilePNG(std::string path, SDL_Texture* tex, TextureData& data)
{
    SDL_Texture* newTexture{ NULL };

		SDL_Surface* loadedSurface = IMG_Load(path.c_str());

		if (loadedSurface == NULL)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
		}
		else
		{
			newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
			if (newTexture == NULL)
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

		return newTexture;
}

void Game::processEvents()
{
    //std::cout << "Processing Events" << std::endl;
    //While application is running
    while(SDL_PollEvent( &e ) != 0)
    { 
        if(e.type == SDL_QUIT)
        {
            m_gameIsRunning = false;
        }

        // Control System processing key presses
        cs.processEvents(e);
    }
}

void Game::update(float dt)
{
   // std::cout << "Updating" << std::endl;
   hs.update(dt);
   cs.update(dt);
   as.update(dt);

}

void Game::render()
{
    //std::cout << "Rendering" << std::endl;

    if( window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_RenderClear(renderer);

        // Render System renders any Entities it can
        rs.render(renderer, window);

        SDL_RenderPresent(renderer);
    }


}

void Game::cleanUp()
{
    std::cout << "Cleaning up" << std::endl;

    //Destroy window
    SDL_DestroyWindow( window );
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}