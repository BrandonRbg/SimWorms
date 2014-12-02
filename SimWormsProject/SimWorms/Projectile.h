#pragma once
#include "Entity.h"
#include "ProjectilePhysicsComponents.h"
class Projectile : public Entity{
protected:
	bool dead;
	bool isLaunched;
public:
	
	virtual void draw(sdl::Window& window) = 0;

	virtual bool isDead() = 0;

	void update(float FrameTime, Terrain& terrain);

	virtual void explode(float frametime, Terrain& terrain) = 0;
};