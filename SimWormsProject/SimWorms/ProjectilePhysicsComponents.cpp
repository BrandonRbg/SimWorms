#include "ProjectilePhysicsComponents.h"
#include "GameManager.h"
#include "Entity.h"


void  ProjectilePhysicsComponents::update(Entity *projectile, Terrain &terrain, float frametime) {
	addFConstraint(sdl::Vector2Float(0, MapManager::getInstance().getActualMap()->gravityForce));
	if (GameManager::getInstance().isStarted())
		addFConstraint(MapManager::getInstance().getActualMap()->windForce);
	checkCollision(projectile, terrain, frametime);
}

void  ProjectilePhysicsComponents::checkCollision(Entity *projectile, Terrain &terrain, float frametime) {
	if (terrain.isPixelSolid(projectile->getPosition() + resultingVector * frametime)) {
		sdl::Vector2Float normalizedVector = resultingVector;
		normalizedVector.normalize();
		while (!terrain.isPixelSolid(projectile->getPosition() + normalizedVector * frametime)) {
			projectile->setPosition(projectile->getPosition() + normalizedVector * frametime);
		}
		projectile->explode(frametime, terrain);
		//GameManager::getInstance().setTour((GameManager::getInstance().getTour() + 1) % (GameManager::getInstance().getNumberPlayer()));
		projectile->isOnGround = true;
	}
	else
		projectile->setPosition(projectile->getPosition() + resultingVector * frametime);
	if (projectile->getPosition().x > terrain.getSize().x || projectile->getPosition().x < 0)
		projectile->setDead(true);
}