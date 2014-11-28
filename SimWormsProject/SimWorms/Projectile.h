#pragma once
#include "Entity.h"
#include "ProjectilePhysicsComponents.h"
class Projectile : public Entity{
public:
	
	virtual void draw(sdl::Window& window) = 0;

	virtual bool isDead() = 0;

	virtual void update(float FrameTime, Terrain& terrain) = 0;

	virtual void explode(float frametime) = 0;
};