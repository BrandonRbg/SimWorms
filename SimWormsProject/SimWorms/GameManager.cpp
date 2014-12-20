#include "GameManager.h"

GameManager::GameManager() {
	tour = 0;
	playerIsOnGround = false;
	numberPlayer = 0;
	useObject = 0;
	menuPause = false;
	fpsText.setFont("data/fonts/Arial.ttf");
	fpsText.setPosition(1240, 10);
	fpsText.setCharacterSize(30);
	fpsText.setColor(sdl::Color::White);
	fpsText.setString("");
	useItem = 0;
}

void GameManager::startGame(int numberTeam) {
	for (int i = 0; i < 4 * numberTeam; i++) {
		EntityManager::getInstance().addEntity(new Player(sdl::Vector2Float(800, 200), i));
		EntityManager::getInstance().addEntity(new Mine(sdl::Vector2Float(100, 200)));
		numberPlayer++;
	}
}

void GameManager::update(sdl::Window& renderWindow, Camera* cam, Map* actualMap, float frametime) {
	if (!menuPause) {
		if (tourClock.getElapsedTime().asSeconds() > 85) {
			tour = (tour + 1) & (numberPlayer);
		}

		if (sdl::Keyboard::isKeyPressed(SDLK_RIGHT) || sdl::Keyboard::isKeyPressed(SDLK_LEFT) || sdl::Keyboard::isKeyPressed(SDLK_SPACE)) {
			for (auto& it : EntityManager::getInstance().getEntities()) {
				Player* tmp = dynamic_cast<Player*>(it);
				if ((tmp != 0) && (tmp->getRank() == tour)) {
					cam->goTo(tmp->getPosition());
				}
			}
		}

		if (useObject == 1 || useItem == 1) {
			if (sdl::Mouse::isButtonReleased(SDL_BUTTON_LEFT)) {
				for (auto& it : EntityManager::getInstance().getEntities()) {
					Player* tmp = dynamic_cast<Player*>(it);
					if ((tmp != 0) && (tmp->getRank() == tour)) {
						//Rocket
					}
				}
			}
		}
		if (useObject == 2 || useItem == 2) {
			if (sdl::Mouse::isButtonReleased(SDL_BUTTON_LEFT)) {
				for (auto& it : EntityManager::getInstance().getEntities()) {
					Player* tmp = dynamic_cast<Player*>(it);
					if ((tmp != 0) && (tmp->getRank() == tour)) {
						//grenade
					}
				}
				useItem == 0;
			}
		}
		if (useObject == 3 || useItem == 3) {
			if (sdl::Mouse::isButtonReleased(SDL_BUTTON_LEFT)) {
				for (auto& it : EntityManager::getInstance().getEntities()) {
					Player* tmp = dynamic_cast<Player*>(it);
					if ((tmp != 0) && (tmp->getRank() == tour)) {
						if (tmp->getDirection()) {
							Melee shoot(sdl::Vector2Float(tmp->getBounds().x + tmp->getBounds().w + 5, tmp->getBounds().y + (tmp->getBounds().h / 2)));
							shoot.checkPlayerTouch(tmp, frametime);
						}
						else {
							Melee shoot(sdl::Vector2Float(tmp->getBounds().x - 50, tmp->getBounds().y + (tmp->getBounds().h / 2)));
							shoot.checkPlayerTouch(tmp, frametime);
						}
					}
				}
				useItem == 0;
			}
		}
		if (useObject == 4 || useItem == 4) {
			if (sdl::Keyboard::isKeyPressed(SDLK_SPACE)) {
				for (auto& it : EntityManager::getInstance().getEntities()) {
					Player* tmp = dynamic_cast<Player*>(it);
					if ((tmp != 0) && (tmp->getRank() == tour)) {
						tmp->setUseJetpack(true);
					}
				}
			}
			if (sdl::Keyboard::isKeyReleased(SDLK_SPACE)) {
				for (auto& it : EntityManager::getInstance().getEntities()) {
					Player* tmp = dynamic_cast<Player*>(it);
					if ((tmp != 0) && (tmp->getRank() == tour)) {
						tmp->setUseJetpack(false);
					}
				}
			}
		}

		if (useObject > 4) {
			useItem = useObject;
		}

		if (useObject < 0 && useObject < 5) {
			useItem == useObject;
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

		std::stringstream ss;
		ss << 85 - tourClock.getElapsedTime().asSeconds();
		fpsText.setString(ss.str());

		/*pixel.update(frametime, actualMap.terrain);
		if (pixel.isDead())
		std::cout << "DEAD";
		pixel.draw(renderWindow);*/
	}
	if (sdl::Keyboard::isKeyPressed(SDLK_ESCAPE)) {
		menuPause = true;
	}

	if (sdl::Keyboard::isKeyReleased(SDLK_ESCAPE)) {
		menuPause == false;
	}

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

bool GameManager::getMenuPause() {
	return this->menuPause;
}