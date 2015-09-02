// lazyfoo.net/tutorials/SDL/

#include <SDL.h>
#include <stdio.h>

// Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{

    // Window
    SDL_Window *window = NULL;

    // Surface contained by the window
    SDL_Surface *surface = NULL;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize. SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        
        if (window == NULL)
        {
            printf("Window could not be created. SDL_Error %s\n",
                   SDL_GetError());
        }
        else
        {
            // Get window surface
            surface = SDL_GetWindowSurface(window);

            // Fill the surface
            SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format,
                                                   0xFF, 0xFF, 0xFF));

            // Update the surface
            SDL_UpdateWindowSurface(window);

            // Wait for two seconds
            SDL_Delay(2000);
        }
    }

    // Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();        
    
    return 0;
}
