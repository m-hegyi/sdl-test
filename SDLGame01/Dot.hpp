#pragma once

#include "Engine/Engine.hpp"
#include "Engine/BaseObject.hpp"
#include "Engine/InputHandler.hpp"

class Dot : public BaseObject {
public:
	Dot(int x, int y, int radius);
	bool init();
	void update() override;
	void render() override;

private:
	Uint32* m_pixels;
	InputHandler* m_inputHandler;

	int m_x;
	int m_y;
	int m_radius;
};