#include "Dot.hpp"

Dot::Dot(int x, int y, int radius) : m_x(x), m_y(y), m_radius(radius) {
	
}

bool Dot::init() {
	m_pixels = new Uint32[m_radius * 2 * m_radius * 2];

	memset(m_pixels, 255, m_radius * 2 * m_radius * 2 * sizeof(Uint32));

	m_renderer = m_engine->getRenderer();
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC,
		m_radius * 2, m_radius * 2);
	if (m_texture == NULL) {
		return false;
	}

	return true;
}

void Dot::update() {
	Vector2D* mousePos = new Vector2D(12.f, 12.f);
	mousePos = m_engine->getInputHandler()->getMousePosition();

	m_x = (int)mousePos->getX();
	m_y = (int)mousePos->getY();
}

void Dot::render() {
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

	SDL_UpdateTexture(m_texture, NULL, m_pixels, m_radius * 2 * sizeof(Uint32));

	SDL_Rect dist;
	dist.x = m_x;
	dist.y = m_y;
	dist.w = m_radius * 2;
	dist.h = m_radius * 2;

	SDL_RenderCopy(m_renderer, m_texture, NULL, &dist);

	for (int i = 1; i < 90; i++) {
		SDL_RenderCopyEx(m_renderer, m_texture, NULL, &dist, i, NULL, SDL_FLIP_NONE);
	}
}
