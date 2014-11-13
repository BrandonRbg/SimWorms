#pragma once
#include "PhysicsComponent.h"
#include "Player.h"
class PlayerPhysicsComponent : private PhysicsComponent
{
private:
	
public:
	PlayerPhysicsComponent();
	~PlayerPhysicsComponent();
	void update();
	bool checkCollision(Terrain &terrain);
};

