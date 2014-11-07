#pragma once
#include "Vector2.h"
#include "Rect.h"
#include "View.h"

namespace sdl{
	class Drawable
	{
	public:
		virtual void draw(SDL_Renderer* renderer, sdl::View &view) = 0;
	};
}

