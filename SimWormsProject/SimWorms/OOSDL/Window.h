#pragma once

#include <string>
#include <list>
#include <iostream>

#include <SDL2/SDL.h>

#include "Vector2.h"
#include "Color.h"
#include "Drawable.h"
#include "View.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "VideoMode.h"

namespace sdl{
	class Window
	{
	public:
		Window(sdl::VideoMode vm, const std::string& title, bool fs);
		~Window();

		void setVideoMode(sdl::VideoMode vm);
		void setFullScreen(bool fs);

		void draw(sdl::Drawable* drawable);
		void clear();
		void clear(sdl::Color& color);
		void show();
		void setTitle(const std::string& title);
		void setView(sdl::View &view);

		sdl::View getDefaultView();
		bool pollEvent(SDL_Event &event);

		bool isOpen();
		void close();

		unsigned int windowID;

		SDL_Renderer* getRenderer();
		sdl::View getView();
	protected:
		sdl::Vector2Float size;

		std::string title;
		std::list <sdl::Drawable*> drawables;
		SDL_Window* sdlWindow;
		SDL_Renderer* sdlRender;
		
		sdl::View view;

		bool isWindowOpen;
		bool isOnFullscreen;
	private:
		static int instances;
	};

}