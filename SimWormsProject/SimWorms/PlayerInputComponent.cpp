#include "PlayerInputComponent.h"
#include "Player.h"
void PlayerInputComponent::update(Player &player, float frametime){
	if (player.isOnGround)
		player.stop();
	if (sdl::Keyboard::isKeyPressed(SDLK_SPACE)){
		player.jump(frametime);
	}
	else if (sdl::Keyboard::isKeyPressed(GameOptionsManager::getInstance().getKeyControl("left")) && sdl::Keyboard::isKeyReleased(GameOptionsManager::getInstance().getKeyControl("right"))){
		player.moveLeft(frametime);
	}
	else if (sdl::Keyboard::isKeyPressed(GameOptionsManager::getInstance().getKeyControl("right")) && sdl::Keyboard::isKeyReleased(GameOptionsManager::getInstance().getKeyControl("left"))){
		player.moveRight(frametime);
	}

}