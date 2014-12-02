#include "ProjectilePhysicsComponents.h"
#include "Entity.h"

void  ProjectilePhysicsComponents::update(Entity *projectile, Terrain &terrain, float frametime) {
	addConstraint(sdl::Vector2Float(0, 10), frametime);
	checkCollision(projectile, terrain, frametime);
}

void  ProjectilePhysicsComponents::checkCollision(Entity *projectile, Terrain &terrain, float frametime) {
	projectile->setPosition(projectile->getPosition() + resultingVector);
	if (terrain.isPixelSolid(projectile->getPosition())) {
		projectile->explode(frametime, terrain);
	}
}