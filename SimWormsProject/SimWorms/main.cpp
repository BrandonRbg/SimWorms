#include <sstream>
#include <time.h>

#include "OOSDL/OOSDL.h"

#include "AssetsManager.h"
#include "GameOptionsManager.h"
#include "Player.h"
#include "EventManager.h"
#include "Gui/GuiTextBox.h"
#include "Gui/GuiMainMenu.h"
#include "Grenade.h"
#include "HealPack.h"

#include "Camera.h"

#include "MapManager.h"

int main(int argc, char** argv){
	srand(time(0));
	SDL_StartTextInput();
	sdl::Window renderWindow(sdl::VideoMode(1280, 1024), "SimWorms", false);
	GameOptionsManager::getInstance().update(renderWindow);

	MapManager::getInstance().loadMapsFromFolder("data/maps");
	Map actualMap = MapManager::getInstance().getActualMap();

	Camera cam(renderWindow, actualMap);

	//PhysicsPixel pixel(sdl::Color::Black, sdl::Vector2Float(100, 100), sdl::Vector2Float(0, 0));


	//GuiMainMenu Game;
	//GuiTextBox Text;
	//Player player(sdl::Vector2Float(800,200));
	//view.setCenter(player.getPosition());

	sdl::StaticText fpsText;
	fpsText.setFont("data/fonts/Arial.ttf");
	fpsText.setPosition(10, 10);
	fpsText.setCharacterSize(16);
	fpsText.setColor(sdl::Color::Black);
	fpsText.setString("");

	sdl::Clock fpsClock;
	sdl::Clock fpsDisplayUpdateClock;

	EntityManager::getInstance().addEntity(new Player(sdl::Vector2Float(800, 200)));

	sdl::Clock runclock;
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

			if (event.key.keysym.sym == SDLK_q){
				EntityManager::getInstance().addEntity(new HealPack(sdl::Mouse::getPosition(cam.getView())));
			}
			//if (event.key.keysym.sym == SDLK_e){
			//	GameOptionsManager::getInstance().setVideoMode(sdl::VideoMode::getModes()[0]);
			//}/*
			//if (event.key.keysym.sym == SDLK_f){
			//	GameOptionsManager::getInstance().setFullScreen(true);
			//}
			//if (event.key.keysym.sym == SDLK_g){
			//	GameOptionsManager::getInstance().setFullScreen(false);
			//}
			//if (event.key.keysym.sym == SDLK_u){
			//	GameOptionsManager::getInstance().update(renderWindow);
			//}
			if (event.type == SDL_MOUSEWHEEL)
				cam.proceedZoom(event.wheel.y);

		}
		if (sdl::Mouse::isButtonPressed(SDL_BUTTON_LEFT)){
			/*if (sdl::Mouse::getPosition().x > 0 && sdl::Mouse::getPosition().x < terrain.getSize().x && sdl::Mouse::getPosition().y > 0 && sdl::Mouse::getPosition().y < terrain.getSize().y){
			ExplosionsManager::getInstance().addExplosion(sdl::Mouse::getPosition(view), terrain, rand() % 50 + 50);
			std::cout << sdl::Mouse::getPosition(view).x << ", " << sdl::Mouse::getPosition(view).y << std::endl;
			std::cout << sdl::Mouse::getPosition().x << ", " << sdl::Mouse::getPosition().y << std::endl;

			}*/

			//EntityManager::getInstance().addEntity(new Grenade(sdl::Mouse::getPosition(cam.getView()), sdl::Vector2Float(0,0), 0, 3));
			//EntityManager::getInstance().addEntity(new Explosion(sdl::Mouse::getPosition(cam.getView()), actualMap.terrain, 50));
			/*cam.goTo(sdl::Mouse::getPosition(cam.getView()));*/
			//actualMap.terrain.addPixel(sdl::Mouse::getPosition(cam.getView()), sdl::Color::Black);
		}
		if (sdl::Mouse::isButtonPressed(SDL_BUTTON_RIGHT)){
			(*EntityManager::getInstance().getEntities().begin())->setPosition(sdl::Mouse::getPosition(cam.getView()));
			//pixel.setPosition(sdl::Mouse::getPosition(cam.getView()));
		}
		/*if (sdl::Keyboard::isKeyPressed(SDLK_w))
		pixel.move(0, -500 * frametime);
		if (sdl::Keyboard::isKeyPressed(SDLK_a))
		pixel.move(-500 * frametime, 0);
		if (sdl::Keyboard::isKeyPressed(SDLK_s))
		pixel.move(0, 500 * frametime);
		if (sdl::Keyboard::isKeyPressed(SDLK_d))
		pixel.move(500 * frametime, 0);*/
		renderWindow.clear(sdl::Color::White);
		cam.update(renderWindow);
		actualMap.draw(renderWindow);

		EntityManager::getInstance().update(frametime, actualMap.terrain, renderWindow);

		if (fpsDisplayUpdateClock.getElapsedTime().asSeconds() > 0.2) {
			std::stringstream ss;
			ss << "SimWorms v0.0.1" << " @ " << fps << " fps";
			fpsText.setString(ss.str());
			fpsDisplayUpdateClock.restart();
		}
		//	Game.update(renderWindow);
		//Game.draw(renderWindow);
		/*Text.update(renderWindow);
		Text.draw(renderWindow);*/
		/*player.update(frametime, terrain);
		player.draw(renderWindow);*/

		/*pixel.update(frametime, actualMap.terrain);
		if (pixel.isDead())
		std::cout << "DEAD";
		pixel.draw(renderWindow);*/

		renderWindow.draw(&fpsText);

		renderWindow.show();
	}
	SDL_StopTextInput();
	return 0;
}