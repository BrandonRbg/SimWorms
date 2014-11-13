#include "PlayerPhysicsComponent.h"
#include "Player.h"

void PlayerPhysicsComponent::update(Player &player, Terrain &terrain, float frametime){
	addConstraint(sdl::Vector2Float(0, 10)* frametime);
	checkCollision(player, terrain, frametime);
}

void PlayerPhysicsComponent::checkCollision(Player &player, Terrain &terrain, float frametime){
	sdl::Vector2Float playerVelocity = player.getVelocity() + resultingVector;
	sdl::Vector2Float finalPos = player.getPosition() + resultingVector;
	// is going left...
	if (playerVelocity.x < 0){
		sdl::Vector2Float finalPosLeft(finalPos.x, finalPos.y + (player.getBounds().h / 2));
		while (terrain.isPixelSolid(finalPosLeft)){
			finalPos.x++;
			if (terrain.isPixelSolid(finalPosLeft)) {
				player.setVelocity(sdl::Vector2Float(0, player.getVelocity().y));
				stopMovingX(player);
				break;
			}
		}
	}
	// is going right...
	else if (playerVelocity.x > 0){
		sdl::Vector2Float finalPosRight(finalPos.x + player.getBounds().w, finalPos.y + (player.getBounds().h / 2));
		while (terrain.isPixelSolid(finalPosRight)){
			finalPos.x--;
			if (terrain.isPixelSolid(finalPosRight)) {
				player.setVelocity(sdl::Vector2Float(0, player.getVelocity().y));
				stopMovingX(player);
				break;
			}
		}
	}
	// is going up...
	if (playerVelocity.y <= 0){
		sdl::Vector2Float finalPosUp(finalPos.x + (player.getBounds().w / 2), finalPos.y);
		while (terrain.isPixelSolid(finalPosUp)){
			finalPos.y++;
			if (terrain.isPixelSolid(finalPosUp)) {
				player.setVelocity(sdl::Vector2Float(player.getVelocity().x, 0));
				resultingVector = 0;
				break;
			}
		}
	}
	// is going down...
	else if (playerVelocity.y >= 0){
		sdl::Vector2Float finalPosDown(finalPos.x + (player.getBounds().w / 2), finalPos.y + player.getBounds().h);
		while (terrain.isPixelSolid(finalPosDown)){
			finalPos.y--;
			if (terrain.isPixelSolid(finalPosDown)) {
				player.setVelocity(sdl::Vector2Float(player.getVelocity().x, 0));
				resultingVector = 0;
				break;
			}
		}
	}
	player.setPosition(finalPos);
}
void PlayerPhysicsComponent::stopMovingX(Player &player){
	resultingVector = sdl::Vector2Float(0, resultingVector.y);
	player.setVelocity(sdl::Vector2Float(0, player.getVelocity().y));
}

bool PlayerPhysicsComponent::isInMidAir(){
	if (resultingVector.y == 0)
		return false;
	else
		return true;
}