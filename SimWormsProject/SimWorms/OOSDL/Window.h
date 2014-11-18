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
<<<<<<< HEAD
=======
#include "VideoMode.h"
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011

namespace sdl{
	class Window
	{
	public:
<<<<<<< HEAD
		Window(float x, float y, const std::string& title, Uint32 flags);
		Window(sdl::Vector2Float vect, const std::string& title, Uint32 flags) : sdl::Window((int)vect.x, (int)vect.y, title, flags) {}
		~Window();

=======
		Window(sdl::VideoMode vm, const std::string& title, bool fs);
		~Window();

		void setVideoMode(sdl::VideoMode vm);
		void setFullScreen(bool fs);

>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
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
<<<<<<< HEAD
=======
		bool isOnFullscreen;
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
	private:
		static int instances;
	};

}