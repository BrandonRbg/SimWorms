#pragma once
#include "PhysicsComponent.h"
class Entity;
class Player;
class PlayerPhysicsComponent : public PhysicsComponent
{
private:
	bool isSliding(Entity *player, Terrain &terrain, float x, float y, float frametime);
	bool cannotMove;
public:
	void update(Entity *entity, Terrain &terrain, float frametime);
	void checkCollision(Entity *entity, Terrain &terrain, float frametime);
	bool cantMove(Entity *player);
	bool isUpperBoundBlocked;
	void stopMovingX(Entity *player);
	void stopMovingY(Entity *player);
};

