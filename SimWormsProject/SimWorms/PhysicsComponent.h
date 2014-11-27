#pragma once
#include "OOSDL\OOSDL.h"
#include "Terrain.h"
class Entity;
class PhysicsComponent
{
protected:
	sdl::Vector2Float resultingVector;
	sdl::Vector2Float position;
	sdl::Vector2Float velocity;
public:
	PhysicsComponent();
	virtual void update(Entity *entity, Terrain &terrain, float frametime) = 0;
	virtual void checkCollision(Entity *entity, Terrain &terrain, float frametime) = 0;
	virtual bool cantMove(Entity *player) = 0;
	virtual void stopMovingX(Entity *player) = 0;
	virtual void stopMovingY(Entity *player) = 0;
	void addConstraint(sdl::Vector2Float &vector, float frametime);
};

