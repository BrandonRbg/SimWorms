#include "PlayerInputComponent.h"
#include "Player.h"

void PlayerInputComponent::update(Player &player){
	if (sdl::Keyboard::isKeyPressed(SDLK_a)){
		player.moveLeft();
	}
	if (sdl::Keyboard::isKeyReleased(SDLK_a))
	{
		player.stopLeft();
	}
	if (sdl::Keyboard::isKeyPressed(SDLK_d)){
		player.moveRight();
	}
	if (sdl::Keyboard::isKeyReleased(SDLK_d))
	{
		player.stopRight();
	}
	if (sdl::Keyboard::isKeyPressed(SDLK_SPACE)){
		player.jump();
	}
}
