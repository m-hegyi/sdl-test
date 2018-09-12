#pragma once

#include "Engine/BaseObject.hpp"

class Point : public BaseObject {
public:
	Point(int x, int y) { m_x = x; m_y = y; };
	bool init() override;
	void render() override;
	void update() override {};
	
private:
	Uint32* m_pixels;
};