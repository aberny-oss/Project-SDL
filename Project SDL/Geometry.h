#pragma once
#include <SDL.h>
#include "Math.h"
class Geometry
{
protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;

public:
	Geometry(int width, int height)
		: m_x(0), m_y(0), m_width(width), m_height(height)
	{}
	virtual void Draw(SDL_Renderer* renderer) = 0;

	void SetPosition(int x, int y, float anchorX, float anchorY);
	Vector2 GetPosition(float anchorX, float anchorY);


};

