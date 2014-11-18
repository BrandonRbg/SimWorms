#include "VideoMode.h"

std::vector<sdl::VideoMode> sdl::VideoMode::modes;

sdl::VideoMode::VideoMode(){
	SDL_GetDisplayMode(0, 0, &dm);
	this->h = dm.h;
	this->w = dm.w;
}

sdl::VideoMode::VideoMode(unsigned int w, unsigned int h){
	this->w = w;
	this->h = h;
	dm = { SDL_PIXELFORMAT_RGBA8888, this->w, this->h, 0, 0 };
}

std::vector<sdl::VideoMode>& sdl::VideoMode::getModes(){
	SDL_DisplayMode tmp;
	int nummodes = SDL_GetNumDisplayModes(0);
	for (int j = 0; j < nummodes; ++j) {
		SDL_GetDisplayMode(0, j, &tmp);
		modes.push_back(sdl::VideoMode(tmp.w, tmp.h));
	}
	return modes;
}

