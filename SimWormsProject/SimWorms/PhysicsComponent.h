#pragma once
#include "OOSDL\OOSDL.h"
#include "Terrain.h"
#include "MapManager.h"
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
	virtual bool cantMove(Entity *entity) = 0;
	virtual void stopMovingX(Entity *entity) = 0;
	virtual void stopMovingY(Entity *entity) = 0;
	void addConstraint(sdl::Vector2Float &vector, float frametime);
	void addFConstraint(sdl::Vector2Float &vector);
	sdl::Vector2Float getResultingVector() { return resultingVector; }
};

