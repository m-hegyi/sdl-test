#include <iostream>
#include <SDL.h>
#include <iostream>

#include "Engine/Engine.hpp"


int main(int argc, char* argv[]) {

	SDLEngine::Engine* engine = new SDLEngine::Engine();

	engine->init("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);

	while (engine->isRunning()) {
		engine->handleEvent();
		engine->update();
		engine->render();
		std::cout << SDL_GetTicks() << std::endl;
		SDL_Delay(10);
	}

	engine->quit();

	return 0;

}
