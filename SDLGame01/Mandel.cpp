#include "Mandel.hpp"
#include <iostream>

bool Mandel::init()
{
	m_centerPoint.setX((int)m_width / 2);
	m_centerPoint.setY((int)m_height / 2);

	m_pixels = new Uint32[m_width * m_height];

	memset(m_pixels, 255, m_width * m_height * sizeof(Uint32));

	m_resolution = 4;

	m_texture = SDL_CreateTexture(m_engine->getRenderer(), 
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, m_width, m_height);

	calculate();

	if (m_texture == NULL) {
		return false;
	}
	return true;
}

void Mandel::render() {
	/*for (int x = 0; x < m_width; x++) {
		Uint8 color = (int)((x + 1) * 255) / m_width;
		for (int y = 0; y < m_height; y++) {
			m_pixels[x + y * m_width] = color << 16;
		}
	}*/

	SDL_UpdateTexture(m_texture, NULL, m_pixels, m_width * sizeof(Uint32));

	SDL_RenderCopy(m_engine->getRenderer(), m_texture, NULL, NULL);
}

void Mandel::calculate() {
	// 0 position at 320, 240
	// base 100 pixel = 1
	// -x -> m_x < 320
	// -y -> m_y < 240
	// x Min: -3,2 Max: 3,2
	// y Min: -2,4 Max: 2,4
	
	// test x => y = 0  z*z+c
	//float pos = ((0 - m_centerPoint.getX()) - 0) / (m_unit * m_zoom);
	for (int x = 0; x < m_width; x++) {
		// if x = 0 pos is -3.2
		float pos = ((0 - m_centerPoint.getX()) + x) / (m_unit * m_zoom);
		if (!iterate(pos, 0.f)) {

		}

	}

}

bool Mandel::iterate(float xPos, float yPos) {
	// 3 times
	

	return false;
}
