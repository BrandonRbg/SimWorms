#pragma once
#include "PhysicsComponent.h"
class Player;
class PlayerPhysicsComponent : public PhysicsComponent
{
public:
	void update(Player &player, Terrain &terrain, float frametime);
	void checkCollision(Player &player, Terrain &terrain, float frametime);
<<<<<<< HEAD
	void stopMovingX(Player &player);
	bool isInMidAir();
=======
	bool isInMidAir(Player &player);
	bool isUpperBoundBlocked;
	bool isUpperBoundBlockedFromLeft;
	bool isUpperBoundBlockedFromRight;
	void stopMovingX(Player &player);
	void stopMovingY(Player &player);
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
};

