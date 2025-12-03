 #include "Circle.h"

void Circle::Draw(SDL_Renderer* renderer)
{
    float perimeter = 2 * M_PI;
    float step = perimeter / m_precision;

    Vector2 center = GetPosition(0.5f, 0.5f);

    int lastX = m_radius * cos(0) + center.x;
    int lastY = m_radius * sin(0) + center.y;

    for (int i = 1; i <= m_precision; i++)
    {
        int currentX = m_radius * cos(step * i) + center.x;
        int currentY = m_radius * sin(step * i) + center.y;

        SDL_RenderDrawLine(renderer, lastX, lastY, currentX, currentY);

        lastX = currentX;
        lastY = currentY;
    }
}
