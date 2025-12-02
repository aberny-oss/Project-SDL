#pragma once
#include "Geometry.h"
class Rectangle : public Geometry
{
public:
	Rectangle(int x, int y, int width, int height)
		: Geometry(x, y, width, height)
	{}

	void Draw(SDL_Renderer* renderer) override;


};

