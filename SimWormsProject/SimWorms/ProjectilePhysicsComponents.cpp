#include "ProjectilePhysicsComponents.h"
#include "GameManager.h"
#include "Entity.h"

void  ProjectilePhysicsComponents::update(Entity *projectile, Terrain &terrain, float frametime) {
	addConstraint(sdl::Vector2Float(0, MapManager::getInstance().getActualMap().gravityForce), frametime);
	addConstraint(MapManager::getInstance().getActualMap().windForce, frametime);
	checkCollision(projectile, terrain, frametime);
}

void  ProjectilePhysicsComponents::checkCollision(Entity *projectile, Terrain &terrain, float frametime) {
	if (terrain.isPixelSolid(projectile->getPosition() + resultingVector)) {
		sdl::Vector2Float normalizedVector = resultingVector;
		normalizedVector.normalize();
		while (!terrain.isPixelSolid(projectile->getPosition() + normalizedVector)) {
			projectile->setPosition(projectile->getPosition() + normalizedVector);
		}
		projectile->explode(frametime, terrain);
		GameManager::getInstance().setTour((GameManager::getInstance().getTour() + 1) % (GameManager::getInstance().getNumberPlayer()));
	}
	else
		projectile->setPosition(projectile->getPosition() + resultingVector);
}