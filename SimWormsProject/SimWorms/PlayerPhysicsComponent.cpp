#pragma once
#include "PlayerPhysicsComponent.h"
#include "Entity.h"

void PlayerPhysicsComponent::update(Entity *player, Terrain &terrain, float frametime){
	addConstraint(sdl::Vector2Float(0, 10), frametime);
	if (!(player->isOnGround && player->getVelocity().y > 0))
		player->setVelocity(player->getVelocity() + resultingVector);
	else if (player->isOnGround)
		stopMovingY(player);
	player->setPosition(player->getPosition() + player->getVelocity());
	checkCollision(player, terrain, frametime);
	//if (resultingVector.y * (1 / frametime) > 200) {
	//	player->setHealth(player->getHealth() - (resultingVector.y * (1 / frametime) / 45));
	//}
	//if (resultingVector.y * (1 / frametime) > 325) {
	//	player->setHealth(0);
	//}
}

void PlayerPhysicsComponent::checkCollision(Entity *player, Terrain &terrain, float frametime){
	sdl::Vector2Float  finalPosition = player->getPosition();
	player->isOnGround = false;
	for (int bottomX = (int)finalPosition.x - player->getBounds().w / 2; bottomX <= (int)finalPosition.x + player->getBounds().w / 2; bottomX++) {
		if (terrain.isPixelSolid(sdl::Vector2Float(bottomX, (int)finalPosition.y + player->getBounds().y / 2 + 1)) && (player->getVelocity().y > 0)) {
			player->isOnGround = true;
			for (int yCheck = (int)finalPosition.y + player->getBounds().h / 4; yCheck < (int)finalPosition.y + player->getBounds().h / 2; yCheck++) {
				if (terrain.isPixelSolid(sdl::Vector2Float(bottomX, yCheck))) {
					finalPosition.y = yCheck - player->getBounds().h / 2;
					break;
				}
			}
		}
	}

	player->isTopBlocked = false;
	for (int topX = (int)finalPosition.x - player->getBounds().w / 2; topX <= (int)finalPosition.x + player->getBounds().w / 2; topX++) {
		if (terrain.isPixelSolid(sdl::Vector2Float(topX, (int)finalPosition.y - player->getBounds().h / 2 - 1))) {
			player->isTopBlocked = true;
		}
	}
	if (player->getVelocity().y < 0) {
		for (int leftY = (int)finalPosition.y - player->getBounds().y / 2; leftY <= (int)finalPosition.y + player->getBounds().h / 2; leftY++) {
			if (terrain.isPixelSolid(sdl::Vector2Float((int)finalPosition.x - player->getBounds().w / 2, leftY))) {
				for (int xCheck = (int)finalPosition.x - player->getBounds().w / 4; xCheck < (int)finalPosition.x - player->getBounds().w / 2; xCheck--) {
					if (terrain.isPixelSolid(sdl::Vector2Float(xCheck, leftY))) {
						finalPosition.x = xCheck + player->getBounds().w / 2;
						break;
					}
				}
				if (leftY > finalPosition.y && !player->isTopBlocked) {
					finalPosition.y -= 1;
				}
				else {
					player->setVelocity(sdl::Vector2Float(player->getVelocity().x, player->getVelocity().y * -0.4));
					finalPosition.x += 2;
				}
			}
		}
	}
	if (player->getVelocity().x > 0) {
		for (int rightY = (int)finalPosition.y - player->getBounds().h / 2; rightY <= (int)finalPosition.y + player->getBounds().h / 2; rightY++) {
			if (terrain.isPixelSolid(sdl::Vector2Float((int)finalPosition.x + player->getBounds().w / 2, rightY))) {
				for (int xCheck = (int)finalPosition.x + player->getBounds().w / 4; xCheck < (int)finalPosition.x + player->getBounds().w / 2 + 1; xCheck++) {
					if (terrain.isPixelSolid(sdl::Vector2Float(xCheck, rightY))) {
						finalPosition.x = xCheck - player->getBounds().w / 2;
						break;
					}
				}
				if (rightY > finalPosition.y && !player->isTopBlocked) {
					finalPosition.y -= 1;
				}
				else {
					player->setVelocity(sdl::Vector2Float(player->getVelocity().x * -0.4, player->getVelocity().y));
					finalPosition.x -= 2;
				}
			}
		}
	}

	if (finalPosition.x < 0 && player->getVelocity().x < 0) {
		finalPosition.x -= finalPosition.x;
		player->setVelocity(sdl::Vector2Float(player->getVelocity().x * -1, player->getVelocity().y));
	}
	if (finalPosition.y < 0 && player->getVelocity().y < 0) {
		finalPosition.y -= finalPosition.y;
		player->setVelocity(sdl::Vector2Float(player->getVelocity().x, player->getVelocity().y * -1));
	}
	if (finalPosition.x > terrain.getSize().x && player->getVelocity().y > 0) {
		finalPosition.x += terrain.getSize().x - finalPosition.x;
		player->setVelocity(sdl::Vector2Float(player->getVelocity().x * -1, player->getVelocity().y));
	}
	if (finalPosition.y + player->getBounds().h / 2 > terrain.getSize().y && player->getVelocity().y > 0) {
		finalPosition.y += terrain.getSize().y - finalPosition.y - player->getBounds().h / 2;
		player->setVelocity(sdl::Vector2Float(player->getVelocity().x, 0));
		player->isOnGround = true;
	}
	player->setPosition(finalPosition);
}

bool PlayerPhysicsComponent::isSliding(Entity *player, Terrain &terrain, float x, float y, float frametime){
	float terrainNormalX = terrain.getNormal(sdl::Vector2Float(x, y)).x;
	if (terrainNormalX > 0.9 || terrainNormalX < -0.9){
		stopMovingX(player);
		stopMovingY(player);
		addConstraint(sdl::Vector2Float(125 * terrainNormalX, 0), frametime);
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