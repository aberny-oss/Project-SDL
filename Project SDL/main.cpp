#include <SDL.h>
#include <iostream>

//void DrawHorizontalLine(SDL_Renderer* renderer, int x, int y, int length)
//{
//    for (int i = 0; i < length; i++)
//    {
//        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//        SDL_RenderDrawPoint(renderer, (x + i), y);
//        SDL_RenderPresent(renderer);
//    }
//
//}
//
//void DrawVerticalLine(SDL_Renderer* renderer, int x, int y, int length)
//{
//    for (int i = 0; i < length; i++)
//    {
//        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//        SDL_RenderDrawPoint(renderer, x, (y + i));
//        SDL_RenderPresent(renderer);
//    }
//
//}

//void DrawRectangle(SDL_Renderer* renderer, int x, int y, int width, int height)
//{
//    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//    SDL_RenderDrawLine(renderer, x, y, (x + width), y);
//    SDL_RenderDrawLine(renderer, (x + width), y, (x + width), (y + height));
//    SDL_RenderDrawLine(renderer, (x + width), (y + height), x, (y + height));
//    SDL_RenderDrawLine(renderer, x, (y + height), x, y);
//    SDL_RenderPresent(renderer);
//    
//
//}

void DrawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, int precision)

{
    /*SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    float perimeter = 2 * M_PI;
    float step = perimeter / precision; 

    for (int i = 0; i < precision; i++)
    {
        int x1 = radius * cos(step * i) + centerX;
        int y1 = radius * sin(step * i) + centerY;
        int x2 = radius * cos(step * (i + 1)) + centerX;
        int y2 = radius * sin(step * (i + 1)) + centerY;

        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
    SDL_RenderPresent(renderer);*/

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    float perimeter = 2 * M_PI;
    float step = perimeter / precision;

    for (int i = 0; i < precision; i++)
    {
        int x1 = radius * cos(step * i) + centerX;
        int y1 = radius * sin(step * i) + centerY;
        int x2 = radius * cos(step * (i + 1)) + centerX;
        int y2 = radius * sin(step * (i + 1)) + centerY;

        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
    SDL_RenderPresent(renderer);
}

// etape 1 pi / precision 
//etape 2 cos point etape 1 * i
//etape pareil sin 
// pareil cos sin i +1

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

    /*DrawHorizontalLine(renderer, 10, 10, 100);
    DrawVerticalLine(renderer, 10, 10, 100);*/

    /*SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 10, 10, 110, 110);
    SDL_RenderPresent(renderer);*/

    /*DrawRectangle(renderer, 10, 10, 200, 100);*/

    DrawCircle(renderer, 250, 250, 69, 666);

    SDL_Delay(4500);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
