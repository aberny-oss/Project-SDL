#include <SDL.h>
#include <iostream>
#include "Rectangle.h"

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

void DrawRectangle(SDL_Renderer* renderer, int x, int y, int width, int height)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, x, y, (x + width), y);
    SDL_RenderDrawLine(renderer, (x + width), y, (x + width), (y + height));
    SDL_RenderDrawLine(renderer, (x + width), (y + height), x, (y + height));
    SDL_RenderDrawLine(renderer, x, (y + height), x, y);
    SDL_RenderPresent(renderer);
    

}

//void DrawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, int precision)
//
//{
//    /*SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//    float perimeter = 2 * M_PI;
//    float step = perimeter / precision; 
//
//    for (int i = 0; i < precision; i++)
//    {
//        int x1 = radius * cos(step * i) + centerX;
//        int y1 = radius * sin(step * i) + centerY;
//        int x2 = radius * cos(step * (i + 1)) + centerX;
//        int y2 = radius * sin(step * (i + 1)) + centerY;
//
//        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
//    }
//    SDL_RenderPresent(renderer);*/
//
//    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//    float perimeter = 2 * M_PI;
//    float step = perimeter / precision;
//
//    for (int i = 0; i < precision; i++)
//    {
//        int x1 = radius * cos(step * i) + centerX;
//        int y1 = radius * sin(step * i) + centerY;
//        int x2 = radius * cos(step * (i + 1)) + centerX;
//        int y2 = radius * sin(step * (i + 1)) + centerY;
//
//        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
//    }
//    SDL_RenderPresent(renderer);
//}

void DrawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, int precision)
{
    float perimeter = 2 * M_PI;
    float step = perimeter / precision;

    int lastX = radius * cos(0) + centerX;
    int lastY = radius * sin(0) + centerY;

    for (int i = 1; i <= precision; i++)
    {
        int currentX = radius * cos(step * i) + centerX;
        int currentY = radius * sin(step * i) + centerY;

        SDL_RenderDrawLine(renderer, lastX, lastY, currentX, currentY);

        lastX = currentX;
        lastY = currentY;
    }
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

    int wWidth = 640;
    int wHeight = 480;

    SDL_Window* window = SDL_CreateWindow("SDL", 250, 250, wWidth, 480, SDL_WINDOW_SHOWN);

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


    Rectangle rectangle1(100,50);
    Rectangle rectangle2(100, 50);
    Rectangle rectangle3(100, 50);
    Rectangle rectangle4(100, 50);
    Rectangle rectangle5(100, 50);
    
    rectangle1.SetPosition((wWidth - wWidth), (wHeight - wHeight), 0.f, 0.f);
    Vector2 pos1 = rectangle1.GetPosition(0.5f, 0.5f);
    rectangle1.Draw(renderer);

    rectangle2.SetPosition((wWidth - 1), (wHeight - wHeight), 1.f, 0.f);
    Vector2 pos2 = rectangle2.GetPosition(0.5f, 0.5f);
    rectangle2.Draw(renderer);

    rectangle3.SetPosition((wWidth - 1), (wHeight - 1), 1.f, 1.f);
    Vector2 pos3 = rectangle3.GetPosition(0.5f, 0.5f);
    rectangle3.Draw(renderer);

    rectangle4.SetPosition((wWidth - wWidth), (wHeight - 1), 0.f, 1.f);
    Vector2 pos4 = rectangle4.GetPosition(0.5f, 0.5f);
    rectangle4.Draw(renderer);

    rectangle5.SetPosition((wWidth / 2), (wHeight / 2), 0.5f, 0.5f);
    Vector2 pos5 = rectangle5.GetPosition(0.5f, 0.5f);
    rectangle5.Draw(renderer);


    /*SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawPoint(renderer, 100, 100);
    SDL_RenderPresent(renderer);*/

    /*DrawHorizontalLine(renderer, 10, 10, 100);
    DrawVerticalLine(renderer, 10, 10, 100);*/

    /*SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 10, 10, 110, 110);
    SDL_RenderPresent(renderer);*/

    /*DrawRectangle(renderer, 10, 10, 200, 100);*/

    //tuto
    /*Rectangle rect(0, 0, 50, 50);*/

    /*DrawCircle(renderer, 250, 250, 69, 666);*/

    SDL_Delay(4500);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
