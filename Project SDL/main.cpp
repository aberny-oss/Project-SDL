#include <SDL.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <SDL_image.h>
#include <SDL_events.h>
#include "Rectangle.h"
#include "Circle.h"
#include "Image.h"


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

//void DrawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius, int precision)
//{
//    float perimeter = 2 * M_PI;
//    float step = perimeter / precision;
//
//    int lastX = radius * cos(0) + centerX;
//    int lastY = radius * sin(0) + centerY;
//
//    for (int i = 1; i <= precision; i++)
//    {
//        int currentX = radius * cos(step * i) + centerX;
//        int currentY = radius * sin(step * i) + centerY;
//
//        SDL_RenderDrawLine(renderer, lastX, lastY, currentX, currentY);
//
//        lastX = currentX;
//        lastY = currentY;
//    }
//}

// etape 1 pi / precision 
//etape 2 cos point etape 1 * i
//etape pareil sin 
// pareil cos sin i +1

int main(int argc, char* argv[])
{
    srand(time(NULL));
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    int wWidth = 640;
    int wHeight = 480;

    SDL_Window* window = SDL_CreateWindow("SDL", 250, 250, wWidth, wHeight, SDL_WINDOW_SHOWN);

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

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    Rectangle rectangle1(100,50);
    Rectangle rectangle2(100, 50);
    Rectangle rectangle3(100, 50);
    Rectangle rectangle4(100, 50);
    Rectangle rectangle5(100, 50);

    int colorR = rand() % 256;
    int colorG = rand() % 256;
    int colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    rectangle1.SetPosition((wWidth - wWidth), (wHeight - wHeight), 0.f, 0.f);
    rectangle1.Draw(renderer);
    Vector2 posR1RD = rectangle1.GetPosition(1.f, 1.f);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    rectangle2.SetPosition((wWidth - 1), (wHeight - wHeight), 1.f, 0.f);
    rectangle2.Draw(renderer);
    Vector2 posR2LD = rectangle2.GetPosition(0.f, 1.f);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    rectangle3.SetPosition((wWidth - 1), (wHeight - 1), 1.f, 1.f);
    rectangle3.Draw(renderer);
    Vector2 posR3LU = rectangle3.GetPosition(0.f, 0.f);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    rectangle4.SetPosition((wWidth - wWidth), (wHeight - 1), 0.f, 1.f);
    rectangle4.Draw(renderer);
    Vector2 posR4RU = rectangle4.GetPosition(1.f, 0.f);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    rectangle5.SetPosition((wWidth / 2), (wHeight / 2), 0.5f, 0.5f);
    rectangle5.Draw(renderer);
    Vector2 posR5LU = rectangle5.GetPosition(0.f, 0.f);
    Vector2 posR5RU = rectangle5.GetPosition(1.f, 0.f);
    Vector2 posR5RD = rectangle5.GetPosition(1.f, 1.f);
    Vector2 posR5LD = rectangle5.GetPosition(0.f, 1.f);
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    Circle circle1(32, 666);
    Circle circle2(32, 666);
    Circle circle3(32, 666);
    Circle circle4(32, 666);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    circle1.SetPosition(posR5LU.x, posR5LU.y, 0.5f, 0.5f);
    circle1.Draw(renderer);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    circle1.SetPosition(posR5RU.x, posR5RU.y, 0.5f, 0.5f);
    circle1.Draw(renderer);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    circle1.SetPosition(posR5RD.x, posR5RD.y, 0.5f, 0.5f);
    circle1.Draw(renderer);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    circle1.SetPosition(posR5LD.x, posR5LD.y, 0.5f, 0.5f);
    circle1.Draw(renderer);

    
    Image image1(renderer, "imageSDL.bmp",(wWidth / 4), (wHeight / 4));
    image1.SetPosition(posR1RD.x, posR1RD.y, 0.f, 0.f);
    image1.Draw(renderer);

    Image image2(renderer, "imageSDL.bmp", (wWidth / 4), (wHeight / 4));
    image2.SetPosition(posR2LD.x, posR2LD.y, 1.f, 0.f);
    image2.Draw(renderer);

    Image image3(renderer, "imageSDL.bmp", (wWidth / 4), (wHeight / 4));
    image3.SetPosition(posR3LU.x, posR3LU.y, 1.f, 1.f);
    image3.Draw(renderer);

    Image image4(renderer, "imageSDL.bmp", (wWidth / 4), (wHeight / 4));
    image4.SetPosition(posR4RU.x, posR4RU.y, 0.f, 1.f);
    image4.Draw(renderer);

    /*SDL_RenderCopy(renderer, texture, NULL, NULL);

    SDL_RenderPresent(renderer);*/


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

    SDL_RenderPresent(renderer);

    bool game_is_still_running = true;
    while (game_is_still_running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                std::cout << "key down" << std::endl;
                break;
            case SDL_KEYUP:
                std::cout << "key up" << std::endl;
                break;
            case SDL_QUIT:
                std::cout << "key quit" << std::endl;
                game_is_still_running = false;
                break;
            }
            switch (event.key.keysym.scancode)
            {
            case SDL_SCANCODE_A:
                std::cout << "key a" << std::endl;
                break;
            }
        }
    }


    SDL_Delay(1000);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
