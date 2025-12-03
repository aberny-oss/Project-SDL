#pragma once
#include "Geometry.h"
class Circle : public Geometry
{
private:
	int m_precision;

public:
	Circle(int radius, int precision) : Geometry(radius * 2, radius * 2)
	{
		m_precision = precision;
	}

};

