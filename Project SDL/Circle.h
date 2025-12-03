#pragma once
#include "Geometry.h"
class Circle : public Geometry
{
private:
	int m_radius;
	int m_precision;

public:
	Circle(int radius, int precision) : Geometry(radius * 2, radius * 2)
	{
		m_radius = radius;
		m_precision = precision;
	}

	void Draw(SDL_Renderer* renderer) override;

};

