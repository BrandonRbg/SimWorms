#include "WindowsManager.h"


sdl::WindowsManager::WindowsManager()
{
}


sdl::WindowsManager::~WindowsManager()
{
	std::list<sdl::Window*>::iterator it;
	for (it = windows.begin(); it != windows.end(); ++it)
		delete *it;
}

void sdl::WindowsManager::append(sdl::Window *window){
	windows.push_back(window);
}

void sdl::WindowsManager::remove(sdl::Window *window){
	windows.remove(window);
}

void sdl::WindowsManager::update(){
	std::list<sdl::Window*>::iterator it;
	for (it = windows.begin(); it != windows.end(); ++it)
		(*it)->show();
}
sdl::Window* sdl::WindowsManager::getWindowByID(unsigned int windowID){
	std::list<sdl::Window*>::iterator it;
	for (it = windows.begin(); it != windows.end(); ++it)
		if ((*it)->windowID == windowID)
			return (*it);
	return nullptr;
}