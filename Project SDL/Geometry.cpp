#include "Geometry.h"

Geometry::Geometry(int width, int height)
{
	m_x = 0;
	m_y = 0;
	m_width = width;
	m_height = height;

	m_color = { rand() % 256, rand() % 256, rand() % 256, 255 };
}

void Geometry::SetPosition(const Vector2f& position, float anchorX, float anchorY)
{
	SetPosition(position.x, position.y, anchorX, anchorY);
}

void Geometry::SetPosition(float x, float y, float anchorX, float anchorY)
{
	m_x = x - (m_width * anchorX);
	m_y = y - (m_height * anchorY);
}

Vector2f Geometry::GetPosition(float anchorX, float anchorY) const
{
	Vector2f pos;

	pos.x = m_x + (m_width * anchorX);
	pos.y = m_y + (m_height * anchorY);

	return pos;
}

void Geometry::Resize(int width, int height)
{
	m_width = width;
	m_height = height;
}

void Geometry::Move(float x, float y)
{
	m_x += x;
	m_y += y;
}
