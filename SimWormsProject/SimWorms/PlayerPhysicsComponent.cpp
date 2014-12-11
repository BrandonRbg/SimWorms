#pragma once
#include "PlayerPhysicsComponent.h"
#include "Entity.h"

void PlayerPhysicsComponent::update(Entity *player, Terrain &terrain, float frametime){
	if (player->isOnGround)
		stopMovingY(player);
	else
		addConstraint(sdl::Vector2Float(0, 10), frametime);
	player->setVelocity(player->getVelocity() + resultingVector);
	checkCollision(player, terrain, frametime);
	//if (resultingVector.y * (1 / frametime) > 200) {
	//	player->setHealth(player->getHealth() - (resultingVector.y * (1 / frametime) / 45));
	//}
	//if (resultingVector.y * (1 / frametime) > 325) {
	//	player->setHealth(0);
	//}
}

void PlayerPhysicsComponent::checkCollision(Entity *player, Terrain &terrain, float frametime){
	sdl::Vector2Float finalPos = player->getPosition() + player->getVelocity();
	if (player->getVelocity().y >= 0){
		while (player->getPosition().y < finalPos.y){
			player->isOnGround = false;
			if (terrain.isPixelSolid(player->getPosition() + sdl::Vector2Float(0, 1))){
				finalPos = player->getPosition();
				player->isOnGround = true;
				player->setPosition(finalPos);
			}
			else
				player->setPosition(player->getPosition() + sdl::Vector2Float(0, 1));
		}
		if (player->getVelocity().x > 0){
			player->setPosition(player->getPosition() - sdl::Vector2Float(0, 5));
			while (player->getPosition().x < finalPos.x){
				if (terrain.isPixelSolid(player->getPosition()))
					break;
				else
					player->setPosition(player->getPosition() + sdl::Vector2Float(1, 0));
			}
		}
		else if (player->getVelocity().x < 0){
			player->setPosition(player->getPosition() - sdl::Vector2Float(0, 5));
			while (player->getPosition().x > finalPos.x){
				if (terrain.isPixelSolid(player->getPosition()))
					break;
				else
					player->setPosition(player->getPosition() - sdl::Vector2Float(1, 0));
			}
		}
		if (player->isOnGround){
			while (!terrain.isPixelSolid(player->getPosition() + sdl::Vector2Float(0, 1))){
				player->setPosition(player->getPosition() + sdl::Vector2Float(0, 1));
			}
		}
	}
	else{

	}
}

bool PlayerPhysicsComponent::isSliding(Entity *player, Terrain &terrain, float x, float y, float frametime){
	float terrainNormalX = terrain.getNormal(sdl::Vector2Float(x, y)).x;
	if (terrainNormalX > 0.9 || terrainNormalX < -0.9){
		stopMovingX(player);
		stopMovingY(player);
		addConstraint(sdl::Vector2Float(25 * terrainNormalX, 0), frametime);
		player->setVelocity(resultingVector + player->getVelocity());
		cannotMove = true;
		return true;
	}
	cannotMove = false;
	return false;
}
void PlayerPhysicsComponent::stopMovingX(Entity *player){
	resultingVector = sdl::Vector2Float(0, resultingVector.y);
	player->setVelocity(resultingVector);
}
void PlayerPhysicsComponent::stopMovingY(Entity *player){
	resultingVector = sdl::Vector2Float(resultingVector.x, 0);
	player->setVelocity(resultingVector);
}
bool PlayerPhysicsComponent::cantMove(Entity *player){
	return !(player->isOnGround);
}