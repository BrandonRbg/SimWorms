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

	void draw(sdl::Window &target);

	void explode(float frametime, Terrain &terrain);

	void isTimedOut(Terrain &terrain, float frametime);

	sdl::Vector2Float& getPosition();
};