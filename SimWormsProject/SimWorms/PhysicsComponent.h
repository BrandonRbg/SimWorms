#pragma once
#include "OOSDL\OOSDL.h"
#include "Terrain.h"
class PhysicsComponent
{
private:
	sdl::Vector2Float resultingVector;
public:
	PhysicsComponent();
	~PhysicsComponent();
	virtual void update() = 0;
	void addConstraint(sdl::Vector2Float &vector);
	virtual bool checkCollision(Terrain &terrain);
};

