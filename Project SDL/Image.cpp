#include "Image.h"

void Image::Draw(SDL_Renderer* renderer)
{
	SDL_Rect dest;
	dest.x = m_x;
	dest.y = m_y;
	dest.w = m_width;
	dest.h = m_height;
	SDL_RenderCopy(renderer, texture, NULL, &dest);

}