#pragma once
#include "EntityManager.h"
#include "Player.h"
#include "Explosion.h"

class Mine : public Entity{
public:
	Mine(sdl::Vector2Float &position);
	~Mine();
	void draw(sdl::Window &target);
	void update(float frametime, Terrain& terrain, Camera* cam);
	void explode(float frametime, Terrain &terrain) { return; }
};