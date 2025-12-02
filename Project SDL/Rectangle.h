#pragma once
#include "Geometry.h"
class Rectangle : public Geometry
{
public:
	Rectangle(int width, int height)
		: Geometry(width, height)
	{}

	void Draw(SDL_Renderer* renderer) override;


};

