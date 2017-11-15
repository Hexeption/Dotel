//
// Created by Keirb on 12/11/2017.
//

#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);

    if (window == nullptr)
    {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_UpdateWindowSurface(window);
    SDL_Delay(6000);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}