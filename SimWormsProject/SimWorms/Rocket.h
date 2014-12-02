#pragma once
#include "Projectile.h"
#include "ExplosionsManager.h"

class Rocket : public Projectile{
public:
	Rocket(sdl::Vector2Float &startingPosition, sdl::Vector2Float &orientation, float force);
	~Rocket() { delete physics; }

	void update(float frameTime, Terrain &terrain);

	void draw(sdl::Window &target);

	bool isDead() { return dead; }

	void explode(float frametime, Terrain &terrain);
};