#pragma once
#include "Projectile.h"

class Rocket : public Projectile{
protected:
	bool dead;
public:
	Rocket(sdl::Vector2Float &startingPosition, sdl::Vector2Float &orientation, float force);

	void update(float frameTime, Terrain &terrain);

	void draw(sdl::Window &target);

	bool isDead();
};