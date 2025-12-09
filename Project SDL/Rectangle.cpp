#include "Rectangle.h"

#include <SDL.h>

Rectangle::Rectangle(int width, int height) : Geometry(width, height)
{
}

void Rectangle::Draw(SDL_Renderer* renderer)
{
	SDL_Rect rect = { m_x, m_y, m_width, m_height };

	SDL_RenderDrawRect(renderer, &rect);
}

Vector2f Rectangle::GetRadius() const
{
	Vector2f center = GetPosition(0.5f, 0.5f);
	return center;
}