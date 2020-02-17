#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *gWindow         = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gXOut          = NULL;

bool init()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    else
    {
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                   SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n",
                   SDL_GetError());
            return false;
        }
        else
        {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return true;
}

bool loadMedia()
{
    gXOut = SDL_LoadBMP("x.bmp");
    if(gXOut == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", "x.bmp",
               SDL_GetError());
        return false;
    }

    return true;
}

void close()
{
    SDL_FreeSurface(gXOut);
    gXOut = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    SDL_Quit();
}

int main(int argc, char *args[])
{
    if(!init())
    {
        printf("Failed to initialize!\n");
        close();
        return 1;
    }

    if(!loadMedia())
    {
        printf("Failed to load media!\n");
        close();
        return 1;
    }

    bool quit = false;
    SDL_Event e;

    while(!quit)
    {
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
    }

    close();

    return 0;
}
