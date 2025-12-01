#include <SDL.h>
#include <iostream>

void DrawHorizontalLine(SDL_Renderer* renderer, int x, int y, int length)
{
    for (int i = 0; i < length; i++)
    {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, (x + i), y);
        SDL_RenderPresent(renderer);
    }

}

void DrawVerticalLine(SDL_Renderer* renderer, int x, int y, int length)
{
    for (int i = 0; i < length; i++)
    {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderDrawPoint(renderer, x, (y + i));
        SDL_RenderPresent(renderer);
    }

}


int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

    if (!window)
    {
        std::cout << "SDL_CreateWindow Error : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL, 0);
    if (!renderer)
    {
        std::cout << "SDL_CreateRenderer Error : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    /*SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawPoint(renderer, 100, 100);
    SDL_RenderPresent(renderer);*/

    DrawHorizontalLine(renderer, 10, 10, 100);
    DrawVerticalLine(renderer, 10, 10, 100);


    SDL_Delay(4500);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
