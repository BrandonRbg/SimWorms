#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
namespace sdl{
	class VideoMode
	{
	public:
		VideoMode();
		VideoMode(unsigned int w, unsigned int h);
		
		static std::vector<VideoMode>& getModes();
		
		unsigned int w;
		unsigned int h;
		SDL_DisplayMode dm;

		static std::vector<VideoMode> modes;
	};
}
