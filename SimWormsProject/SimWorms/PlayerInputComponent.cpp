#include "PlayerInputComponent.h"
#include "Player.h"
void PlayerInputComponent::update(Player &player){
	if (sdl::Keyboard::isKeyPressed(SDLK_LEFT)){
		player.moveLeft();
	}
	if (sdl::Keyboard::isKeyReleased(SDLK_LEFT))
	{
		player.stop();
	}
	if (sdl::Keyboard::isKeyPressed(SDLK_RIGHT)){
		player.moveRight();
	}
	if (sdl::Keyboard::isKeyReleased(SDLK_RIGHT)){
		//player.stop();
	}
}