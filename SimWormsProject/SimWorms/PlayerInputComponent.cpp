#include "PlayerInputComponent.h"
#include "Player.h"

void PlayerInputComponent::update(Entity *player, float frametime){
	if (player->isOnGround)
		player->stop();
	Player* tmp = static_cast<Player*>(player);
	if (tmp != 0 && tmp->getState() != PlayerState::JetPack) {
		if (sdl::Keyboard::isKeyPressed(SDLK_SPACE)){		
		player->jump(frametime);
		}
	}
	if (sdl::Keyboard::isKeyPressed(GameOptionsManager::getInstance().getKeyControl("left")) && sdl::Keyboard::isKeyReleased(GameOptionsManager::getInstance().getKeyControl("right"))){
		player->setDirection(false);
		if (tmp->getState() == PlayerState::JetPack){
			player->stop();
			player->moveLeft(frametime);
			player->moveLeft(frametime);
			player->moveLeft(frametime);
			player->moveLeft(frametime);
			player->moveLeft(frametime);
			player->moveLeft(frametime);
		}
		player->moveLeft(frametime);
	}
	else if (sdl::Keyboard::isKeyPressed(GameOptionsManager::getInstance().getKeyControl("right")) && sdl::Keyboard::isKeyReleased(GameOptionsManager::getInstance().getKeyControl("left"))){
		player->setDirection(true);
		if (tmp->getState() == PlayerState::JetPack){
			player->stop();
			player->moveRight(frametime);
			player->moveRight(frametime);
			player->moveRight(frametime);
			player->moveRight(frametime);
			player->moveRight(frametime);
			player->moveRight(frametime);
		}
		player->moveRight(frametime);
	}

}