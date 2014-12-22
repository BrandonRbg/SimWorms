#pragma once
#include "Entity.h"
#include "ProjectilePhysicsComponents.h"
#include "Explosion.h"
class Projectile : public Entity{
protected:
	bool isLaunched;
public:
	
	virtual void draw(sdl::Window& window) = 0;

	void update(float frametime, Terrain& terrain, Camera* cam);

	virtual void explode(float frametime, Terrain& terrain) = 0;

	virtual void isTimedOut(Terrain &terrain, float frametime) = 0;
};