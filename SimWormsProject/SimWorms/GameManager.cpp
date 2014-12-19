#include "GameManager.h"

GameManager::GameManager() {
	tour = 0;
	playerIsOnGround = false;
	numberPlayer = 0;
}

void GameManager::startGame(int numberTeam) {
	for (int i = 0; i < numberTeam; i++) {
		for (int j = 0; j < 4; j++) {
			EntityManager::getInstance().addEntity(new Player(sdl::Vector2Float(800, 200), i, j));
			EntityManager::getInstance().addEntity(new Mine(sdl::Vector2Float(100, 200)));
			numberPlayer++;
		}
	}
}

void GameManager::update(sdl::Window& renderWindow, Camera* cam, Map* actualMap, float frametime) {
	SDL_Event event;

	if (tourClock.getElapsedTime().asSeconds() > 85) {
		tour = (tour + 1) & (numberPlayer);
	}

	while (renderWindow.pollEvent(event)){
		EventManager::getInstance().launchEvent(event);
		if (event.type == SDL_WINDOWEVENT)
			if (event.window.event == SDL_WINDOWEVENT_CLOSE)
				renderWindow.close();
		if (event.type == SDL_KEYDOWN)
			if (event.key.keysym.sym == SDLK_ESCAPE)
				renderWindow.close();

		if (event.key.keysym.sym == SDLK_q){
			EntityManager::getInstance().addEntity(new HealPack(sdl::Mouse::getPosition(cam->getView())));
		}
		if (event.key.keysym.sym == SDLK_g){
			EntityManager::getInstance().addEntity(new Grenade(sdl::Mouse::getPosition(cam->getView()), sdl::Vector2Float(0, 0), 0, 5));
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
			cam->proceedZoom(event.wheel.y);

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
		(*EntityManager::getInstance().getEntities().begin())->setPosition(sdl::Mouse::getPosition(cam->getView()));
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
	cam->update(renderWindow);
	actualMap->draw(renderWindow);

	EntityManager::getInstance().update(frametime, actualMap->terrain, renderWindow);

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

}

int GameManager::getTour() {
	return this->tour;
}

void GameManager::setTour(int tour) {
	this->tour = tour;
	tourClock.restart();
}

int GameManager::getNumberPlayer() {
	return this->numberPlayer;
}

void GameManager::setNumberPlayer(int numberPlayer) {
	this->numberPlayer = numberPlayer;
}