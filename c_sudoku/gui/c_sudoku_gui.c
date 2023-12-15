#include <SDL2/SDL.h>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 640

int init();
void closeStuff();

// rendering window
SDL_Window *gWindow = NULL;
// surface contained by the window
SDL_Surface *gScreenSurface = NULL;

int main(int argc, char const *argv[])
{
    //Start up SDL and create window
    if(!init())
    {
        perror("Failed to initialize!\n");
    }
    else
    {
        //Update the surface
        SDL_UpdateWindowSurface(gWindow);
        //Hack to get window to stay up
        SDL_Event e; 
        int quit = 0; 
        while(!quit) 
        {
            while(SDL_PollEvent( &e )) 
                if(e.type == SDL_QUIT) quit = 1;
                else if (e.key.keysym.sym == SDLK_ESCAPE) quit = 1;
        }
    }

    //Free resources and close SDL
    closeStuff();

    return 0;
}

int init()
{
    int success = 1;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        perror("failed to initialize");
        success = 0;
    }
    else
    {
        gWindow = SDL_CreateWindow("Sudoku", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            perror("failed to create window");
            success = 0;
        }
        else
            gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
    return success;
}

void closeStuff()
{
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}