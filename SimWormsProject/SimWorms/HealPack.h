#pragma once
#include "EntityManager.h"
#include "Player.h"

class HealPack : public Entity{
public:
	HealPack(sdl::Vector2Float &position);
	~HealPack();
	void draw(sdl::Window &target);
	void update(float frametime, Terrain& terrain, Camera* cam);
	bool isDead();
	void explode(float frametime, Terrain &terrain) { return; }
};