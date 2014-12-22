#include "PlayerInputComponent.h"
#include "Player.h"

void PlayerInputComponent::update(Entity *player, float frametime){
	if (player->isOnGround)
		player->stop();
	if (sdl::Keyboard::isKeyPressed(SDLK_SPACE)){
		if (!player->jetpack) {
			player->jump(frametime);
		}
	}
	else if (sdl::Keyboard::isKeyPressed(GameOptionsManager::getInstance().getKeyControl("left")) && sdl::Keyboard::isKeyReleased(GameOptionsManager::getInstance().getKeyControl("right"))){
		player->setDirection(false);
		player->moveLeft(frametime);
	}
	else if (sdl::Keyboard::isKeyPressed(GameOptionsManager::getInstance().getKeyControl("right")) && sdl::Keyboard::isKeyReleased(GameOptionsManager::getInstance().getKeyControl("left"))){
		player->setDirection(true);
		player->moveRight(frametime);
	}

}