#pragma once

#include "Object.hpp"
#include "Engine.hpp"

class BaseObject : public SDLObject {
public:
	void setEngine(Engine* engine) { m_engine = engine; }
	virtual void render() = 0;
	virtual void update() = 0;
	virtual bool init() = 0;

	Vector2D getPosition() const { return Vector2D((float)m_x, (float)m_y); }
	int getX() const { return m_x; }
	int getY() const { return m_y; }

protected:
	Engine* m_engine;

	int m_x;
	int m_y;
	int m_width;
	int m_height;
};