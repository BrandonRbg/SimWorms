#pragma once
#include "Text.h"

namespace sdl{
	class StaticText : public Text
	{
	public:
		StaticText(const std::string &text, const std::string &fontPath, int characterSize = 25) : Text(text, fontPath, characterSize){};
		StaticText() : Text("", ""){};
		void draw(SDL_Renderer* renderer, sdl::View &view);
	};
}

