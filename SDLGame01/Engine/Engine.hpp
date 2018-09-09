#pragma once
#include <SDL.h>
#include <string>
#include <vector>

#include "Object.hpp"

namespace SDLEngine {

	class Engine {
	public:
		Engine();

		bool init(std::string title, int xPos, int yPos, int width, int height, Uint32 windowFlags);
		bool isRunning() { return m_isRunning; };

		void handleEvent();
		void update();
		void render();

		void quit();

		SDL_Renderer* getRenderer() const { return m_renderer; }

		std::string getError();
	private:
		bool m_isRunning;
		int m_screenWidth;
		int m_screenHeight;
		Uint32 m_startTime;

		Uint32 m_diffTime;

		std::string m_errorMsg;

		Uint32* m_pixels;

		SDL_Event m_event;
		SDL_Texture* m_texture;
		SDL_Renderer* m_renderer;
		SDL_Window* m_window;

		std::vector<SDLObject*> m_objects;
	};
}