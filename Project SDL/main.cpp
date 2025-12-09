#include <SDL.h>

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

#include "Rectangle.h"
#include "Circle.h"
#include "Image.h"
#include "InputManager.h"


//void DrawHorizontalLine(SDL_Renderer* renderer, int x, int y, int length)
//{
//    for (int i = 0; i < length; i++)
//    {
//        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//        SDL_RenderDrawPoint(renderer, (x + i), y);
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
//    }*/
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

#define WIDTH 640
#define HEIGHT 480

#define CENTER_X (WIDTH - 1) / 2
#define CENTER_Y (HEIGHT - 1) / 2

#define TARGET_FPS 60
#define TARGET_DELTA_TIME 1.f / TARGET_FPS

int main(int argc, char* argv[])
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        std::cout << "Error SDL2 Initialization : " << SDL_GetError();
        return 1;
    }

    SDL_Window* window;
    SDL_Renderer* renderer;

    window = SDL_CreateWindow("SDL", 250, 250, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        std::cout << "Error window creation";
        return false;
    }

    renderer = SDL_CreateRenderer(window, NULL, 0);
    if (renderer == NULL)
    {
        std::cout << "Error renderer creation";
        return false;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*Rectangle rectangle1(100,50);
    Rectangle rectangle2(100, 50);
    Rectangle rectangle3(100, 50);
    Rectangle rectangle4(100, 50);
    Rectangle rectangle5(100, 50);

    int colorR = rand() % 256;
    int colorG = rand() % 256;
    int colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    rectangle1.SetPosition((WIDTH - WIDTH), (HEIGHT - HEIGHT), 0.f, 0.f);
    rectangle1.Draw(renderer);
    Vector2f posR1RD = rectangle1.GetPosition(1.f, 1.f);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    rectangle2.SetPosition((WIDTH - 1), (HEIGHT - HEIGHT), 1.f, 0.f);
    rectangle2.Draw(renderer);
    Vector2f posR2LD = rectangle2.GetPosition(0.f, 1.f);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    rectangle3.SetPosition((WIDTH - 1), (HEIGHT - 1), 1.f, 1.f);
    rectangle3.Draw(renderer);
    Vector2f posR3LU = rectangle3.GetPosition(0.f, 0.f);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    rectangle4.SetPosition((WIDTH - WIDTH), (HEIGHT - 1), 0.f, 1.f);
    rectangle4.Draw(renderer);
    Vector2f posR4RU = rectangle4.GetPosition(1.f, 0.f);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    rectangle5.SetPosition(CENTER_X, CENTER_Y, 0.5f, 0.5f);
    rectangle5.Draw(renderer);
    Vector2f posR5LU = rectangle5.GetPosition(0.f, 0.f);
    Vector2f posR5RU = rectangle5.GetPosition(1.f, 0.f);
    Vector2f posR5RD = rectangle5.GetPosition(1.f, 1.f);
    Vector2f posR5LD = rectangle5.GetPosition(0.f, 1.f);*/

    Rectangle rectangle1(100, 50);
    rectangle1.SetPosition(CENTER_X / 3, CENTER_Y / 3);
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    Circle circle1(32);
    Circle circle2(32);
    /*Circle circle3(32);
    Circle circle4(32);*/

	circle1.SetPosition(CENTER_X / 2, CENTER_Y / 2);
	circle2.SetPosition(CENTER_X / 2 + CENTER_X, CENTER_Y / 2 + CENTER_Y);

    int speedC1 = 400;
	int speedC2 = 300;

    float deltaTime = 0;

    /*colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    circle1.SetPosition(posR5LU.x, posR5LU.y);
    circle1.Draw(renderer);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    circle2.SetPosition(posR5RU.x, posR5RU.y);
    circle2.Draw(renderer);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    circle3.SetPosition(posR5RD.x, posR5RD.y);
    circle3.Draw(renderer);

    colorR = rand() % 256;
    colorG = rand() % 256;
    colorB = rand() % 256;

    SDL_SetRenderDrawColor(renderer, colorR, colorG, colorB, 255);
    circle4.SetPosition(posR5LD.x, posR5LD.y);
    circle4.Draw(renderer);


    Image image1(renderer, "imageSDL.bmp", CENTER_X / 2, CENTER_Y / 2);
    image1.SetPosition(posR1RD.x, posR1RD.y, 0.f, 0.f);
    image1.Draw(renderer);

    Image image2(renderer, "imageSDL.bmp", CENTER_X / 2, CENTER_Y / 2);
    image2.SetPosition(posR2LD.x, posR2LD.y, 1.f, 0.f);
    image2.Draw(renderer);

    Image image3(renderer, "imageSDL.bmp", CENTER_X / 2, CENTER_Y / 2);
    image3.SetPosition(posR3LU.x, posR3LU.y, 1.f, 1.f);
    image3.Draw(renderer);

    Image image4(renderer, "imageSDL.bmp", CENTER_X / 2, CENTER_Y / 2);
    image4.SetPosition(posR4RU.x, posR4RU.y, 0.f, 1.f);
    image4.Draw(renderer);*/

	/*Image image1(renderer, "imageSDL.bmp");
    Image image2(renderer, "imageSDL.bmp");
    Image image3(renderer, "imageSDL.bmp");
    Image image4(renderer, "imageSDL.bmp");

	image1.Resize(CENTER_X / 2, CENTER_Y / 2);
    image2.Resize(CENTER_X / 2, CENTER_Y / 2);
    image3.Resize(CENTER_X / 2, CENTER_Y / 2);
    image4.Resize(CENTER_X / 2, CENTER_Y / 2);

    image1.SetPosition(posR1RD, 0.f, 0.f);
    image2.SetPosition(posR2LD, 1.f, 0.f);
    image3.SetPosition(posR3LU, 1.f, 1.f);
    image4.SetPosition(posR4RU, 0.f, 1.f);

	image1.Draw(renderer);
    image2.Draw(renderer);
    image3.Draw(renderer);
    image4.Draw(renderer);*/

    /*SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawPoint(renderer, 100, 100);*/

    /*DrawHorizontalLine(renderer, 10, 10, 100);
    DrawVerticalLine(renderer, 10, 10, 100);*/

    /*SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, 10, 10, 110, 110);*/

    SDL_RenderPresent(renderer);

    /*struct State
    {
        bool isDown;
        bool isHeld;
        bool isUp;
    };

    State m_states[SDL_NUM_SCANCODES];*/

   // bool game_is_still_running = true;
   // while (game_is_still_running)
   // {
   //     SDL_Event event;
   //     while (SDL_PollEvent(&event))
   //     {
   //         /*switch (event.type)
   //         {
   //         case SDL_KEYDOWN:
   //         {
   //             switch (event.key.keysym.sym)
   //             {
   //             case SDLK_a:
   //                 if (event.key.repeat)
   //                     break;

   //                 m_states[event.key.keysym.scancode].isDown = true;
   //                 break;
   //             }
			//	break;
   //         }
   //         case SDL_KEYUP:
   //         {
   //             switch (event.key.keysym.sym)
   //             {
   //             case SDLK_a:
   //                 m_states[event.key.keysym.scancode].isUp = true;
   //                 break;
   //             }
   //             break;
   //         }
   //         }*/
   //         /*switch (event.key.type)
   //         {
   //         case SDL_KEYDOWN:
   //             std::cout << "key down" << std::endl;
   //             switch (event.key.keysym.sym)
   //             {
   //             case SDLK_a:
   //                 std::cout << "key a down" << std::endl;
   //                 break;
   //             case SDLK_ESCAPE:
   //                 std::cout << "key escape" << std::endl;
   //                 game_is_still_running = false;
   //                 break;
   //             }
   //             break;
   //         case SDL_KEYUP:
   //             std::cout << "key up" << std::endl;
   //             switch (event.key.keysym.sym)
   //             {
   //             case SDLK_a:
   //                 std::cout << "key a up" << std::endl;
   //                 break;
   //             }
   //             break;
   //         case SDL_QUIT:
   //             std::cout << "key quit" << std::endl;
   //             game_is_still_running = false;
   //             break;
   //         }*/
   //         int x, y;
   //         SDL_GetMouseState(&x, &y);
   //         switch (event.button.type)
   //         {
   //         case SDL_MOUSEBUTTONDOWN:
   //             /*std::cout << "mouse button down" << std::endl;*/
   //             std::cout << "Clic a la positions " << x << " - " << y << std::endl;
   //             break;
   //         case SDL_MOUSEBUTTONUP:
   //             /*std::cout << "mouse button up" << std::endl;*/
   //             break;
   //         }
   //     }
   //     /*for (int i = 0; i < SDL_NUM_SCANCODES; ++i)
   //     {
   //         State& state = m_states[i];

   //         if (state.isDown)
   //         {
   //             state.isHeld = true;
   //             std::cout << "key a down" << std::endl;
   //         }

   //         if (state.isHeld)
   //         {
			//	std::cout << "key a held" << std::endl;
			//}

   //         if (state.isUp)
   //         {
   //             state.isHeld = false;
   //             std::cout << "key a up" << std::endl;
   //         }
   //         state.isDown = false;
   //         state.isUp = false;
   //     }*/
   // }

bool game_is_still_running = true;

while (game_is_still_running)
{
	Uint64 start = SDL_GetTicks64(); // Temps au début de la frame

	// LEARN INPUTS
    InputManager::Get()->Update();   // 1) lire les événements SDL

    //UPDATE
    if (InputManager::Get()->IsHeld(SDLK_o))
    {
        //move up
        circle1.Move(0.f, -speedC1 * deltaTime);

    }
    if (InputManager::Get()->IsHeld(SDLK_k))
    {
        //move left
        circle1.Move(-speedC1 * deltaTime, 0.f);

    }
    if (InputManager::Get()->IsHeld(SDLK_l))
    {
        //move down
        circle1.Move(0.f, speedC1 * deltaTime);
    }
    if (InputManager::Get()->IsHeld(SDLK_m))
    {
        //move right
        circle1.Move(speedC1 * deltaTime, 0.f);
    }

    circle2.Move(0.f, -speedC2 * deltaTime);


    if (circle2.GetPosition(0.f, 1.f).y < 0)
        circle2.SetPosition(CENTER_X / 2 + CENTER_X, HEIGHT + circle2.GetRadius());

    if (circle1.IsColliding(&circle2))
        std::cout << "Les cercles ce touchent." << std::endl;

    //DRAW
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    circle1.Draw(renderer);
    circle2.Draw(renderer);

    rectangle1.Draw(renderer);

    SDL_RenderPresent(renderer);
    Uint64 end = SDL_GetTicks64();

    deltaTime = (end - start) / 1000.f;
    float diff = TARGET_DELTA_TIME - deltaTime;

    //Cap FPS
    if (diff > 0)
    {
        SDL_Delay(diff * 1000);
        deltaTime = TARGET_DELTA_TIME;
    }

    //Display FPS
    std::cout << 1.f / deltaTime << std::endl;
}

//while (game_is_still_running)
//{
//    //  // 1) Met à jour les entrées (clavier)
//    //  InputManager::Get()->Update();
//    //  // 2) Lis les touches
//    //  if (InputManager::Get()->IsDown(SDLK_a))
//    //  {
//          //std::cout << "Touche A appuyée !" << std::endl; // Détecte le moment où on appuie sur la touche A
//    //  }
//    //  if (InputManager::Get()->IsHeld(SDLK_a))
//    //  {
//          //std::cout << "Touche A maintenue !" << std::endl; // Détecte tant que la touche A est maintenue enfoncée
//    //  }
//    //  if (InputManager::Get()->IsUp(SDLK_a))
//    //  {
//          //std::cout << "Touche A relâchée !" << std::endl; // Détecte le moment où on relâche la touche A
//    //  }
//    //  // 3) Update du jeu (physique, logique, etc.)
//    //  // 4) Render (affichage)
//
//      // Dans ta boucle de jeu
//    InputManager* input = InputManager::Get();
//    input->Update();
//
//
//    // On parcourt une petite liste de touches à tester
//    SDL_KeyCode keysToCheck[] = { SDLK_ESCAPE, SDLK_a, SDLK_z, SDLK_e, SDLK_r, SDLK_t, SDLK_y, SDLK_SPACE };
//
//    for (SDL_KeyCode key : keysToCheck)
//    {
//        if (!input->IsDown(key))
//        {
//            continue; // si cette touche n'a pas été pressée cette frame, on saute
//        }
//        switch (key)
//        {
//        case SDLK_ESCAPE:
//            // quitter le jeu
//            game_is_still_running = false;
//            break;
//
//        case SDLK_a:
//            // Touche A pressée
//            std::cout << "Touche A appuyee !" << std::endl;
//            break;
//
//        case SDLK_z:
//            // Touche Z pressée
//            std::cout << "Touche Z appuyee !" << std::endl;
//            break;
//
//        case SDLK_e:
//            // Touche E pressée
//            std::cout << "Touche E appuyee !" << std::endl;
//            break;
//
//        case SDLK_r:
//            // Touche R pressée
//            std::cout << "Touche R appuyee !" << std::endl;
//            break;
//
//        case SDLK_t:
//            // Touche T pressée
//            std::cout << "Touche T appuyee !" << std::endl;
//            break;
//
//        case SDLK_y:
//            // Touche Y pressée
//            std::cout << "Touche Y appuyee !" << std::endl;
//            break;
//
//        case SDLK_SPACE:
//            // Touche ESPACE pressée
//            std::cout << "Touche ESPACE appuyee !" << std::endl;
//            break;
//
//        default:
//            break;
//        }
//    }
//
//    for (SDL_KeyCode key : keysToCheck)
//    {
//        if (!input->IsHeld(key))
//        {
//            continue;
//        }
//
//        switch (key)
//        {
//        case SDLK_a:
//            // Touche A maintenue
//            std::cout << "Touche A maintenue !" << std::endl;
//            break;
//        case SDLK_z:
//            // Touche Z maintenue
//            std::cout << "Touche Z maintenue !" << std::endl;
//            break;
//        case SDLK_e:
//            // Touche E maintenue
//            std::cout << "Touche E maintenue !" << std::endl;
//            break;
//        case SDLK_r:
//            // Touche R maintenue
//            std::cout << "Touche R maintenue !" << std::endl;
//            break;
//        case SDLK_t:
//            // Touche T maintenue
//            std::cout << "Touche T maintenue !" << std::endl;
//            break;
//        case SDLK_y:
//            // Touche Y maintenue
//            std::cout << "Touche Y maintenue !" << std::endl;
//            break;
//        case SDLK_SPACE:
//            // Touche ESPACE maintenue
//            std::cout << "Touche ESPACE maintenue !" << std::endl;
//            break;
//        default:
//            break;
//        }
//    }
//
//    for (SDL_KeyCode key : keysToCheck)
//    {
//        if (!input->IsUp(key))
//        {
//            continue;
//        }
//
//        switch (key)
//        {
//        case SDLK_a:
//			// Touche A relâchée
//            std::cout << "Touche A relachee !" << std::endl;
//            break;
//        case SDLK_z:
//            // Touche Z relâchée
//            std::cout << "Touche Z relachee !" << std::endl;
//            break;
//        case SDLK_e:
//            // Touche E relâchée
//            std::cout << "Touche E relachee !" << std::endl;
//            break;
//        case SDLK_r:
//            // Touche R relâchée
//            std::cout << "Touche R relachee !" << std::endl;
//            break;
//        case SDLK_t:
//            // Touche T relâchée
//            std::cout << "Touche T relachee !" << std::endl;
//            break;
//        case SDLK_y:
//            // Touche Y relâchée
//            std::cout << "Touche Y relachee !" << std::endl;
//            break;
//        case SDLK_SPACE:
//            // Touche ESPACE relâchée
//            std::cout << "Touche ESPACE relachee !" << std::endl;
//            break;
//        default:
//            break;
//        }
//    }
//
//}
    
    SDL_Delay(500);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
