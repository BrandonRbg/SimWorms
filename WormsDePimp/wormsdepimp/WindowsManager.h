#pragma once
#include "Window.h"
#include <list>
namespace sdl{
	class WindowsManager
	{
	public:
		WindowsManager();
		~WindowsManager();

		void append(sdl::Window *window);
		void remove(sdl::Window *window);

		void update();
		sdl::Window* getWindowByID(unsigned int windowID);
	private:
		std::list<sdl::Window*> windows;
	};
}

