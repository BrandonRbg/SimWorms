#include "GameState.h"
#include "ScreenStateManager.h"
#include "PauseMenuState.h"

GameState::GameState(sdl::Window &target, std::vector<Team> teams)
{
	cam = new Camera(target, MapManager::getInstance().getActualMap());
	GameManager::getInstance().startGame(teams);
	EventManager::getInstance().addCallbackToID(SDL_KEYDOWN, std::bind(&GameState::onKeyPressed, this, std::placeholders::_1));
}

void GameState::update(sdl::Window &target, float frametime) {
	if (!paused){
		cam->update(target);
		weaponMenu.update(target);
	}

	GameManager::getInstance().update(target, cam, MapManager::getInstance().getActualMap(), frametime);
	EntityManager::getInstance().update(frametime, MapManager::getInstance().getActualMap()->terrain, target, cam);
}

void GameState::onKeyPressed(SDL_Event event){
	if (event.key.keysym.sym == SDLK_ESCAPE){
		if (!paused){
			ScreenStateManager::getInstance().pushScreenState(new PauseMenuState());
			pause(true);
		}
	}
}

void GameState::draw(sdl::Window &target) {
	target.clear(sdl::Color::White);
	MapManager::getInstance().draw(target);
	GameManager::getInstance().draw(target);
	EntityManager::getInstance().draw(target);
	weaponMenu.draw(target);
}

GameState::~GameState() {
	delete cam;
}