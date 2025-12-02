#include "Geometry.h"

void Geometry::SetPosition(int x, int y, float anchorX, float anchorY)
{
	m_x = x - (m_width * anchorX);
	m_y = y - (m_width * anchorY);
}

Vector2 Geometry::GetPosition(float anchorX, float anchorY)
{
	Vector2 pos;

	pos.x = m_x + (m_width * anchorX);
	pos.y = m_y + (m_height * anchorY);

	return pos;
}
