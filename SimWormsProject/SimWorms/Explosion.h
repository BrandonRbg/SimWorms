#pragma once
#include "OOSDL/AnimatedSprite.h"
#include "AssetsManager.h"
#include "EntityManager.h"
class Explosion : public Entity
{
public:
	Explosion(sdl::Vector2Float &position, Terrain &terrain, float radius, float frametime);
	~Explosion();
	void draw(sdl::Window& target);
	bool isDead();
	void explode(float frametime, Terrain &terrain);
	void update(float frametime, Terrain& terrain, Camera* cam);
private:
	int numberOfFrames;
	int delay;
	float radius;
	sdl::Clock explosionClock;
	sdl::AnimatedSprite* explosionSprite;
};

