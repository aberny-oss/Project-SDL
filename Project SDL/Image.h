#pragma once
//#include <iostream>
#include "Geometry.h"
//#include "SDL_image.h"

struct SDL_Texture;

class Image : public Geometry
{
	SDL_Texture* m_texture;

public:
	Image(SDL_Renderer* renderer, const char* path);

	void Resize(int width, int height) override;

	void Draw(SDL_Renderer* renderer) override;

};

//class Image : public Geometry
//{
//protected:
//	const char* path;
//	SDL_Texture* texture;
//public:
//	Image(SDL_Renderer* renderer, const char* path, int width, int height)
//		: Geometry(width, height) 
//	{
//		texture = IMG_LoadTexture(renderer, path);
//		if (texture == NULL)
//		{
//			std::cout << "Erreur du chargement d'image: " << std::endl;
//		}
//	}
//
//	
//	void Draw(SDL_Renderer* renderer) override;
//
//};