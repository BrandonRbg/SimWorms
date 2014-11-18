#include "PlayerInputComponent.h"
#include "Player.h"
void PlayerInputComponent::update(Player &player){
	if (sdl::Keyboard::isKeyPressed(SDLK_LEFT)){
		player.moveLeft();
	}
<<<<<<< HEAD
	if (sdl::Keyboard::isKeyReleased(SDLK_LEFT))
	{
=======
	if (sdl::Keyboard::isKeyReleased(SDLK_LEFT)){
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
		player.stop();
	}
	if (sdl::Keyboard::isKeyPressed(SDLK_RIGHT)){
		player.moveRight();
	}
	if (sdl::Keyboard::isKeyReleased(SDLK_RIGHT)){
<<<<<<< HEAD
		//player.stop();
=======
		player.stop();
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
	}
}