#pragma once
#include <SDL.h>
#include <stdlib.h>     /* srand, rand */
#include "Math.h"

struct Color
{
	int r;
	int g;
	int b;
	int a;
};

class Geometry
{
protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;

	Color m_color;

public:
	Geometry(int width, int height);

	virtual void Draw(SDL_Renderer* renderer) = 0;

	void SetPosition(const Vector2f& position, float anchorX = 0.5f, float anchorY = 0.5f);
	void SetPosition(float x, float y, float anchorX = 0.5f, float anchorY = 0.5f);

	Vector2f GetPosition(float anchorX = 0.5f, float anchorY = 0.5f) const;

	virtual void Resize(int width, int height);

	void Move(float x, float y);


};

