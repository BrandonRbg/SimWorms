#pragma once
#include "PlayerPhysicsComponent.h"
#include "EntityManager.h"

void PlayerPhysicsComponent::update(Entity *player, Terrain &terrain, float frametime){
	if (player->isOnGround && !player->jetpack)
		stopMovingY(player);
	else
		addConstraint(sdl::Vector2Float(0, MapManager::getInstance().getActualMap().gravityForce), frametime);
	player->setVelocity(player->getVelocity() + resultingVector);
	checkCollision(player, terrain, frametime);

	if (!EntityManager::getInstance().first) {
		if ((resultingVector.y * (1 / frametime) > 200) && (player->isOnGround)) {
			player->setHealth(player->getHealth() - (resultingVector.y * (1 / frametime) / 45));
		}
		if ((resultingVector.y * (1 / frametime) > 325) && (player->isOnGround)) {
			player->setHealth(0);
		}
	}
}

void PlayerPhysicsComponent::checkCollision(Entity *player, Terrain &terrain, float frametime){
	sdl::Vector2Float finalPos = player->getPosition() + player->getVelocity();
	sdl::Vector2Float pixelOfCollision = sdl::Vector2Float();
	if (player->getVelocity().y >= 0){
		if (player->getVelocity().x >= 0){
			for (float yCheck = player->getBounds().h; yCheck > player->getBounds().h / 2 && pixelOfCollision == sdl::Vector2Float(); yCheck--){
				for (float xCheck = player->getBounds().w; xCheck > player->getBounds().w / 2; xCheck--){
					if (player->isPixelSolid(sdl::Vector2Float(xCheck, yCheck))){
						pixelOfCollision = sdl::Vector2Float(xCheck, yCheck);
						break;
					} 
				}
			}
		}
		else{
			for (float yCheck = player->getBounds().h; yCheck > player->getBounds().h / 2 && pixelOfCollision == sdl::Vector2Float(); yCheck--){
				for (float xCheck = 0; xCheck < player->getBounds().w; xCheck++){
					if (player->isPixelSolid(sdl::Vector2Float(xCheck, yCheck))){
						pixelOfCollision = sdl::Vector2Float(xCheck, yCheck);
						break;
					}
				}
			}
		}
	}
	else{
		if (player->getVelocity().x >= 0){
			for (float yCheck = 0; yCheck < player->getBounds().h / 2 && pixelOfCollision == sdl::Vector2Float(); yCheck++){
				for (float xCheck = player->getBounds().w; xCheck > player->getBounds().w / 2; xCheck--){
					if (player->isPixelSolid(sdl::Vector2Float(xCheck, yCheck))){
						pixelOfCollision = sdl::Vector2Float(xCheck, yCheck + player->getBounds().h / 2);
						break;
					}
				}
			}
		}
		else{
			for (float yCheck = 0; yCheck < player->getBounds().h / 2 && pixelOfCollision == sdl::Vector2Float(); yCheck++){
				for (float xCheck = 0; xCheck < player->getBounds().w / 2; xCheck++){
					if (player->isPixelSolid(sdl::Vector2Float(xCheck, yCheck))){
						pixelOfCollision = sdl::Vector2Float(xCheck, yCheck + player->getBounds().h / 2);
						break;
					}
				}
			}
		}
	}
	player->setOrigin(pixelOfCollision);
	if (player->getVelocity().y >= 0 && !player->jetpack){
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
		unsigned int dist = 0;
		if (player->getVelocity().x > 0){
			player->setPosition(player->getPosition() - sdl::Vector2Float(0, 1));
			while (player->getPosition().x < finalPos.x){
				if (terrain.isPixelSolid(player->getPosition()))
					break;
				else{
					dist++;
					player->setPosition(player->getPosition() + sdl::Vector2Float(1, 0));
				}
			}
		}
		else if (player->getVelocity().x < 0 ){
			player->setPosition(player->getPosition() - sdl::Vector2Float(0, 1));
			while (player->getPosition().x > finalPos.x){
				if (terrain.isPixelSolid(player->getPosition()))
					break;
				else{
					dist++;
					player->setPosition(player->getPosition() - sdl::Vector2Float(1, 0));
				}
			}
		}
		if (!isSliding(player, terrain, player->getPosition().x, player->getPosition().y,frametime)){
			if (terrain.isPixelSolid(player->getPosition() + sdl::Vector2Float(0, 1))){
				if (player->getVelocity().x != 0 && dist == 0){
					if (player->getVelocity().x < 0)
						player->setPosition(player->getPosition() + sdl::Vector2Float(1,1));
					else
						player->setPosition(player->getPosition() + sdl::Vector2Float(-1, 1));
				}
			}
			else if (player->getVelocity().x != 0 && terrain.isPixelSolid(player->getPosition() + sdl::Vector2Float(0, 2)))
				player->setPosition(player->getPosition() + sdl::Vector2Float(0, 1));
			else{
				player->isOnGround = terrain.isPixelSolid(player->getPosition() + sdl::Vector2Float(0, 2));
				if (!player->isOnGround){
					stopMovingX(player);
					player->setPosition(player->getPosition() + sdl::Vector2Float(0, 1));
				}
			}
		}
	}
	else{
		sdl::Vector2Float normalizedMove = player->getVelocity();
		normalizedMove.normalize();
		if (normalizedMove.x > 0){
			while (player->getPosition().y > finalPos.y && player->getPosition().x < finalPos.x){
				if (terrain.isPixelSolid(player->getPosition() + normalizedMove))
					break;
				else
					player->setPosition(player->getPosition() + normalizedMove);
			} 
		}
		else if (normalizedMove.x < 0){
			while (player->getPosition().y > finalPos.y && player->getPosition().x > finalPos.x){
				if (terrain.isPixelSolid(player->getPosition() + normalizedMove))
					break;
				else
					player->setPosition(player->getPosition() + normalizedMove);
			}
		}
		else{
			while (player->getPosition().y > finalPos.y){
				if (terrain.isPixelSolid(player->getPosition() + normalizedMove))
					break;
				else
					player->setPosition(player->getPosition() + normalizedMove);
			}
		}
	}
}

bool PlayerPhysicsComponent::isSliding(Entity *player, Terrain &terrain, float x, float y, float frametime){
	float terrainNormalX = terrain.getNormal(sdl::Vector2Float(x, y)).x;
	if (terrainNormalX > 0.9 || terrainNormalX < -0.9){
		stopMovingX(player);
		stopMovingY(player);
		addConstraint(sdl::Vector2Float(25 * terrainNormalX, 0), frametime);
		player->setVelocity(resultingVector + player->getVelocity());
		player->setPosition(player->getPosition() + player->getVelocity());
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
	if (!player->jetpack)
		return !player->isOnGround || cannotMove;
	else
		return false;
}