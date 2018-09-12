#include "Point.hpp"

bool Point::init()
{
	m_pixels = new Uint32[1];

	memset(m_pixels, 255, sizeof(Uint32));

	m_renderer = m_engine->getRenderer();

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, 1, 1);

	if (m_texture == NULL) {
		return false;
	}

	return true;
}

void Point::render() {
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_Rect dist;
	dist.x = m_x;
	dist.y = m_y;
	dist.w = 1;
	dist.h = 1;

	SDL_UpdateTexture(m_texture, NULL, m_pixels, sizeof(Uint32));

	SDL_RenderCopy(m_renderer, m_texture, NULL, &dist);
}
