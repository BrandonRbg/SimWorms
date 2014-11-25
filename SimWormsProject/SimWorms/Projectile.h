#pragma once
#include "Entity.h"

class Projectile : public Entity{
public:
	//Projectile(sdl::Vector2Float &startingPosition, sdl::Vector2Float &orientation, float force);

	virtual void draw(sdl::Window& window) = 0;

	virtual bool isDead() = 0;

	virtual void update(float FrameTime, Terrain& terrain) = 0;
};