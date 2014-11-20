#include "PlayerInputComponent.h"
#include "Player.h"
void PlayerInputComponent::update(Player &player){
	player.stop();
	if (sdl::Keyboard::isKeyPressed(GameOptionsManager::getInstance().getKeyControl("left")) && sdl::Keyboard::isKeyReleased(GameOptionsManager::getInstance().getKeyControl("right"))){
		player.moveLeft();
	}
	else if (sdl::Keyboard::isKeyPressed(GameOptionsManager::getInstance().getKeyControl("right")) && sdl::Keyboard::isKeyReleased(GameOptionsManager::getInstance().getKeyControl("left"))){
		player.moveRight();
	}
}