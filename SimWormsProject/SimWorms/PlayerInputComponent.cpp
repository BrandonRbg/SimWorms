#include "PlayerInputComponent.h"
#include "Player.h"
void PlayerInputComponent::update(Player &player){
	if (sdl::Keyboard::isKeyReleased(GameOptionsManager::getInstance().getKeyControl("left"))){
		player.stop();
	}
	if (sdl::Keyboard::isKeyReleased(GameOptionsManager::getInstance().getKeyControl("right"))){
		player.stop();
	}
	if (sdl::Keyboard::isKeyPressed(GameOptionsManager::getInstance().getKeyControl("left"))){
		player.moveLeft();
	}
	if (sdl::Keyboard::isKeyPressed(GameOptionsManager::getInstance().getKeyControl("right"))){
		player.moveRight();
	}
}