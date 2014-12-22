#include "GameState.h"


GameState::GameState(sdl::Window &target, int numberTeam)
{
	actualMap = new Map(MapManager::getInstance().getActualMap());
	cam = new Camera(target, actualMap);
	GameManager::getInstance().startGame(numberTeam);
}

void GameState::update(sdl::Window &target, float frametime) {
	weaponMenu.update(target);
	weaponMenu.draw(target);
	GameManager::getInstance().setUseObject(weaponMenu.WeaponSelected());
	if (GameManager::getInstance().getMenuPause()) {
		pause.update(target);
		pause.draw(target);
	}
	GameManager::getInstance().update(target, cam, actualMap, frametime);
}

void GameState::draw(sdl::Window &target) {
	actualMap->draw(target);
}

GameState::~GameState() {
	delete cam;
	delete actualMap;
}