#pragma once
#include <SDL.h>
class Geometry
{
protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;

public:
	Geometry(int x, int y, int width, int height)
		: m_x(x), m_y(y), m_width(width), m_height(height)
	{}
	virtual void Draw(SDL_Renderer* renderer) = 0;

};

