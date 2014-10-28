#include <SDL2/SDL.h>

#include "Window.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Terrain.h"
#include "ExplosionsManager.h"
#include "Player.h"

int main(int argc, char** argv){
	sdl::Window renderWindow(sdl::Vector2Float(800, 600), std::string("Worms"));
	Terrain terrain;
	terrain.loadTerrainFromFile("map.png");

	Player player(50, 0);
	sdl::Clock frameClock;
	while (renderWindow.isOpen()){
		float frametime = frameClock.restart().asSeconds();
		SDL_Event* event = new SDL_Event();
		while (SDL_PollEvent(event)){
			if (event->type == SDL_WINDOWEVENT)
				if (event->window.event == SDL_WINDOWEVENT_CLOSE)
					renderWindow.close();
			if (event->type == SDL_KEYDOWN)
				sdl::Keyboard::updateKeyState(event->key.keysym.sym, true);
			if (event->type == SDL_KEYUP)
				sdl::Keyboard::updateKeyState(event->key.keysym.sym, false);
			if (event->type == SDL_MOUSEBUTTONDOWN)
				sdl::Mouse::updateMouseButtonState(event->button.button, true);
			if (event->type == SDL_MOUSEBUTTONUP)
				sdl::Mouse::updateMouseButtonState(event->button.button, false);
			if (event->type == SDL_MOUSEMOTION)
				sdl::Mouse::updateMousePosition(event->motion.x, event->motion.y);
		} delete event;
		float normalX, normalY;
		if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
			normalX = terrain.getNormalAtPosition(sdl::Mouse::getPosition()).x;
			normalY = terrain.getNormalAtPosition(sdl::Mouse::getPosition()).y;
			float normalModule = sqrt(pow(normalX, 2) + pow(normalY, 2));
			
			//std::cout << "Normal X: " << normalX << ", " << normalY << std::endl;
			if (sdl::Mouse::getPosition().x > 0 && sdl::Mouse::getPosition().x < terrain.getWidth() && sdl::Mouse::getPosition().y > 0 && sdl::Mouse::getPosition().y < terrain.getHeight()){
				ExplosionsManager::getInstance().addExplosion(sdl::Mouse::getPosition(), 150);
				terrain.explode(sdl::Mouse::getPosition(), 50);
			}

			
		}
		if (sdl::Mouse::isButtonPressed(SDL_BUTTON_RIGHT)){
			player.setX(sdl::Mouse::getPosition().x);
			player.setY(sdl::Mouse::getPosition().y);
		}
		renderWindow.clear();

		player.update(frametime);
		player.checkConstraints(terrain);
		player.draw(renderWindow);


		terrain.drawTerrain(renderWindow);
		ExplosionsManager::getInstance().update(renderWindow);
		renderWindow.show();
	}

	return 0;
}