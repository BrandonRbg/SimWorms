#pragma once
#include "Singleton.h"
#include "Explosion.h"
#include "Terrain.h"


class ExplosionsManager : public Singleton<ExplosionsManager>
{
public:
	~ExplosionsManager();
	void addExplosion(sdl::Vector2Float position, Terrain &terrain, float radius);
	void update(sdl::Window& target);
private:
	std::list<Explosion*> explosions;
};

