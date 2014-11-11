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

namespace sdl{
	class Window
	{
	public:
		Window(float x, float y, const std::string& title);
		Window(sdl::Vector2Float vect, const std::string& title) : sdl::Window((int)vect.x, (int)vect.y, title) {}
		~Window();

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
	private:
		static int instances;
	};

}