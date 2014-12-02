#pragma once
#include "Projectile.h"
#include "OOSDL\Clock.h"

class Grenade : public Projectile{
protected:
	bool dead;
	sdl::Clock* clock;
public:
	Grenade(sdl::Vector2Float &startingPosition, sdl::Vector2Float &orientation, float force, double time);

	void update(float frameTime, Terrain &terrain);

	void draw(sdl::Window &target);

	bool isDead();
};