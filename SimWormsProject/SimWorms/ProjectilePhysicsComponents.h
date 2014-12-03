#pragma once
#include "PhysicsComponent.h"
class Entity;
class ProjectilePhysicsComponents : public PhysicsComponent
{
public:
	void update(Entity *projectile, Terrain &terrain, float frametime);
	void checkCollision(Entity *projectile, Terrain &terrain, float frametime);
	bool cantMove(Entity *projectile){ return false; }
	void stopMovingX(Entity *projectile){ resultingVector.x = 0; }
	void stopMovingY(Entity *projectile){ resultingVector.y = 0; }
};

