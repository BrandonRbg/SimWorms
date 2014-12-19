#include "GameManager.h"

GameManager::GameManager() {
	tour = 0;
	playerIsOnGround = false;
	numberPlayer = 0;
}

void GameManager::startGame(int numberTeam) {
	for (int i = 0; i < 4 * numberTeam; i++) {
		EntityManager::getInstance().addEntity(new Player(sdl::Vector2Float(800, 200), i));
		EntityManager::getInstance().addEntity(new Mine(sdl::Vector2Float(100, 200)));
		numberPlayer++;
	}
}

void GameManager::update(sdl::Window& renderWindow, Camera* cam, Map* actualMap, float frametime) {
	if (tourClock.getElapsedTime().asSeconds() > 85) {
		tour = (tour + 1) & (numberPlayer);
	}

	if (sdl::Keyboard::isKeyPressed(SDLK_RIGHT) || sdl::Keyboard::isKeyPressed(SDLK_LEFT) || sdl::Keyboard::isKeyPressed(SDLK_SPACE)) {
		for (auto& it : EntityManager::getInstance().getEntities()) {
			Player* tmp = dynamic_cast<Player*>(it);
			if ((tmp != 0) && (tmp->getRank == tour)) {
				cam->goTo(tmp->getPosition());
			}
		}
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
	actualMap->draw(renderWindow);
	cam->update(renderWindow);
	

	EntityManager::getInstance().update(frametime, actualMap->terrain, renderWindow);

	weaponMenu.update(renderWindow);
	weaponMenu.draw(renderWindow);

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

int GameManager::getUseObject() {
	return this->useObject;
}

void GameManager::setUseObject(int useObject) {
	this->useObject = useObject;
}