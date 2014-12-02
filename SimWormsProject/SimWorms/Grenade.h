#pragma once
#include "Projectile.h"
#include "OOSDL\Clock.h"
class Grenade : public Projectile{
protected:
	sdl::Clock* clock;
	double timer;
public:
	Grenade(sdl::Vector2Float &startingPosition, sdl::Vector2Float &orientation, float force, double time);

	~Grenade();

	void update(float frameTime, Terrain &terrain);

	void draw(sdl::Window &target);

	bool isDead() { return dead; }

	void explode(float frametime, Terrain &terrain);
};