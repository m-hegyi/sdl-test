#pragma once

#include "Engine/BaseObject.hpp"
#include "Engine/Vector2.hpp"

class Mandel : public BaseObject {
public:
	Mandel(int width, int height) { m_width = width; m_height = height; }
	bool init() override;
	void update() override {};
	void render() override;

	bool iterate(float xPos, float yPos);

	float iterator(float number);

	void calculate();
private:
	Vector2D m_centerPoint;

	int m_zoom = 1;
	// if the zoom is van 1 unit is 100 pixel
	const int m_unit = 100;

	Uint32* m_pixels;
	int m_resolution;
};