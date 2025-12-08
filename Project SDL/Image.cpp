#include "Image.h"
#include <SDL.h>
#include <iostream>
#include "AssetManager.h"

Image::Image(SDL_Renderer* renderer, const char* path) : Geometry(-1, -1)
{
	m_texture = AssetManager::Get()->LoadTexture(renderer, path);

	SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);
}

void Image::Resize(int width, int height)
{
	float factorWidth = static_cast<float>(width) / static_cast<float>(m_width);
	float factorHeight = static_cast<float>(height) / static_cast<float>(m_height);

	float factorMin = std::min(factorWidth, factorHeight);

	int newWidth = static_cast<int>(m_width * factorMin);
	int newHeight = static_cast<int>(m_height * factorMin);

	m_width = std::max(1, newWidth);
	m_height = std::max(1, newHeight);
}

void Image::Draw(SDL_Renderer* renderer)
{
	SDL_Rect dst = { m_x, m_y, m_width, m_height };

	SDL_RenderCopy(renderer, m_texture, NULL, &dst);
}


//void Image::Draw(SDL_Renderer* renderer)
//{
//	SDL_Rect dest;
//	dest.x = m_x;
//	dest.y = m_y;
//	dest.w = m_width;
//	dest.h = m_height;
//	SDL_RenderCopy(renderer, texture, NULL, &dest);
//
//}