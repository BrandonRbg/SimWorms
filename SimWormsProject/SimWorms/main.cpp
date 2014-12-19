#include <sstream>
#include <time.h>

#include "OOSDL/OOSDL.h"

#include "GameOptionsManager.h"
#include "EventManager.h"
#include "ScreenStateManager.h"
#include "SplashScreenState.h"

int main(int argc, char** argv){
	srand(time(0));
	SDL_StartTextInput();
	sdl::Window renderWindow(sdl::VideoMode(1280, 1024), "SimWorms", false);
	GameOptionsManager::getInstance().update(renderWindow);

	ScreenStateManager::getInstance().pushScreenState(new SplashScreenState);

	sdl::StaticText fpsText;
	fpsText.setFont("data/fonts/Arial.ttf");
	fpsText.setPosition(10, 10);
	fpsText.setCharacterSize(16);
	fpsText.setColor(sdl::Color::White);
	fpsText.setString("");

	sdl::Clock fpsClock;
	sdl::Clock fpsDisplayUpdateClock;

	while (renderWindow.isOpen()){
		float frametime = fpsClock.restart().asSeconds();
		int fps = (int)(1 / frametime);
		SDL_Event event;

		while (renderWindow.pollEvent(event)){
			EventManager::getInstance().launchEvent(event);
			if (event.type == SDL_WINDOWEVENT)
				if (event.window.event == SDL_WINDOWEVENT_CLOSE)
					renderWindow.close();
			if (event.type == SDL_KEYDOWN)
				if (event.key.keysym.sym == SDLK_ESCAPE)
					renderWindow.close();
		}
		renderWindow.clear(sdl::Color::White);

		ScreenStateManager::getInstance().update(renderWindow, frametime);
		ScreenStateManager::getInstance().draw(renderWindow);

		if (fpsDisplayUpdateClock.getElapsedTime().asSeconds() > 0.2) {
			std::stringstream ss;
			ss << "SimWorms v0.0.1" << " @ " << fps << " fps";
			fpsText.setString(ss.str());
			fpsDisplayUpdateClock.restart();
		}


		renderWindow.draw(&fpsText);

		renderWindow.show();
	}
	SDL_StopTextInput();
	return 0;
}