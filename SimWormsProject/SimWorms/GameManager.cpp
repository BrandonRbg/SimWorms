#include "GameManager.h"

GameManager::GameManager() {
	tour = 0;
	numberPlayer = 0;
	numberPlayerOnGround = 0;
	useObject = 0;
	menuPause = false;
	tourText.setFont("data/fonts/Arial.ttf");
	tourText.setPosition(1240, 10);
	tourText.setCharacterSize(30);
	tourText.setColor(sdl::Color::White);
	tourText.setString("");
	useItem = 0;
}

void GameManager::startGame(int numberTeam) {
	std::default_random_engine engine;
	std::uniform_int_distribution<int> dist(15, 1265);
	for (int i = 0; i < 4 * numberTeam; i++) {
		EntityManager::getInstance().addEntity(new Player(sdl::Vector2Float(dist(engine), 0), i)); // doit être random en x
		numberPlayer++;
	}
	for (int i = 0; i < MapManager::getInstance().getActualMap().landMinesCount; i++) {
		EntityManager::getInstance().addEntity(new Mine(sdl::Vector2Float(dist(engine), 0))); // doit être random en x
	}
}

void GameManager::update(sdl::Window& renderWindow, Camera* cam, Map* actualMap, float frametime) {
	if (EntityManager::getInstance().first) {
		for (auto& it : EntityManager::getInstance().getEntities()) {
			Player* tmp = dynamic_cast<Player*>(it);
			if (tmp != 0 && tmp->isOnGround) {
				numberPlayerOnGround++;
			}
		}
		if (numberPlayerOnGround == numberPlayer) {
			EntityManager::getInstance().first = false;
		}
		else {
			numberPlayerOnGround = 0;
		}
	}
	if (!menuPause) {
		if (tourClock.getElapsedTime().asSeconds() > 85) {
			tour = (tour + 1) & (numberPlayer);
			tourClock.restart();
			MapManager::getInstance().getActualMap().updateWindForce();
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
		actualMap->update();
		actualMap->draw(renderWindow);
		cam->update(renderWindow);


		EntityManager::getInstance().update(frametime, actualMap->terrain, renderWindow);

		std::stringstream ss;
		ss << 85 - tourClock.getElapsedTime().asSeconds();
		tourText.setString(ss.str());

		renderWindow.draw(&tourText);

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
	MapManager::getInstance().getActualMap().updateWindForce();
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