#pragma once
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <string>
#include "Vector2.h"
#include "Color.h"

namespace sdl {
	class Texture {
	public:
		Texture();
		~Texture();
		bool loadFromFile(const std::string &path);
		Vector2Float getSize();
		SDL_Surface* getSurface();
		sdl::Color getPixel(sdl::Vector2Float &pixel);
		void setPixel(sdl::Vector2Float &pixel, sdl::Color& color);
		bool hasChanged(bool reset);
	private:
		SDL_Surface* surface;
		int changes;
		int proof;
		bool loaded;
	};
}
