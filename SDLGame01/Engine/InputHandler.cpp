#include "InputHandler.hpp"

InputHandler::InputHandler() {
	m_mousePosition = new Vector2D();
}

bool InputHandler::update() {
	SDL_Event event;


	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			return false;
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
		default:
			break;
		}
	}

	return true;
}

void InputHandler::onMouseMove(SDL_Event event) {
	m_mousePosition->setX((float)event.motion.x);
	m_mousePosition->setY((float)event.motion.y);
}
