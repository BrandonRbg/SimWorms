#pragma once
#include "OOSDL\OOSDL.h"
#include "Terrain.h"
// DO NOT MAKE INSTANCES OF!!!
class PhysicsComponent
{
protected:
	sdl::Vector2Float resultingVector;
public:
	PhysicsComponent();
	virtual void update(Terrain &terrain);
	void addConstraint(sdl::Vector2Float &vector);
	virtual void checkCollision(Terrain &terrain);
};

