#pragma once

class Vector2D {
public:
	Vector2D() : m_x(0), m_y(0) {};
	Vector2D(float x, float y) : m_x(x), m_y(y) {};

	float getX() const { return m_x; }
	float getY() const { return m_y; }

	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

private:
	float m_x;
	float m_y;
};