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
	Geometry(int width, int height);

	virtual void Draw(SDL_Renderer* renderer) = 0;

	void SetPosition(const Vector2& position, float anchorX = 0.5f, float anchorY = 0.5f);
	void SetPosition(int x, int y, float anchorX, float anchorY);

	Vector2 GetPosition(float anchorX, float anchorY);

	virtual void Resize(int width, int height);


};

