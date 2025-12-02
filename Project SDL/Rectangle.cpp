#include "Rectangle.h"

void Rectangle::Draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer, m_x, m_y, (m_x + m_width), m_y);
    SDL_RenderDrawLine(renderer, (m_x + m_width), m_y, (m_x + m_width), (m_y + m_height));
    SDL_RenderDrawLine(renderer, (m_x + m_width), (m_y + m_height), m_x, (m_y + m_height));
    SDL_RenderDrawLine(renderer, m_x, (m_y + m_height), m_x, m_y);
    SDL_RenderPresent(renderer);
}
