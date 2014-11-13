#pragma once
#include "Text.h"

namespace sdl{
	class StaticText : public Text
	{
	public:
		void draw(SDL_Renderer* renderer, sdl::View &view);
	};
}

