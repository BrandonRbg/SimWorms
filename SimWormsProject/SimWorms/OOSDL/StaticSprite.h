#pragma once
#include "Sprite.h"

namespace sdl{
	class StaticSprite : public Sprite
	{
	public:
		void draw(SDL_Renderer* renderer, sdl::View &view);
	};
}

