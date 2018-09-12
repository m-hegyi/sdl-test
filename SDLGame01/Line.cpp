#include "Line.hpp"
#include <iostream>

void Line::render() {
	SDL_SetRenderDrawColor(m_engine->getRenderer(), 255, 255, 255, 255);
	SDL_RenderDrawLine(m_engine->getRenderer(), (int)m_start.getX(), (int)m_start.getY(), 
		(int)m_end.getX(), (int)m_end.getY());

}
