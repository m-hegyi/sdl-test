#pragma once
#include <SDL.h>
#include <vector>

#include "Vector2.hpp"

enum mouse_buttons {
	MOUSE_LEFT,
	MOUSE_MIDDLE,
	MOUSE_RIGHT
};

class InputHandler {

public:
	InputHandler();
	bool update();
	void clean() {};

	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition() { return m_mousePosition; };

private:
	void onMouseMove(SDL_Event event);

private:
	Vector2D* m_mousePosition;
};