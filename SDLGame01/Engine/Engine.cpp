#include "Engine.hpp"
#include <iostream>

using namespace SDLEngine;

Engine::Engine() {
	m_startTime = 0;
	m_diffTime = 0;
}

bool SDLEngine::Engine::init(std::string title, int xPos, int yPos, int width, int height, Uint32 windowFlags) {

	m_screenWidth = width;
	m_screenHeight = height;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		m_errorMsg = "SDL init failed";
		return false;
	}
	else {
		m_window = SDL_CreateWindow(title.c_str(), xPos, yPos, width, height, windowFlags);

		if (m_window == NULL) {
			m_errorMsg = "SDL Window create failed";
			return false;
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, 0);

		if (m_renderer == NULL) {
			m_errorMsg = "SDL renderer create failed";
			return false;
		}

		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, m_screenWidth, m_screenHeight);

		if (m_texture == NULL) {
			m_errorMsg = "SDL texture create failed";
			return false;
		}
	}

	m_pixels = new Uint32[m_screenWidth * m_screenHeight];

	memset(m_pixels, 255, m_screenWidth * m_screenHeight * sizeof(Uint32));

	m_isRunning = true;
	return true;
}

void Engine::handleEvent() {
	while (SDL_PollEvent(&m_event)) {
		switch (m_event.type) {
		case SDL_QUIT:
			m_isRunning = false;
			break;
		default:
			break;
		}
	}
}

void Engine::update() {
	for (int i = 0; i < m_objects.size(); i++) {
		m_objects[i]->update();
	}
}

void Engine::render() {
	// háttérszín
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);

	for (int x = 0; x < m_screenWidth; x++) {

		Uint8 color = (int)((x + 1) * 255) / m_screenWidth;



		for (int y = 0; y < m_screenHeight; y++) {
			// Uint8 color2 = (int)((y + 1) * 255) / m_screenHeight;
			m_pixels[y * m_screenWidth + x] = color << 16;
		}
	}
	SDL_UpdateTexture(m_texture, NULL, m_pixels, (m_screenWidth * sizeof(Uint32)));

	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);

	SDL_RenderPresent(m_renderer);
}

void Engine::quit() {
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}
