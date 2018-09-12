#pragma once

#include "Engine/BaseObject.hpp"
#include "Engine/Vector2.hpp"

class Line : public BaseObject {
public:
	Line(Vector2D start, Vector2D end) : m_start(start), m_end(end) {};
	bool init() override { return true; };
	void render() override;
	void update() override {};

private:
	Vector2D m_start;
	Vector2D m_end;
};