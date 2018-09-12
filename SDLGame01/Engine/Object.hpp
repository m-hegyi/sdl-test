#pragma once
#include <SDL.h>

class SDLObject {

public:
	virtual void render() = 0;
	virtual void update() = 0;

protected:
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
};