#pragma once
#include "Geometry.h"
class Circle : public Geometry
{
public:
	Circle(int x, int y, int width, int height)
		: Geometry(x, y, width, height)
	{}

};

