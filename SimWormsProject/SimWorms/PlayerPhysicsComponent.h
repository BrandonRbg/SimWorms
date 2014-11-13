#pragma once
#include "PhysicsComponent.h"
class Player;
class PlayerPhysicsComponent : public PhysicsComponent
{
public:
	void update(Player &player, Terrain &terrain, float frametime);
	void checkCollision(Player &player, Terrain &terrain, float frametime);
	void stopMovingX(Player &player);
	bool isInMidAir();
};

