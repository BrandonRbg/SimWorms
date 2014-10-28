#pragma once
#include "Singleton.h"
#include "Explosion.h"


class ExplosionsManager : public Singleton<ExplosionsManager>
{
public:
	~ExplosionsManager();
	void addExplosion(sdl::Vector2Int position, float radius);
	void update(sdl::Window& target);
private:
	std::list<Explosion*> explosions;
};

