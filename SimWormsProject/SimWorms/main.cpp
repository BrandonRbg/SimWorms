#include <sstream>

#include "OOSDL/OOSDL.h"
#include "OOSDL/StaticSprite.h"
#include "Terrain.h"
#include "AssetsManager.h"

int main(int argc, char** argv){
	sdl::Window renderWindow(800, 600, "SimWorms", 0);
	Terrain terrain;
	terrain.loadTerrainFromFile("Maps/farm/map.png");
	sdl::StaticSprite bg;
	bg.setTexture(&AssetsManager::getInstance().getTexture("Maps/farm/background.jpg"));
	sdl::View view;
	view = renderWindow.getDefaultView();

	sdl::StaticText fpsText;
	fpsText.setFont("Arial.ttf");
	fpsText.setPosition(10, 10);
	fpsText.setCharacterSize(16);
	fpsText.setColor(sdl::Color::Black);
	fpsText.setString("");

	sdl::Clock fpsClock;
	sdl::Clock fpsDisplayUpdateClock;
	while (renderWindow.isOpen()){
		int fps = (int)(1 / fpsClock.restart().asSeconds());
		SDL_Event event;
		
		while (renderWindow.pollEvent(event)){
			if (event.type == SDL_WINDOWEVENT)
			if (event.window.event == SDL_WINDOWEVENT_CLOSE)
				renderWindow.close();
			if (event.type == SDL_KEYDOWN)
			if (event.key.keysym.sym == SDLK_ESCAPE)
				renderWindow.close();
		}
		if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
			if (sdl::Mouse::getPosition().x > 0 && sdl::Mouse::getPosition().x < terrain.getWidth() && sdl::Mouse::getPosition().y > 0 && sdl::Mouse::getPosition().y < terrain.getHeight()){
				terrain.explode(sdl::Mouse::getPosition(view), 50, 3, sdl::Color::Black);
				std::cout << sdl::Mouse::getPosition(view).x << ", " << sdl::Mouse::getPosition(view).y << std::endl;
			}
		}
		if (sdl::Keyboard::isKeyPressed(SDLK_w))
			view.move(0, -10);
		if (sdl::Keyboard::isKeyPressed(SDLK_a))
			view.move(-10, 0);
		if (sdl::Keyboard::isKeyPressed(SDLK_s))
			view.move(0, 10);
		if (sdl::Keyboard::isKeyPressed(SDLK_d))
			view.move(10, 0);
		renderWindow.clear(sdl::Color::White);
		renderWindow.setView(view);
		renderWindow.draw(&bg);
		terrain.draw(renderWindow);

		if (fpsDisplayUpdateClock.getElapsedTime().asSeconds() > 0.2) {
			std::stringstream ss;
			ss << "SimWorms v0.0.1" << " @ " << fps << " fps";
			fpsText.setString(ss.str());
			fpsDisplayUpdateClock.restart();
		}
		renderWindow.draw(&fpsText);

		renderWindow.show();
	}
	return 0;
}