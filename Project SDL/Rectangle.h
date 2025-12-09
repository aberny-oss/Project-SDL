#pragma once

#include "Geometry.h"


class Rectangle : public Geometry
{
public:
	Rectangle(int width, int height);

	void Draw(SDL_Renderer* renderer) override;

	Vector2f GetRadius() const override;
};

